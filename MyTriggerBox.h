// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "TeleporterSystemCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class TELEPORTERSYSTEM_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AMyTriggerBox();

	UFUNCTION()
		void EnterTeleporter(class AActor* overlappedActor, class AActor* otherActor);
	UFUNCTION()
		void ExitTeleporter(class AActor* overlappedActor, class AActor* otherActor);

	UPROPERTY(EditAnywhere, Category = "Teleporter")
		AMyTriggerBox* OtherTeleport;
	UPROPERTY()
		bool Teleport;

	
};
