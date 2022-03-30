// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/BaseAIController.h"
#include "AI/Enemy/EnemyAIController.h"
#include "GameFramework/GameModeBase.h"
#include "TowerDefenseGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ATowerDefenseGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ATowerDefenseGameModeBase();
	virtual void BeginPlay() override;
	
	virtual void StartPlay() override;

	
private:
};