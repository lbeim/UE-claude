// Copyright NM 2026
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSCMessage.h"
#include "OSCBridgeReceiver.generated.h"

class UOSCServer;

USTRUCT(BlueprintType)
struct OSCBRIDGE_API FOSCBridgeAddressStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	FName Address;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	int64 Count = 0;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	double FirstSeenSeconds = 0.0;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	double LastSeenSeconds = 0.0;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	float HzEMA = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	FString ArgTypeSignature;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	int32 ArgCount = 0;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	float LastValueFloat = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	FString LastValueDisplay;
};

USTRUCT(BlueprintType)
struct OSCBRIDGE_API FOSCBridgeCaptureEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	FName Address;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	double TimestampSeconds = 0.0;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	FString ArgTypeSignature;

	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	FString DisplayValue;

	// Per-arg float-coerced view (float / int32 / int64 / double / bool → 0/1). Non-numeric types get 0.f as placeholder.
	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	TArray<float> FloatArgs;

	// First arg of OSC string type, empty otherwise
	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	FString FirstStringArg;

	// First arg of OSC bool type, false otherwise (T → true, F → false)
	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	bool FirstBoolArg = false;

	// Composed FLinearColor — from OSC 'r' type, or first 3-4 floats (alpha defaults 1.0 for 3-float), or default Black
	UPROPERTY(BlueprintReadOnly, Category = "OSC Bridge")
	FLinearColor LinearColorArg = FLinearColor::Black;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOSCBridgeCapturedSignature, const FOSCBridgeCaptureEntry&, Entry, const FOSCMessage&, Message);

UCLASS(BlueprintType, Blueprintable, DisplayName = "OSC Bridge Receiver")
class OSCBRIDGE_API AOSCBridgeReceiver : public AActor
{
	GENERATED_BODY()

public:
	AOSCBridgeReceiver();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC Bridge")
	FString ReceiveIPAddress = TEXT("0.0.0.0");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC Bridge")
	int32 Port = 8000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC Bridge")
	bool bMulticastLoopback = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC Bridge")
	bool bAutoStartInGame = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC Bridge|Editor")
	bool bListenInEditor = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC Bridge", meta = (ClampMin = "16", ClampMax = "65536"))
	int32 RingBufferSize = 1024;

	UPROPERTY(BlueprintAssignable, Category = "OSC Bridge")
	FOSCBridgeCapturedSignature OnCaptured;

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "OSC Bridge")
	void StartListening();

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "OSC Bridge")
	void StopListening();

	UFUNCTION(BlueprintCallable, Category = "OSC Bridge")
	bool IsListening() const;

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "OSC Bridge")
	void ClearStats();

	UFUNCTION(BlueprintCallable, Category = "OSC Bridge")
	TArray<FName> GetKnownAddresses() const;

	UFUNCTION(BlueprintCallable, Category = "OSC Bridge")
	TArray<FOSCBridgeAddressStats> GetAllAddressStats() const;

	UFUNCTION(BlueprintCallable, Category = "OSC Bridge")
	bool GetAddressStats(FName Address, FOSCBridgeAddressStats& OutStats) const;

	UFUNCTION(BlueprintCallable, Category = "OSC Bridge")
	TArray<FOSCBridgeCaptureEntry> GetRecentMessages(int32 MaxCount = 64) const;

	UFUNCTION(BlueprintCallable, Category = "OSC Bridge")
	float GetLatestFloat(FName Address, bool& bFound) const;

	UFUNCTION(BlueprintCallable, Category = "OSC Bridge")
	FString GetLatestDisplay(FName Address, bool& bFound) const;

	static AOSCBridgeReceiver* GetActiveReceiver();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void Destroyed() override;
	virtual void OnConstruction(const FTransform& Transform) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	void HandleOscMessageReceived(const FOSCMessage& Message, const FString& IPAddress, uint16 InPort);

	void RecordMessage(const FOSCMessage& Message);
	void DrawDebugOverlay();
	bool IsEditorWorld() const;
	void ReconfigureForEditorFlag();

	UPROPERTY()
	TObjectPtr<UOSCServer> Server;

	TMap<FName, FOSCBridgeAddressStats> Stats;
	TArray<FOSCBridgeCaptureEntry> RingBuffer;
	int32 RingWriteIndex = 0;

	static TWeakObjectPtr<AOSCBridgeReceiver> ActiveReceiver;
};
