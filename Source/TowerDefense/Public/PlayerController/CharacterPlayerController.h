// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharacterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ACharacterPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ACharacterPlayerController();
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
};
