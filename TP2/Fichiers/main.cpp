/********************************************
* Titre: Travail pratique #2 - main.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include <iostream>
#include "depense.h";
#include "utilisateur.h"
#include "transfert.h"
#include "groupe.h"

using namespace std;

int main() {

	/* REPONSES AUX QUESTIONS :
	1) Quelle est l'utilité de l'opérateur = et du constructeur par copie ?

	Il existe un constructeur par copie et un opérateur = par défaut. Néanmoins, ceux-ci ne font que copier les valeurs des attributs de l'objet "source" dans les attributs
	de l'objet "destination". Cela pose un problème quand l'objet fait de l'allocation dynamique, CAD quand il contient des attributs qui sont des pointeurs.
	Le nouvel objet aura donc ses attributs qui pointeront vers les mêmes espaces mémoire. À la fin du programme, quand le destructeur de l'objet source sera appelé,
	l'espace mémoire sera libéré, puis le destructeur de l'objet destination sera appelé à son tour. Cela causera alors une erreur d'execution dans notre programme et 
	des probables fuites de mémoire.

	L'utilité de déclarer un constructeur par copie et de surcharger l'opérateur d'assignation est donc d'éviter ces problèmes là.

	2) Qu'est-ce qui différentie l'opérateur = du constructeur par copie ?

	Le code est un peu plus compliqué pour la surcharge de l'opérateur =. En fait il reprend le code du constructeur par copie et du destructeur.
	De plus, on gère en effet l'auto-affectation et les appels en cascade avec le code de l'opérateur =.

	*/

	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************************" << endl;

	// Initialisation des depenses
	Depense* d1 = new Depense("d1", 12, "IGA");
	Depense* d2 = new Depense("d2", 11, "Provigo");
	Depense* d3 = new Depense("d3", 5, "Jean-Drapeau");
	Depense* d4 = new Depense("d4", 23, "Vieux Port");
	Depense* d5 = new Depense("d5", 17, "Metro");
	Depense* d6 = new Depense("d6", 29, "Desjardins");

	// Exemple d'utilisation du constructeur par copie et de l'operateur d'assignation
	Depense* d7 = new Depense(*d5);
	d7->setNom("d7");
	d7->setLieu("Maisonnee");

	Depense* d8 = new Depense();
	*d8 = *d1;
	d8->setNom("d8");
	d8->setLieu("Banque Scotia");

	// Initialisation des utilisateurs
	Utilisateur* u1 = new Utilisateur("Martin");
	Utilisateur* u2 = new Utilisateur("Franklin");
	Utilisateur* u3 = new Utilisateur("Geraldine");
	Utilisateur* u4 = new Utilisateur("Bernard");

	//Exemple d'utilisation de l'operateur d'assignation
	Utilisateur* u5 = new Utilisateur();
	*u5 = *u1;
	u5->setNom("Christian");

	// Initialisation du groupe
	Groupe* groupe = new Groupe("Vacances");

	// Ajout des utilisateurs et des depenses au groupe
	((((*groupe += u1) += u2) += u3) += u4) += u5;

	groupe->ajouterDepense(d1, u1).ajouterDepense(d2, u1).ajouterDepense(d3, u2).ajouterDepense(d4, u3).ajouterDepense(d5, u4)
		.ajouterDepense(d6, u5).ajouterDepense(d7, u3).ajouterDepense(d8, u4);

	// Affichage
	cout << *groupe;

	// Equilibrage des comptes
	groupe->equilibrerComptes();

	// Affichage
	cout << *groupe;

	system("pause");
	return 0;
}
