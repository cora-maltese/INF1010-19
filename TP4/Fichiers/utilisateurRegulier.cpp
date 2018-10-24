/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom, MethodePaiement methodePaiement, const string & courriel, const string & idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), possedeGroupe_(false)
{}

bool UtilisateurRegulier::getPossedeGroupe() const {
	return possedeGroupe_;
}

void UtilisateurRegulier::setPossedeGroupe(bool possedeGroupe) {
	possedeGroupe_ = possedeGroupe;
}

void UtilisateurRegulier::print(ostream& os) const {
	os << "Utilisateur (Regulier, dans un groupe) " << nom_ << " :" << endl;
	os << "\t\tTotal a payer: " << balanceTransferts_ << "$ (et " << balanceFrais_ << "$ de frais)" << endl;
	os << "\t\tListe des depenses : " << endl;
	for (size_t i = 0; i < depenses_.size(); i++) {
		os << "\t\t\t" << *depenses_[i];
	}
	os << endl;
}
