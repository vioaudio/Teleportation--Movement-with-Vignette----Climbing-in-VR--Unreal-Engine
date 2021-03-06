// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HandController.generated.h"


UCLASS()
class ARCHITECTUREEXPLORER_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHandController();

	void Grip();
	void PairController(AHandController* Controller); //References other controller
	void Release();
	void SetHand(EControllerHand Hand); //Public Method used so we can set hands in VRCharacter

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Default Sub Object
	UPROPERTY(VisibleAnywhere)
		class UMotionControllerComponent* MotionController;	

	//Callbacks
	UFUNCTION()
	void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
	void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
	void HapticFeedback();

	//Helpers
	bool CanClimb() const;
	EControllerHand HandPass;

	//Parameters
	UPROPERTY(EditDefaultsOnly)
		class UHapticFeedbackEffect_Base* HapticCurve;

	//State
	bool bCanClimb = false;
	bool bIsClimbing = false;
	FVector ClimbingStartLocation;
	AHandController* OtherController;
};
