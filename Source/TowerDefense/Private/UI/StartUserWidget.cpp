// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StartUserWidget.h"

#include "Components/Button.h"

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
			// StartGameButton->OnReleased.Add(ScriptDelegate);
		}
		HelpButton = Cast<UButton>(GetWidgetFromName("HelpButton"));
		if (HelpButton)
		{
			/*设置悬浮时，按钮外观颜色(淡黄)*/
			HelpButton->WidgetStyle.Hovered.TintColor = FSlateColor(FLinearColor(0.995811,1.f,0.304887));
			/*设置按钮点击事件*/
			// HelpButton->OnReleased.Add(ScriptDelegate);
		}
		SetButton = Cast<UButton>(GetWidgetFromName("SetButton"));
		if (SetButton)
		{
			/*设置悬浮时，按钮外观颜色(淡黄)*/
			SetButton->WidgetStyle.Hovered.TintColor = FSlateColor(FLinearColor(0.995811,1.f,0.304887));
			/*设置按钮点击事件*/
			// SetButton->OnReleased.Add(ScriptDelegate);
		}
		ExitGameButton = Cast<UButton>(GetWidgetFromName("ExitGameButton"));
		if (ExitGameButton)
		{
			/*设置悬浮时，按钮外观颜色(淡黄)*/
			ExitGameButton->WidgetStyle.Hovered.TintColor = FSlateColor(FLinearColor(0.995811,1.f,0.304887));
			/*设置按钮点击事件*/
			// ExitGameButton->OnReleased.AddDynamic();
		}
		return true;
	}
	return  false;
}
