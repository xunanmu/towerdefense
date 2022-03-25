// Copyright Epic Games, Inc. All Rights Reserved.


#include "TowerDefenseGameModeBase.h"

#include "Character/ParagonTwinblastCharacter.h"
#include "PlayerController/CharacterPlayerController.h"

ATowerDefenseGameModeBase::ATowerDefenseGameModeBase()
{
	DefaultPawnClass = AParagonTwinblastCharacter::StaticClass();
	PlayerControllerClass = ACharacterPlayerController::StaticClass();
	
}
