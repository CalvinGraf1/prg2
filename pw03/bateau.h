/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.h
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Groupe         : B-LABO_3_GROUPE_A
 Date creation  : 25.05.2023

 Description    : En-tête de la librairie permettant la gestion d'un port et de ses
                  bateaux

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#ifndef LAB3_BATEAU_H
#define LAB3_BATEAU_H

#include <stdint.h> // uint8_t, uint16_t

typedef enum {
	VOILIER, PECHE, PLAISANCE
} TagType;

typedef struct {
	uint8_t longueur; // en mètres
	const char *nomProprietaire;
} BateauDePlaisance;

typedef struct {
	uint8_t tonnagePoisson;
} BateauDePeche;

typedef union {
	BateauDePeche peche;
	BateauDePlaisance plaisance;
} Fonction;

typedef struct {
	uint16_t puissance; // en chevaux
	Fonction fonction;
} Moteur;

typedef struct {
	uint16_t surface; // en mètres carrés
} Voile;

typedef union {
	Voile voile;
	Moteur moteur;
} Categorie;

typedef struct {
	TagType tag;
	Categorie categorie;
	const char *nom;
} Bateau;

#include "taxe.h"

extern const char *TAG_TYPE_NOM[];

/// Crée un nouveau bateau de type voilier
/// \param surface surface de la voile [m2]
/// \param nom nom du bateau
/// \return voilier
Bateau nouveauVoilier(uint16_t surface, const char *nom);

/// Crée un nouveau bateau de type pêche
/// \param puissance puissance du moteur [CV]
/// \param tonnage tonnage de poisson [t]
/// \param nom nom du bateau
/// \return bateau de pêche
Bateau nouveauPeche(uint16_t puissance, uint8_t tonnage, const char *nom);

/// Crée un nouveau bateau de type plaisance
/// \param puissance puissance du moteur [CV]
/// \param longueur longueur du bateau [m]
/// \param nom nom du bateau
/// \param nomProprietaire nom du propriétaire du bateau
/// \return bateau de plaisance
Bateau nouveauPlaisance(uint16_t puissance, uint8_t longueur,
								const char *nom, const char *nomProprietaire);

void affichageInfoVoilier(const Bateau *bateau);

void affichageInfoPeche(const Bateau *bateau);

void affichageInfoPlaisance(const Bateau *bateau);

/// Affichage des informations d'un bateau spécifique
void affichageBateau(const Bateau *bateau);

/// Affichage des informations de tous les bateaux du port, décroissant de leur taxe
void affichagePort(Bateau *port, size_t taille);

#endif //LAB3_BATEAU_H
