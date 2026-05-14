// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OSCBridgeReceiver.h"
#include "OSCMessage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOSCBridgeReceiver() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_AActor();
OSC_API UClass* Z_Construct_UClass_UOSCServer_NoRegister();
OSC_API UScriptStruct* Z_Construct_UScriptStruct_FOSCMessage();
OSCBRIDGE_API UClass* Z_Construct_UClass_AOSCBridgeReceiver();
OSCBRIDGE_API UClass* Z_Construct_UClass_AOSCBridgeReceiver_NoRegister();
OSCBRIDGE_API UFunction* Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCBridgeAddressStats();
OSCBRIDGE_API UScriptStruct* Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry();
UPackage* Z_Construct_UPackage__Script_OSCBridge();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FOSCBridgeAddressStats ********************************************
struct Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FOSCBridgeAddressStats); }
	static inline consteval int16 GetStructAlignment() { return alignof(FOSCBridgeAddressStats); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Address_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Count_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstSeenSeconds_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSeenSeconds_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HzEMA_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArgTypeSignature_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArgCount_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastValueFloat_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastValueDisplay_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FOSCBridgeAddressStats constinit property declarations ************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Count;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_FirstSeenSeconds;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_LastSeenSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HzEMA;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ArgTypeSignature;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ArgCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LastValueFloat;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LastValueDisplay;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FOSCBridgeAddressStats constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOSCBridgeAddressStats>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOSCBridgeAddressStats;
class UScriptStruct* FOSCBridgeAddressStats::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCBridgeAddressStats.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOSCBridgeAddressStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOSCBridgeAddressStats, (UObject*)Z_Construct_UPackage__Script_OSCBridge(), TEXT("OSCBridgeAddressStats"));
	}
	return Z_Registration_Info_UScriptStruct_FOSCBridgeAddressStats.OuterSingleton;
	}

// ********** Begin ScriptStruct FOSCBridgeAddressStats Property Definitions ***********************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, Address), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Address_MetaData), NewProp_Address_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, Count), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Count_MetaData), NewProp_Count_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_FirstSeenSeconds = { "FirstSeenSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, FirstSeenSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstSeenSeconds_MetaData), NewProp_FirstSeenSeconds_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_LastSeenSeconds = { "LastSeenSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, LastSeenSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSeenSeconds_MetaData), NewProp_LastSeenSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_HzEMA = { "HzEMA", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, HzEMA), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HzEMA_MetaData), NewProp_HzEMA_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_ArgTypeSignature = { "ArgTypeSignature", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, ArgTypeSignature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArgTypeSignature_MetaData), NewProp_ArgTypeSignature_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_ArgCount = { "ArgCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, ArgCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArgCount_MetaData), NewProp_ArgCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_LastValueFloat = { "LastValueFloat", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, LastValueFloat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastValueFloat_MetaData), NewProp_LastValueFloat_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_LastValueDisplay = { "LastValueDisplay", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeAddressStats, LastValueDisplay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastValueDisplay_MetaData), NewProp_LastValueDisplay_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_Count,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_FirstSeenSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_LastSeenSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_HzEMA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_ArgTypeSignature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_ArgCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_LastValueFloat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewProp_LastValueDisplay,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FOSCBridgeAddressStats Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
	nullptr,
	&NewStructOps,
	"OSCBridgeAddressStats",
	Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::PropPointers),
	sizeof(FOSCBridgeAddressStats),
	alignof(FOSCBridgeAddressStats),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOSCBridgeAddressStats()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCBridgeAddressStats.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOSCBridgeAddressStats.InnerSingleton, Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FOSCBridgeAddressStats.InnerSingleton);
}
// ********** End ScriptStruct FOSCBridgeAddressStats **********************************************

// ********** Begin ScriptStruct FOSCBridgeCaptureEntry ********************************************
struct Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FOSCBridgeCaptureEntry); }
	static inline consteval int16 GetStructAlignment() { return alignof(FOSCBridgeCaptureEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Address_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimestampSeconds_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArgTypeSignature_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayValue_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloatArgs_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "Comment", "// Per-arg float-coerced view (float / int32 / int64 / double / bool \xe2\x86\x92 0/1). Non-numeric types get 0.f as placeholder.\n" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
		{ "ToolTip", "Per-arg float-coerced view (float / int32 / int64 / double / bool \xe2\x86\x92 0/1). Non-numeric types get 0.f as placeholder." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstStringArg_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "Comment", "// First arg of OSC string type, empty otherwise\n" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
		{ "ToolTip", "First arg of OSC string type, empty otherwise" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstBoolArg_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "Comment", "// First arg of OSC bool type, false otherwise (T \xe2\x86\x92 true, F \xe2\x86\x92 false)\n" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
		{ "ToolTip", "First arg of OSC bool type, false otherwise (T \xe2\x86\x92 true, F \xe2\x86\x92 false)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinearColorArg_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "Comment", "// Composed FLinearColor \xe2\x80\x94 from OSC 'r' type, or first 3-4 floats (alpha defaults 1.0 for 3-float), or default Black\n" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
		{ "ToolTip", "Composed FLinearColor \xe2\x80\x94 from OSC 'r' type, or first 3-4 floats (alpha defaults 1.0 for 3-float), or default Black" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FOSCBridgeCaptureEntry constinit property declarations ************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_TimestampSeconds;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ArgTypeSignature;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloatArgs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FloatArgs;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FirstStringArg;
	static void NewProp_FirstBoolArg_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_FirstBoolArg;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LinearColorArg;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FOSCBridgeCaptureEntry constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOSCBridgeCaptureEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOSCBridgeCaptureEntry;
class UScriptStruct* FOSCBridgeCaptureEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCBridgeCaptureEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOSCBridgeCaptureEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry, (UObject*)Z_Construct_UPackage__Script_OSCBridge(), TEXT("OSCBridgeCaptureEntry"));
	}
	return Z_Registration_Info_UScriptStruct_FOSCBridgeCaptureEntry.OuterSingleton;
	}

// ********** Begin ScriptStruct FOSCBridgeCaptureEntry Property Definitions ***********************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeCaptureEntry, Address), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Address_MetaData), NewProp_Address_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_TimestampSeconds = { "TimestampSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeCaptureEntry, TimestampSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimestampSeconds_MetaData), NewProp_TimestampSeconds_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_ArgTypeSignature = { "ArgTypeSignature", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeCaptureEntry, ArgTypeSignature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArgTypeSignature_MetaData), NewProp_ArgTypeSignature_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_DisplayValue = { "DisplayValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeCaptureEntry, DisplayValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayValue_MetaData), NewProp_DisplayValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FloatArgs_Inner = { "FloatArgs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FloatArgs = { "FloatArgs", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeCaptureEntry, FloatArgs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloatArgs_MetaData), NewProp_FloatArgs_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FirstStringArg = { "FirstStringArg", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeCaptureEntry, FirstStringArg), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstStringArg_MetaData), NewProp_FirstStringArg_MetaData) };
void Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FirstBoolArg_SetBit(void* Obj)
{
	((FOSCBridgeCaptureEntry*)Obj)->FirstBoolArg = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FirstBoolArg = { "FirstBoolArg", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOSCBridgeCaptureEntry), &Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FirstBoolArg_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstBoolArg_MetaData), NewProp_FirstBoolArg_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_LinearColorArg = { "LinearColorArg", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOSCBridgeCaptureEntry, LinearColorArg), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinearColorArg_MetaData), NewProp_LinearColorArg_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_TimestampSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_ArgTypeSignature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_DisplayValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FloatArgs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FloatArgs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FirstStringArg,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_FirstBoolArg,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewProp_LinearColorArg,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FOSCBridgeCaptureEntry Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
	nullptr,
	&NewStructOps,
	"OSCBridgeCaptureEntry",
	Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::PropPointers),
	sizeof(FOSCBridgeCaptureEntry),
	alignof(FOSCBridgeCaptureEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry()
{
	if (!Z_Registration_Info_UScriptStruct_FOSCBridgeCaptureEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOSCBridgeCaptureEntry.InnerSingleton, Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FOSCBridgeCaptureEntry.InnerSingleton);
}
// ********** End ScriptStruct FOSCBridgeCaptureEntry **********************************************

// ********** Begin Delegate FOSCBridgeCapturedSignature *******************************************
struct Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics
{
	struct _Script_OSCBridge_eventOSCBridgeCapturedSignature_Parms
	{
		FOSCBridgeCaptureEntry Entry;
		FOSCMessage Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Entry_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOSCBridgeCapturedSignature constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Entry;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOSCBridgeCapturedSignature constinit property declarations *************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOSCBridgeCapturedSignature Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::NewProp_Entry = { "Entry", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OSCBridge_eventOSCBridgeCapturedSignature_Parms, Entry), Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Entry_MetaData), NewProp_Entry_MetaData) }; // 151022394
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OSCBridge_eventOSCBridgeCapturedSignature_Parms, Message), Z_Construct_UScriptStruct_FOSCMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) }; // 1106582076
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::NewProp_Entry,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOSCBridgeCapturedSignature Property Definitions ************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_OSCBridge, nullptr, "OSCBridgeCapturedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::_Script_OSCBridge_eventOSCBridgeCapturedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::_Script_OSCBridge_eventOSCBridgeCapturedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOSCBridgeCapturedSignature_DelegateWrapper(const FMulticastScriptDelegate& OSCBridgeCapturedSignature, FOSCBridgeCaptureEntry const& Entry, FOSCMessage const& Message)
{
	struct _Script_OSCBridge_eventOSCBridgeCapturedSignature_Parms
	{
		FOSCBridgeCaptureEntry Entry;
		FOSCMessage Message;
	};
	_Script_OSCBridge_eventOSCBridgeCapturedSignature_Parms Parms;
	Parms.Entry=Entry;
	Parms.Message=Message;
	OSCBridgeCapturedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOSCBridgeCapturedSignature *********************************************

// ********** Begin Class AOSCBridgeReceiver Function ClearStats ***********************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_ClearStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearStats constinit property declarations ****************************
// ********** End Function ClearStats constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_ClearStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "ClearStats", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_ClearStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_ClearStats_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_ClearStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_ClearStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execClearStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearStats();
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function ClearStats *************************************

// ********** Begin Class AOSCBridgeReceiver Function GetAddressStats ******************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics
{
	struct OSCBridgeReceiver_eventGetAddressStats_Parms
	{
		FName Address;
		FOSCBridgeAddressStats OutStats;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAddressStats constinit property declarations ***********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutStats;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAddressStats constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAddressStats Property Definitions **********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetAddressStats_Parms, Address), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::NewProp_OutStats = { "OutStats", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetAddressStats_Parms, OutStats), Z_Construct_UScriptStruct_FOSCBridgeAddressStats, METADATA_PARAMS(0, nullptr) }; // 1286623432
void Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OSCBridgeReceiver_eventGetAddressStats_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OSCBridgeReceiver_eventGetAddressStats_Parms), &Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::NewProp_OutStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::PropPointers) < 2048);
// ********** End Function GetAddressStats Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "GetAddressStats", 	Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::OSCBridgeReceiver_eventGetAddressStats_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::OSCBridgeReceiver_eventGetAddressStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execGetAddressStats)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Address);
	P_GET_STRUCT_REF(FOSCBridgeAddressStats,Z_Param_Out_OutStats);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetAddressStats(Z_Param_Address,Z_Param_Out_OutStats);
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function GetAddressStats ********************************

// ********** Begin Class AOSCBridgeReceiver Function GetAllAddressStats ***************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics
{
	struct OSCBridgeReceiver_eventGetAllAddressStats_Parms
	{
		TArray<FOSCBridgeAddressStats> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllAddressStats constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllAddressStats constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllAddressStats Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOSCBridgeAddressStats, METADATA_PARAMS(0, nullptr) }; // 1286623432
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetAllAddressStats_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1286623432
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::PropPointers) < 2048);
// ********** End Function GetAllAddressStats Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "GetAllAddressStats", 	Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::OSCBridgeReceiver_eventGetAllAddressStats_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::OSCBridgeReceiver_eventGetAllAddressStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execGetAllAddressStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FOSCBridgeAddressStats>*)Z_Param__Result=P_THIS->GetAllAddressStats();
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function GetAllAddressStats *****************************

// ********** Begin Class AOSCBridgeReceiver Function GetKnownAddresses ****************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics
{
	struct OSCBridgeReceiver_eventGetKnownAddresses_Parms
	{
		TArray<FName> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetKnownAddresses constinit property declarations *********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetKnownAddresses constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetKnownAddresses Property Definitions ********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetKnownAddresses_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::PropPointers) < 2048);
// ********** End Function GetKnownAddresses Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "GetKnownAddresses", 	Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::OSCBridgeReceiver_eventGetKnownAddresses_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::OSCBridgeReceiver_eventGetKnownAddresses_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execGetKnownAddresses)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FName>*)Z_Param__Result=P_THIS->GetKnownAddresses();
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function GetKnownAddresses ******************************

// ********** Begin Class AOSCBridgeReceiver Function GetLatestDisplay *****************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics
{
	struct OSCBridgeReceiver_eventGetLatestDisplay_Parms
	{
		FName Address;
		bool bFound;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLatestDisplay constinit property declarations **********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static void NewProp_bFound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFound;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLatestDisplay constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLatestDisplay Property Definitions *********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetLatestDisplay_Parms, Address), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::NewProp_bFound_SetBit(void* Obj)
{
	((OSCBridgeReceiver_eventGetLatestDisplay_Parms*)Obj)->bFound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::NewProp_bFound = { "bFound", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OSCBridgeReceiver_eventGetLatestDisplay_Parms), &Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::NewProp_bFound_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetLatestDisplay_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::NewProp_bFound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::PropPointers) < 2048);
// ********** End Function GetLatestDisplay Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "GetLatestDisplay", 	Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::OSCBridgeReceiver_eventGetLatestDisplay_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::OSCBridgeReceiver_eventGetLatestDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execGetLatestDisplay)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Address);
	P_GET_UBOOL_REF(Z_Param_Out_bFound);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetLatestDisplay(Z_Param_Address,Z_Param_Out_bFound);
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function GetLatestDisplay *******************************

// ********** Begin Class AOSCBridgeReceiver Function GetLatestFloat *******************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics
{
	struct OSCBridgeReceiver_eventGetLatestFloat_Parms
	{
		FName Address;
		bool bFound;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLatestFloat constinit property declarations ************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Address;
	static void NewProp_bFound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLatestFloat constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLatestFloat Property Definitions ***********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetLatestFloat_Parms, Address), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::NewProp_bFound_SetBit(void* Obj)
{
	((OSCBridgeReceiver_eventGetLatestFloat_Parms*)Obj)->bFound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::NewProp_bFound = { "bFound", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OSCBridgeReceiver_eventGetLatestFloat_Parms), &Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::NewProp_bFound_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetLatestFloat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::NewProp_bFound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::PropPointers) < 2048);
// ********** End Function GetLatestFloat Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "GetLatestFloat", 	Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::OSCBridgeReceiver_eventGetLatestFloat_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::OSCBridgeReceiver_eventGetLatestFloat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execGetLatestFloat)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Address);
	P_GET_UBOOL_REF(Z_Param_Out_bFound);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetLatestFloat(Z_Param_Address,Z_Param_Out_bFound);
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function GetLatestFloat *********************************

// ********** Begin Class AOSCBridgeReceiver Function GetRecentMessages ****************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics
{
	struct OSCBridgeReceiver_eventGetRecentMessages_Parms
	{
		int32 MaxCount;
		TArray<FOSCBridgeCaptureEntry> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC Bridge" },
		{ "CPP_Default_MaxCount", "64" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetRecentMessages constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetRecentMessages constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetRecentMessages Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::NewProp_MaxCount = { "MaxCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetRecentMessages_Parms, MaxCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry, METADATA_PARAMS(0, nullptr) }; // 151022394
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OSCBridgeReceiver_eventGetRecentMessages_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 151022394
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::NewProp_MaxCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::PropPointers) < 2048);
// ********** End Function GetRecentMessages Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "GetRecentMessages", 	Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::OSCBridgeReceiver_eventGetRecentMessages_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::OSCBridgeReceiver_eventGetRecentMessages_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execGetRecentMessages)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FOSCBridgeCaptureEntry>*)Z_Param__Result=P_THIS->GetRecentMessages(Z_Param_MaxCount);
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function GetRecentMessages ******************************

// ********** Begin Class AOSCBridgeReceiver Function IsListening **********************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics
{
	struct OSCBridgeReceiver_eventIsListening_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsListening constinit property declarations ***************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsListening constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsListening Property Definitions **************************************
void Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OSCBridgeReceiver_eventIsListening_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OSCBridgeReceiver_eventIsListening_Parms), &Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::PropPointers) < 2048);
// ********** End Function IsListening Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "IsListening", 	Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::OSCBridgeReceiver_eventIsListening_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::OSCBridgeReceiver_eventIsListening_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_IsListening()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_IsListening_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execIsListening)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsListening();
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function IsListening ************************************

// ********** Begin Class AOSCBridgeReceiver Function StartListening *******************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_StartListening_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartListening constinit property declarations ************************
// ********** End Function StartListening constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_StartListening_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "StartListening", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_StartListening_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_StartListening_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_StartListening()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_StartListening_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execStartListening)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartListening();
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function StartListening *********************************

// ********** Begin Class AOSCBridgeReceiver Function StopListening ********************************
struct Z_Construct_UFunction_AOSCBridgeReceiver_StopListening_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopListening constinit property declarations *************************
// ********** End Function StopListening constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOSCBridgeReceiver_StopListening_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOSCBridgeReceiver, nullptr, "StopListening", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOSCBridgeReceiver_StopListening_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOSCBridgeReceiver_StopListening_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AOSCBridgeReceiver_StopListening()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOSCBridgeReceiver_StopListening_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOSCBridgeReceiver::execStopListening)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopListening();
	P_NATIVE_END;
}
// ********** End Class AOSCBridgeReceiver Function StopListening **********************************

// ********** Begin Class AOSCBridgeReceiver *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AOSCBridgeReceiver;
UClass* AOSCBridgeReceiver::GetPrivateStaticClass()
{
	using TClass = AOSCBridgeReceiver;
	if (!Z_Registration_Info_UClass_AOSCBridgeReceiver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("OSCBridgeReceiver"),
			Z_Registration_Info_UClass_AOSCBridgeReceiver.InnerSingleton,
			StaticRegisterNativesAOSCBridgeReceiver,
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
	return Z_Registration_Info_UClass_AOSCBridgeReceiver.InnerSingleton;
}
UClass* Z_Construct_UClass_AOSCBridgeReceiver_NoRegister()
{
	return AOSCBridgeReceiver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AOSCBridgeReceiver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "OSC Bridge Receiver" },
		{ "IncludePath", "OSCBridgeReceiver.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReceiveIPAddress_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Port_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bMulticastLoopback_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoStartInGame_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bListenInEditor_MetaData[] = {
		{ "Category", "OSC Bridge|Editor" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RingBufferSize_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ClampMax", "65536" },
		{ "ClampMin", "16" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCaptured_MetaData[] = {
		{ "Category", "OSC Bridge" },
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Server_MetaData[] = {
		{ "ModuleRelativePath", "Public/OSCBridgeReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AOSCBridgeReceiver constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReceiveIPAddress;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Port;
	static void NewProp_bMulticastLoopback_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMulticastLoopback;
	static void NewProp_bAutoStartInGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoStartInGame;
	static void NewProp_bListenInEditor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bListenInEditor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RingBufferSize;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCaptured;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Server;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AOSCBridgeReceiver constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClearStats"), .Pointer = &AOSCBridgeReceiver::execClearStats },
		{ .NameUTF8 = UTF8TEXT("GetAddressStats"), .Pointer = &AOSCBridgeReceiver::execGetAddressStats },
		{ .NameUTF8 = UTF8TEXT("GetAllAddressStats"), .Pointer = &AOSCBridgeReceiver::execGetAllAddressStats },
		{ .NameUTF8 = UTF8TEXT("GetKnownAddresses"), .Pointer = &AOSCBridgeReceiver::execGetKnownAddresses },
		{ .NameUTF8 = UTF8TEXT("GetLatestDisplay"), .Pointer = &AOSCBridgeReceiver::execGetLatestDisplay },
		{ .NameUTF8 = UTF8TEXT("GetLatestFloat"), .Pointer = &AOSCBridgeReceiver::execGetLatestFloat },
		{ .NameUTF8 = UTF8TEXT("GetRecentMessages"), .Pointer = &AOSCBridgeReceiver::execGetRecentMessages },
		{ .NameUTF8 = UTF8TEXT("IsListening"), .Pointer = &AOSCBridgeReceiver::execIsListening },
		{ .NameUTF8 = UTF8TEXT("StartListening"), .Pointer = &AOSCBridgeReceiver::execStartListening },
		{ .NameUTF8 = UTF8TEXT("StopListening"), .Pointer = &AOSCBridgeReceiver::execStopListening },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_ClearStats, "ClearStats" }, // 1019362754
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_GetAddressStats, "GetAddressStats" }, // 2297371976
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_GetAllAddressStats, "GetAllAddressStats" }, // 2846122933
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_GetKnownAddresses, "GetKnownAddresses" }, // 2982868604
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestDisplay, "GetLatestDisplay" }, // 2119423073
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_GetLatestFloat, "GetLatestFloat" }, // 717989032
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_GetRecentMessages, "GetRecentMessages" }, // 477856522
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_IsListening, "IsListening" }, // 3581685292
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_StartListening, "StartListening" }, // 229404088
		{ &Z_Construct_UFunction_AOSCBridgeReceiver_StopListening, "StopListening" }, // 2695711687
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOSCBridgeReceiver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AOSCBridgeReceiver_Statics

// ********** Begin Class AOSCBridgeReceiver Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_ReceiveIPAddress = { "ReceiveIPAddress", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeReceiver, ReceiveIPAddress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReceiveIPAddress_MetaData), NewProp_ReceiveIPAddress_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeReceiver, Port), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Port_MetaData), NewProp_Port_MetaData) };
void Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bMulticastLoopback_SetBit(void* Obj)
{
	((AOSCBridgeReceiver*)Obj)->bMulticastLoopback = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bMulticastLoopback = { "bMulticastLoopback", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOSCBridgeReceiver), &Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bMulticastLoopback_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bMulticastLoopback_MetaData), NewProp_bMulticastLoopback_MetaData) };
void Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bAutoStartInGame_SetBit(void* Obj)
{
	((AOSCBridgeReceiver*)Obj)->bAutoStartInGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bAutoStartInGame = { "bAutoStartInGame", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOSCBridgeReceiver), &Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bAutoStartInGame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoStartInGame_MetaData), NewProp_bAutoStartInGame_MetaData) };
void Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bListenInEditor_SetBit(void* Obj)
{
	((AOSCBridgeReceiver*)Obj)->bListenInEditor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bListenInEditor = { "bListenInEditor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOSCBridgeReceiver), &Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bListenInEditor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bListenInEditor_MetaData), NewProp_bListenInEditor_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_RingBufferSize = { "RingBufferSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeReceiver, RingBufferSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RingBufferSize_MetaData), NewProp_RingBufferSize_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_OnCaptured = { "OnCaptured", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeReceiver, OnCaptured), Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCaptured_MetaData), NewProp_OnCaptured_MetaData) }; // 2011861088
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_Server = { "Server", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOSCBridgeReceiver, Server), Z_Construct_UClass_UOSCServer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Server_MetaData), NewProp_Server_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOSCBridgeReceiver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_ReceiveIPAddress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_Port,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bMulticastLoopback,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bAutoStartInGame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_bListenInEditor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_RingBufferSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_OnCaptured,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOSCBridgeReceiver_Statics::NewProp_Server,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOSCBridgeReceiver_Statics::PropPointers) < 2048);
// ********** End Class AOSCBridgeReceiver Property Definitions ************************************
UObject* (*const Z_Construct_UClass_AOSCBridgeReceiver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OSCBridge,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOSCBridgeReceiver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOSCBridgeReceiver_Statics::ClassParams = {
	&AOSCBridgeReceiver::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AOSCBridgeReceiver_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AOSCBridgeReceiver_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOSCBridgeReceiver_Statics::Class_MetaDataParams), Z_Construct_UClass_AOSCBridgeReceiver_Statics::Class_MetaDataParams)
};
void AOSCBridgeReceiver::StaticRegisterNativesAOSCBridgeReceiver()
{
	UClass* Class = AOSCBridgeReceiver::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AOSCBridgeReceiver_Statics::Funcs));
}
UClass* Z_Construct_UClass_AOSCBridgeReceiver()
{
	if (!Z_Registration_Info_UClass_AOSCBridgeReceiver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOSCBridgeReceiver.OuterSingleton, Z_Construct_UClass_AOSCBridgeReceiver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOSCBridgeReceiver.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AOSCBridgeReceiver);
AOSCBridgeReceiver::~AOSCBridgeReceiver() {}
// ********** End Class AOSCBridgeReceiver *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h__Script_OSCBridge_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOSCBridgeAddressStats::StaticStruct, Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics::NewStructOps, TEXT("OSCBridgeAddressStats"),&Z_Registration_Info_UScriptStruct_FOSCBridgeAddressStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOSCBridgeAddressStats), 1286623432U) },
		{ FOSCBridgeCaptureEntry::StaticStruct, Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics::NewStructOps, TEXT("OSCBridgeCaptureEntry"),&Z_Registration_Info_UScriptStruct_FOSCBridgeCaptureEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOSCBridgeCaptureEntry), 151022394U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOSCBridgeReceiver, AOSCBridgeReceiver::StaticClass, TEXT("AOSCBridgeReceiver"), &Z_Registration_Info_UClass_AOSCBridgeReceiver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOSCBridgeReceiver), 3583721277U) },
	};
}; // Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h__Script_OSCBridge_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h__Script_OSCBridge_1143440358{
	TEXT("/Script/OSCBridge"),
	Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h__Script_OSCBridge_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h__Script_OSCBridge_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h__Script_OSCBridge_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h__Script_OSCBridge_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
