// Fill out your copyright notice in the Description page of Project Settings.


#include "OurMonsterShooterGameMode.h"

#include "Kismet/GameplayStatics.h"

void AOurMonsterShooterGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountDownTimerHandle, this,
		&AOurMonsterShooterGameMode::CountdownTimer, 1.0f, true, 1.0f);
}

void AOurMonsterShooterGameMode::RestartGameplay(bool Won) 
{
	if (Won)
	{
		ResetLevel();
	}
	else
	{
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this,
			&AOurMonsterShooterGameMode::ResetLevel, 3.0f);
	}
}

void AOurMonsterShooterGameMode::ResetLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Gameplay");
}

void AOurMonsterShooterGameMode::CountdownTimer()
{
	TimerCount--;

	if (TimerCount == 0)
	{
		GetWorldTimerManager().ClearTimer(CountDownTimerHandle);

		ResetLevel();
	}
}
