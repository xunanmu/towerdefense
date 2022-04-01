// Copyright Epic Games, Inc. All Rights Reserved.


#include "TowerDefenseGameModeBase.h"

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
	// HUDClass = ASightHUD::StaticClass();
	
}
 

void ATowerDefenseGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	/*生成开始界面*/
	UStartUserWidget* StartUserWidget = CreateWidget<UStartUserWidget>(GetGameInstance(),
		LoadClass<UStartUserWidget>(nullptr,
			TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_StartWidget.BP_StartWidget_C'")));

	StartUserWidget->AddToViewport();
	/*生成敌人*/
	GetWorld()->SpawnActor<AEnemyFactory>();
}




