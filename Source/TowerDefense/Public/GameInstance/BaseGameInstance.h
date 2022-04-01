// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/StartUserWidget.h"
#include "BaseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UBaseGameInstance();
	virtual void Init() override;
	/*显示加载屏幕*/
	virtual void BeginLoadingScreen(const FString& MapName);
	/*隐藏加载屏幕*/
	virtual void EndLoadingScreen(UWorld* LoadedWorld);
protected:
	TSubclassOf<UStartUserWidget> LoadingWidgetClass;
	UStartUserWidget* LoadingWidget;
};
