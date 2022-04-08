// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "HealthUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UHealthUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UHealthUserWidget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer){};
	virtual bool Initialize() override;

	/*更新血量进度条*/
	// UFUNCTION(NetMulticast,Reliable)
	void UpdateHealthProgressBar(float Value);

	/*更新位置*/
	// UFUNCTION(NetMulticast,Reliable)
	void UpdateLocation(FVector2D NewLocation);

	UProgressBar* HealthProgressBar;
};
