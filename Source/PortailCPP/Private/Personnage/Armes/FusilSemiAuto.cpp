// Fill out your copyright notice in the Description page of Project Settings.

#include "FusilSemiAuto.h"


UFusilSemiAuto::UFusilSemiAuto()
	:UArme(10, 1.0f, 30, "/Game/FirstPerson/FPWeapon/Mesh/SK_FPGun")
{}

void UFusilSemiAuto::CommencerTir() {
	FaireApparaitreProjectile();
}

void UFusilSemiAuto::TerminerTir()
{
	UE_LOG(LogTemp, Warning, TEXT("tir termine"));
}