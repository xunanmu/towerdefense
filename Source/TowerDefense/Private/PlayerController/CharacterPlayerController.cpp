// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/CharacterPlayerController.h"

ACharacterPlayerController::ACharacterPlayerController()
{
	/*默认显示鼠标*/
	bShowMouseCursor = true;
}

void ACharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();
}


void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
