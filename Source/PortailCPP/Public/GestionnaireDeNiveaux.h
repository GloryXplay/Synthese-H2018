// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/LevelStreaming.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GestionnaireDeNiveaux.generated.h"

UCLASS()
class PORTAILCPP_API AGestionnaireDeNiveaux : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGestionnaireDeNiveaux();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//marque une niveau � charger pour le level streaming
	void ChargerNiveau(FName nomNiveau, int IdStream);
	//retourne si oui ou non un niveau a fini d'�tre charg�
	bool NiveauEstCharge(FName nomNiveau);
	//marque un niveau comme �tant � d�charger pour le level streaming
	void DechargerNiveau(FName nomNiveau);
};
