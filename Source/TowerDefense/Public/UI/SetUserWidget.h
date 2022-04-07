// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SetUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API USetUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	USetUserWidget(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer){}

	virtual bool Initialize() override;

	UFUNCTION() void HandUp();
	UFUNCTION() void EnemyDifficulty();
	UFUNCTION() void EnemyKind();
	UFUNCTION() void Close();
	UFUNCTION() void ExitGame();
private:
	class UButton* HangUpButton;
	class UButton* EnemyDifficultyButton;
	class UButton* EnemyKindButton;
	class UButton* CloseButton;
	class UButton* ExitGameButton;
};
