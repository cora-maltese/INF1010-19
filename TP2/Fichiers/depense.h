/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	// TODO: Ajouter le lieu dans les constructeurs
	Depense();
	Depense(const string& nom, double montant, const string& lieu);

	// TODO: Ajouter un constructeur par copie
	Depense(const Depense &depense);

	// TODO: Ajouter une surcharge de l'operateur =
	Depense& operator=(const Depense& depense);

	// Destructeur
	~Depense();

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(string lieu);

	// TODO: Remplacer par une surcharge de l'operateur <<
	// void afficherDepense() const;
	friend ostream& operator<<(ostream& os, const Depense&);

private:
	string nom_;
	double montant_;
	// TODO: Ajouter l'attribut lieu
	string* lieu_;
};

#endif
