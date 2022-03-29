// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/CharacterPlayerController.h"

#include "Blueprint/UserWidget.h"

ACharacterPlayerController::ACharacterPlayerController()
{
	/*默认显示鼠标*/
	bShowMouseCursor = true;
	/*显示瞄准*/
}

void ACharacterPlayerController::BeginPlay()
{
	
}


void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
