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

	/*加载设置按钮*/
	static ConstructorHelpers::FClassFinder<UUserWidget> SetUserWidget_BP(TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_SetWidget.BP_SetWidget_C'"));
    SetWidget = CreateWidget<UUserWidget>(AActor::GetWorld(),SetUserWidget_BP.Class);
	if (SetWidget)
	{
		SetWidget->AddToViewport();
		SetWidget->SetVisibility(ESlateVisibility::Collapsed);
		bSetWidget = true;
	}
	/*敌人血条*/
	// 初始化操作
	// static ConstructorHelpers::FClassFinder<UHealthUserWidget> HealthUserWidget(TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_HealthWidget.BP_HealthWidget'"));
	// // EnemyHealthUserWidget = CreateWidget<UHealthUserWidget>(this, HealthUserWidget.Class);
	// if (EnemyHealthUserWidget) {
	// 	EnemyHealthUserWidget->SetVisibility(ESlateVisibility::Hidden);
	// 	EnemyHealthUserWidget->AddToViewport();
	// }
	
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

void ACharacterPlayerController::SetEnemyHealthBarVisibility(bool bVisibility)
{
	if (EnemyHealthUserWidget)
	{
		if (bVisibility) {
			EnemyHealthUserWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else {
			EnemyHealthUserWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void ACharacterPlayerController::UpdateEnemyHealthBarPosition(FVector Position)
{
	if (EnemyHealthUserWidget) {
		// 将血条位置抬高之后变成输出到屏幕的位置
		FVector2D ScreenPosition;
		FVector TargetPosition = FVector(Position.X, Position.Y, Position.Z + 150);
		ProjectWorldLocationToScreen(TargetPosition, ScreenPosition);

		// 设置它在屏幕显示的大小
		FVector2D ScreenSize(200, 25);

		// 居中计算
		ScreenPosition.X -= ScreenSize.X * 0.5f;
		EnemyHealthUserWidget->SetPositionInViewport(ScreenPosition); 
		EnemyHealthUserWidget->SetDesiredSizeInViewport(ScreenPosition);
	}
}

void ACharacterPlayerController::ExitGame()
{
	UUserWidget* UserWidget = CreateWidget<UUserWidget>(AActor::GetWorld(),
		LoadClass<UUserWidget>(nullptr,
			TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_EndWidget.BP_EndWidget_C'")));

	UserWidget->AddToViewport();
}

void ACharacterPlayerController::OpenSetWidget()
{
	if (bSetWidget)
	{
		SetWidget->SetVisibility(ESlateVisibility::Visible);
		bSetWidget= false;
	}
	else
	{
		SetWidget->SetVisibility(ESlateVisibility::Collapsed);
		bSetWidget = true;
	}
}


void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("B",IE_Pressed,this,&ACharacterPlayerController::OpenBackpack);
	InputComponent->BindAction("J",IE_Pressed,this,&ACharacterPlayerController::OpenAimat);
	InputComponent->BindAction("Esc",IE_Pressed,this,&ACharacterPlayerController::ExitGame);
	InputComponent->BindAction("set",IE_Pressed,this,&ACharacterPlayerController::OpenSetWidget);
}
