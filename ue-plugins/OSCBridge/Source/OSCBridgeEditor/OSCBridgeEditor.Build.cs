// Copyright NM 2026
using UnrealBuildTool;

public class OSCBridgeEditor : ModuleRules
{
	public OSCBridgeEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"OSCBridge"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Slate",
			"SlateCore",
			"UnrealEd",
			"ToolMenus",
			"WorkspaceMenuStructure",
			"InputCore",
			"ApplicationCore",
			"OSC"
		});
	}
}
