/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"

// Constructeurs
Depense::Depense() : 
	nom_(""), 
	montant_(0),
	lieu_(nullptr)
{
}

Depense::Depense(const string& nom, double montant, const string& lieu) :
	nom_(nom),
	montant_(montant),
	lieu_(new string(lieu))
{
}

// Constructeur par copie
Depense::Depense(const Depense& depense) {
	nom_ = depense.getNom();
	montant_ = depense.getMontant();
	lieu_ = new string(*depense.lieu_);
}

// Methode surcharge de l'operateur =
Depense& Depense::operator=(const Depense& depense)
{
	if (this != &depense)
	{
		delete lieu_;
		nom_ = depense.getNom();
		montant_ = depense.getMontant();
		lieu_ = new string(*depense.lieu_);
	}
	return *this;
}

// Destructeur
Depense::~Depense() {
	delete lieu_;
	lieu_ = nullptr;
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(string lieu) {
	lieu_ = &lieu;
}

/*// Methode d'affichage
void Depense::afficherDepense() const {
	cout << "Achat : " << nom_ << " Prix : " << montant_ << "; " << endl;
}*/

// Methode surcharge de l'operateur <<
ostream& operator<<(ostream& os, const Depense &depense) {
	os << "Achat : " << depense.getNom() << " Prix : " << depense.getMontant() << "; " << endl;
	return os;
}
