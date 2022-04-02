// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/StartGameMode.h"

#include "UI/StartUserWidget.h"

void AStartGameMode::BeginPlay()
{
	Super::BeginPlay();
	/*生成开始界面*/
	UStartUserWidget* StartUserWidget = CreateWidget<UStartUserWidget>(GetGameInstance(),
		LoadClass<UStartUserWidget>(nullptr,
			TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_StartWidget.BP_StartWidget_C'")));

	StartUserWidget->AddToViewport();
}
