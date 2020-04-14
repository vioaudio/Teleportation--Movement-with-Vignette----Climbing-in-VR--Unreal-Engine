// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Curves/CurveFloat.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "MotionControllerComponent.h"
#include "TimerManager.h"



// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VR Root"));
	VRRoot->SetupAttachment(GetRootComponent());
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);

	DestinationMarker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Destination Marker"));
	DestinationMarker->SetupAttachment(GetRootComponent());

	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Left Controller"));
	LeftController->SetupAttachment(VRRoot);
	LeftController->SetTrackingSource(EControllerHand::Left);

	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Right Controller"));
	RightController->SetupAttachment(VRRoot);
	RightController->SetTrackingSource(EControllerHand::Right);

	PostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("Post Process Component"));
	PostProcessComponent->SetupAttachment(GetRootComponent());

	TeleportPath = CreateDefaultSubobject<USplineComponent>(TEXT("Teleport Path"));
	TeleportPath->SetupAttachment(RightController);
}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	DestinationMarker->SetVisibility(false);
	
	if (BlinkerMaterialBase != nullptr)
	{
		BlinkerMaterialInstance = UMaterialInstanceDynamic::Create(BlinkerMaterialBase, this);
		PostProcessComponent->AddOrUpdateBlendable(BlinkerMaterialInstance);
		BlinkerMaterialInstance->SetScalarParameterValue(TEXT("Radius"), 1);
	}
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Calculate how much HMD moved in this frame
	FVector NewCameraOffset = Camera->GetComponentLocation() - GetActorLocation();

	//Removes Up & Down (only works if Up is on the Z axis)
	NewCameraOffset.Z = 0;

	//Move Actor the same way camera moved
	AddActorWorldOffset(NewCameraOffset);

	//Move VR Root in opposite way
	VRRoot->AddWorldOffset(-NewCameraOffset);

	UpdateDestinationMarker();
	UpdateBlinkers();
}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AVRCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AVRCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Teleport"), IE_Released, this, &AVRCharacter::BeginTeleport);
}

void AVRCharacter::BeginTeleport()
{
	//Fade out the viewport
	StartCameraFade(0, 1);
	FTimerHandle Handle;
	GetWorldTimerManager().SetTimer(Handle, this, &AVRCharacter::FinishTeleport, TeleportFadeTime);
}

void AVRCharacter::DrawTeleportPath(const TArray<FVector>& Path)
{
	UpdateSpline(Path);

	for (int32 i = 0; i < Path.Num(); i++)
	{
		if (TeleportPathMeshPool.Num() <= i)//True If there are more points that have not yet been added to the Object Pool
		{
			UStaticMeshComponent* DynamicMesh = NewObject<UStaticMeshComponent>(this); //creates new static mesh at runtime
			DynamicMesh->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform); // Places Object at 0,0,0 relative to parent
			DynamicMesh->SetStaticMesh(TeleportArchMesh); //Sets Mesh during Runtime
			DynamicMesh->SetMaterial(0, TeleportArchMaterial); //Sets Material during Runtime to material at index (0)
			DynamicMesh->RegisterComponent();
			TeleportPathMeshPool.Add(DynamicMesh); //Adds it to an Object Pool
		}
		UStaticMeshComponent* DynamicMesh = TeleportPathMeshPool[i]; //Gets the current mesh at this index
		DynamicMesh->SetWorldLocation(Path[i]); //Sets location to index of the point being referred to in the for loop
	}
	
}

bool AVRCharacter::FindTeleportDestination(TArray<FVector> &OutPath, FVector &OutLocation)
{
	FVector Start = RightController->GetComponentLocation() + FVector(0, 10 ,0);
	FVector LookDirection = RightController->GetForwardVector();
	
	FPredictProjectilePathParams Params(
		TeleportProjectileRadius,
		Start,
		LookDirection * TeleportProjectileSpeed,
		TeleportSimulationTime,
		ECC_Visibility,
		this
	);
	Params.DrawDebugType = EDrawDebugTrace::ForOneFrame;
	Params.bTraceComplex = true; //Enables it to hit more things in scene

	FPredictProjectilePathResult Result;
	bool bHit = UGameplayStatics::PredictProjectilePath(this, Params, Result);
	if (!bHit) return false;
	
	for (FPredictProjectilePathPointData PointData : Result.PathData) //Outputs an Array of Locations for each point on the path
	{
		OutPath.Add(PointData.Location);
	}

	OutLocation = Result.HitResult.Location;
	return bHit;

	//Use Below code for a straight line teleport rather than parabolic
	//Angles the lookdirection down so that it is more comfortable to choose teleport location
	//FVector LookDirection = (RightController->GetForwardVector()).RotateAngleAxis(30, RightController->GetRightVector());
	//FVector End = Start + LookDirection * MaxTeleportDistance;
	//DrawDebugLine(GetWorld(), Start, End, FColor(0, 255, 0), false, 0.f, 0, 2.f);
	//FHitResult HitResult;
	//bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility); //Line Trace
	//OutLocation = HitResult.Location;
}

void AVRCharacter::FinishTeleport()
{
	//Move Player to Desitnation
	FVector CapsuleCenter = FVector(0, 0, GetCapsuleComponent()->GetScaledCapsuleHalfHeight());
	SetActorLocation(DestinationMarker->GetComponentLocation() + CapsuleCenter);
	//Fade in the viewport 
	StartCameraFade(1, 0);
}

FVector2D AVRCharacter::GetBlinkersCenter() //Currently Call is Commented Out
{
	FVector MovementDirection = GetVelocity().GetSafeNormal(); 
	if (MovementDirection.IsNearlyZero())
	{
		return FVector2D(0.5f, 0.5f);
	}

	return FVector2D();

	FVector WorldStationaryPosition;

	if (FVector::DotProduct(Camera->GetForwardVector(), MovementDirection) > 0) 
	{
		WorldStationaryPosition = Camera->GetComponentLocation() + MovementDirection * 1000.f; //Moving Forward Solution
	}
	else
	{
		WorldStationaryPosition = Camera->GetComponentLocation() - MovementDirection * 1000.f; //Moving Backward Solution
	}

	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC == nullptr)
	{
		return FVector2D(0.5, 0.5f);
	}

	FVector2D ScreenStationaryLocation;
	PC->ProjectWorldLocationToScreen(WorldStationaryPosition, ScreenStationaryLocation);

	int32 SizeX, SizeY;
	PC->GetViewportSize(SizeX, SizeY);

	//Convert Into UVs
	ScreenStationaryLocation.X /= SizeX;
	ScreenStationaryLocation.Y /= SizeY;
	return FVector2D(0.5, 0.5f); //return ScreenStationaryLocation;
	
}

void AVRCharacter::MoveForward(float throttle)
{
	AddMovementInput(throttle * Camera->GetForwardVector());
}

void AVRCharacter::MoveRight(float throttle)
{
	AddMovementInput(throttle * Camera->GetRightVector());
}

void AVRCharacter::StartCameraFade(float FromAlpha, float ToAlpha)
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC != nullptr)
	{
		PC->PlayerCameraManager->StartCameraFade(FromAlpha, ToAlpha, TeleportFadeTime, FLinearColor::Black);
	}
}

void AVRCharacter::UpdateBlinkers()
{
	if (RadiusVsVelocity == nullptr) { return; }
	else
	{
		float Speed = GetVelocity().Size();
		float Radius = RadiusVsVelocity->GetFloatValue(Speed); //Gets Radius
		BlinkerMaterialInstance->SetScalarParameterValue(TEXT("Radius"), Radius);

		//FVector2D Center = GetBlinkersCenter();
		//BlinkerMaterialInstance->SetVectorParameterValue(TEXT("Center"), FLinearColor(Center.X, Center.Y, 0)); //Sets Center
	}
}

void AVRCharacter::UpdateSpline(const TArray<FVector>& Path)
{
	TeleportPath->ClearSplinePoints(false);
	for (int32 i = 0; i < Path.Num(); i++)
	{
		FVector LocalPosition = TeleportPath->GetComponentTransform().InverseTransformPosition(Path[i]); // Coverts Position from World to Local
		FSplinePoint Point(i, LocalPosition, ESplinePointType::Curve);
		TeleportPath->AddPoint(Point, false);
	}

	TeleportPath->UpdateSpline();
}

//Teleport Function 
void AVRCharacter::UpdateDestinationMarker()
{
	FVector Location;
	TArray<FVector> Path;
	bool bHasDestination = FindTeleportDestination(Path, Location);

	//Set the teleport destination
	if (bHasDestination)
	{
		DestinationMarker->SetWorldLocation(Location);
		DestinationMarker->SetVisibility(true);
		//UE_LOG(LogTemp, Error, TEXT("Location is %s"), *Location.ToString());
		DrawTeleportPath(Path);
	}
	else
		DestinationMarker->SetVisibility(false); //Hide Marker if Invalid Location
}
