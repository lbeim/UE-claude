// Copyright NM 2026
using UnrealBuildTool;

public class OSCBridge : ModuleRules
{
	public OSCBridge(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"OSC"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Networking",
			"Sockets"
		});
	}
}
