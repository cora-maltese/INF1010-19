#ifndef UTILISATEUR_REGULIER_H
#define UTILISATEUR_REGULIER_H

#include "utilisateur.h"
using namespace std;

class UtilisateurRegulier : public Utilisateur {
public : 
	// Constructeur
	UtilisateurRegulier(const string& nom = "", TypeUtilisateur type = Regulier, double interet = TAUX_REGULIER, bool estGroupe = false);

	// Constructeur par copie
	UtilisateurRegulier(const UtilisateurRegulier& utilisateur); 

	// M�thode surcharge de l'op�rateur =
	// UtilisateurRegulier& operator=(const UtilisateurRegulier& utilisateur);

	// Getters
	bool estGroupe() const; 
	 
	// Setters
	void setEtatGroupe(bool etat); 
	
	// M�thode d'affichage
	friend ostream& operator<<(ostream& os, const UtilisateurRegulier& utilisateur); 

private :
	bool estGroupe_; 
};

#endif
