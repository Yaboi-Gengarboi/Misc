// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Pokemon_UprisingTarget : TargetRules
{
	public Pokemon_UprisingTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Pokemon_Uprising" } );
	}
}
