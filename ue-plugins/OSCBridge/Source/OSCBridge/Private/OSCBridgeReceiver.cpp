// Copyright NM 2026
#include "OSCBridgeReceiver.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "OSCAddress.h"
#include "OSCManager.h"
#include "OSCMessage.h"
#include "OSCServer.h"
#include "OSCTypes.h"

#include "OSCBridgeLog.h"

static TAutoConsoleVariable<int32> CVarOSCBridgeDebug(
	TEXT("OSCBridge.Debug"),
	0,
	TEXT("If > 0, draws on-screen overlay listing OSC addresses with their last value and rate. Number controls how many lines to show."),
	ECVF_Default);

TWeakObjectPtr<AOSCBridgeReceiver> AOSCBridgeReceiver::ActiveReceiver;

AOSCBridgeReceiver* AOSCBridgeReceiver::GetActiveReceiver()
{
	return ActiveReceiver.Get();
}

AOSCBridgeReceiver::AOSCBridgeReceiver()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AOSCBridgeReceiver::BeginPlay()
{
	Super::BeginPlay();

	ActiveReceiver = this;

	if (bAutoStartInGame)
	{
		StartListening();
	}
}

void AOSCBridgeReceiver::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StopListening();
	if (ActiveReceiver.Get() == this)
	{
		ActiveReceiver = nullptr;
	}
	Super::EndPlay(EndPlayReason);
}

void AOSCBridgeReceiver::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CVarOSCBridgeDebug.GetValueOnGameThread() > 0)
	{
		DrawDebugOverlay();
	}
}

void AOSCBridgeReceiver::Destroyed()
{
	StopListening();
	if (ActiveReceiver.Get() == this)
	{
		ActiveReceiver = nullptr;
	}
	Super::Destroyed();
}

void AOSCBridgeReceiver::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ReconfigureForEditorFlag();
}

#if WITH_EDITOR
void AOSCBridgeReceiver::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FName PropertyName = PropertyChangedEvent.GetPropertyName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AOSCBridgeReceiver, bListenInEditor)
	  || PropertyName == GET_MEMBER_NAME_CHECKED(AOSCBridgeReceiver, ReceiveIPAddress)
	  || PropertyName == GET_MEMBER_NAME_CHECKED(AOSCBridgeReceiver, Port)
	  || PropertyName == GET_MEMBER_NAME_CHECKED(AOSCBridgeReceiver, bMulticastLoopback))
	{
		if (IsListening())
		{
			StopListening();
		}
		ReconfigureForEditorFlag();
	}
}
#endif

void AOSCBridgeReceiver::ReconfigureForEditorFlag()
{
	if (!IsEditorWorld())
	{
		return;
	}

	if (bListenInEditor && !IsListening())
	{
		StartListening();
		ActiveReceiver = this;
	}
	else if (!bListenInEditor && IsListening())
	{
		StopListening();
	}
}

bool AOSCBridgeReceiver::IsEditorWorld() const
{
	const UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}
	return World->WorldType == EWorldType::Editor || World->WorldType == EWorldType::EditorPreview;
}

void AOSCBridgeReceiver::StartListening()
{
	if (Server && Server->IsActive())
	{
		return;
	}

	if (!Server)
	{
		Server = UOSCManager::CreateOSCServer(
			ReceiveIPAddress,
			Port,
			bMulticastLoopback,
			/*bStartListening*/ false,
			TEXT("OSCBridgeReceiver"),
			this);

		if (!Server)
		{
			UE_LOG(LogOSCBridge, Error, TEXT("OSCBridge: failed to create UOSCServer on %s:%d"), *ReceiveIPAddress, Port);
			return;
		}

		Server->OnOscMessageReceivedNative.AddUObject(this, &AOSCBridgeReceiver::HandleOscMessageReceived);
	}

	Server->Listen();
	ActiveReceiver = this;
	UE_LOG(LogOSCBridge, Display, TEXT("OSCBridge: listening on %s:%d"), *ReceiveIPAddress, Port);
}

void AOSCBridgeReceiver::StopListening()
{
	if (!Server)
	{
		return;
	}

	if (Server->IsActive())
	{
		Server->Stop();
	}
	Server->OnOscMessageReceivedNative.RemoveAll(this);
	Server = nullptr;
}

bool AOSCBridgeReceiver::IsListening() const
{
	return Server && Server->IsActive();
}

void AOSCBridgeReceiver::HandleOscMessageReceived(const FOSCMessage& Message, const FString& /*IPAddress*/, uint16 /*InPort*/)
{
	UE_LOG(LogOSCBridge, Verbose, TEXT("rx %s"), *Message.GetAddress().GetFullPath());
	RecordMessage(Message);
}

namespace
{
	FString BuildTypeSignature(const TArray<UE::OSC::FOSCData>& Args)
	{
		FString Sig;
		Sig.Reserve(Args.Num());
		for (const UE::OSC::FOSCData& Data : Args)
		{
			Sig.AppendChar(static_cast<TCHAR>(static_cast<uint8>(Data.GetDataType())));
		}
		return Sig;
	}

	FString BuildDisplayValue(const TArray<UE::OSC::FOSCData>& Args)
	{
		using EDataType = UE::OSC::EDataType;

		if (Args.Num() == 0)
		{
			return TEXT("(no args)");
		}

		FString Out;
		for (int32 i = 0; i < Args.Num(); ++i)
		{
			if (i > 0)
			{
				Out += TEXT(", ");
			}
			const UE::OSC::FOSCData& Data = Args[i];
			switch (Data.GetDataType())
			{
				case EDataType::Float:    Out += FString::Printf(TEXT("%.3f"), Data.GetFloat()); break;
				case EDataType::Double:   Out += FString::Printf(TEXT("%.3f"), Data.GetDouble()); break;
				case EDataType::Int32:    Out += FString::Printf(TEXT("%d"), Data.GetInt32()); break;
				case EDataType::Int64:    Out += FString::Printf(TEXT("%lld"), Data.GetInt64()); break;
				case EDataType::String:   Out += FString::Printf(TEXT("\"%s\""), *Data.GetString()); break;
				case EDataType::True:     Out += TEXT("true"); break;
				case EDataType::False:    Out += TEXT("false"); break;
				case EDataType::NilValue: Out += TEXT("nil"); break;
				case EDataType::Blob:     Out += FString::Printf(TEXT("blob[%d]"), Data.GetBlobArrayView().Num()); break;
				case EDataType::Char:     Out += FString::Printf(TEXT("'%c'"), Data.GetChar()); break;
				case EDataType::Color:
				{
					const FColor C = Data.GetColor();
					Out += FString::Printf(TEXT("(%d,%d,%d,%d)"), C.R, C.G, C.B, C.A);
				} break;
				default: Out += TEXT("?"); break;
			}
		}
		return Out;
	}

	float ExtractFirstAsFloat(const TArray<UE::OSC::FOSCData>& Args)
	{
		if (Args.Num() == 0)
		{
			return 0.f;
		}
		const UE::OSC::FOSCData& D = Args[0];
		if (D.IsFloat())  return D.GetFloat();
		if (D.IsInt32())  return static_cast<float>(D.GetInt32());
		if (D.IsInt64())  return static_cast<float>(D.GetInt64());
		if (D.IsDouble()) return static_cast<float>(D.GetDouble());
		if (D.IsBool())   return D.GetBool() ? 1.f : 0.f;
		return 0.f;
	}
}

void AOSCBridgeReceiver::RecordMessage(const FOSCMessage& Message)
{
	const FOSCAddress& OSCAddr = Message.GetAddress();
	const FName AddressName(*OSCAddr.GetFullPath());

	const TArray<UE::OSC::FOSCData>& Args = Message.GetArgumentsChecked();
	const FString TypeSig = BuildTypeSignature(Args);
	const FString Display = BuildDisplayValue(Args);
	const double Now = FPlatformTime::Seconds();

	FOSCBridgeAddressStats& AddrStats = Stats.FindOrAdd(AddressName);
	if (AddrStats.Count == 0)
	{
		AddrStats.Address = AddressName;
		AddrStats.FirstSeenSeconds = Now;
	}
	else
	{
		const double Dt = Now - AddrStats.LastSeenSeconds;
		if (Dt > KINDA_SMALL_NUMBER)
		{
			const float InstantHz = static_cast<float>(1.0 / Dt);
			constexpr float Alpha = 0.1f;
			AddrStats.HzEMA = (AddrStats.HzEMA <= 0.f)
				? InstantHz
				: (Alpha * InstantHz + (1.f - Alpha) * AddrStats.HzEMA);
		}
	}
	AddrStats.LastSeenSeconds = Now;
	AddrStats.Count++;
	AddrStats.ArgCount = Args.Num();
	AddrStats.ArgTypeSignature = TypeSig;
	AddrStats.LastValueDisplay = Display;
	AddrStats.LastValueFloat = ExtractFirstAsFloat(Args);

	FOSCBridgeCaptureEntry Entry;
	Entry.Address = AddressName;
	Entry.TimestampSeconds = Now;
	Entry.ArgTypeSignature = TypeSig;
	Entry.DisplayValue = Display;

	Entry.FloatArgs.Reserve(Args.Num());
	for (const UE::OSC::FOSCData& Data : Args)
	{
		if (Data.IsFloat())       Entry.FloatArgs.Add(Data.GetFloat());
		else if (Data.IsDouble()) Entry.FloatArgs.Add(static_cast<float>(Data.GetDouble()));
		else if (Data.IsInt32())  Entry.FloatArgs.Add(static_cast<float>(Data.GetInt32()));
		else if (Data.IsInt64())  Entry.FloatArgs.Add(static_cast<float>(Data.GetInt64()));
		else if (Data.IsBool())   Entry.FloatArgs.Add(Data.GetBool() ? 1.f : 0.f);
		else                      Entry.FloatArgs.Add(0.f);
	}

	for (const UE::OSC::FOSCData& Data : Args)
	{
		if (Data.IsString())
		{
			Entry.FirstStringArg = Data.GetString();
			break;
		}
	}

	for (const UE::OSC::FOSCData& Data : Args)
	{
		if (Data.IsBool())
		{
			Entry.FirstBoolArg = Data.GetBool();
			break;
		}
	}

	if (Args.Num() == 1 && Args[0].IsColor())
	{
		Entry.LinearColorArg = FLinearColor::FromSRGBColor(Args[0].GetColor());
	}
	else if (Entry.FloatArgs.Num() >= 4)
	{
		Entry.LinearColorArg = FLinearColor(Entry.FloatArgs[0], Entry.FloatArgs[1], Entry.FloatArgs[2], Entry.FloatArgs[3]);
	}
	else if (Entry.FloatArgs.Num() == 3)
	{
		Entry.LinearColorArg = FLinearColor(Entry.FloatArgs[0], Entry.FloatArgs[1], Entry.FloatArgs[2], 1.f);
	}

	if (RingBufferSize > 0)
	{
		if (RingBuffer.Num() < RingBufferSize)
		{
			RingBuffer.Add(Entry);
		}
		else
		{
			RingBuffer[RingWriteIndex % RingBufferSize] = Entry;
		}
	}
	RingWriteIndex++;

	OnCaptured.Broadcast(Entry, Message);
}

TArray<FName> AOSCBridgeReceiver::GetKnownAddresses() const
{
	TArray<FName> Out;
	Stats.GenerateKeyArray(Out);
	return Out;
}

TArray<FOSCBridgeAddressStats> AOSCBridgeReceiver::GetAllAddressStats() const
{
	TArray<FOSCBridgeAddressStats> Out;
	Out.Reserve(Stats.Num());
	for (const TPair<FName, FOSCBridgeAddressStats>& Pair : Stats)
	{
		Out.Add(Pair.Value);
	}
	return Out;
}

bool AOSCBridgeReceiver::GetAddressStats(FName Address, FOSCBridgeAddressStats& OutStats) const
{
	if (const FOSCBridgeAddressStats* Found = Stats.Find(Address))
	{
		OutStats = *Found;
		return true;
	}
	return false;
}

TArray<FOSCBridgeCaptureEntry> AOSCBridgeReceiver::GetRecentMessages(int32 MaxCount) const
{
	TArray<FOSCBridgeCaptureEntry> Out;
	if (RingBuffer.Num() == 0 || MaxCount <= 0)
	{
		return Out;
	}

	const int32 BufferSize = RingBuffer.Num();
	const int32 N = FMath::Min(MaxCount, BufferSize);
	Out.Reserve(N);

	for (int32 i = 0; i < N; ++i)
	{
		const int32 Idx = ((RingWriteIndex - 1 - i) % BufferSize + BufferSize) % BufferSize;
		Out.Add(RingBuffer[Idx]);
	}
	return Out;
}

float AOSCBridgeReceiver::GetLatestFloat(FName Address, bool& bFound) const
{
	if (const FOSCBridgeAddressStats* S = Stats.Find(Address))
	{
		bFound = true;
		return S->LastValueFloat;
	}
	bFound = false;
	return 0.f;
}

FString AOSCBridgeReceiver::GetLatestDisplay(FName Address, bool& bFound) const
{
	if (const FOSCBridgeAddressStats* S = Stats.Find(Address))
	{
		bFound = true;
		return S->LastValueDisplay;
	}
	bFound = false;
	return FString();
}

void AOSCBridgeReceiver::ClearStats()
{
	Stats.Reset();
	RingBuffer.Reset();
	RingWriteIndex = 0;
}

void AOSCBridgeReceiver::DrawDebugOverlay()
{
	if (!GEngine)
	{
		return;
	}

	const int32 MaxLines = FMath::Max(1, CVarOSCBridgeDebug.GetValueOnGameThread());
	const uint64 BaseKey = static_cast<uint64>(reinterpret_cast<UPTRINT>(this));

	GEngine->AddOnScreenDebugMessage(
		BaseKey, 0.1f, FColor::Cyan,
		FString::Printf(TEXT("[OSCBridge] %s:%d  addr=%d  msgs=%d"),
			*ReceiveIPAddress, Port, Stats.Num(), RingWriteIndex));

	TArray<FOSCBridgeAddressStats> Sorted;
	Sorted.Reserve(Stats.Num());
	for (const TPair<FName, FOSCBridgeAddressStats>& Pair : Stats)
	{
		Sorted.Add(Pair.Value);
	}
	Sorted.Sort([](const FOSCBridgeAddressStats& A, const FOSCBridgeAddressStats& B)
	{
		return A.LastSeenSeconds > B.LastSeenSeconds;
	});

	const int32 ToShow = FMath::Min(Sorted.Num(), MaxLines);
	for (int32 i = 0; i < ToShow; ++i)
	{
		const FOSCBridgeAddressStats& S = Sorted[i];
		GEngine->AddOnScreenDebugMessage(
			BaseKey + 1 + static_cast<uint64>(i),
			0.1f, FColor::White,
			FString::Printf(TEXT("  %s  [%s]  %.1f Hz  -> %s"),
				*S.Address.ToString(), *S.ArgTypeSignature, S.HzEMA, *S.LastValueDisplay));
	}
}
