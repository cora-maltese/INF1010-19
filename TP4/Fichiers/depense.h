/********************************************
* Titre: Travail pratique #4 - depense.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeur
	Depense(const string& nom = "", double montant = 0, const string& lieu = "Montreal");

	// Constructeur par copie
	Depense(const Depense& depense);

	// Surcharge de l'operateur =
	Depense& operator=(const Depense& depense);

	// Destructeur
	~Depense();

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string* getLieu() const;

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Depense& depense);

private:
	string nom_;
	double montant_;
	string* lieu_;
};

#endif
