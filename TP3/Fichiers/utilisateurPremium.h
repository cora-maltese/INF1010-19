#ifndef UTILISATEUR_PREMIUM_H
#define UTILISATEUR_PREMIUM_H

#include "utilisateur.h"
using namespace std;

class UtilisateurPremium : public Utilisateur {
public:
	// Constructeur
	UtilisateurPremium(const string& nom = "", unsigned int joursRestants = 30, double taux = 0.05);

	// Constructeur par copie
	UtilisateurPremium(const UtilisateurPremium& utilisateur); 

	// M�thode surcharge de l'op�rateur =
	// UtilisateurPremium& operator=(const UtilisateurPremium& utilisateur);

	// Getters
	unsigned int getJoursRestants() const; 
	double getTaux() const; 

	// Setters
	void setJoursRestants(unsigned int joursRestants);

	// M�thode de calcul
	void calculerTaux(); 
	
	// M�thode d'affichage
	friend ostream& operator<<(ostream& os, const UtilisateurPremium& utilisateur);

private: 
	unsigned int joursRestants_; 
	double taux_; 
};

#endif
