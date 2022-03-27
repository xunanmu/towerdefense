// Copyright Epic Games, Inc. All Rights Reserved.


#include "TowerDefenseGameModeBase.h"

#include "Character/ParagonTwinblastCharacter.h"
#include "PlayerController/CharacterPlayerController.h"
#include "UI/SightHUD.h"

ATowerDefenseGameModeBase::ATowerDefenseGameModeBase()
{
	DefaultPawnClass = AParagonTwinblastCharacter::StaticClass();
	PlayerControllerClass = ACharacterPlayerController::StaticClass();
	HUDClass = ASightHUD::StaticClass();
	
}
