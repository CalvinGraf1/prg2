/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.c
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Groupe         : B-LABO_3_GROUPE_A
 Date creation  : 25.05.2023

 Description    : Librairie permettant la gestion d'un port et de ses bateaux

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#include <stdio.h> // printf
#include <assert.h> // assert
#include <string.h> // strlen
#include "bateau.h"

const char *TAG_TYPE_NOM[] = {
	"Voilier", "Peche", "Plaisance"
};

Bateau nouveauVoilier(uint16_t surface, const char *nom) {
	assert(surface != 0);
	assert(nom != NULL && strlen(nom) > 0);
	Bateau b;
	b.tag = VOILIER;
	b.categorie.voile.surface = surface;
	b.nom = nom;
	return b;
}

Bateau nouveauPeche(uint16_t puissance, uint8_t tonnage, const char *nom) {
	assert(puissance != 0);
	assert(nom != NULL && strlen(nom) > 0);
	Bateau b;
	b.tag = PECHE;
	b.categorie.moteur.puissance = puissance;
	b.categorie.moteur.fonction.peche.tonnagePoisson = tonnage;
	b.nom = nom;
	return b;
}

Bateau nouveauPlaisance(uint16_t puissance, uint8_t longueur,
								const char *nom, const char *nomProprietaire) {
	assert(puissance != 0);
	assert(longueur != 0);
	assert(nom != NULL && strlen(nom) > 0);
	assert(nomProprietaire != NULL && strlen(nomProprietaire) > 0);
	Bateau b;
	b.tag = PLAISANCE;
	b.categorie.moteur.puissance = puissance;
	b.categorie.moteur.fonction.plaisance.longueur = longueur;
	b.categorie.moteur.fonction.plaisance.nomProprietaire = nomProprietaire;
	b.nom = nom;
	return b;
}

void (*affichageInfo[])(const Bateau *) = {
	affichageInfoVoilier,
	affichageInfoPeche,
	affichageInfoPlaisance
};

void affichageInfoVoilier(const Bateau *bateau) {
	printf("Surface: %d [m2]\n", bateau->categorie.voile.surface);
}

void affichageInfoPeche(const Bateau *bateau) {
	printf("Puissance: %d [CV]\n", bateau->categorie.moteur.puissance);
	printf("Tonnage: %d [t]\n", bateau->categorie.moteur.fonction.peche
	.tonnagePoisson);
}

void affichageInfoPlaisance(const Bateau *bateau) {
	printf("Puissance: %d [CV]\n", bateau->categorie.moteur.puissance);
	printf("Longueur: %d [m]\n", bateau->categorie.moteur.fonction.plaisance
	.longueur);
	printf("Proprietaire: %s\n",
			 bateau->categorie.moteur.fonction.plaisance.nomProprietaire);
}

void affichageBateau(const Bateau *bateau) {
	printf("Nom: %s\n", bateau->nom);
	printf("Type: %s\n", TAG_TYPE_NOM[bateau->tag]);
	affichageInfo[bateau->tag](bateau);
	printf("\n");
}

void affichagePort(Bateau *port, size_t taille) {
	double *taxes = taxesPort(port, taille);

	if (taxes == NULL) {
		printf("Erreur allocation mémoire des taxes.\n");
		return;
	}

	// trier les bateaux/taxes par ordre décroissant des taxes annuelles
	for (size_t i = 0; i < taille; ++i) {
		for (size_t j = i + 1; j < taille; ++j) {
			if (taxes[i] < taxes[j]) {
				double tmp = taxes[i];
				taxes[i] = taxes[j];
				taxes[j] = tmp;

				Bateau tmpBateau = port[i];
				port[i] = port[j];
				port[j] = tmpBateau;
			}
		}
	}

	// Affichage des bateaux par ordre décroissant de leur taxe annuelle
	for (size_t i = 0; i < taille; ++i) {
		printf("Nom: %s\n", port[i].nom);
		printf("Type: %s\n", TAG_TYPE_NOM[port[i].tag]);
		affichageInfo[port[i].tag](&port[i]);
		printf("Taxes annuelles: %.2f Euro(s)\n\n", taxes[i]);
	}

	free(taxes);
}