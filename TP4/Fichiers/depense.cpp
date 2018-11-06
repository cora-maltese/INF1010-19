/********************************************
* Titre: Travail pratique #4 - depense.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "depense.h"

// Constructeur
Depense::Depense(const string& nom, double montant, const string& lieu) : 
	nom_(nom), 
	montant_(montant), 
	lieu_(new string(lieu))
{}

// Constructeur par copie
Depense::Depense(const Depense& depense) : 
	nom_(depense.nom_), 
	montant_(depense.montant_), 
	lieu_(new string(*depense.lieu_))
{}

// Surcharge de l'operateur =
Depense& Depense::operator=(const Depense& depense) {
	if (this != &depense) {
		delete lieu_;
		nom_ = depense.nom_;
		montant_ = depense.montant_;
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

string* Depense::getLieu() const {
	return lieu_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& nom) {
	*lieu_ = nom;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Depense& depense) {
	os << "- Depense (a " << *depense.lieu_ << ") : "  << depense.nom_ << ". | Prix: " << depense.montant_ << "$" << endl;
	return os;
}
