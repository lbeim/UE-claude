// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOSCBridge_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	OSCBRIDGE_API UFunction* Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_OSCBridge;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_OSCBridge()
	{
		if (!Z_Registration_Info_UPackage__Script_OSCBridge.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_OSCBridge_OSCBridgeCapturedSignature__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/OSCBridge",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x588A5F2D,
			0xFE25110B,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_OSCBridge.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_OSCBridge.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_OSCBridge(Z_Construct_UPackage__Script_OSCBridge, TEXT("/Script/OSCBridge"), Z_Registration_Info_UPackage__Script_OSCBridge, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x588A5F2D, 0xFE25110B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
