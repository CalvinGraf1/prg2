/*
 -----------------------------------------------------------------------------------
 Nom du fichier : statistique.h
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Groupe         : B-LABO_3_GROUPE_A
 Date creation  : 25.05.2023

 Description    : En-tête de la librairie permettant le calcul de statistiques

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#ifndef LAB3_STATISTIQUE_H
#define LAB3_STATISTIQUE_H

#include <math.h>

typedef enum {
	SOMME,
	MOYENNE,
	MEDIANE,
	ECARTTYPE
} TagStat;

extern double (*fonctionStatistique[])(double *, size_t);

extern const char *TAG_STAT_NOM[];

double somme(const double *tab, size_t taille);

double moyenne(double *tab, size_t taille);

double mediane(double *tab, size_t taille);

double ecart_type(double *tab, size_t taille);

#endif //LAB3_STATISTIQUE_H
