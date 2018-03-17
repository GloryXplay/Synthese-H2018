// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "StatistiquesDuJoueur.h"
#include "EngineUtils.h"
#include "TimerManager.h"
#include "Portail.h"
#include "GestionnaireDeNiveaux.h"
#include "Personnage/Personnage.h"
#include "GameFramework/PlayerStart.h"
#include "InformationsNiveau.h"
#include "Blueprint/UserWidget.h"
#include "ModeDeJeu_MenuPrincipal.generated.h"

/**
 * 
 */
UCLASS()
class PORTAILCPP_API AModeDeJeu_MenuPrincipal : public AGameModeBase
{
	GENERATED_BODY()

		AGestionnaireDeNiveaux* GestionnaireDeNiveaux;

	//-----------------------------------------
	//---------OUVERTURE DE LA PARTIE----------
	//-----------------------------------------

	//liste de tous les niveaux qui ont �t� choisis par le g�n�rateur de carte au lancement d'une partie
	TArray<InformationsNiveau*> NiveauxChoisis;

	//choisis les niveaux qui seront utilis�s pendant la partie
	void SelectionnerNiveaux(TArray<InformationsNiveau*> ListeCompleteNiveaux, int NbNiveauxVoulus);

	//s�lectionne quels niveaux seront connect�s ensemble (NE CONNECTE PAS LES PORTAILS)
	void RelierNiveaux();

	//charge les niveaux
	AGestionnaireDeNiveaux * ChargerLesNiveaux();

	//connecte les portails de tous les niveaux de mani�re � ce que tous les niveaux soient accessibles
	void ConnecterLesPortails();

	//Trouve tous les acteurs de type APortail charg�s dans le jeu, et les stock dans NiveauxChoisis
	void TrouverTousLesPortailsCharges(AGestionnaireDeNiveaux * const GestionnaireDeNiveaux);

	//Trouve tous les acteurs de type PointApparition charg�s dans le jeu, et les stock dans NiveauChoisis
	void ChercherPointsApparition();

	//Supprime tous les objets APersonnage d�j� pr�sent (ex: le personnage par d�faut), et en cr�e un certain nombre, plac�s dans les PointsApparitions s�lectionn�s pr�c�demment
	void PlacerJoueurs(int NbJoueurs);

	//-----------------------------------------
	//---------FERMETURE DE LA PARTIE----------
	//-----------------------------------------

	void PartieTerminee(int idNoJoueurGagnant);

	void DechargerCarte();

	void DetruireTousLesJoueurs();

	//-----------------------------------------
	//--------D�ROULEMENT DE LA PARTIE---------
	//-----------------------------------------

	StatistiquesDuJoueur * StatsJoueurs[4];

	void ReapparitionJoueur(int NoJoueur);
	
public:
	AModeDeJeu_MenuPrincipal();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MenuPrincipal")
	TSubclassOf<UUserWidget> StartingWidgetClass;
	
	//le num�ro du joueur gagnant. si �gal � -1, le menu ne l'affichera pas
	UPROPERTY(BlueprintReadOnly, Category = "MenuPrincipal")
	int NoJoueurGagnant;

	virtual void BeginPlay() override;

	UPROPERTY()
	UUserWidget* CurrentWidget;
	
	UFUNCTION(BlueprintCallable, Category = "MenuPrincipal")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	void JoueurEnTueUnAutre(int IndexJoueurTueur, int IndexJoueurMort);

	//appelle toutes les fonctions d'ouverture de la partie
	UFUNCTION(BlueprintCallable, Category = "GenerationCarte")
	void GenererCarte(int nbJoueurs);
};
