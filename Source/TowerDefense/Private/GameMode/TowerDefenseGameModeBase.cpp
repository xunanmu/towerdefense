// Copyright Epic Games, Inc. All Rights Reserved.


#include "GameMode/TowerDefenseGameModeBase.h"

#include "AI/Enemy/EnemyAIController.h"
#include "AI/Enemy/EnemyFactory.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Character/ParagonTwinblastCharacter.h"
#include "PlayerController/CharacterPlayerController.h"
#include "UI/StartUserWidget.h"

ATowerDefenseGameModeBase::ATowerDefenseGameModeBase()
{
	
	DefaultPawnClass = AParagonTwinblastCharacter::StaticClass();
	PlayerControllerClass = ACharacterPlayerController::StaticClass();
	
}
 

void ATowerDefenseGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	/*生成敌人*/
	GetWorld()->SpawnActor<AEnemyFactory>();
}




