#include "transfert.h"

// Constructeur par défaut
Transfert::Transfert()
{
	montant_ = 0.0;
	donneur_ = nullptr;
	receveur_ = nullptr;
}

// Constructeur par paramètres
Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour)
{
	montant_ = montant;
	donneur_ = de;
	receveur_ = pour;
}

// Getters
double Transfert::getMontant() const 
{
	return montant_;
}

Utilisateur* Transfert::getDonneur() const
{
	return donneur_;
}

Utilisateur* Transfert::getReceveur() const
{
	return receveur_;
}

// Setters
void Transfert::setMontant(double montant)
{
	montant_ = montant;
}

void Transfert::setDonneur(Utilisateur* donneur)
{
	donneur_ = donneur;
}

void Transfert::setReceveur(Utilisateur* receveur)
{
	receveur_ = receveur;
}

// Méthode d'affichage
void Transfert::afficherTransfert()
{
	cout << "Transfert effectue par " << this->getDonneur()->getNom() << " pour " << this->getReceveur()->getNom() << " d'un montant de " << this->getMontant() << endl;
}