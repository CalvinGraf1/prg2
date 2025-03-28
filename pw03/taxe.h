/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxe.h
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Groupe         : B-LABO_3_GROUPE_A
 Date creation  : 25.05.2023

 Description    : En-tête de la librairie permettant le calcul et l'affichage des
                  taxes annuelles des bateaux d'un port

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#ifndef LAB3_TAXE_H
#define LAB3_TAXE_H

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf
#include "bateau.h"
#include "statistique.h"

#define TAXE_BASE_VOILE 50
#define TAXE_BASE_MOTEUR 100
#define TAXE_SPECIFIQUE_VOILIER 25
#define TAXE_SPECIFIQUE_PECHE 100
#define TAXE_SPECIFIQUE_PLAISANCE 50
#define TAXE_LONGUEUR_PLAISANCE 15
#define SURFACE_VOILIER 200
#define TONNAGE_POISSON 20
#define PUISSANCE_MOTEUR 100

double calculerTaxeVoilier(const Bateau *bateau);

double calculerTaxePeche(const Bateau *bateau);

double calculerTaxePlaisance(const Bateau *bateau);

/// Récupération de la taxe annuelle d'un bateau spécifique
double taxeBateau(const Bateau *bateau);

/// Récupération de la taxe annuelle de tous les bateaux d'un type donné
double *taxesType(const Bateau *bateaux, size_t taillePort,
						TagType type, size_t *nombreBateauType);

/// Récupération de la taxe annuelle de tous les bateaux d'un port
double *taxesPort(const Bateau *bateaux, size_t taillePort);

/// Affichage de la taxe annuelle d'un bateau donné
void affichageTaxeBateau(const Bateau *bateau);

/// Affichage de la statistique choisie pour tous les bateaux d'un type donné
void affichageStatistiqueType(const Bateau *bateaux, size_t taillePort,
										TagStat stat, TagType type);

/// Affichage de la statistique choisie pour tous les bateaux d'un port
void affichageStatistiquePort(const Bateau *bateaux, size_t taillePort,
										TagStat stat);

#endif //LAB3_TAXE_H
