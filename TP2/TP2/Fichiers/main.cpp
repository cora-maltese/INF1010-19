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
	1) Quelle est l'utilit� de l'op�rateur = et du constructeur par copie ?

	Il existe un constructeur par copie et un op�rateur = par d�faut. N�anmoins, ceux-ci ne font que copier les valeurs des attributs de l'objet "source" dans les attributs
	de l'objet "destination". Cela pose un probl�me quand l'objet fait de l'allocation dynamique, CAD quand il contient des attributs qui sont des pointeurs.
	Le nouvel objet aura donc ses attributs qui pointeront vers les m�mes espaces m�moire. � la fin du programme, quand le destructeur de l'objet source sera appel�,
	l'espace m�moire sera lib�r�, puis le destructeur de l'objet destination sera appel� � son tour. Cela causera alors une erreur d'execution dans notre programme et 
	des probables fuites de m�moire.

	L'utilit� de d�clarer un constructeur par copie et de surcharger l'op�rateur d'assignation est donc d'�viter ces probl�mes l�.

	2) Qu'est-ce qui diff�rentie l'op�rateur = du constructeur par copie ?

	Le code est un peu plus compliqu� pour la surcharge de l'op�rateur =. En fait il reprend le code du constructeur par copie et du destructeur.
	De plus, on g�re en effet l'auto-affectation et les appels en cascade avec le code de l'op�rateur =.

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
