/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>

#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);

	// TODO: Ajouter un constructeur par copie
	Utilisateur(const Utilisateur& utilisateur);

	// Surcharge de l'operateur =
	Utilisateur& operator=(const Utilisateur& utilisateur);

	// Destructeur
	~Utilisateur();

	// Methodes d'accès
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;

	// Getter pour le nouvel attribut vecteur des dépenses
	vector<Depense*> getDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// void ajouterDepense(Depense* uneDepense);
	// Surcharge de l'operateur += pour remplacer ajouterDepense
	Utilisateur& operator+=(Depense *uneDepense);

	// TODO: Remplacer par une surcharge de l'operateur <<
	// void afficherUtilisateur() const;
	friend ostream& operator<<(ostream& os, const Utilisateur&);

private:
	string nom_;
	// TODO: Remplacer depenses_ par un vecteur
	unsigned int nombreDepenses_;
	vector<Depense*> depenses_;
};

#endif
