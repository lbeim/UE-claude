// Copyright NM 2026
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSCBridgeReceiver.h"
#include "OSCBridgeRouter.generated.h"

class UMaterialParameterCollection;
class UMaterialParameterCollectionInstance;

/** Address pattern matching — exact ("/mod/intensity") or trailing-wildcard ("/mod/*"). */
namespace OSCBridgePattern
{
	OSCBRIDGE_API bool Matches(FName Pattern, FName Address);
	OSCBRIDGE_API FString CapturedSuffix(FName Pattern, FName Address);
	OSCBRIDGE_API bool HasWildcard(FName Pattern);
}

USTRUCT(BlueprintType)
struct OSCBRIDGE_API FOSCFloatBinding
{
	GENERATED_BODY()

	/** OSC address to match. Exact ("/mod/intensity") or trailing-wildcard ("/mod/*"). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Pattern;

	/** Label passed to the OnFloat event — switch on this in a Blueprint subclass. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|MPC Target")
	TObjectPtr<UMaterialParameterCollection> TargetMPC;

	/** Empty or "*" with wildcard pattern → captured suffix is used as the param name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|MPC Target")
	FName ParameterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	float Scale = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	float Offset = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	bool bClamp = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform", meta = (EditCondition = "bClamp"))
	float ClampMin = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform", meta = (EditCondition = "bClamp"))
	float ClampMax = 1.f;

	/** 0 = passthrough. >0 = EMA blend (higher = more reactive). 0.1 heavy, 0.5 medium, 0.9 light. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Smoothing", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float SmoothingAlpha = 0.f;
};

USTRUCT(BlueprintType)
struct OSCBRIDGE_API FOSCVector3Binding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Pattern;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|MPC Target")
	TObjectPtr<UMaterialParameterCollection> TargetMPC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|MPC Target")
	FName ParameterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	FVector Scale = FVector::OneVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	FVector Offset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Smoothing", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float SmoothingAlpha = 0.f;
};

USTRUCT(BlueprintType)
struct OSCBRIDGE_API FOSCVector4Binding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Pattern;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|MPC Target")
	TObjectPtr<UMaterialParameterCollection> TargetMPC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|MPC Target")
	FName ParameterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	FLinearColor Scale = FLinearColor(1.f, 1.f, 1.f, 1.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	FLinearColor Offset = FLinearColor(0.f, 0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Smoothing", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float SmoothingAlpha = 0.f;

	/** If true and the message is a single OSC 'r' arg, unpack via sRGB → LinearColor. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	bool bAcceptOSCColor = true;
};

USTRUCT(BlueprintType)
struct OSCBRIDGE_API FOSCBoolBinding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Pattern;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|MPC Target")
	TObjectPtr<UMaterialParameterCollection> TargetMPC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|MPC Target")
	FName ParameterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	bool bInvert = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	float FalseValue = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Transform")
	float TrueValue = 1.f;
};

USTRUCT(BlueprintType)
struct OSCBRIDGE_API FOSCStringBinding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Pattern;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Tag;
};

USTRUCT(BlueprintType)
struct OSCBRIDGE_API FOSCBangBinding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Pattern;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	FName Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Cooldown", meta = (ClampMin = "0.0"))
	float CooldownSeconds = 0.f;
};

UCLASS(BlueprintType, Blueprintable, DisplayName = "OSC Bridge Router")
class OSCBRIDGE_API AOSCBridgeRouter : public AActor
{
	GENERATED_BODY()

public:
	AOSCBridgeRouter();

	/** Explicit Receiver reference. Leave empty + bAutoFindActiveReceiver=true to attach to whichever is currently Active. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	TWeakObjectPtr<AOSCBridgeReceiver> Receiver;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	bool bAutoFindActiveReceiver = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC")
	bool bRouteInEditor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Bindings")
	TArray<FOSCFloatBinding> FloatBindings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Bindings")
	TArray<FOSCVector3Binding> Vector3Bindings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Bindings")
	TArray<FOSCVector4Binding> Vector4Bindings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Bindings")
	TArray<FOSCBoolBinding> BoolBindings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Bindings")
	TArray<FOSCStringBinding> StringBindings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSC|Bindings")
	TArray<FOSCBangBinding> BangBindings;

	UFUNCTION(BlueprintImplementableEvent, Category = "OSC|Events")
	void OnFloat(FName Tag, FName Address, float Value);

	UFUNCTION(BlueprintImplementableEvent, Category = "OSC|Events")
	void OnVector3(FName Tag, FName Address, FVector Value);

	UFUNCTION(BlueprintImplementableEvent, Category = "OSC|Events")
	void OnVector4(FName Tag, FName Address, FLinearColor Value);

	UFUNCTION(BlueprintImplementableEvent, Category = "OSC|Events")
	void OnBool(FName Tag, FName Address, bool bValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "OSC|Events")
	void OnString(FName Tag, FName Address, const FString& Value);

	UFUNCTION(BlueprintImplementableEvent, Category = "OSC|Events")
	void OnBang(FName Tag, FName Address);

	UFUNCTION(BlueprintImplementableEvent, Category = "OSC|Events")
	void OnUnboundMessage(FName Address, const FOSCBridgeCaptureEntry& Entry);

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "OSC")
	void RebindReceiver();

	UFUNCTION(BlueprintCallable, Category = "OSC")
	AOSCBridgeReceiver* GetBoundReceiver() const;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Destroyed() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	UFUNCTION()
	void HandleReceiverCaptured(const FOSCBridgeCaptureEntry& Entry, const FOSCMessage& Message);

	void SubscribeToReceiver(AOSCBridgeReceiver* InReceiver);
	void UnsubscribeFromCurrentReceiver();
	AOSCBridgeReceiver* ResolveDesiredReceiver() const;
	bool IsEditorWorld() const;

	void ApplyFloatBinding(const FOSCFloatBinding& Binding, int32 Index, FName Address, const FOSCBridgeCaptureEntry& Entry);
	void ApplyVector3Binding(const FOSCVector3Binding& Binding, int32 Index, FName Address, const FOSCBridgeCaptureEntry& Entry);
	void ApplyVector4Binding(const FOSCVector4Binding& Binding, int32 Index, FName Address, const FOSCBridgeCaptureEntry& Entry);
	void ApplyBoolBinding(const FOSCBoolBinding& Binding, FName Address, const FOSCBridgeCaptureEntry& Entry);
	void ApplyStringBinding(const FOSCStringBinding& Binding, FName Address, const FOSCBridgeCaptureEntry& Entry);
	void ApplyBangBinding(const FOSCBangBinding& Binding, int32 Index, FName Address);

	FName ResolveParamName(FName Pattern, FName ConfiguredName, FName Address) const;
	UMaterialParameterCollectionInstance* GetMPCInstance(UMaterialParameterCollection* Collection) const;

	TWeakObjectPtr<AOSCBridgeReceiver> SubscribedReceiver;

	TMap<int32, TMap<FName, float>> FloatSmoothing;
	TMap<int32, TMap<FName, FVector>> Vector3Smoothing;
	TMap<int32, TMap<FName, FLinearColor>> Vector4Smoothing;

	TMap<int32, TMap<FName, double>> BangCooldownExpiry;

	FTimerHandle RetryRebindHandle;
};
