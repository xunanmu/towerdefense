// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HealthUserWidget.h"

bool UHealthUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		HealthProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("HealthProgressBar")));
		return true;
	}
	return false;
}

void UHealthUserWidget::UpdateHealthProgressBar(float Value)
{
	HealthProgressBar->SetPercent(Value);
	UE_LOG(LogTemp,Error,TEXT("[%s,%f]"),*GetName(),HealthProgressBar->Percent);
}



void UHealthUserWidget::UpdateLocation(FVector2D NewLocation)
{
	this->SetPositionInViewport(NewLocation);
}

