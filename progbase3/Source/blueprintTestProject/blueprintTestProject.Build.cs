// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class blueprintTestProject : ModuleRules
{
	public blueprintTestProject(ReadOnlyTargetRules Target) : base (Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "eXiSoundVis" });


        PrivateDependencyModuleNames.AddRange(new string[] { "eXiSoundVis" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "eXiSoundVis" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
