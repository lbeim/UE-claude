// Copyright NM 2026
#include "OSCBridgeRouter.h"

#include "OSCBridgeLog.h"

#include "Engine/World.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"
#include "TimerManager.h"

// ---------- OSCBridgePattern ----------

namespace OSCBridgePattern
{
	bool Matches(FName Pattern, FName Address)
	{
		if (Pattern.IsNone())
		{
			return false;
		}
		const FString PStr = Pattern.ToString();
		if (PStr.EndsWith(TEXT("/*")))
		{
			const FString Prefix = PStr.LeftChop(1);
			return Address.ToString().StartsWith(Prefix);
		}
		return Address == Pattern;
	}

	FString CapturedSuffix(FName Pattern, FName Address)
	{
		const FString PStr = Pattern.ToString();
		if (PStr.EndsWith(TEXT("/*")))
		{
			const FString Prefix = PStr.LeftChop(1);
			const FString AStr = Address.ToString();
			if (AStr.StartsWith(Prefix))
			{
				return AStr.Mid(Prefix.Len());
			}
		}
		return FString();
	}

	bool HasWildcard(FName Pattern)
	{
		return Pattern.ToString().EndsWith(TEXT("/*"));
	}
}

// ---------- AOSCBridgeRouter ----------

AOSCBridgeRouter::AOSCBridgeRouter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AOSCBridgeRouter::BeginPlay()
{
	Super::BeginPlay();
	RebindReceiver();

	if (!SubscribedReceiver.IsValid() && bAutoFindActiveReceiver)
	{
		if (UWorld* World = GetWorld())
		{
			World->GetTimerManager().SetTimer(RetryRebindHandle, this, &AOSCBridgeRouter::RebindReceiver, 0.5f, false);
		}
	}
}

void AOSCBridgeRouter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(RetryRebindHandle);
	}
	UnsubscribeFromCurrentReceiver();
	Super::EndPlay(EndPlayReason);
}

void AOSCBridgeRouter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (IsEditorWorld() && bRouteInEditor)
	{
		RebindReceiver();
	}
}

void AOSCBridgeRouter::Destroyed()
{
	UnsubscribeFromCurrentReceiver();
	Super::Destroyed();
}

#if WITH_EDITOR
void AOSCBridgeRouter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (IsEditorWorld())
	{
		RebindReceiver();
	}
}
#endif

void AOSCBridgeRouter::RebindReceiver()
{
	AOSCBridgeReceiver* Desired = ResolveDesiredReceiver();
	if (SubscribedReceiver.Get() == Desired)
	{
		return;
	}
	UnsubscribeFromCurrentReceiver();
	if (Desired)
	{
		SubscribeToReceiver(Desired);
	}
	else
	{
		UE_LOG(LogOSCBridge, Warning,
			TEXT("OSCBridgeRouter '%s': no Receiver bound — set the Receiver field or place an AOSCBridgeReceiver in the level and hit 'Rebind Receiver'."),
			*GetName());
	}
}

AOSCBridgeReceiver* AOSCBridgeRouter::GetBoundReceiver() const
{
	return SubscribedReceiver.Get();
}

AOSCBridgeReceiver* AOSCBridgeRouter::ResolveDesiredReceiver() const
{
	if (AOSCBridgeReceiver* Explicit = Receiver.Get())
	{
		return Explicit;
	}
	if (bAutoFindActiveReceiver)
	{
		return AOSCBridgeReceiver::GetActiveReceiver();
	}
	return nullptr;
}

void AOSCBridgeRouter::SubscribeToReceiver(AOSCBridgeReceiver* InReceiver)
{
	if (!InReceiver)
	{
		return;
	}
	// PIE-duplication carries over BlueprintAssignable delegate invocation-list entries
	// from the editor world. RemoveDynamic-then-AddDynamic avoids the duplicate-add ensure.
	InReceiver->OnCaptured.RemoveDynamic(this, &AOSCBridgeRouter::HandleReceiverCaptured);
	InReceiver->OnCaptured.AddDynamic(this, &AOSCBridgeRouter::HandleReceiverCaptured);
	SubscribedReceiver = InReceiver;
	UE_LOG(LogOSCBridge, Display, TEXT("OSCBridgeRouter: subscribed to %s"), *InReceiver->GetName());
}

void AOSCBridgeRouter::UnsubscribeFromCurrentReceiver()
{
	if (AOSCBridgeReceiver* R = SubscribedReceiver.Get())
	{
		R->OnCaptured.RemoveDynamic(this, &AOSCBridgeRouter::HandleReceiverCaptured);
	}
	SubscribedReceiver = nullptr;
}

bool AOSCBridgeRouter::IsEditorWorld() const
{
	const UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}
	return World->WorldType == EWorldType::Editor || World->WorldType == EWorldType::EditorPreview;
}

FName AOSCBridgeRouter::ResolveParamName(FName Pattern, FName ConfiguredName, FName Address) const
{
	if (!ConfiguredName.IsNone() && ConfiguredName != FName(TEXT("*")))
	{
		return ConfiguredName;
	}
	const FString Suffix = OSCBridgePattern::CapturedSuffix(Pattern, Address);
	return Suffix.IsEmpty() ? NAME_None : FName(*Suffix);
}

UMaterialParameterCollectionInstance* AOSCBridgeRouter::GetMPCInstance(UMaterialParameterCollection* Collection) const
{
	if (!Collection)
	{
		return nullptr;
	}
	UWorld* World = GetWorld();
	if (!World)
	{
		return nullptr;
	}
	return World->GetParameterCollectionInstance(Collection);
}

void AOSCBridgeRouter::HandleReceiverCaptured(const FOSCBridgeCaptureEntry& Entry, const FOSCMessage& Message)
{
	const FName Address = Entry.Address;
	bool bMatched = false;

	for (int32 i = 0; i < FloatBindings.Num(); ++i)
	{
		if (OSCBridgePattern::Matches(FloatBindings[i].Pattern, Address))
		{
			ApplyFloatBinding(FloatBindings[i], i, Address, Entry);
			bMatched = true;
		}
	}
	for (int32 i = 0; i < Vector3Bindings.Num(); ++i)
	{
		if (OSCBridgePattern::Matches(Vector3Bindings[i].Pattern, Address))
		{
			ApplyVector3Binding(Vector3Bindings[i], i, Address, Entry);
			bMatched = true;
		}
	}
	for (int32 i = 0; i < Vector4Bindings.Num(); ++i)
	{
		if (OSCBridgePattern::Matches(Vector4Bindings[i].Pattern, Address))
		{
			ApplyVector4Binding(Vector4Bindings[i], i, Address, Entry);
			bMatched = true;
		}
	}
	for (const FOSCBoolBinding& B : BoolBindings)
	{
		if (OSCBridgePattern::Matches(B.Pattern, Address))
		{
			ApplyBoolBinding(B, Address, Entry);
			bMatched = true;
		}
	}
	for (const FOSCStringBinding& B : StringBindings)
	{
		if (OSCBridgePattern::Matches(B.Pattern, Address))
		{
			ApplyStringBinding(B, Address, Entry);
			bMatched = true;
		}
	}
	for (int32 i = 0; i < BangBindings.Num(); ++i)
	{
		if (OSCBridgePattern::Matches(BangBindings[i].Pattern, Address))
		{
			ApplyBangBinding(BangBindings[i], i, Address);
			bMatched = true;
		}
	}

	if (!bMatched)
	{
		OnUnboundMessage(Address, Entry);
	}
}

void AOSCBridgeRouter::ApplyFloatBinding(const FOSCFloatBinding& Binding, int32 Index, FName Address, const FOSCBridgeCaptureEntry& Entry)
{
	if (Entry.FloatArgs.Num() == 0)
	{
		return;
	}

	float Value = Entry.FloatArgs[0] * Binding.Scale + Binding.Offset;
	if (Binding.bClamp)
	{
		Value = FMath::Clamp(Value, Binding.ClampMin, Binding.ClampMax);
	}

	if (Binding.SmoothingAlpha > 0.f)
	{
		TMap<FName, float>& AddrMap = FloatSmoothing.FindOrAdd(Index);
		if (float* Existing = AddrMap.Find(Address))
		{
			*Existing = FMath::Lerp(*Existing, Value, Binding.SmoothingAlpha);
			Value = *Existing;
		}
		else
		{
			AddrMap.Add(Address, Value);
		}
	}

	if (Binding.TargetMPC)
	{
		const FName ParamName = ResolveParamName(Binding.Pattern, Binding.ParameterName, Address);
		if (!ParamName.IsNone())
		{
			if (UMaterialParameterCollectionInstance* MPCI = GetMPCInstance(Binding.TargetMPC))
			{
				MPCI->SetScalarParameterValue(ParamName, Value);
			}
		}
	}

	OnFloat(Binding.Tag, Address, Value);
}

void AOSCBridgeRouter::ApplyVector3Binding(const FOSCVector3Binding& Binding, int32 Index, FName Address, const FOSCBridgeCaptureEntry& Entry)
{
	if (Entry.FloatArgs.Num() < 3)
	{
		return;
	}

	FVector Value(
		Entry.FloatArgs[0] * Binding.Scale.X + Binding.Offset.X,
		Entry.FloatArgs[1] * Binding.Scale.Y + Binding.Offset.Y,
		Entry.FloatArgs[2] * Binding.Scale.Z + Binding.Offset.Z);

	if (Binding.SmoothingAlpha > 0.f)
	{
		TMap<FName, FVector>& AddrMap = Vector3Smoothing.FindOrAdd(Index);
		if (FVector* Existing = AddrMap.Find(Address))
		{
			*Existing = FMath::Lerp(*Existing, Value, Binding.SmoothingAlpha);
			Value = *Existing;
		}
		else
		{
			AddrMap.Add(Address, Value);
		}
	}

	if (Binding.TargetMPC)
	{
		const FName ParamName = ResolveParamName(Binding.Pattern, Binding.ParameterName, Address);
		if (!ParamName.IsNone())
		{
			if (UMaterialParameterCollectionInstance* MPCI = GetMPCInstance(Binding.TargetMPC))
			{
				MPCI->SetVectorParameterValue(ParamName, FLinearColor(Value.X, Value.Y, Value.Z, 0.f));
			}
		}
	}

	OnVector3(Binding.Tag, Address, Value);
}

void AOSCBridgeRouter::ApplyVector4Binding(const FOSCVector4Binding& Binding, int32 Index, FName Address, const FOSCBridgeCaptureEntry& Entry)
{
	FLinearColor Value;
	bool bSourced = false;

	if (Binding.bAcceptOSCColor && Entry.ArgTypeSignature == TEXT("r"))
	{
		Value = Entry.LinearColorArg;
		bSourced = true;
	}
	else if (Entry.FloatArgs.Num() >= 4)
	{
		Value = FLinearColor(Entry.FloatArgs[0], Entry.FloatArgs[1], Entry.FloatArgs[2], Entry.FloatArgs[3]);
		bSourced = true;
	}
	else if (Entry.FloatArgs.Num() == 3)
	{
		Value = FLinearColor(Entry.FloatArgs[0], Entry.FloatArgs[1], Entry.FloatArgs[2], 1.f);
		bSourced = true;
	}

	if (!bSourced)
	{
		return;
	}

	Value.R = Value.R * Binding.Scale.R + Binding.Offset.R;
	Value.G = Value.G * Binding.Scale.G + Binding.Offset.G;
	Value.B = Value.B * Binding.Scale.B + Binding.Offset.B;
	Value.A = Value.A * Binding.Scale.A + Binding.Offset.A;

	if (Binding.SmoothingAlpha > 0.f)
	{
		TMap<FName, FLinearColor>& AddrMap = Vector4Smoothing.FindOrAdd(Index);
		if (FLinearColor* Existing = AddrMap.Find(Address))
		{
			*Existing = FMath::Lerp(*Existing, Value, Binding.SmoothingAlpha);
			Value = *Existing;
		}
		else
		{
			AddrMap.Add(Address, Value);
		}
	}

	if (Binding.TargetMPC)
	{
		const FName ParamName = ResolveParamName(Binding.Pattern, Binding.ParameterName, Address);
		if (!ParamName.IsNone())
		{
			if (UMaterialParameterCollectionInstance* MPCI = GetMPCInstance(Binding.TargetMPC))
			{
				MPCI->SetVectorParameterValue(ParamName, Value);
			}
		}
	}

	OnVector4(Binding.Tag, Address, Value);
}

void AOSCBridgeRouter::ApplyBoolBinding(const FOSCBoolBinding& Binding, FName Address, const FOSCBridgeCaptureEntry& Entry)
{
	bool bRaw = Entry.FirstBoolArg;

	const bool bHasNativeBool = Entry.ArgTypeSignature.Contains(TEXT("T")) || Entry.ArgTypeSignature.Contains(TEXT("F"));
	if (!bHasNativeBool && Entry.FloatArgs.Num() > 0)
	{
		bRaw = Entry.FloatArgs[0] != 0.f;
	}

	if (Binding.bInvert)
	{
		bRaw = !bRaw;
	}

	const float Value = bRaw ? Binding.TrueValue : Binding.FalseValue;

	if (Binding.TargetMPC)
	{
		const FName ParamName = ResolveParamName(Binding.Pattern, Binding.ParameterName, Address);
		if (!ParamName.IsNone())
		{
			if (UMaterialParameterCollectionInstance* MPCI = GetMPCInstance(Binding.TargetMPC))
			{
				MPCI->SetScalarParameterValue(ParamName, Value);
			}
		}
	}

	OnBool(Binding.Tag, Address, bRaw);
}

void AOSCBridgeRouter::ApplyStringBinding(const FOSCStringBinding& Binding, FName Address, const FOSCBridgeCaptureEntry& Entry)
{
	OnString(Binding.Tag, Address, Entry.FirstStringArg);
}

void AOSCBridgeRouter::ApplyBangBinding(const FOSCBangBinding& Binding, int32 Index, FName Address)
{
	if (Binding.CooldownSeconds > 0.f)
	{
		TMap<FName, double>& Expiry = BangCooldownExpiry.FindOrAdd(Index);
		const double Now = FPlatformTime::Seconds();
		const double NextAllowed = Expiry.FindRef(Address);
		if (Now < NextAllowed)
		{
			return;
		}
		Expiry.Add(Address, Now + Binding.CooldownSeconds);
	}

	OnBang(Binding.Tag, Address);
}
