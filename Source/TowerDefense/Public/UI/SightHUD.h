// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SightHUD.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ASightHUD : public AHUD
{
	GENERATED_BODY()
public:
	ASightHUD(){}
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTexture;
	virtual void DrawHUD() override;
};
