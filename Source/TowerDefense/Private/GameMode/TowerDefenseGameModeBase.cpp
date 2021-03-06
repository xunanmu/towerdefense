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
	static ConstructorHelpers::FClassFinder<AParagonTwinblastCharacter> BPClass(TEXT("Blueprint'/Game/TowerDefense/UI/BackpackUserWidget_BP/BP_TEST.BP_TEST_C'"));
	DefaultPawnClass = BPClass.Class;
	PlayerControllerClass = ACharacterPlayerController::StaticClass();
	
}
 

void ATowerDefenseGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	/*็ๆๆไบบ*/
	GetWorld()->SpawnActor<AEnemyFactory>();
}




