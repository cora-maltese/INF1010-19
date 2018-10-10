#include "depense.h"

// Constructeur par d�faut
Depense::Depense()
{
	titre_ = "unknown";
	montant_ = 0.0;
}

// Constructeur par param�tres
Depense::Depense(string& titre, double montant)
{
	titre_ = titre;
	montant_ = montant;
}

// Getters
string Depense::getTitre() const
{
	return titre_;
}

double Depense::getMontant() const
{
	return montant_;
}

// Setters
void Depense::setTitre(string& titre)
{
	titre_ = titre;
}

void Depense::setMontant(double montant)
{
	montant_ = montant;
}

// M�thode d'affichage
void Depense::afficherDepense()
{
	cout << "Depense : " << this->getTitre() << " - Montant : " << this->getMontant() << ";" << endl;
}
