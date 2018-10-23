#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>
using namespace std;

enum TypeDepense {groupe, individuelle};

class Depense {
public:
	// Constructeurs
	Depense(const string& nom = "", double montant = 0, const string& lieu = "Montreal", TypeDepense type = individuelle);

	// Constructeur par copie
	Depense(const Depense& depense);

	// M�thode surcharge de l'op�rateur =
	// Depense& operator=(const Depense& depense);

	// Destructeur 
	~Depense();

	// Getters
	string getNom() const;
	double getMontant() const;
	string* getLieu() const;
	TypeDepense getType() const;

	// Setters
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);
	void setType(TypeDepense type); 
	
	// M�thode d'affichage
	friend ostream& operator<<(ostream& os, const Depense& depense);

private:
	string nom_;
	double montant_;
	string* lieu_;
	TypeDepense type_;
};

#endif
