#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include "depenseGroupe.h"
#include "depense.h"

using namespace std;

const double TAUX_REGULIER = 0.05;
enum TypeUtilisateur {Regulier, Premium};

class Utilisateur {
public:
	// Constructeur
	Utilisateur(const string& nom = "", TypeUtilisateur type = Regulier, double interet = 0.0);

	// Constructeur par copie
	Utilisateur(const Utilisateur& utilisateur);

	// Méthode surcharge de l'opérateur =
	Utilisateur& operator=(const Utilisateur& utilisateur);

	// Destructeur
	~Utilisateur(); 

	// Getters
	string getNom() const;
	double getInteret() const; 
	TypeUtilisateur getType() const;
	double getTotalDepenses() const;
	vector<Depense*> getDepenses() const; 
	unsigned int getNombreDepenses() const; 

	// Méthodes de modifications
	void setNom(const string& nom);
	void ajouterInteret(double montant);
	void calculerTotalDepenses();
	Utilisateur& operator+=(Depense* depense);
	
	// Méthode d'affichage
	friend ostream& operator<<(ostream& os, const Utilisateur& user);

private:
	string nom_;
	double interet_;
	TypeUtilisateur type_; 
	vector <Depense*> depenses_;
	double totalDepenses_; 
};

#endif
