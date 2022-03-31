// Copyright Epic Games, Inc. All Rights Reserved.


#include "TowerDefenseGameModeBase.h"

#include "AI/Enemy/EnemyAIController.h"
#include "AI/Enemy/EnemyFactory.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Character/ParagonTwinblastCharacter.h"
#include "PlayerController/CharacterPlayerController.h"
#include "UI/SightHUD.h"

ATowerDefenseGameModeBase::ATowerDefenseGameModeBase()
{
	
	DefaultPawnClass = AParagonTwinblastCharacter::StaticClass();
	PlayerControllerClass = ACharacterPlayerController::StaticClass();
	// HUDClass = ASightHUD::StaticClass();
	
}


void ATowerDefenseGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UEnemyFactory::CreateEnemy(GetWorld(),5);
}




