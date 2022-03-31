// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UStartUserWidget(const FObjectInitializer& ObjectInitializer);

	virtual bool Initialize() override;
private:
	class UButton* StartGameButton;
	class UButton* HelpButton;
	class UButton* SetButton;
	class UButton* ExitGameButton;
};
