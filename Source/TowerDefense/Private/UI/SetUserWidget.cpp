// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SetUserWidget.h"

#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

bool USetUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		HangUpButton = Cast<UButton>(GetWidgetFromName("HangUpButton"));
		EnemyDifficultyButton = Cast<UButton>(GetWidgetFromName("EnemyDifficultyButton"));
		EnemyKindButton = Cast<UButton>(GetWidgetFromName("EnemyKindButton"));
		CloseButton = Cast<UButton>(GetWidgetFromName("CloseButton"));
		ExitGameButton = Cast<UButton>(GetWidgetFromName("ExitGameButton"));
		if (HangUpButton)
		{
			HangUpButton->OnClicked.AddDynamic(this, &USetUserWidget::HandUp);
		}
		if (EnemyDifficultyButton)
		{
			EnemyDifficultyButton->OnClicked.AddDynamic(this, &USetUserWidget::EnemyDifficulty);
		}
		if (EnemyKindButton)
		{
			EnemyKindButton->OnClicked.AddDynamic(this, &USetUserWidget::EnemyKind);
		}
		if (CloseButton)
		{
			CloseButton->OnClicked.AddDynamic(this, &USetUserWidget::Close);
		}
		if (ExitGameButton)
		{
			ExitGameButton->OnClicked.AddDynamic(this,&USetUserWidget::ExitGame);
		}
		return true;
	}
	
	return false;
}

void USetUserWidget::HandUp()
{
}

void USetUserWidget::EnemyDifficulty()
{
}

void USetUserWidget::EnemyKind()
{
}

void USetUserWidget::Close()
{
	this->RemoveFromViewport();
}

void USetUserWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit,true);
}
