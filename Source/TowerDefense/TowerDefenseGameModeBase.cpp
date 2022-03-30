// Copyright Epic Games, Inc. All Rights Reserved.


#include "TowerDefenseGameModeBase.h"

#include "Character/ParagonTwinblastCharacter.h"
#include "PlayerController/CharacterPlayerController.h"
#include "UI/SightHUD.h"

ATowerDefenseGameModeBase::ATowerDefenseGameModeBase()
{
	
	BotPawnClass = AParagonTwinblastCharacter::StaticClass();
	DefaultPawnClass = AParagonTwinblastCharacter::StaticClass();
	PlayerControllerClass = ACharacterPlayerController::StaticClass();
	// HUDClass = ASightHUD::StaticClass();
	
}

UClass* ATowerDefenseGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	if (InController->IsA<ABaseAIController>())
	{
		return BotPawnClass;
	}
	return Super::GetDefaultPawnClassForController_Implementation(InController);
}


void ATowerDefenseGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	// AutoCreateEnemy(5);
}
void ATowerDefenseGameModeBase::StartPlay()
{
	Super::StartPlay();
	// CreateAIController();
	// CreateBot();
}

void ATowerDefenseGameModeBase::AutoCreateEnemy(int n)
{
	for (int i = 0; i < n;++i)
	{
		
		FRotator ActorRotation(0.0f,-90.0f,0.f);
		FVector ActorLocation(400.f,47767.6875f,24717.435547f);
		
		GetWorld()->SpawnActor<AParagonTwinblastCharacter>(ActorLocation,ActorRotation);
	}
}


ABaseAIController* ATowerDefenseGameModeBase::CreateAIController()
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Instigator = nullptr;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ABaseAIController *AIController = GetWorld()->SpawnActor<ABaseAIController>(SpawnParameters);
	return AIController;
}

void ATowerDefenseGameModeBase::CreateBot()
{
	for(FConstControllerIterator It = GetWorld()->GetControllerIterator();It;It++)
	{
		ABaseAIController *AIController = Cast<ABaseAIController>(*It);
		if (AIController)
		{
			RestartPlayer(AIController);
		}
	}
}
