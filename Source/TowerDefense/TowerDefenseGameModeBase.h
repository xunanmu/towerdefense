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
	
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
	
	virtual void StartPlay() override;

	/*自动生成敌方人物*/
    void AutoCreateEnemy(int n);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = GameMode)
	TSubclassOf<APawn> BotPawnClass;
private:
	ABaseAIController* CreateAIController();
	void CreateBot();
};
