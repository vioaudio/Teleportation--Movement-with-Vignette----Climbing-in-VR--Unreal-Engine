// Fill out your copyright notice in the Description page of Project Settings.


#include "HandController.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "MotionControllerComponent.h"
#include "Haptics/HapticFeedbackEffect_Base.h"


// Sets default values
AHandController::AHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Motion Controller"));
	SetRootComponent(MotionController);
}


// Called when the game starts or when spawned
void AHandController::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AHandController::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AHandController::ActorEndOverlap);
}

// Called every frame
void AHandController::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);

		if (bIsClimbing)
		{
			FVector HandControllerDelta = GetActorLocation() - ClimbingStartLocation;
			//Dont need to cast because moving parent is sufficient, & don't need to access methods lower down
			GetAttachParentActor()->AddActorWorldOffset(-HandControllerDelta); //Moves Parents in Opposite Direction so controller appears to be stationary
		}
	}

void AHandController::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//Logic here makes sures that if Can Climb is already true, you don't get a double notification that you can climb. For instance
	//if you moved your controller from a climbable object into another one before fully leaving the first one, important for 
	//implementing vibration or any other notifcation to the player that they have touched a climbable object
	bool bNewCanClimb = CanClimb();

	if (!bCanClimb && bNewCanClimb)
	{
		APawn* Pawn = Cast<APawn>(GetAttachParentActor()); 
		if (Pawn != nullptr)
		{
			APlayerController* PC = Cast<APlayerController>(Pawn->GetController()); //Gets Player controller of Parent Actor
			if (PC != nullptr)
			{
				PC->PlayHapticEffect(HapticCurve, HandPass);
			}
		}
	}
	bCanClimb = bNewCanClimb;
}

void AHandController::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	bCanClimb = CanClimb();
}

void AHandController::HapticFeedback()
{
}

bool AHandController::CanClimb() const
{
	
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);

	for (AActor* OverlappingActor : OverlappingActors)
	{
		if (OverlappingActor->ActorHasTag(TEXT("Climbable")))
		{
			return true;
		}
	}
	return false;
}

void AHandController::Grip()
{
	if (!bCanClimb) return;
	if (!bIsClimbing)
	{
		bIsClimbing = true; //UpdateState
		ClimbingStartLocation = GetActorLocation(); //Location of HandController

		OtherController->bIsClimbing = false; //If you grip with other  hand than the opposite hand becomes false

		//Change Movement Mode To Flying
		ACharacter* Character = Cast<ACharacter>(GetAttachParentActor());
		if (Character != nullptr)
		{
			Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
		}
	}
}

void AHandController::PairController(AHandController * Controller)
{
	OtherController = Controller;
	OtherController->OtherController = this;
}

void AHandController::Release()
{
	if (bIsClimbing) 
	{
		ACharacter* Character = Cast<ACharacter>(GetAttachParentActor());
		if (Character != nullptr)
		{
			Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling);
		}
	}
	bIsClimbing = false;

	 //UpdateState
}

void AHandController::SetHand(EControllerHand Hand)
{
	MotionController->SetTrackingSource(Hand);
	HandPass = Hand;
}



