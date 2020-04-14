// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

UCLASS()
class ARCHITECTUREEXPLORER_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frameKK
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 
	void BeginTeleport();
	FVector2D GetBlinkersCenter();
	bool FindTeleportDestination(FVector &OutLocation);
	void FinishTeleport();
	void MoveForward(float throttle);
	void MoveRight(float throttle);
	void StartCameraFade(float FromAlpha, float ToAlpha);
	void UpdateBlinkers();
	void UpdateDestinationMarker();


private:
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY()
	class UMaterialInstanceDynamic* BlinkerMaterialInstance;
	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent* LeftController;
	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent* RightController;
	UPROPERTY()
	class UPostProcessComponent* PostProcessComponent;
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* VRRoot;
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DestinationMarker;

private:
	UPROPERTY(EditAnywhere)
	float MaxTeleportDistance = 1000.f;
	UPROPERTY(EditAnywhere)
	float TeleportFadeTime = 1.f;
	UPROPERTY(EditAnywhere)
	FVector TeleportProjectionExtent = FVector(100, 100, 100);
	UPROPERTY(EditAnywhere)
	class UCurveFloat* RadiusVsVelocity;
	UPROPERTY(EditAnywhere)
	class UMaterialInterface* BlinkerMaterialBase;

};
