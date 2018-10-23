#include "utilisateurPremium.h"

// Constructeur
UtilisateurPremium::UtilisateurPremium(const string& nom, unsigned int jourRestants, double taux) : Utilisateur(nom), joursRestants_(jourRestants), taux_(taux)
{}

// Constructeur par copie
UtilisateurPremium::UtilisateurPremium(const UtilisateurPremium& utilisateur) : Utilisateur(utilisateur)
{
	taux_ = utilisateur.getTaux();
	joursRestants_ = utilisateur.getJoursRestants();
}

/*
// Méthode surcharge de l'opérateur =
UtilisateurPremium& UtilisateurPremium::operator=(const UtilisateurPremium& utilisateur)
{
	if (this != &utilisateur)
	{
		//On désalloue l'espace mémoire de chaque pointeur contenu dans le vecteur de l'objet courant.
		for (unsigned int i = 0; i < this->getNombreDepenses(); i++) {
			delete this->getDepenses()[i];
			this->getDepenses()[i] = nullptr;
		}

		this->getNom() = utilisateur.getNom();
		interet_ = utilisateur.getInteret();
		this->getType() = utilisateur.getType();
		this->getTotalDepenses() = utilisateur.getTotalDepenses();

		//On réalloue l'espace mémoire pour chaque nouveau pointeur.
		for (unsigned int i = 0; i < depenses_.size(); i++) {
			depenses_[i] = new Depense(*utilisateur.depenses_[i]);
		}
	}
	return *this;
}*/


// Getters
unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

double UtilisateurPremium::getTaux() const {
	return taux_;
}


// Setters
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants)
{
	joursRestants_ = joursRestants;
	if (joursRestants_ == 0)
		cout << "Erreur : L'utilisateur " << this->getNom() << " doit renouveler son abonnement Premium." << endl;
}

// Méthode de calcul
void UtilisateurPremium::calculerTaux()
{
	int indice = this->getNombreDepenses()/2;
	indice = static_cast<double>(indice);
	indice = indice / 100;
	cout << "INDICE EST " << indice << endl;
	if (indice <= 0.05)
		taux_ -= indice;
	else
		taux_ = 0;
}


// Méthode d'affichage
ostream & operator<<(ostream & os, const UtilisateurPremium& utilisateur)
{
	os << "Utilisateur " << utilisateur.getNom() << " (" << utilisateur.getType() << ") a depense pour un total de : " << utilisateur.getTotalDepenses() << ", PolyCount prend en interet : "
		<< utilisateur.getTaux() << ". Voici les depenses :" << endl;
	os << "Il vous reste " << utilisateur.getJoursRestants() << " jour(s) dans votre abonnement." << endl;
	for (unsigned int i = 0; i < utilisateur.getNombreDepenses(); i++) {
		os << "\t\t";
		os << *utilisateur.getDepenses()[i];
	}
	return os;
}
