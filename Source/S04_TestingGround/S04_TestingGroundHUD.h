// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "S04_TestingGroundHUD.generated.h"

UCLASS()
class AS04_TestingGroundHUD : public AHUD
{
	GENERATED_BODY()

public:
	AS04_TestingGroundHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

