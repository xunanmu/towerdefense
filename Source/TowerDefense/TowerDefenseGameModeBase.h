// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/BaseAIController.h"
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
	/*自动生成敌方人物*/
	void AutoCreateEnemy(int n);

	virtual void StartPlay() override;
private:
	ABaseAIController* CreateAIController();
	void CreateBot();
};
