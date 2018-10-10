/**
 * INF1010 - Programmation orientée-objet : TP1
 * Auteurs : Paul Corrand (1886657) et Thierry Larouche (1849329)
 * Date : 24 septembre 2018
 */


#include <iostream>
#include "groupe.h"

using namespace std; 

int main(int argc, const char * argv[]) {
    cout << "******* Bienvenue sur PolyCount *******" << endl << "***************************************" << endl << endl;

    // Créer un  groupe pour  6 depenses et 4 utilisateurs
	string nomGroupe = "Barcelone";
	Groupe barcelone(nomGroupe, 6, 4);

    // Créer 5 utilisateurs
	string nomU1 = "Mark";
	string nomU2 = "Paul";
	string nomU3 = "Quentin";
	string nomU4 = "Julie";
	string nomU5 = "Sophie";

	Utilisateur* u1Mark = new Utilisateur(nomU1);
	Utilisateur* u2Paul = new Utilisateur(nomU2);
	Utilisateur* u3Quentin = new Utilisateur(nomU3);
	Utilisateur* u4Julie = new Utilisateur(nomU4);
	Utilisateur* u5Sophie = new Utilisateur(nomU5);
    
    // Créer 7 dépenses
	string nomD1 = "Pizzeria";
	string nomD2 = "Location voiture";
	string nomD3 = "Theatre";
	string nomD4 = "Cinema";
	string nomD5 = "Souvenirs";
	string nomD6 = "Essence";
	string nomD7 = "Nightclub";

	Depense* d1Pizzeria = new Depense(nomD1, 200);
	Depense* d2Location = new Depense(nomD2, 10);
	Depense* d3Theatre = new Depense(nomD3, 50);
	Depense* d4Cine = new Depense(nomD4, 50);
	Depense* d5Souvenirs = new Depense(nomD5, 200);
	Depense* d6Essence = new Depense(nomD6, 50);
	Depense* d7Nightclub = new Depense(nomD7, 60);
    
    // Ajouter les utilisateurs au groupe
	barcelone.ajouterUtilisateur(u1Mark);
	barcelone.ajouterUtilisateur(u2Paul);
	barcelone.ajouterUtilisateur(u3Quentin);
	barcelone.ajouterUtilisateur(u4Julie);
	barcelone.ajouterUtilisateur(u5Sophie);

    // Ajouter les depenses au groupe
	barcelone.ajouterDepense(d1Pizzeria, u1Mark);
	barcelone.ajouterDepense(d2Location, u2Paul);
	barcelone.ajouterDepense(d3Theatre, u3Quentin);
	barcelone.ajouterDepense(d4Cine, u4Julie);
	barcelone.ajouterDepense(d5Souvenirs, u5Sophie);
	barcelone.ajouterDepense(d6Essence, u1Mark);
	barcelone.ajouterDepense(d7Nightclub, u1Mark);
    
    // Calculer le total du groupe et de chaque utilisateur
	barcelone.calculerTotalDepenses();

    // Afficher  le groupe
	barcelone.afficherGroupe();
 
    // Equilibrer les comptes
	barcelone.equilibrerComptes();

    // Terminer le programme correctement
	delete u1Mark;
	delete u2Paul;
	delete u3Quentin;
	delete u4Julie;
	delete u5Sophie;

	delete d1Pizzeria;
	delete d2Location;
	delete d3Theatre;
	delete d4Cine;
	delete d5Souvenirs;
	delete d6Essence;
	delete d7Nightclub;

	barcelone.~Groupe();

	return 0;
}


/********************** 
Réponses aux questions :

1. 
Agrégation (par pointeur) car Groupe a pour attribut un tableau dynamique contenant des pointeurs de Transfert. 
Si on supprime l'instance du Groupe alors que des transferts d'argent ont eu lieu entre les utilisateurs, 

2. Certaines méthodes ne doivent pas effectuer de modifications sur les attributs de l'objet (comme les getters par exemple).
On ajoute donc le mot-clé const à certaines méthodes pour signaler au compilateur de renvoyer un code d'erreur si jamais la méthode essaye de modifier l'attribut.

***********************/
