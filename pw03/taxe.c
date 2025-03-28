/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxe.c
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Groupe         : B-LABO_3_GROUPE_A
 Date creation  : 25.05.2023

 Description    : Librairie permettant le calcul et l'affichage des taxes annuelles
                  des bateaux d'un port

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/
#include "taxe.h"

double (*calculTaxes[])(const Bateau *) = {
	calculerTaxeVoilier,
	calculerTaxePeche,
	calculerTaxePlaisance
};

double calculerTaxeVoilier(const Bateau *bateau) {
	double taxe = TAXE_BASE_VOILE;
	if (bateau->categorie.voile.surface >= SURFACE_VOILIER)
		taxe += TAXE_SPECIFIQUE_VOILIER;
	return taxe;
}

double calculerTaxePeche(const Bateau *bateau) {
	double taxe = TAXE_BASE_MOTEUR;
	if (bateau->categorie.moteur.fonction.peche.tonnagePoisson >= TONNAGE_POISSON)
		taxe += TAXE_SPECIFIQUE_PECHE;
	return taxe;
}

double calculerTaxePlaisance(const Bateau *bateau) {
	double taxe = TAXE_BASE_MOTEUR;
	if (bateau->categorie.moteur.puissance < PUISSANCE_MOTEUR)
		taxe += TAXE_SPECIFIQUE_PLAISANCE;
	else
		taxe += bateau->categorie.moteur.fonction.plaisance.longueur *
				  TAXE_LONGUEUR_PLAISANCE;
	return taxe;
}

double taxeBateau(const Bateau *bateau) {
	return calculTaxes[bateau->tag](bateau);
}

double *taxesType(const Bateau *bateaux, size_t taillePort,
						TagType type, size_t *nombreBateauType) {
	*nombreBateauType = 0;
	for (size_t i = 0; i < taillePort; ++i)
		if (bateaux[i].tag == type)
			(*nombreBateauType)++;

	double *taxes = malloc(*nombreBateauType * sizeof(double));

	if (taxes != NULL) {
		size_t j = 0;
		for (size_t i = 0; i < taillePort; ++i) {
			if (bateaux[i].tag == type) {
				taxes[j] = calculTaxes[bateaux[i].tag](&bateaux[i]);
				++j;
			}
		}
	}

	return taxes;
}

double *taxesPort(const Bateau *bateaux, size_t taillePort) {
	double *taxes = malloc(taillePort * sizeof(double));

	if (taxes != NULL)
		for (size_t i = 0; i < taillePort; ++i)
			taxes[i] = calculTaxes[bateaux[i].tag](&bateaux[i]);

	return taxes;
}

void affichageTaxeBateau(const Bateau *bateau) {
	double taxe = taxeBateau(bateau);
	printf("Taxe du bateau %s : %.2f Euro(s)\n\n", bateau->nom, taxe);
}

void affichageStatistiqueType(const Bateau *bateaux, size_t taillePort,
										TagStat stat, TagType type) {
	size_t nombreTypeBateau = 0;
	double *taxes = taxesType(bateaux, taillePort, type, &nombreTypeBateau);

	if (taxes == NULL) {
		printf("Erreur allocation mémoire des taxes.\n");
		return;
	}

	double resultat = fonctionStatistique[stat](taxes, nombreTypeBateau);
	printf("%s des taxes pour les bateaux de type %s : %.2f Euro(s)\n\n",
			 TAG_STAT_NOM[stat], TAG_TYPE_NOM[type], resultat);
}

void affichageStatistiquePort(const Bateau *bateaux, size_t taillePort,
										TagStat stat) {
	double *taxes = taxesPort(bateaux, taillePort);

	if (taxes == NULL) {
		printf("Erreur allocation mémoire des taxes.\n");
		return;
	}

	double resultat = fonctionStatistique[stat](taxes, taillePort);
	printf("%s des taxes pour les bateaux du port : %.2f Euro(s)\n\n",
			 TAG_STAT_NOM[stat], resultat);
}