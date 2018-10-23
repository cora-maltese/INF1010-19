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

	// Méthode surcharge de l'opérateur =
	// UtilisateurPremium& operator=(const UtilisateurPremium& utilisateur);

	// Getters
	unsigned int getJoursRestants() const; 
	double getTaux() const; 

	// Setters
	void setJoursRestants(unsigned int joursRestants);

	// Méthode de calcul
	void calculerTaux(); 
	
	// Méthode d'affichage
	friend ostream& operator<<(ostream& os, const UtilisateurPremium& utilisateur);

private: 
	unsigned int joursRestants_; 
	double taux_; 
};

#endif
