// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI/BackpackUserWidget.h"
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
	
	virtual void Tick(float DeltaSeconds) override;

	/*打开背包*/
	void OpenBackpack();
	/*打开瞄准*/
	void OpenAimat();

	bool bAimat;
	bool bBackPack;
private:
	UUserWidget* Aimat;
	UUserWidget* BackpackUserWidget;
};
