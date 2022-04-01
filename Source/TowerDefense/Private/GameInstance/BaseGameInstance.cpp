// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/BaseGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"



UBaseGameInstance::UBaseGameInstance()
	:Super(),LoadingWidgetClass(nullptr),LoadingWidget(nullptr)
{

}

void UBaseGameInstance::Init()
{
	Super::Init();

	//直接绑定地图加载前后的广播事件
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UBaseGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UBaseGameInstance::EndLoadingScreen);
}

void UBaseGameInstance::BeginLoadingScreen(const FString& MapName)
{
	UE_LOG(LogTemp, Log, TEXT("BeginLoadingScreen"));

	//如果当前不是独立服务器的话，单机游戏可以忽略该判断
	if (!IsRunningDedicatedServer())
	{
		//这是UE4自带的加载屏幕类型
		FLoadingScreenAttributes LoadingScreen;

		//对其进行属性配置
		//当加载完成时是否自动结束播放
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;

		//添加我们的UMG
		//根据Class创建我们的UMG
		LoadingWidget = CreateWidget<UStartUserWidget>(this,
		LoadClass<UStartUserWidget>(nullptr,
			TEXT("WidgetBlueprint'/Game/TowerDefense/UI/BP_StartWidget.BP_StartWidget_C'")));
		
		//获取到UMG对应的共享指针
		TSharedPtr<SWidget> WidgetPtr = LoadingWidget->TakeWidget();
		//正式设置
		LoadingScreen.WidgetLoadingScreen = WidgetPtr;



		// 播放影片相关，我没用到
		// 如果加载完成是否可以任意键打断影片播放
		//LoadingScreen.bMoviesAreSkippable = false;
		// 等待到影片播放结束
		//LoadingScreen.bWaitForManualStop = true;
		// 视频播放类型
		//LoadingScreen.PlaybackType = EMoviePlaybackType::MT_Looped;
		// 视频播放路径
		// 下方路径对应：Content\Movies目录下的squad_intro_movie.mp4文件
		//LoadingScreen.MoviePaths.Add("squad_intro_movie");



		//放MovePlayer里播放
		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}

		
}

void UBaseGameInstance::EndLoadingScreen(UWorld* LoadedWorld)
{
	UE_LOG(LogTemp, Log, TEXT("EndLoadingScreen"));
	//删除UMG
	if (!IsRunningDedicatedServer())
	{
		if (LoadingWidget)
		{
			//从父组件移除
			LoadingWidget->RemoveFromParent();
			//标记删除
			LoadingWidget->MarkPendingKill();
		}
	}
}
