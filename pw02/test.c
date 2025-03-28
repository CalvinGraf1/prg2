/*
 -----------------------------------------------------------------------------------
 Nom du fichier : test.c
 Auteur(s)      : Alan Sottile, Calvin Graf, Lucas Hussain
 Date creation  : 27.04.2023

 Description    : Programme de test pour vérifier que toutes les fonctions de
                  la librairie "listes_dynamiques.h" fonctionnent correctement

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "listes_dynamiques.h"

#define MSG_OK printf("Resultat : OK\n")
#define MSG_KO printf("Resultat : KO !\n")
#define AFFICHAGE(liste) do {          \
afficher(liste, FORWARD);              \
printf(" L: %zu\n", longueur(liste));  \
} while(false)                         \

#define AFFICHAGE_INVERSE(liste) do {  \
afficher(liste, BACKWARD);             \
printf(" L: %zu\n", longueur(liste));  \
} while(false)                         \

/// \brief Compare l'information avec 2
/// \param position Position de l'élément à tester
/// \param info Pointeur vers l'information à tester
/// \return true si l'information est égale à 2, false sinon
bool infoEgalADeux(size_t position, const Info *info);

/// \brief Compare la position avec l'element donné si elle est impaire
/// \param position Position de l'élément à tester
/// \param info Pointeur vers l'information à tester
/// \return true si la position est impaire, false sinon
bool positionImpair(size_t position, const Info *info);

/// \brief Peuple la liste de 0 à nombreElement
/// \param liste Liste à peupler
/// \param nombreElement Nombre d'éléments à ajouter
void peuplementListe(Liste *liste, int nombreElement);

/// \brief Verification fonctionnalité de la fonction afficher
void testAfficher();

/// \brief Verification fonctionnalité de la fonction insererEnTete
/// \param info Information a inserer
void testInsererEnTete(Info info);

/// \brief Verification fonctionnalité de la fonction insererEnQueue
/// \param info Information a inserer
void testInsererEnQueue(Info info);

/// \brief Verification fonctionnalité de la fonction supprimerEnTete
void testSupprimerEnTete();

/// \brief Verification fonctionnalité de la fonction supprimerEnQueue
void testSupprimerEnQueue();

/// \brief Verification fonctionnalité de la fonction estVide
void testEstVide();

/// \brief Verification fonctionnalité de la fonction longueur
void testLongueur();

/// \brief Verification fonctionnalité de la fonction vider
void testVider(size_t position);

/// \brief Verification fonctionnalité de la fonction sontEgales
void testSontEgales();

/// \brief Verification fonctionnalité de la fonction supprimerSelonCritere
void testSupprimerSelonCritere();

int main() {
	printf("INFOS : Longueur de la liste = L\n");

	printf("\n=================== Debut des tests ===================\n");

	testAfficher();
	testInsererEnTete(2);
	testInsererEnQueue(2);
	testSupprimerEnTete();
	testSupprimerEnQueue();
	testEstVide();
	testLongueur();
	testVider(2);
	testSontEgales();
	testSupprimerSelonCritere();

	printf("\n==================== Fin des tests ====================\n");

	return EXIT_SUCCESS;
}

bool infoEgalADeux(size_t position __attribute__((unused)), const Info *info) {
	return *info == 2;
}

bool positionImpair(size_t position, const Info *info __attribute__((unused))) {
	return position % 2;
}

void peuplementListe(Liste *liste, int nombreElement) {
	for (int i = 0; i < nombreElement; ++i)
		insererEnQueue(liste, &i);
}

void testAfficher() {
	printf("\n------------ Test de la fonction : afficher -----------\n");

	Liste *liste = initialiser();
	peuplementListe(liste, 10);

	printf("\nAffichage liste de gauche a droite :\n");
	AFFICHAGE(liste);

	printf("\nAffichage liste de droite a gauche :\n");
	AFFICHAGE_INVERSE(liste);
}

void testInsererEnTete(Info info) {
	Status status;

	Liste *liste = initialiser();
	peuplementListe(liste, 10);

	Liste *listeVide = initialiser();

	printf("\n--------- Test de la fonction : insererEnTete ---------\n");

	// Test 1
	printf("\nInsertion de %d dans une liste vide :\n", info);
	status = insererEnTete(listeVide, &info);
	AFFICHAGE(listeVide);
	(listeVide->tete->suivant->info == 2 && status == OK) ? MSG_OK : MSG_KO;

	// Test 2
	printf("\nInsertion de %d dans une liste non vide (0-9) :\n", info);
	status = insererEnTete(liste, &info);
	AFFICHAGE(liste);
	(liste->tete->suivant->info == 2 && status == OK) ? MSG_OK : MSG_KO;

	// Test 3
	info = INT_MAX;
	printf("\nInsertion de INT_MAX (%d) dans une liste non vide :\n", info);
	status = insererEnTete(liste, &info);
	AFFICHAGE(liste);
	(liste->tete->suivant->info == INT_MAX && status == OK) ? MSG_OK : MSG_KO;
}

void testInsererEnQueue(Info info) {
	Status status;

	Liste *liste = initialiser();
	peuplementListe(liste, 10);

	Liste *listeVide = initialiser();

	printf("\n--------- Test de la fonction : insererEnQueue --------\n");

	// Test 1
	printf("\nInsertion de %d dans une liste vide :\n", info);
	status = insererEnQueue(listeVide, &info);
	AFFICHAGE(listeVide);
	(listeVide->queue->precedent->info == 2 && status == OK) ? MSG_OK : MSG_KO;

	// Test 2
	printf("\nInsertion de %d dans une liste non vide (0-9) :\n", info);
	status = insererEnQueue(liste, &info);
	AFFICHAGE(liste);
	(listeVide->queue->precedent->info == 2 && status == OK) ? MSG_OK : MSG_KO;

	// Test 3
	info = INT_MAX;
	printf("\nInsertion de INT_MAX (%d) dans une liste non vide :\n", info);
	status = insererEnQueue(liste, &info);
	AFFICHAGE(liste);
	(liste->queue->precedent->info == INT_MAX && status == OK) ? MSG_OK : MSG_KO;
}

void testSupprimerEnTete() {
	Status status;
	Info elementSupprime;

	Liste *liste = initialiser();
	peuplementListe(liste, 10);

	Liste *listeVide = initialiser();

	printf("\n-------- Test de la fonction : supprimerEnTete --------\n");

	// Test 1
	printf("\nSuppression en tete dans une liste vide :\n");
	supprimerEnTete(listeVide, &elementSupprime) == LISTE_VIDE ? MSG_OK : MSG_KO;

	// Test 2
	printf("\nSuppression en tete dans une liste non vide (0-9) :\n");
	status = supprimerEnTete(liste, &elementSupprime);
	AFFICHAGE(liste);
	printf("Element supprime : %d\n", elementSupprime);
	(liste->tete->suivant->info == 1 && status == OK) ? MSG_OK : MSG_KO;
}

void testSupprimerEnQueue() {
	Status status;
	Info elementSupprime;

	Liste *liste = initialiser();
	peuplementListe(liste, 10);

	Liste *listeVide = initialiser();

	printf("\n-------- Test de la fonction : supprimerEnQueue -------\n");

	// Test 1
	printf("\nSuppression en queue dans une liste vide :\n");
	supprimerEnQueue(listeVide, &elementSupprime) == LISTE_VIDE ? MSG_OK : MSG_KO;

	// Test 2
	printf("\nSuppression en queue dans une liste non vide (0-9) :\n");
	status = supprimerEnQueue(liste, &elementSupprime);
	AFFICHAGE(liste);
	printf("Element supprime : %d\n", elementSupprime);
	(liste->queue->precedent->info == 8 && status == OK) ? MSG_OK : MSG_KO;
}

void testEstVide() {
	Liste *liste = initialiser();
	int i = 1;
	insererEnQueue(liste, &i);

	Liste *listeVide = initialiser();

	printf("\n------------ Test de la fonction : estVide ------------\n");

	// Test 1
	AFFICHAGE(liste);
	printf("Liste non vide, vide ? %s\n", estVide(liste) ? "true" : "false");
	!(estVide(liste)) ? MSG_OK : MSG_KO;

	// Test 2
	AFFICHAGE(listeVide);
	printf("Liste vide, vide ? %s\n", estVide(listeVide) ? "true" : "false");
	estVide(listeVide) ? MSG_OK : MSG_KO;
}

void testLongueur() {
	printf("\n------------ Test de la fonction : longueur -----------\n");

	// Test 1
	printf("\nLongueur d'une liste de 10 millions d'elements :\n");
	Liste *liste = initialiser();
	peuplementListe(liste, 10000000);
	longueur(liste) == 10000000 ? MSG_OK : MSG_KO;

	// Test 2
	printf("\nLongueur d'une liste vide :\n");
	Liste *listeVide = initialiser();
	longueur(listeVide) == 0 ? MSG_OK : MSG_KO;
}

void testVider(size_t position) {
	printf("\n------------- Test de la fonction : vider -------------\n");

	// Test 1
	printf("\nVider une liste (0-9) a partir de la position %zu :\n", position);
	Liste *liste = initialiser();
	peuplementListe(liste, 10);
	vider(liste, position);
	AFFICHAGE(liste);
	longueur(liste) <= position ? MSG_OK : MSG_KO;

	// Test 2
	printf("\nVider une liste vide :\n");
	Liste *listeVide = initialiser();
	vider(listeVide, 0);
	longueur(listeVide) == 0 ? MSG_OK : MSG_KO;

	// Test 3
	printf("\nVider completement une liste d'1 million d'elements :\n");
	Liste *listeMillion = initialiser();
	peuplementListe(listeMillion, 1000000);
	vider(listeMillion, 0);
	longueur(listeMillion) == 0 ? MSG_OK : MSG_KO;
}

void testSontEgales() {
	printf("\n----------- Test de la fonction : sontEgales ----------\n");

	// Test 1
	printf("\nEgalite de deux listes vides :\n");
	Liste *liste1 = initialiser();
	Liste *liste2 = initialiser();
	sontEgales(liste1, liste2) ? MSG_OK : MSG_KO;

	// Test 2
	printf("\nEgalite de deux memes listes :\n");
	for (int i = 0; i < 10; ++i) {
		insererEnQueue(liste1, &i);
		insererEnQueue(liste2, &i);
	}
	sontEgales(liste1, liste2) ? MSG_OK : MSG_KO;

	// Test 3
	printf("\nEgalite de deux listes differentes :\n");
	int i = 1;
	insererEnQueue(liste1, &i);
	sontEgales(liste1, liste2) ? MSG_KO : MSG_OK;
}

void testSupprimerSelonCritere() {
	printf("\n----- Test de la fonction : supprimerSelonCritere -----\n");

	Liste *liste = initialiser();
	peuplementListe(liste, 10);

	// Test 1
	printf("\nSuppression selon critere info==2, liste (0-9) :\n");
	supprimerSelonCritere(liste, infoEgalADeux);
	AFFICHAGE(liste);

	// Test 2
	printf("\nSuppression selon critere position impair, liste (0-9) :\n");
	supprimerSelonCritere(liste, positionImpair);
	AFFICHAGE(liste);
}