// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "ItemsWindowUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UItemsWindowUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UItemsWindowUserWidget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer){}

	virtual bool Initialize() override;

	UImage* ItemsImage;
};
