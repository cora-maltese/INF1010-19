/********************************************
* Titre: Travail pratique #4 - transfertInterac.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertInterac.h"

TransfertInterac::TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	Transfert(montant, expediteur, receveur), 
	courriel_(receveur->getCourriel())
{}

string TransfertInterac::getCourriel() const {
	return courriel_;
}

void TransfertInterac::setcourriel(string courriel) {
	courriel_ = courriel;
}

double TransfertInterac::getFraisTransfert() const {
	if (typeid(*expediteur_) == typeid(UtilisateurPremium))
		return 0;
	else
		return 1.0;
}
