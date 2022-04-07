// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/CharacterPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Character/ParagonTwinblastCharacter.h"

class UStartUserWidget;

ACharacterPlayerController::ACharacterPlayerController()
{
	/*默认显示鼠标*/
	bShowMouseCursor = true;
	/*显示瞄准*/
	static ConstructorHelpers::FClassFinder<UUserWidget> Aimat_BP(TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_AimatWidget.BP_AimatWidget_C'"));
	Aimat = CreateWidget<UUserWidget>(AActor::GetWorld(),Aimat_BP.Class);
	if (Aimat)
	{
		Aimat->AddToViewport();
		Aimat->SetVisibility(ESlateVisibility::Collapsed);
		bAimat = true;
	}
	/*加载背包UI*/
	static ConstructorHelpers::FClassFinder<UBackpackUserWidget> BackpackUserWidget_BP(TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_BackpackWidget.BP_BackpackWidget_C'"));
	BackpackUserWidget = CreateWidget<UBackpackUserWidget>(AActor::GetWorld(),BackpackUserWidget_BP.Class);
	if (BackpackUserWidget)
	{
		UE_LOG(LogTemp,Error,TEXT("@测试加载背包UI"))
		BackpackUserWidget->AddToViewport();
		BackpackUserWidget->SetVisibility(ESlateVisibility::Collapsed);
		bBackPack = true;
	}
	
}

void ACharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ACharacterPlayerController::OpenBackpack()
{
	UE_LOG(LogTemp,Error,TEXT("@背包UI事件：%d"),bBackPack)
	if (bBackPack)
	{
		UE_LOG(LogTemp,Error,TEXT("@测试背包UI：%d"),bBackPack)
		BackpackUserWidget->SetVisibility(ESlateVisibility::Visible);
		bBackPack = false;
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("@测试背包UI：%d"),bBackPack)
		BackpackUserWidget->SetVisibility(ESlateVisibility::Collapsed);
		bBackPack = true;
	}
}

void ACharacterPlayerController::OpenAimat()
{
	if (bAimat)
	{
		Aimat->SetVisibility(ESlateVisibility::Visible);
		bAimat = false;
	}
	else
	{
		Aimat->SetVisibility(ESlateVisibility::Collapsed);
		bAimat = true;
	}
}


void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("B",IE_Pressed,this,&ACharacterPlayerController::OpenBackpack);
	InputComponent->BindAction("J",IE_Pressed,this,&ACharacterPlayerController::OpenAimat);
}
