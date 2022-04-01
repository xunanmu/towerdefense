// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HelpUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UHelpUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UHelpUserWidget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer){}
	
	virtual bool Initialize() override;

	UFUNCTION() void Close();
private:
	class UButton* CloseButton;
};
