// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StartGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AStartGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AStartGameMode(){}
	virtual void BeginPlay() override;
};
