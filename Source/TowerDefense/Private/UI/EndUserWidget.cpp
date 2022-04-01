// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/EndUserWidget.h"

#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/StartUserWidget.h"

bool UEndUserWidget::Initialize()
{
	ExitGameButton = Cast<UButton>(GetWidgetFromName("ExitGameButton"));
	ExitGameButton->OnClicked.AddDynamic(this,&UEndUserWidget::ExitGame);
	return Super::Initialize();
}

void UEndUserWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit,true);
}