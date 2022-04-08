// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"
#include "UI/HealthUserWidget.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	/*初始化人物的位置和朝向*/
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	/*初始化人物摄像机手臂组件*/
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPringArmComponent"));
	/*设置摄像机手臂与人物之间的距离*/
	SpringArmComponent->TargetArmLength = 500.0f;
	/*设置根组件*/
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);
	
	/*初始摄像机*/
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	/*设置摄像机视野*/
	CameraComponent->FieldOfView = 85.0f;
	/*绑定到摄像机手臂组件*/
	CameraComponent->SetupAttachment(SpringArmComponent);
	
	/*初始化碰撞体*/
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetCapsuleSize(34.0f,94.0f);
	CapsuleComponent->SetupAttachment(RootComponent);

	/*初始血条*/
	HealthComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthComponent"));
	static auto HealthWidget_BP = LoadClass<UHealthUserWidget>(nullptr,
		TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_HealthWidget.BP_HealthWidget_C'"));
	UE_LOG(LogTemp,Error,TEXT("%s->{HealthWidget_BP:%p,HealthUserWidget:%p}"),*GetName(),HealthWidget_BP,HealthUserWidget)
	HealthComponent->SetWidgetClass(HealthWidget_BP);
	HealthComponent->SetWidgetSpace(EWidgetSpace::Screen);
	HealthComponent->SetRelativeLocation(FVector(0,0,100));
	HealthComponent->SetupAttachment(RootComponent);
	

	
	/*初始速度默认值*/
	GetCharacterMovement()->MaxWalkSpeed = 700;
	/*初始攻击默认值*/
	AttackValue = 100;
	/*初始防御默认值*/
	DefenseValue = 100;
	/*初始生命默认值*/
	MaxHealth = 100;
	CurrentHealth = MaxHealth;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward",this,&ABaseCharacter::MoveForWard);
	InputComponent->BindAxis("MoveBack",this,&ABaseCharacter::MoveBack);
	InputComponent->BindAxis("MoveRight",this,&ABaseCharacter::MoveRight);
	InputComponent->BindAxis("MoveLeft",this,&ABaseCharacter::MoveLeft);
	InputComponent->BindAxis("LookUp",this,&ABaseCharacter::AddControllerPitchInput);
	InputComponent->BindAxis("Turn",this,&ABaseCharacter::AddControllerYawInput);
	InputComponent->BindAction("Jump",IE_Pressed,this,&ABaseCharacter::Jump);
	InputComponent->BindAction("Jump",IE_Released,this,&ABaseCharacter::StopJumping);
	InputComponent->BindAction("MouseL",IE_Pressed,this,&ABaseCharacter::Attack);
	InputComponent->BindAction("E",IE_Pressed,this,&ABaseCharacter::SwitchCharacters);
	InputComponent->BindAction("Q",IE_Pressed,this,&ABaseCharacter::SwitchWeapon);
}

void ABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps/*参数名不能乱用*/) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	/*复制当前生命属性*/
	DOREPLIFETIME(ABaseCharacter,CurrentHealth);
}


void ABaseCharacter::MoveForWard(const float Value)
{
	const FVector ForwardVector = GetActorForwardVector();
	AddMovementInput(ForwardVector,Value);
}
void ABaseCharacter::MoveBack(const float Value)
{
	const FVector BackVector = -GetActorForwardVector();
	AddMovementInput(BackVector,Value);
}
void ABaseCharacter::MoveRight(const float Value)
{
	const FVector RightVector = GetActorRightVector();
	AddMovementInput(RightVector,Value);
}
void ABaseCharacter::MoveLeft(const float Value)
{
	const FVector LeftVector = -GetActorRightVector();
	AddMovementInput(LeftVector,Value);
}

void ABaseCharacter::OnRep_CurrentHealth()
{
	OnHealthUpdate();
}

void ABaseCharacter::OnHealthUpdate()
{
	/*客户端*/
	if (IsLocallyControlled())
	{
		FString HealthMessage = FString::Printf(TEXT("你现在的生命值:%d."),CurrentHealth);
		GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Blue,HealthMessage);
		if (CurrentHealth <= 0)
		{
			FString DeathMessage = FString::Printf(TEXT("你已死亡"));
			GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,DeathMessage);
		}
	}

	/*服务端*/
	if(GetLocalRole() == ROLE_Authority)
	{
		FString HealthMessage = FString::Printf(TEXT("%s 当前的生命值%d."),*GetName(),CurrentHealth);
		GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Blue,HealthMessage);
	}

	/*所有端*/
	/*  
	   因任何因伤害或死亡而产生的特殊功能都应放在这里。 
   */
}

void ABaseCharacter::SetCurrentHealth(int healthValue)
{
	/*服务端*/
	if (GetLocalRole() == ROLE_Authority)
	{
		CurrentHealth = FMath::Clamp(healthValue,0,MaxHealth);
		OnHealthUpdate();
	}
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damageApplied = CurrentHealth - DamageAmount;
	SetCurrentHealth(damageApplied);
	return damageApplied;
}
