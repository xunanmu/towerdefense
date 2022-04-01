// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HelpUserWidget.h"

#include "Components/Button.h"


bool UHelpUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		CloseButton =  Cast<UButton>(GetWidgetFromName("CloseButton"));
		CloseButton->OnClicked.AddDynamic(this,&UHelpUserWidget::Close);
		return true;
	}
	
	
	return false;
}

/*关闭按钮有点冗余了，改天抽象出来改改*/
void UHelpUserWidget::Close()
{
	this->RemoveFromViewport();
}
