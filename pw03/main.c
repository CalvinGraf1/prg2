/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Groupe         : B-LABO_3_GROUPE_A
 Date creation  : 25.05.2023

 Description    : Programme principal permettant de tester la création d'un port de
						bateaux et l'affichage de statistiques sur ces derniers

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#include "bateau.h"
#include "statistique.h"

int main() {
	// TEST 1 - Port de 10 bateaux
	{
		const size_t NOMBRE_BATEAU = 10;

		printf("=============================\n");
		printf("====== PORT SAINT LOUIS =====\n");
		printf("=============================\n\n");
		Bateau port[NOMBRE_BATEAU];

		port[0] = nouveauVoilier(199, "WindMaker");
		port[1] = nouveauVoilier(200, "Pikachu");
		port[2] = nouveauVoilier(201, "La baronne");
		port[3] = nouveauPeche(75, 19, "Chalutiosaure");
		port[4] = nouveauPeche(75, 20, "Samira");
		port[5] = nouveauPeche(55, 21, "Golum");
		port[6] = nouveauPlaisance(99, 12, "Reverie", "Michel");
		port[7] = nouveauPlaisance(100, 17, "Eclipse", "Samantha");
		port[8] = nouveauPlaisance(101, 10, "Soleil Couchant", "Alan");
		port[9] = nouveauVoilier(190, "Eole");

		affichagePort(port, NOMBRE_BATEAU);

		affichageStatistiqueType(port, NOMBRE_BATEAU, SOMME, VOILIER);
		affichageStatistiqueType(port, NOMBRE_BATEAU, ECARTTYPE, PECHE);
		affichageStatistiquePort(port, NOMBRE_BATEAU, MEDIANE);
	}

	// TEST 2 - Port de 7 bateaux
	{
		const size_t NOMBRE_BATEAU = 7;
		printf("=============================\n");
		printf("===== PORT DE MARSEILLE =====\n");
		printf("=============================\n\n");
		Bateau port[NOMBRE_BATEAU];

		port[0] = nouveauVoilier(250, "SeaWind");
		port[1] = nouveauPeche(45, 25, "GoodFish");
		port[2] = nouveauPlaisance(110, 30, "YachtPrima", "Justine");
		port[3] = nouveauVoilier(120, "Le boucher");
		port[4] = nouveauPeche(55, 5, "Calvin");
		port[5] = nouveauPlaisance(40, 22, "Asus", "Lucas");
		port[6] = nouveauPlaisance(125, 40, "Victoria", "Armand");

		affichagePort(port, NOMBRE_BATEAU);

		affichageStatistiquePort(port, NOMBRE_BATEAU, SOMME);
		affichageStatistiquePort(port, NOMBRE_BATEAU, MOYENNE);
		affichageStatistiquePort(port, NOMBRE_BATEAU, MEDIANE);

		printf("-------------------------------------------\n\n");
		printf("Affiche d'un bateau en particulier : \n");
		affichageBateau(&port[0]);

		printf("Affiche des taxes d'un bateau en particulier : \n");
		affichageTaxeBateau(&port[1]);
	}

	return EXIT_SUCCESS;
}
