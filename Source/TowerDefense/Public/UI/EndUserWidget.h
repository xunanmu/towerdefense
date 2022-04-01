// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UEndUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UEndUserWidget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer){}
	
	virtual auto Initialize() -> bool override;

	
	UFUNCTION() void ExitGame();
private:
	class UButton* ExitGameButton;
};
