// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StartUserWidget.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/HelpUserWidget.h"

UStartUserWidget::UStartUserWidget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	
}

bool UStartUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		StartGameButton = Cast<UButton>(GetWidgetFromName("StartGameButton"));
		if (StartGameButton)
		{
			/*设置悬浮时，按钮外观颜色(淡黄)*/
			StartGameButton->WidgetStyle.Hovered.TintColor = FSlateColor(FLinearColor(0.995811,1.f,0.304887));
			/*设置按钮点击事件*/
			 StartGameButton->OnClicked.AddDynamic(this,&UStartUserWidget::StartGame);
		}
		HelpButton = Cast<UButton>(GetWidgetFromName("HelpButton"));
		if (HelpButton)
		{
			/*设置悬浮时，按钮外观颜色(淡黄)*/
			HelpButton->WidgetStyle.Hovered.TintColor = FSlateColor(FLinearColor(0.995811,1.f,0.304887));
			/*设置按钮点击事件*/
			HelpButton->OnClicked.AddDynamic(this,&UStartUserWidget::Help);
		}
		SetButton = Cast<UButton>(GetWidgetFromName("SetButton"));
		if (SetButton)
		{
			/*设置悬浮时，按钮外观颜色(淡黄)*/
			SetButton->WidgetStyle.Hovered.TintColor = FSlateColor(FLinearColor(0.995811,1.f,0.304887));
			/*设置按钮点击事件*/
			SetButton->OnClicked.AddDynamic(this,&UStartUserWidget::Set);
		}
		ExitGameButton = Cast<UButton>(GetWidgetFromName("ExitGameButton"));
		if (ExitGameButton)
		{
			/*设置悬浮时，按钮外观颜色(淡黄)*/
			ExitGameButton->WidgetStyle.Hovered.TintColor = FSlateColor(FLinearColor(0.995811,1.f,0.304887));
			/*设置按钮点击事件*/
			ExitGameButton->OnReleased.AddDynamic(this,&UStartUserWidget::ExitGame);
		}
		return true;
	}
	return  false;
}

void UStartUserWidget::StartGame()
{
	UE_LOG(LogTemp,Error,TEXT("开始游戏"));
	// UGameplayStatics::OpenLevel(GetWorld(),FName("TerrainDemo1"));
	this->RemoveFromViewport();
}

void UStartUserWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit,true);
}

void UStartUserWidget::Help()
{
	UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetGameInstance(),
		LoadClass<UUserWidget>(nullptr,
			TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_HelpWidget.BP_HelpWidget_C'")));

	UserWidget->AddToViewport();
	
}

void UStartUserWidget::Set()
{
	UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetGameInstance(),
		LoadClass<UUserWidget>(nullptr,
			TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_SetWidget.BP_SetWidget_C'")));

	UserWidget->AddToViewport();
}
