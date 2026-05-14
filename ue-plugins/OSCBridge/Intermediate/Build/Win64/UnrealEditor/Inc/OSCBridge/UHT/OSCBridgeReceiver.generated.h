// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OSCBridgeReceiver.h"

#ifdef OSCBRIDGE_OSCBridgeReceiver_generated_h
#error "OSCBridgeReceiver.generated.h already included, missing '#pragma once' in OSCBridgeReceiver.h"
#endif
#define OSCBRIDGE_OSCBridgeReceiver_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FOSCBridgeAddressStats;
struct FOSCBridgeCaptureEntry;
struct FOSCMessage;

// ********** Begin ScriptStruct FOSCBridgeAddressStats ********************************************
struct Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics;
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_14_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FOSCBridgeAddressStats_Statics; \
	static class UScriptStruct* StaticStruct();


struct FOSCBridgeAddressStats;
// ********** End ScriptStruct FOSCBridgeAddressStats **********************************************

// ********** Begin ScriptStruct FOSCBridgeCaptureEntry ********************************************
struct Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics;
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_47_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FOSCBridgeCaptureEntry_Statics; \
	static class UScriptStruct* StaticStruct();


struct FOSCBridgeCaptureEntry;
// ********** End ScriptStruct FOSCBridgeCaptureEntry **********************************************

// ********** Begin Delegate FOSCBridgeCapturedSignature *******************************************
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_78_DELEGATE \
OSCBRIDGE_API void FOSCBridgeCapturedSignature_DelegateWrapper(const FMulticastScriptDelegate& OSCBridgeCapturedSignature, FOSCBridgeCaptureEntry const& Entry, FOSCMessage const& Message);


// ********** End Delegate FOSCBridgeCapturedSignature *********************************************

// ********** Begin Class AOSCBridgeReceiver *******************************************************
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_83_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetLatestDisplay); \
	DECLARE_FUNCTION(execGetLatestFloat); \
	DECLARE_FUNCTION(execGetRecentMessages); \
	DECLARE_FUNCTION(execGetAddressStats); \
	DECLARE_FUNCTION(execGetAllAddressStats); \
	DECLARE_FUNCTION(execGetKnownAddresses); \
	DECLARE_FUNCTION(execClearStats); \
	DECLARE_FUNCTION(execIsListening); \
	DECLARE_FUNCTION(execStopListening); \
	DECLARE_FUNCTION(execStartListening);


struct Z_Construct_UClass_AOSCBridgeReceiver_Statics;
OSCBRIDGE_API UClass* Z_Construct_UClass_AOSCBridgeReceiver_NoRegister();

#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_83_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOSCBridgeReceiver(); \
	friend struct ::Z_Construct_UClass_AOSCBridgeReceiver_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend OSCBRIDGE_API UClass* ::Z_Construct_UClass_AOSCBridgeReceiver_NoRegister(); \
public: \
	DECLARE_CLASS2(AOSCBridgeReceiver, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OSCBridge"), Z_Construct_UClass_AOSCBridgeReceiver_NoRegister) \
	DECLARE_SERIALIZER(AOSCBridgeReceiver)


#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_83_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AOSCBridgeReceiver(AOSCBridgeReceiver&&) = delete; \
	AOSCBridgeReceiver(const AOSCBridgeReceiver&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOSCBridgeReceiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOSCBridgeReceiver); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOSCBridgeReceiver) \
	NO_API virtual ~AOSCBridgeReceiver();


#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_80_PROLOG
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_83_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_83_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_83_INCLASS_NO_PURE_DECLS \
	FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h_83_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AOSCBridgeReceiver;

// ********** End Class AOSCBridgeReceiver *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeReceiver_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
