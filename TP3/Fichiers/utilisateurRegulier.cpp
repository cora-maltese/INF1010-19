#include "utilisateurRegulier.h"

// Constructeur
UtilisateurRegulier::UtilisateurRegulier(const string& nom, TypeUtilisateur type, double interet, bool estGroupe) : Utilisateur(nom, type, interet), estGroupe_(estGroupe)
{}

// Constructeur par copie
UtilisateurRegulier::UtilisateurRegulier(const UtilisateurRegulier& utilisateur) : Utilisateur(utilisateur)
{
	estGroupe_ = utilisateur.estGroupe();
}

/*
// Méthode surcharge de l'opérateur =
UtilisateurRegulier& UtilisateurRegulier::operator=(const Utilisateur& utilisateur)
{
	// TODO: insert return statement here
}
*/

// Getters
bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;
}

// Setters
void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;
}

// Méthode d'affichage
ostream& operator<<(ostream& os, const UtilisateurRegulier& utilisateur)
{
	os << "Utilisateur " << utilisateur.getNom() << " (" << utilisateur.getType() << ") a depense pour un total de : " << utilisateur.getTotalDepenses() << ", PolyCount prend en interet : "
		<< utilisateur.getInteret() << "." << endl;
	if (utilisateur.estGroupe())
		os << "Il fait partie d'un groupe." << endl;
	else
		os << "Il ne fait pas partie d'un groupe." << endl;
	os << "Voici les depenses :" << endl;
	for (unsigned int i = 0; i < utilisateur.getNombreDepenses(); i++) {
		os << "\t\t";
		os << utilisateur.getDepenses()[i];
	}
	return os;
}
