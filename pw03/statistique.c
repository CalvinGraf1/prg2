/*
 -----------------------------------------------------------------------------------
 Nom du fichier : statistique.c
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Groupe         : B-LABO_3_GROUPE_A
 Date creation  : 25.05.2023

 Description    : Librairie permettant le calcul de statistiques

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#include "statistique.h"

const char *TAG_STAT_NOM[] = {
	"Somme", "Moyenne", "Mediane", "Ecart-type"
};

double (*fonctionStatistique[])(double *, size_t) = {
	(double (*)(double *, size_t)) somme,
	moyenne,
	mediane,
	ecart_type
};

double somme(const double *tab, size_t taille) {
	double somme = 0;
	for (size_t i = 0; i < taille; ++i)
		somme += tab[i];
	return somme;
}

double moyenne(double *tab, size_t taille) {
	return somme(tab, taille) / (double)taille;
}

double mediane(double *tab, size_t taille) {
	double tmp;
	for (size_t i = 0; i < taille; ++i)
		for (size_t j = i + 1; j < taille; ++j)
			if (tab[i] > tab[j]) {
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
	// Si tableau pair
	if (taille % 2 == 0)
		return (tab[taille / 2 - 1] + tab[taille / 2]) / 2;
	// Si tableau impair
	return tab[taille / 2];
}

double ecart_type(double *tab, size_t taille) {
	double moy = moyenne(tab, taille);
	double somme = 0;
	for (size_t i = 0; i < taille; ++i)
		somme += (tab[i] - moy) * (tab[i] - moy);
	return sqrt(somme / (double)taille);
}