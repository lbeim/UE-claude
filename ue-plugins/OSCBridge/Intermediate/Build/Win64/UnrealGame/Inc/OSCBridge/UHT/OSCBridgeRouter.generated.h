// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OSCBridgeRouter.h"

#ifdef OSCBRIDGE_OSCBridgeRouter_generated_h
#error "OSCBridgeRouter.generated.h already included, missing '#pragma once' in OSCBridgeRouter.h"
#endif
#define OSCBRIDGE_OSCBridgeRouter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AOSCBridgeReceiver;
struct FLinearColor;
struct FOSCBridgeCaptureEntry;
struct FOSCMessage;

// ********** Begin ScriptStruct FOSCFloatBinding **************************************************
struct Z_Construct_UScriptStruct_FOSCFloatBinding_Statics;
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_23_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FOSCFloatBinding_Statics; \
	static class UScriptStruct* StaticStruct();


struct FOSCFloatBinding;
// ********** End ScriptStruct FOSCFloatBinding ****************************************************

// ********** Begin ScriptStruct FOSCVector3Binding ************************************************
struct Z_Construct_UScriptStruct_FOSCVector3Binding_Statics;
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_63_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FOSCVector3Binding_Statics; \
	static class UScriptStruct* StaticStruct();


struct FOSCVector3Binding;
// ********** End ScriptStruct FOSCVector3Binding **************************************************

// ********** Begin ScriptStruct FOSCVector4Binding ************************************************
struct Z_Construct_UScriptStruct_FOSCVector4Binding_Statics;
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_90_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FOSCVector4Binding_Statics; \
	static class UScriptStruct* StaticStruct();


struct FOSCVector4Binding;
// ********** End ScriptStruct FOSCVector4Binding **************************************************

// ********** Begin ScriptStruct FOSCBoolBinding ***************************************************
struct Z_Construct_UScriptStruct_FOSCBoolBinding_Statics;
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_121_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FOSCBoolBinding_Statics; \
	static class UScriptStruct* StaticStruct();


struct FOSCBoolBinding;
// ********** End ScriptStruct FOSCBoolBinding *****************************************************

// ********** Begin ScriptStruct FOSCStringBinding *************************************************
struct Z_Construct_UScriptStruct_FOSCStringBinding_Statics;
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_148_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FOSCStringBinding_Statics; \
	static class UScriptStruct* StaticStruct();


struct FOSCStringBinding;
// ********** End ScriptStruct FOSCStringBinding ***************************************************

// ********** Begin ScriptStruct FOSCBangBinding ***************************************************
struct Z_Construct_UScriptStruct_FOSCBangBinding_Statics;
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_160_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FOSCBangBinding_Statics; \
	static class UScriptStruct* StaticStruct();


struct FOSCBangBinding;
// ********** End ScriptStruct FOSCBangBinding *****************************************************

// ********** Begin Class AOSCBridgeRouter *********************************************************
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleReceiverCaptured); \
	DECLARE_FUNCTION(execGetBoundReceiver); \
	DECLARE_FUNCTION(execRebindReceiver);


#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AOSCBridgeRouter_Statics;
OSCBRIDGE_API UClass* Z_Construct_UClass_AOSCBridgeRouter_NoRegister();

#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOSCBridgeRouter(); \
	friend struct ::Z_Construct_UClass_AOSCBridgeRouter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend OSCBRIDGE_API UClass* ::Z_Construct_UClass_AOSCBridgeRouter_NoRegister(); \
public: \
	DECLARE_CLASS2(AOSCBridgeRouter, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OSCBridge"), Z_Construct_UClass_AOSCBridgeRouter_NoRegister) \
	DECLARE_SERIALIZER(AOSCBridgeRouter)


#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AOSCBridgeRouter(AOSCBridgeRouter&&) = delete; \
	AOSCBridgeRouter(const AOSCBridgeRouter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOSCBridgeRouter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOSCBridgeRouter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOSCBridgeRouter) \
	NO_API virtual ~AOSCBridgeRouter();


#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_172_PROLOG
#define FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_CALLBACK_WRAPPERS \
	FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_INCLASS_NO_PURE_DECLS \
	FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h_175_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AOSCBridgeRouter;

// ********** End Class AOSCBridgeRouter ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Claude_Projects_UE_claude_ue_plugins_OSCBridge_HostProject_Plugins_OSCBridge_Source_OSCBridge_Public_OSCBridgeRouter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
