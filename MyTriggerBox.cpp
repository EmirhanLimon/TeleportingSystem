// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"

AMyTriggerBox::AMyTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::EnterTeleporter);
	OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::ExitTeleporter);
	Teleport = false;
}

void AMyTriggerBox::BeginPlay() {

	Super::BeginPlay();

}

void AMyTriggerBox::EnterTeleporter(AActor* overlappedActor, AActor* otherActor)
{

	if (otherActor && otherActor != this)
	{
		if (OtherTeleport)
		{
			ATeleporterSystemCharacter* Character = Cast<ATeleporterSystemCharacter>(otherActor);

			if (Character && !OtherTeleport->Teleport)
			{
				Teleport = true;
				Character->SetActorLocation(OtherTeleport->GetActorLocation());
				Character->GetController()->SetControlRotation(Character->GetActorRotation());
				Character->SetActorLocation(OtherTeleport->GetActorLocation());
			}
		}
	}
}

void AMyTriggerBox::ExitTeleporter(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (OtherTeleport && !Teleport)
		{
			OtherTeleport->Teleport = false;
		}
    }
}
