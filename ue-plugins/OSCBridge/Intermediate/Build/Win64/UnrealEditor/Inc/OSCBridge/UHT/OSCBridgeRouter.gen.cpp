// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OSCBridgeRouter.h"
#include "OSCBridgeReceiver.h"
#include "OSCMessage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOSCBridgeRouter() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialParameterCollection_NoRegister();
OSC_API UScriptStruct* Z_Construct_UScriptStruct_FOSCMessage();
OSCBRIDGE_API UClass* Z_Construct_UClass_AOSCBridgeReceiver_NoRegister();
OSCBRIDGE_API UClass* Z_Construct_UClass_AOSCBridgeRouter();
OSCBRIDGE_API UClass* Z_Construct_UClass_AOSCBridgeRouter_NoRegister();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCBangBinding();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCBoolBinding();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCFloatBinding();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCStringBinding();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCVector3Binding();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCVector4Binding();
UPackage* Z_Construct_UPackage__Script_OSCBridge();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FOSCFloatBinding **************************************************
struct Z_Construct_UScriptStruct_FOSCFloatBinding_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FOSCFloatBinding); }
	static inline consteval int16 GetStructAlignment() { return alignof(FOSCFloatBinding); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pattern_MetaData[] = {
		{ "Category", "OSC" },
		{ "Comment", "/** OSC address to match. Exact (\"/mod/intensity\") or trailing-wildcard (\"/mod/*\"). */" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
		{ "ToolTip", "OSC address to match. Exact (\"/mod/intensity\") or trailing-wildcard (\"/mod\")." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "Category", "OSC" },
		{ "Comment", "/** Label passed to the OnFloat event \xe2\x80\x94 switch on this in a Blueprint subclass. */" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
		{ "ToolTip", "Label passed to the OnFloat event \xe2\x80\x94 switch on this in a Blueprint subclass." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetMPC_MetaData[] = {
		{ "Category", "OSC|MPC Target" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParameterName_MetaData[] = {
		{ "Category", "OSC|MPC Target" },
		{ "Comment", "/** Empty or \"*\" with wildcard pattern \xe2\x86\x92 captured suffix is used as the param name. */" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
		{ "ToolTip", "Empty or \"*\" with wildcard pattern \xe2\x86\x92 captured suffix is used as the param name." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bClamp_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClampMin_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "EditCondition", "bClamp" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClampMax_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "EditCondition", "bClamp" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmoothingAlpha_MetaData[] = {
		{ "Category", "OSC|Smoothing" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** 0 = passthrough. >0 = EMA blend (higher = more reactive). 0.1 heavy, 0.5 medium, 0.9 light. */" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
		{ "ToolTip", "0 = passthrough. >0 = EMA blend (higher = more reactive). 0.1 heavy, 0.5 medium, 0.9 light." },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FOSCFloatBinding constinit property declarations ******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Pattern;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMPC;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ParameterName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Offset;
	static void NewProp_bClamp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bClamp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClampMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClampMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SmoothingAlpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FOSCFloatBinding constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOSCFloatBinding>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FOSCFloatBinding_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOSCFloatBinding;
class UScriptStruct* FOSCFloatBinding::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCFloatBinding.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOSCFloatBinding.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOSCFloatBinding, (UObject*)Z_Construct_UPackage__Script_OSCBridge(), TEXT("OSCFloatBinding"));
	}
	return Z_Registration_Info_UScriptStruct_FOSCFloatBinding.OuterSingleton;
	}

// ********** Begin ScriptStruct FOSCFloatBinding Property Definitions *****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_Pattern = { "Pattern", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, Pattern), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pattern_MetaData), NewProp_Pattern_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_TargetMPC = { "TargetMPC", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, TargetMPC), Z_Construct_UClass_UMaterialParameterCollection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetMPC_MetaData), NewProp_TargetMPC_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_ParameterName = { "ParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, ParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParameterName_MetaData), NewProp_ParameterName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, Scale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, Offset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
void Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_bClamp_SetBit(void* Obj)
{
	((FOSCFloatBinding*)Obj)->bClamp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_bClamp = { "bClamp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOSCFloatBinding), &Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_bClamp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bClamp_MetaData), NewProp_bClamp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_ClampMin = { "ClampMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, ClampMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClampMin_MetaData), NewProp_ClampMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_ClampMax = { "ClampMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, ClampMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClampMax_MetaData), NewProp_ClampMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_SmoothingAlpha = { "SmoothingAlpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCFloatBinding, SmoothingAlpha), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmoothingAlpha_MetaData), NewProp_SmoothingAlpha_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_Pattern,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_TargetMPC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_ParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_bClamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_ClampMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_ClampMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewProp_SmoothingAlpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FOSCFloatBinding Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
	nullptr,
	&NewStructOps,
	"OSCFloatBinding",
	Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::PropPointers),
	sizeof(FOSCFloatBinding),
	alignof(FOSCFloatBinding),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOSCFloatBinding()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCFloatBinding.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOSCFloatBinding.InnerSingleton, Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FOSCFloatBinding.InnerSingleton);
}
// ********** End ScriptStruct FOSCFloatBinding ****************************************************

// ********** Begin ScriptStruct FOSCVector3Binding ************************************************
struct Z_Construct_UScriptStruct_FOSCVector3Binding_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FOSCVector3Binding); }
	static inline consteval int16 GetStructAlignment() { return alignof(FOSCVector3Binding); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pattern_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetMPC_MetaData[] = {
		{ "Category", "OSC|MPC Target" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParameterName_MetaData[] = {
		{ "Category", "OSC|MPC Target" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmoothingAlpha_MetaData[] = {
		{ "Category", "OSC|Smoothing" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FOSCVector3Binding constinit property declarations ****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Pattern;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMPC;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ParameterName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Offset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SmoothingAlpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FOSCVector3Binding constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOSCVector3Binding>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FOSCVector3Binding_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOSCVector3Binding;
class UScriptStruct* FOSCVector3Binding::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCVector3Binding.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOSCVector3Binding.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOSCVector3Binding, (UObject*)Z_Construct_UPackage__Script_OSCBridge(), TEXT("OSCVector3Binding"));
	}
	return Z_Registration_Info_UScriptStruct_FOSCVector3Binding.OuterSingleton;
	}

// ********** Begin ScriptStruct FOSCVector3Binding Property Definitions ***************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_Pattern = { "Pattern", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector3Binding, Pattern), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pattern_MetaData), NewProp_Pattern_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector3Binding, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_TargetMPC = { "TargetMPC", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector3Binding, TargetMPC), Z_Construct_UClass_UMaterialParameterCollection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetMPC_MetaData), NewProp_TargetMPC_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_ParameterName = { "ParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector3Binding, ParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParameterName_MetaData), NewProp_ParameterName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector3Binding, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector3Binding, Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_SmoothingAlpha = { "SmoothingAlpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector3Binding, SmoothingAlpha), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmoothingAlpha_MetaData), NewProp_SmoothingAlpha_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_Pattern,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_TargetMPC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_ParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewProp_SmoothingAlpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FOSCVector3Binding Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
	nullptr,
	&NewStructOps,
	"OSCVector3Binding",
	Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::PropPointers),
	sizeof(FOSCVector3Binding),
	alignof(FOSCVector3Binding),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOSCVector3Binding()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCVector3Binding.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOSCVector3Binding.InnerSingleton, Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FOSCVector3Binding.InnerSingleton);
}
// ********** End ScriptStruct FOSCVector3Binding **************************************************

// ********** Begin ScriptStruct FOSCVector4Binding ************************************************
struct Z_Construct_UScriptStruct_FOSCVector4Binding_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FOSCVector4Binding); }
	static inline consteval int16 GetStructAlignment() { return alignof(FOSCVector4Binding); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pattern_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetMPC_MetaData[] = {
		{ "Category", "OSC|MPC Target" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParameterName_MetaData[] = {
		{ "Category", "OSC|MPC Target" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmoothingAlpha_MetaData[] = {
		{ "Category", "OSC|Smoothing" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAcceptOSCColor_MetaData[] = {
		{ "Category", "OSC" },
		{ "Comment", "/** If true and the message is a single OSC 'r' arg, unpack via sRGB \xe2\x86\x92 LinearColor. */" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
		{ "ToolTip", "If true and the message is a single OSC 'r' arg, unpack via sRGB \xe2\x86\x92 LinearColor." },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FOSCVector4Binding constinit property declarations ****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Pattern;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMPC;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ParameterName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Offset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SmoothingAlpha;
	static void NewProp_bAcceptOSCColor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAcceptOSCColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FOSCVector4Binding constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOSCVector4Binding>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FOSCVector4Binding_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOSCVector4Binding;
class UScriptStruct* FOSCVector4Binding::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCVector4Binding.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOSCVector4Binding.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOSCVector4Binding, (UObject*)Z_Construct_UPackage__Script_OSCBridge(), TEXT("OSCVector4Binding"));
	}
	return Z_Registration_Info_UScriptStruct_FOSCVector4Binding.OuterSingleton;
	}

// ********** Begin ScriptStruct FOSCVector4Binding Property Definitions ***************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_Pattern = { "Pattern", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector4Binding, Pattern), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pattern_MetaData), NewProp_Pattern_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector4Binding, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_TargetMPC = { "TargetMPC", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector4Binding, TargetMPC), Z_Construct_UClass_UMaterialParameterCollection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetMPC_MetaData), NewProp_TargetMPC_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_ParameterName = { "ParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector4Binding, ParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParameterName_MetaData), NewProp_ParameterName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector4Binding, Scale), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector4Binding, Offset), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_SmoothingAlpha = { "SmoothingAlpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCVector4Binding, SmoothingAlpha), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmoothingAlpha_MetaData), NewProp_SmoothingAlpha_MetaData) };
void Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_bAcceptOSCColor_SetBit(void* Obj)
{
	((FOSCVector4Binding*)Obj)->bAcceptOSCColor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_bAcceptOSCColor = { "bAcceptOSCColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOSCVector4Binding), &Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_bAcceptOSCColor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAcceptOSCColor_MetaData), NewProp_bAcceptOSCColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_Pattern,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_TargetMPC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_ParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_SmoothingAlpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewProp_bAcceptOSCColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FOSCVector4Binding Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
	nullptr,
	&NewStructOps,
	"OSCVector4Binding",
	Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::PropPointers),
	sizeof(FOSCVector4Binding),
	alignof(FOSCVector4Binding),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOSCVector4Binding()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCVector4Binding.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOSCVector4Binding.InnerSingleton, Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FOSCVector4Binding.InnerSingleton);
}
// ********** End ScriptStruct FOSCVector4Binding **************************************************

// ********** Begin ScriptStruct FOSCBoolBinding ***************************************************
struct Z_Construct_UScriptStruct_FOSCBoolBinding_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FOSCBoolBinding); }
	static inline consteval int16 GetStructAlignment() { return alignof(FOSCBoolBinding); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pattern_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetMPC_MetaData[] = {
		{ "Category", "OSC|MPC Target" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParameterName_MetaData[] = {
		{ "Category", "OSC|MPC Target" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInvert_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FalseValue_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrueValue_MetaData[] = {
		{ "Category", "OSC|Transform" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FOSCBoolBinding constinit property declarations *******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Pattern;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMPC;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ParameterName;
	static void NewProp_bInvert_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInvert;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FalseValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TrueValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FOSCBoolBinding constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOSCBoolBinding>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FOSCBoolBinding_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOSCBoolBinding;
class UScriptStruct* FOSCBoolBinding::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCBoolBinding.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOSCBoolBinding.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOSCBoolBinding, (UObject*)Z_Construct_UPackage__Script_OSCBridge(), TEXT("OSCBoolBinding"));
	}
	return Z_Registration_Info_UScriptStruct_FOSCBoolBinding.OuterSingleton;
	}

// ********** Begin ScriptStruct FOSCBoolBinding Property Definitions ******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_Pattern = { "Pattern", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBoolBinding, Pattern), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pattern_MetaData), NewProp_Pattern_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBoolBinding, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_TargetMPC = { "TargetMPC", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBoolBinding, TargetMPC), Z_Construct_UClass_UMaterialParameterCollection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetMPC_MetaData), NewProp_TargetMPC_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_ParameterName = { "ParameterName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBoolBinding, ParameterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParameterName_MetaData), NewProp_ParameterName_MetaData) };
void Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_bInvert_SetBit(void* Obj)
{
	((FOSCBoolBinding*)Obj)->bInvert = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_bInvert = { "bInvert", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOSCBoolBinding), &Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_bInvert_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInvert_MetaData), NewProp_bInvert_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_FalseValue = { "FalseValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBoolBinding, FalseValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FalseValue_MetaData), NewProp_FalseValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_TrueValue = { "TrueValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBoolBinding, TrueValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrueValue_MetaData), NewProp_TrueValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_Pattern,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_TargetMPC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_ParameterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_bInvert,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_FalseValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewProp_TrueValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FOSCBoolBinding Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
	nullptr,
	&NewStructOps,
	"OSCBoolBinding",
	Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::PropPointers),
	sizeof(FOSCBoolBinding),
	alignof(FOSCBoolBinding),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOSCBoolBinding()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCBoolBinding.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOSCBoolBinding.InnerSingleton, Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FOSCBoolBinding.InnerSingleton);
}
// ********** End ScriptStruct FOSCBoolBinding *****************************************************

// ********** Begin ScriptStruct FOSCStringBinding *************************************************
struct Z_Construct_UScriptStruct_FOSCStringBinding_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FOSCStringBinding); }
	static inline consteval int16 GetStructAlignment() { return alignof(FOSCStringBinding); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pattern_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FOSCStringBinding constinit property declarations *****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Pattern;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FOSCStringBinding constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOSCStringBinding>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FOSCStringBinding_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOSCStringBinding;
class UScriptStruct* FOSCStringBinding::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCStringBinding.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOSCStringBinding.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOSCStringBinding, (UObject*)Z_Construct_UPackage__Script_OSCBridge(), TEXT("OSCStringBinding"));
	}
	return Z_Registration_Info_UScriptStruct_FOSCStringBinding.OuterSingleton;
	}

// ********** Begin ScriptStruct FOSCStringBinding Property Definitions ****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCStringBinding_Statics::NewProp_Pattern = { "Pattern", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCStringBinding, Pattern), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pattern_MetaData), NewProp_Pattern_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCStringBinding_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCStringBinding, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOSCStringBinding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCStringBinding_Statics::NewProp_Pattern,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCStringBinding_Statics::NewProp_Tag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCStringBinding_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FOSCStringBinding Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOSCStringBinding_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
	nullptr,
	&NewStructOps,
	"OSCStringBinding",
	Z_Construct_UScriptStruct_FOSCStringBinding_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCStringBinding_Statics::PropPointers),
	sizeof(FOSCStringBinding),
	alignof(FOSCStringBinding),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCStringBinding_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOSCStringBinding_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOSCStringBinding()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCStringBinding.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOSCStringBinding.InnerSingleton, Z_Construct_UScriptStruct_FOSCStringBinding_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FOSCStringBinding.InnerSingleton);
}
// ********** End ScriptStruct FOSCStringBinding ***************************************************

// ********** Begin ScriptStruct FOSCBangBinding ***************************************************
struct Z_Construct_UScriptStruct_FOSCBangBinding_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FOSCBangBinding); }
	static inline consteval int16 GetStructAlignment() { return alignof(FOSCBangBinding); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pattern_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownSeconds_MetaData[] = {
		{ "Category", "OSC|Cooldown" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FOSCBangBinding constinit property declarations *******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Pattern;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FOSCBangBinding constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOSCBangBinding>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FOSCBangBinding_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOSCBangBinding;
class UScriptStruct* FOSCBangBinding::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCBangBinding.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOSCBangBinding.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOSCBangBinding, (UObject*)Z_Construct_UPackage__Script_OSCBridge(), TEXT("OSCBangBinding"));
	}
	return Z_Registration_Info_UScriptStruct_FOSCBangBinding.OuterSingleton;
	}

// ********** Begin ScriptStruct FOSCBangBinding Property Definitions ******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCBangBinding_Statics::NewProp_Pattern = { "Pattern", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBangBinding, Pattern), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pattern_MetaData), NewProp_Pattern_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCBangBinding_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBangBinding, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCBangBinding_Statics::NewProp_CooldownSeconds = { "CooldownSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBangBinding, CooldownSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownSeconds_MetaData), NewProp_CooldownSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOSCBangBinding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBangBinding_Statics::NewProp_Pattern,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBangBinding_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBangBinding_Statics::NewProp_CooldownSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBangBinding_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FOSCBangBinding Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOSCBangBinding_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
	nullptr,
	&NewStructOps,
	"OSCBangBinding",
	Z_Construct_UScriptStruct_FOSCBangBinding_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBangBinding_Statics::PropPointers),
	sizeof(FOSCBangBinding),
	alignof(FOSCBangBinding),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBangBinding_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOSCBangBinding_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOSCBangBinding()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCBangBinding.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOSCBangBinding.InnerSingleton, Z_Construct_UScriptStruct_FOSCBangBinding_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FOSCBangBinding.InnerSingleton);
}
// ********** End ScriptStruct FOSCBangBinding *****************************************************

// ********** Begin Class AOSCBridgeRouter Function GetBoundReceiver *******************************
struct Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics
{
	struct OSCBridgeRouter_eventGetBoundReceiver_Parms
	{
		AOSCBridgeReceiver* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetBoundReceiver constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBoundReceiver constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBoundReceiver Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventGetBoundReceiver_Parms, ReturnValue), Z_Construct_UClass_AOSCBridgeReceiver_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::PropPointers) < 2048);
// ********** End Function GetBoundReceiver Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "GetBoundReceiver", 	Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::OSCBridgeRouter_eventGetBoundReceiver_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::OSCBridgeRouter_eventGetBoundReceiver_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeRouter::execGetBoundReceiver)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AOSCBridgeReceiver**)Z_Param__Result=P_THIS->GetBoundReceiver();
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeRouter Function GetBoundReceiver *********************************

// ********** Begin Class AOSCBridgeRouter Function HandleReceiverCaptured *************************
struct Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics
{
	struct OSCBridgeRouter_eventHandleReceiverCaptured_Parms
	{
		FOSCBridgeCaptureEntry Entry;
		FOSCMessage Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Entry_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleReceiverCaptured constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Entry;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleReceiverCaptured constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleReceiverCaptured Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::NewProp_Entry = { "Entry", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventHandleReceiverCaptured_Parms, Entry), Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Entry_MetaData), NewProp_Entry_MetaData) }; // 151022394
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventHandleReceiverCaptured_Parms, Message), Z_Construct_UScriptStruct_FOSCMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) }; // 1106582076
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::NewProp_Entry,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::PropPointers) < 2048);
// ********** End Function HandleReceiverCaptured Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "HandleReceiverCaptured", 	Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::OSCBridgeRouter_eventHandleReceiverCaptured_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::OSCBridgeRouter_eventHandleReceiverCaptured_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeRouter::execHandleReceiverCaptured)
{
	P_GET_STRUCT_REF(FOSCBridgeCaptureEntry,Z_Param_Out_Entry);
	P_GET_STRUCT_REF(FOSCMessage,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleReceiverCaptured(Z_Param_Out_Entry,Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeRouter Function HandleReceiverCaptured ***************************

// ********** Begin Class AOSCBridgeRouter Function OnBang *****************************************
struct OSCBridgeRouter_eventOnBang_Parms
{
	FName Tag;
	FName Address;
};
static FName NAME_AOSCBridgeRouter_OnBang = FName(TEXT("OnBang"));
void AOSCBridgeRouter::OnBang(FName Tag, FName Address)
{
	OSCBridgeRouter_eventOnBang_Parms Parms;
	Parms.Tag=Tag;
	Parms.Address=Address;
	UFunction* Func = FindFunctionChecked(NAME_AOSCBridgeRouter_OnBang);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC|Events" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnBang constinit property declarations ********************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnBang constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnBang Property Definitions *******************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnBang_Parms, Tag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnBang_Parms, Address), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::NewProp_Address,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::PropPointers) < 2048);
// ********** End Function OnBang Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "OnBang", 	Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::PropPointers), 
sizeof(OSCBridgeRouter_eventOnBang_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(OSCBridgeRouter_eventOnBang_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_OnBang()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_OnBang_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AOSCBridgeRouter Function OnBang *******************************************

// ********** Begin Class AOSCBridgeRouter Function OnBool *****************************************
struct OSCBridgeRouter_eventOnBool_Parms
{
	FName Tag;
	FName Address;
	bool bValue;
};
static FName NAME_AOSCBridgeRouter_OnBool = FName(TEXT("OnBool"));
void AOSCBridgeRouter::OnBool(FName Tag, FName Address, bool bValue)
{
	OSCBridgeRouter_eventOnBool_Parms Parms;
	Parms.Tag=Tag;
	Parms.Address=Address;
	Parms.bValue=bValue ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AOSCBridgeRouter_OnBool);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC|Events" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnBool constinit property declarations ********************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static void NewProp_bValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnBool constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnBool Property Definitions *******************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnBool_Parms, Tag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnBool_Parms, Address), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::NewProp_bValue_SetBit(void* Obj)
{
	((OSCBridgeRouter_eventOnBool_Parms*)Obj)->bValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OSCBridgeRouter_eventOnBool_Parms), &Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::NewProp_bValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::PropPointers) < 2048);
// ********** End Function OnBool Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "OnBool", 	Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::PropPointers), 
sizeof(OSCBridgeRouter_eventOnBool_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(OSCBridgeRouter_eventOnBool_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_OnBool()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_OnBool_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AOSCBridgeRouter Function OnBool *******************************************

// ********** Begin Class AOSCBridgeRouter Function OnFloat ****************************************
struct OSCBridgeRouter_eventOnFloat_Parms
{
	FName Tag;
	FName Address;
	float Value;
};
static FName NAME_AOSCBridgeRouter_OnFloat = FName(TEXT("OnFloat"));
void AOSCBridgeRouter::OnFloat(FName Tag, FName Address, float Value)
{
	OSCBridgeRouter_eventOnFloat_Parms Parms;
	Parms.Tag=Tag;
	Parms.Address=Address;
	Parms.Value=Value;
	UFunction* Func = FindFunctionChecked(NAME_AOSCBridgeRouter_OnFloat);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC|Events" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnFloat constinit property declarations *******************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnFloat constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnFloat Property Definitions ******************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnFloat_Parms, Tag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnFloat_Parms, Address), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnFloat_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::PropPointers) < 2048);
// ********** End Function OnFloat Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "OnFloat", 	Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::PropPointers), 
sizeof(OSCBridgeRouter_eventOnFloat_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(OSCBridgeRouter_eventOnFloat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_OnFloat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_OnFloat_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AOSCBridgeRouter Function OnFloat ******************************************

// ********** Begin Class AOSCBridgeRouter Function OnString ***************************************
struct OSCBridgeRouter_eventOnString_Parms
{
	FName Tag;
	FName Address;
	FString Value;
};
static FName NAME_AOSCBridgeRouter_OnString = FName(TEXT("OnString"));
void AOSCBridgeRouter::OnString(FName Tag, FName Address, const FString& Value)
{
	OSCBridgeRouter_eventOnString_Parms Parms;
	Parms.Tag=Tag;
	Parms.Address=Address;
	Parms.Value=Value;
	UFunction* Func = FindFunctionChecked(NAME_AOSCBridgeRouter_OnString);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC|Events" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnString constinit property declarations ******************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnString constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnString Property Definitions *****************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnString_Parms, Tag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnString_Parms, Address), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnString_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::PropPointers) < 2048);
// ********** End Function OnString Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "OnString", 	Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::PropPointers), 
sizeof(OSCBridgeRouter_eventOnString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(OSCBridgeRouter_eventOnString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_OnString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_OnString_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AOSCBridgeRouter Function OnString *****************************************

// ********** Begin Class AOSCBridgeRouter Function OnUnboundMessage *******************************
struct OSCBridgeRouter_eventOnUnboundMessage_Parms
{
	FName Address;
	FOSCBridgeCaptureEntry Entry;
};
static FName NAME_AOSCBridgeRouter_OnUnboundMessage = FName(TEXT("OnUnboundMessage"));
void AOSCBridgeRouter::OnUnboundMessage(FName Address, FOSCBridgeCaptureEntry const& Entry)
{
	OSCBridgeRouter_eventOnUnboundMessage_Parms Parms;
	Parms.Address=Address;
	Parms.Entry=Entry;
	UFunction* Func = FindFunctionChecked(NAME_AOSCBridgeRouter_OnUnboundMessage);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC|Events" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Entry_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnUnboundMessage constinit property declarations **********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Entry;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnUnboundMessage constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnUnboundMessage Property Definitions *********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnUnboundMessage_Parms, Address), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::NewProp_Entry = { "Entry", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnUnboundMessage_Parms, Entry), Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Entry_MetaData), NewProp_Entry_MetaData) }; // 151022394
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::NewProp_Entry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::PropPointers) < 2048);
// ********** End Function OnUnboundMessage Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "OnUnboundMessage", 	Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::PropPointers), 
sizeof(OSCBridgeRouter_eventOnUnboundMessage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(OSCBridgeRouter_eventOnUnboundMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AOSCBridgeRouter Function OnUnboundMessage *********************************

// ********** Begin Class AOSCBridgeRouter Function OnVector3 **************************************
struct OSCBridgeRouter_eventOnVector3_Parms
{
	FName Tag;
	FName Address;
	FVector Value;
};
static FName NAME_AOSCBridgeRouter_OnVector3 = FName(TEXT("OnVector3"));
void AOSCBridgeRouter::OnVector3(FName Tag, FName Address, FVector Value)
{
	OSCBridgeRouter_eventOnVector3_Parms Parms;
	Parms.Tag=Tag;
	Parms.Address=Address;
	Parms.Value=Value;
	UFunction* Func = FindFunctionChecked(NAME_AOSCBridgeRouter_OnVector3);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC|Events" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnVector3 constinit property declarations *****************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnVector3 constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnVector3 Property Definitions ****************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnVector3_Parms, Tag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnVector3_Parms, Address), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnVector3_Parms, Value), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::PropPointers) < 2048);
// ********** End Function OnVector3 Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "OnVector3", 	Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::PropPointers), 
sizeof(OSCBridgeRouter_eventOnVector3_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(OSCBridgeRouter_eventOnVector3_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_OnVector3()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_OnVector3_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AOSCBridgeRouter Function OnVector3 ****************************************

// ********** Begin Class AOSCBridgeRouter Function OnVector4 **************************************
struct OSCBridgeRouter_eventOnVector4_Parms
{
	FName Tag;
	FName Address;
	FLinearColor Value;
};
static FName NAME_AOSCBridgeRouter_OnVector4 = FName(TEXT("OnVector4"));
void AOSCBridgeRouter::OnVector4(FName Tag, FName Address, FLinearColor Value)
{
	OSCBridgeRouter_eventOnVector4_Parms Parms;
	Parms.Tag=Tag;
	Parms.Address=Address;
	Parms.Value=Value;
	UFunction* Func = FindFunctionChecked(NAME_AOSCBridgeRouter_OnVector4);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC|Events" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnVector4 constinit property declarations *****************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnVector4 constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnVector4 Property Definitions ****************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnVector4_Parms, Tag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnVector4_Parms, Address), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeRouter_eventOnVector4_Parms, Value), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::PropPointers) < 2048);
// ********** End Function OnVector4 Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "OnVector4", 	Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::PropPointers), 
sizeof(OSCBridgeRouter_eventOnVector4_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(OSCBridgeRouter_eventOnVector4_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_OnVector4()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_OnVector4_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AOSCBridgeRouter Function OnVector4 ****************************************

// ********** Begin Class AOSCBridgeRouter Function RebindReceiver *********************************
struct Z_Construct_UFunction_AOSCBridgeRouter_RebindReceiver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RebindReceiver constinit property declarations ************************
// ********** End Function RebindReceiver constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeRouter_RebindReceiver_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeRouter, nullptr, "RebindReceiver", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeRouter_RebindReceiver_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeRouter_RebindReceiver_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AOSCBridgeRouter_RebindReceiver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeRouter_RebindReceiver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeRouter::execRebindReceiver)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RebindReceiver();
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeRouter Function RebindReceiver ***********************************

// ********** Begin Class AOSCBridgeRouter *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AOSCBridgeRouter;
UClass* AOSCBridgeRouter::GetPrivateStaticClass()
{
	using TClass = AOSCBridgeRouter;
	if (!Z_Registration_Info_UClass_AOSCBridgeRouter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("OSCBridgeRouter"),
			Z_Registration_Info_UClass_AOSCBridgeRouter.InnerSingleton,
			StaticRegisterNativesAOSCBridgeRouter,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AOSCBridgeRouter.InnerSingleton;
}
UClass* Z_Construct_UClass_AOSCBridgeRouter_NoRegister()
{
	return AOSCBridgeRouter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AOSCBridgeRouter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "OSC Bridge Router" },
		{ "IncludePath", "OSCBridgeRouter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Receiver_MetaData[] = {
		{ "Category", "OSC" },
		{ "Comment", "/** Explicit Receiver reference. Leave empty + bAutoFindActiveReceiver=true to attach to whichever is currently Active. */" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
		{ "ToolTip", "Explicit Receiver reference. Leave empty + bAutoFindActiveReceiver=true to attach to whichever is currently Active." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoFindActiveReceiver_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRouteInEditor_MetaData[] = {
		{ "Category", "OSC" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloatBindings_MetaData[] = {
		{ "Category", "OSC|Bindings" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vector3Bindings_MetaData[] = {
		{ "Category", "OSC|Bindings" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vector4Bindings_MetaData[] = {
		{ "Category", "OSC|Bindings" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoolBindings_MetaData[] = {
		{ "Category", "OSC|Bindings" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StringBindings_MetaData[] = {
		{ "Category", "OSC|Bindings" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BangBindings_MetaData[] = {
		{ "Category", "OSC|Bindings" },
		{ "ModuleRelativePath", "Public/OSCBridgeRouter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AOSCBridgeRouter constinit property declarations *************************
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Receiver;
	static void NewProp_bAutoFindActiveReceiver_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoFindActiveReceiver;
	static void NewProp_bRouteInEditor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRouteInEditor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FloatBindings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FloatBindings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Vector3Bindings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Vector3Bindings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Vector4Bindings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Vector4Bindings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BoolBindings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_BoolBindings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StringBindings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StringBindings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BangBindings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_BangBindings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AOSCBridgeRouter constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetBoundReceiver"), .Pointer = &AOSCBridgeRouter::execGetBoundReceiver },
		{ .NameUTF8 = UTF8TEXT("HandleReceiverCaptured"), .Pointer = &AOSCBridgeRouter::execHandleReceiverCaptured },
		{ .NameUTF8 = UTF8TEXT("RebindReceiver"), .Pointer = &AOSCBridgeRouter::execRebindReceiver },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AOSCBridgeRouter_GetBoundReceiver, "GetBoundReceiver" }, // 974423134
		{ &Z_Construct_UFunction_AOSCBridgeRouter_HandleReceiverCaptured, "HandleReceiverCaptured" }, // 3571775261
		{ &Z_Construct_UFunction_AOSCBridgeRouter_OnBang, "OnBang" }, // 964312013
		{ &Z_Construct_UFunction_AOSCBridgeRouter_OnBool, "OnBool" }, // 1266036161
		{ &Z_Construct_UFunction_AOSCBridgeRouter_OnFloat, "OnFloat" }, // 3304395006
		{ &Z_Construct_UFunction_AOSCBridgeRouter_OnString, "OnString" }, // 3219246313
		{ &Z_Construct_UFunction_AOSCBridgeRouter_OnUnboundMessage, "OnUnboundMessage" }, // 2156656710
		{ &Z_Construct_UFunction_AOSCBridgeRouter_OnVector3, "OnVector3" }, // 1057754177
		{ &Z_Construct_UFunction_AOSCBridgeRouter_OnVector4, "OnVector4" }, // 992593821
		{ &Z_Construct_UFunction_AOSCBridgeRouter_RebindReceiver, "RebindReceiver" }, // 3040133983
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOSCBridgeRouter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AOSCBridgeRouter_Statics

// ********** Begin Class AOSCBridgeRouter Property Definitions ************************************
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Receiver = { "Receiver", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeRouter, Receiver), Z_Construct_UClass_AOSCBridgeReceiver_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Receiver_MetaData), NewProp_Receiver_MetaData) };
void Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_bAutoFindActiveReceiver_SetBit(void* Obj)
{
	((AOSCBridgeRouter*)Obj)->bAutoFindActiveReceiver = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_bAutoFindActiveReceiver = { "bAutoFindActiveReceiver", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOSCBridgeRouter), &Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_bAutoFindActiveReceiver_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoFindActiveReceiver_MetaData), NewProp_bAutoFindActiveReceiver_MetaData) };
void Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_bRouteInEditor_SetBit(void* Obj)
{
	((AOSCBridgeRouter*)Obj)->bRouteInEditor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_bRouteInEditor = { "bRouteInEditor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOSCBridgeRouter), &Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_bRouteInEditor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRouteInEditor_MetaData), NewProp_bRouteInEditor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_FloatBindings_Inner = { "FloatBindings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOSCFloatBinding, METADATA_PARAMS(0, nullptr) }; // 3133542768
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_FloatBindings = { "FloatBindings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeRouter, FloatBindings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloatBindings_MetaData), NewProp_FloatBindings_MetaData) }; // 3133542768
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Vector3Bindings_Inner = { "Vector3Bindings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOSCVector3Binding, METADATA_PARAMS(0, nullptr) }; // 2014039653
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Vector3Bindings = { "Vector3Bindings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeRouter, Vector3Bindings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vector3Bindings_MetaData), NewProp_Vector3Bindings_MetaData) }; // 2014039653
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Vector4Bindings_Inner = { "Vector4Bindings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOSCVector4Binding, METADATA_PARAMS(0, nullptr) }; // 3899335690
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Vector4Bindings = { "Vector4Bindings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeRouter, Vector4Bindings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vector4Bindings_MetaData), NewProp_Vector4Bindings_MetaData) }; // 3899335690
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_BoolBindings_Inner = { "BoolBindings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOSCBoolBinding, METADATA_PARAMS(0, nullptr) }; // 354754433
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_BoolBindings = { "BoolBindings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeRouter, BoolBindings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoolBindings_MetaData), NewProp_BoolBindings_MetaData) }; // 354754433
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_StringBindings_Inner = { "StringBindings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOSCStringBinding, METADATA_PARAMS(0, nullptr) }; // 150166160
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_StringBindings = { "StringBindings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeRouter, StringBindings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StringBindings_MetaData), NewProp_StringBindings_MetaData) }; // 150166160
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_BangBindings_Inner = { "BangBindings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOSCBangBinding, METADATA_PARAMS(0, nullptr) }; // 1036197313
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_BangBindings = { "BangBindings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeRouter, BangBindings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BangBindings_MetaData), NewProp_BangBindings_MetaData) }; // 1036197313
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOSCBridgeRouter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Receiver,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_bAutoFindActiveReceiver,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_bRouteInEditor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_FloatBindings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_FloatBindings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Vector3Bindings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Vector3Bindings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Vector4Bindings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_Vector4Bindings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_BoolBindings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_BoolBindings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_StringBindings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_StringBindings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_BangBindings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeRouter_Statics::NewProp_BangBindings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOSCBridgeRouter_Statics::PropPointers) < 2048);
// ********** End Class AOSCBridgeRouter Property Definitions **************************************
UObject* (*const Z_Construct_UClass_AOSCBridgeRouter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOSCBridgeRouter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOSCBridgeRouter_Statics::ClassParams = {
	&AOSCBridgeRouter::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AOSCBridgeRouter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AOSCBridgeRouter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOSCBridgeRouter_Statics::Class_MetaDataParams), Z_Construct_UClass_AOSCBridgeRouter_Statics::Class_MetaDataParams)
};
void AOSCBridgeRouter::StaticRegisterNativesAOSCBridgeRouter()
{
	UClass* Class = AOSCBridgeRouter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AOSCBridgeRouter_Statics::Funcs));
}
UClass* Z_Construct_UClass_AOSCBridgeRouter()
{
	if (!Z_Registration_Info_UClass_AOSCBridgeRouter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOSCBridgeRouter.OuterSingleton, Z_Construct_UClass_AOSCBridgeRouter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOSCBridgeRouter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AOSCBridgeRouter);
AOSCBridgeRouter::~AOSCBridgeRouter() {}
// ********** End Class AOSCBridgeRouter ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h__Script_OSCBridge_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOSCFloatBinding::StaticStruct, Z_Construct_UScriptStruct_FOSCFloatBinding_Statics::NewStructOps, TEXT("OSCFloatBinding"),&Z_Registration_Info_UScriptStruct_FOSCFloatBinding, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOSCFloatBinding), 3133542768U) },
		{ FOSCVector3Binding::StaticStruct, Z_Construct_UScriptStruct_FOSCVector3Binding_Statics::NewStructOps, TEXT("OSCVector3Binding"),&Z_Registration_Info_UScriptStruct_FOSCVector3Binding, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOSCVector3Binding), 2014039653U) },
		{ FOSCVector4Binding::StaticStruct, Z_Construct_UScriptStruct_FOSCVector4Binding_Statics::NewStructOps, TEXT("OSCVector4Binding"),&Z_Registration_Info_UScriptStruct_FOSCVector4Binding, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOSCVector4Binding), 3899335690U) },
		{ FOSCBoolBinding::StaticStruct, Z_Construct_UScriptStruct_FOSCBoolBinding_Statics::NewStructOps, TEXT("OSCBoolBinding"),&Z_Registration_Info_UScriptStruct_FOSCBoolBinding, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOSCBoolBinding), 354754433U) },
		{ FOSCStringBinding::StaticStruct, Z_Construct_UScriptStruct_FOSCStringBinding_Statics::NewStructOps, TEXT("OSCStringBinding"),&Z_Registration_Info_UScriptStruct_FOSCStringBinding, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOSCStringBinding), 150166160U) },
		{ FOSCBangBinding::StaticStruct, Z_Construct_UScriptStruct_FOSCBangBinding_Statics::NewStructOps, TEXT("OSCBangBinding"),&Z_Registration_Info_UScriptStruct_FOSCBangBinding, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOSCBangBinding), 1036197313U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOSCBridgeRouter, AOSCBridgeRouter::StaticClass, TEXT("AOSCBridgeRouter"), &Z_Registration_Info_UClass_AOSCBridgeRouter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOSCBridgeRouter), 2939530098U) },
	};
}; // Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h__Script_OSCBridge_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h__Script_OSCBridge_3246397247{
	TEXT("/Script/OSCBridge"),
	Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h__Script_OSCBridge_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h__Script_OSCBridge_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h__Script_OSCBridge_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h__Script_OSCBridge_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
