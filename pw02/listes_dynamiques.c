/*
 -----------------------------------------------------------------------------------
 Nom du fichier : listes_dynamiques.c
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Date creation  : 27.04.2023

 Description    : Fichier contenant les definitions pour la librairie permettant la
 						gestion de listes doublement chaînées non circulaires

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include "listes_dynamiques.h"

Liste *initialiser(void) {
	Liste *liste = (Liste *) malloc(sizeof(Liste));

	liste->tete = (Element *) malloc(sizeof(Element));
	liste->queue = (Element *) malloc(sizeof(Element));

	liste->tete->precedent = NULL;
	liste->tete->suivant = liste->queue;
	liste->queue->precedent = liste->tete;
	liste->queue->suivant = NULL;

	return liste;
}

bool estVide(const Liste *liste) {
	return liste->tete->suivant == liste->queue;
}

size_t longueur(const Liste *liste) {
	size_t longueur = 0;
	Element *element = liste->tete->suivant;
	while (element->suivant != NULL) {
		longueur++;
		element = element->suivant;
	}
	return longueur;
}

void afficher(const Liste *liste, Mode mode) {
	if (longueur(liste)) {
		if (mode == FORWARD) {
			Element *element = liste->tete->suivant;
			printf("[");
			while (element->suivant != NULL) { // Ne prend pas en compte la queue
				printf("%d", element->info);
				if (element->suivant->suivant != NULL)
					printf(",");

				element = element->suivant;
			}
			printf("]");
		} else {
			Element *element = liste->queue->precedent;
			printf("[");
			while (element->precedent != NULL) { // Ne prend pas en compte la tete
				printf("%d", element->info);
				if (element->precedent->precedent != NULL)
					printf(",");

				element = element->precedent;
			}
			printf("]");
		}
	} else { // Liste vide
		printf("[]");
	}
}

Status insererEnTete(Liste *liste, const Info *info) {
	Element *element = (Element *) malloc(sizeof(Element));
	if (element == NULL)
		return MEMOIRE_INSUFFISANTE;

	element->info = *info; // On met l'info

	element->suivant = liste->tete->suivant; // son suivant = l'ancien début
	element->precedent = liste->tete; // son précédent = tete

	liste->tete->suivant->precedent = element; // précédent l'ancien debut = l'element
	liste->tete->suivant = element; // suivant de la tête = l'element

	return OK;
}

Status insererEnQueue(Liste *liste, const Info *info) {
	Element *element = (Element *) malloc(sizeof(Element));
	if (element == NULL)
		return MEMOIRE_INSUFFISANTE;

	element->info = *info; // On met l'info

	element->precedent = liste->queue->precedent; // son précédent = l'ancienne fin
	element->suivant = liste->queue; // son suivant = queue

	liste->queue->precedent->suivant = element; // suivant l'ancienne fin = l'element
	liste->queue->precedent = element; // précédent de la queue = l'element

	return OK;
}

Status supprimerEnTete(Liste *liste, Info *info) {
	if (estVide(liste))
		return LISTE_VIDE;

	Element *element = liste->tete->suivant;
	*info = element->info;

	element->suivant->precedent = liste->tete;
	liste->tete->suivant = element->suivant;
	free(element);

	return OK;
}

Status supprimerEnQueue(Liste *liste, Info *info) {
	if (estVide(liste))
		return LISTE_VIDE;

	Element *element = liste->queue->precedent;
	*info = element->info;

	element->precedent->suivant = liste->queue;
	liste->queue->precedent = element->precedent;

	free(element);

	return OK;
}

void supprimerSelonCritere(Liste *liste,
									bool (*critere)(size_t position, const Info *info)) {
	Element *element = liste->tete->suivant;
	size_t position = 0;

	while (element->suivant != NULL) {
		Element *suivant = element->suivant;
		if (critere(position, &element->info)) { // Désassemblage du maillon si critère
			element->precedent->suivant = suivant;
			suivant->precedent = element->precedent;
			free(element);
		}

		element = suivant;
		++position;
	}
}


void vider(Liste *liste, size_t position) {
	if (position < longueur(liste)) {
		Element *element = liste->tete;

		for (size_t i = 0; i < position; ++i) // On se place à la position
			element = element->suivant;

		Element *tmp = element->suivant;
		Element *suivant;

		element->suivant = liste->queue;
		liste->queue->precedent = element;

		while (tmp->suivant != NULL) { // On supprime tous les éléments suivants
			suivant = tmp->suivant;
			free(tmp);
			tmp = suivant;
		}
	}
}

bool sontEgales(const Liste *liste1, const Liste *liste2) {
	if (longueur(liste1) != longueur(liste2))
		return false;

	Element *elementListe1 = liste1->tete->suivant;
	Element *elementListe2 = liste2->tete->suivant;

	while (elementListe1->suivant != NULL && elementListe2->suivant != NULL) {
		if (elementListe1->info != elementListe2->info)
			return false;

		elementListe1 = elementListe1->suivant;
		elementListe2 = elementListe2->suivant;
	}
	return true;
}