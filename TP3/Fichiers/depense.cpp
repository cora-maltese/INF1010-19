#include "depense.h"

// Constructeurs
Depense::Depense(const string& nom, double montant, const string& lieu, TypeDepense type) : nom_(nom), montant_(montant), lieu_(new string(lieu)), type_(type)
{
}

// Constructeur par copie
Depense::Depense(const Depense& depense)
{
	nom_ = depense.getNom();
	montant_ = depense.getMontant();
	lieu_ = new string(*depense.lieu_);
	type_ = depense.getType();
}

/*
// Méthode surcharge de l'opérateur =
Depense& Depense::operator=(const Depense & depense) 
{

}
*/

// Destructeur
Depense::~Depense()
{	
	delete lieu_;
}

// Getters
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() const {
	return lieu_;
}

TypeDepense Depense::getType() const {
	return TypeDepense();
}

// Setters
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& nom) {
	lieu_ = new string(nom);
}

void Depense::setType(TypeDepense type) {
	type_ = type; 
}

// Méthode d'affichage
ostream & operator<<(ostream& os, const Depense& depense)
{
	if (depense.getType() == individuelle) {
		os << "Depense Individuelle - Achat : " << depense.getNom() << " Prix : " << depense.getMontant() << "; " << endl;
	}
	return os;
}
