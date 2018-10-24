/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurPremium.h"

UtilisateurPremium::UtilisateurPremium(const string& nom, MethodePaiement methodePaiement, unsigned int joursRestants, const string& courriel, const string& idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), joursRestants_(joursRestants)
{}

unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

void UtilisateurPremium::print(ostream& os) const {
	if (joursRestants_ == 0) {
		os << "Erreur : l'utilisateur " << nom_ << " doit renouveler son abonnement Premium." << endl;
	}
	else {
		os << "Utilisateur (Premium) " << nom_ << " :" << endl;
		// PC : peut-être corriger l'affichage "3$ ou -3$ economisés"
		// balanceFrais_ est négatif de toute manière pour un utilisateur Premium, donc pas besoin de if, juste faire une nouvelle string pour l'affichage
		// string balanceFraisPourAffichage;
		double opposeBalanceFrais = 0 - balanceFrais_;
		os << "\t\tTotal a payer: " << balanceTransferts_ << "$ (" << balanceFrais_ << "$ economises)" << endl;
		os << "\t\tJours restants: " << joursRestants_ << endl;
		os << "\t\tListe des depenses : " << endl;
		for (size_t i = 0; i < depenses_.size(); i++) {
			os << "\t\t\t" << *depenses_[i];
		}
		os << endl;
	}
}
