#ifndef DEPENSE_GROUPE_H
#define DEPENSE_GROUPE_H

#include "depense.h"

#include <vector>

using namespace std; 

class DepenseGroupe : public Depense {
public:
	// Constructeur
	DepenseGroupe(const string& nom = "", double montant = 0, const string& lieu = "Montreal", TypeDepense type = groupe, unsigned int nombreParticipants = 0);

	// Constructeur par copie
	DepenseGroupe(const DepenseGroupe& depense); 

	// Getters
	unsigned int getNombreParticipants() const; 
	double getMontantPersonnel() const;

	// Setters
	void setNombreParticipants(unsigned int nombre); 

	// Méthode d'affichage
	friend ostream& operator<<(ostream& os, const DepenseGroupe& depense);

private : 
	unsigned int nombreParticipants_; 
};

#endif
