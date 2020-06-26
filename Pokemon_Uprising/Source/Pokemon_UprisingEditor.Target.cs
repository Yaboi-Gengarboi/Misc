// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Pokemon_UprisingEditorTarget : TargetRules
{
	public Pokemon_UprisingEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Pokemon_Uprising" } );
	}
}
