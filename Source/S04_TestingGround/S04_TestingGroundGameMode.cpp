// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "S04_TestingGroundGameMode.h"
#include "S04_TestingGroundHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS04_TestingGroundGameMode::AS04_TestingGroundGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Character/Behaviour/Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS04_TestingGroundHUD::StaticClass();
}
