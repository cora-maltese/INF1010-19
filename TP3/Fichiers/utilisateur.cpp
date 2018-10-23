#include "utilisateur.h"

// Constructeur
Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type, double interet) : nom_(nom), type_(type), interet_(interet)
{}

// Constructeur par copie
Utilisateur::Utilisateur(const Utilisateur& utilisateur)
{
	nom_ = utilisateur.getNom();
	interet_ = utilisateur.getInteret();
	type_ = utilisateur.getType();
	totalDepenses_ = utilisateur.getTotalDepenses();
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		depenses_[i] = new Depense(*utilisateur.depenses_[i]);
	}
}

// Méthode surcharge de l'opérateur =
Utilisateur& Utilisateur::operator=(const Utilisateur& utilisateur)
{
	if (this != &utilisateur)
	{
		//On désalloue l'espace mémoire de chaque pointeur contenu dans le vecteur de l'objet courant.
		for (unsigned int i = 0; i < depenses_.size(); i++) {
			delete depenses_[i];
			depenses_[i] = nullptr;
		}

		nom_ = utilisateur.getNom();
		interet_ = utilisateur.getInteret();
		type_ = utilisateur.getType();
		totalDepenses_ = utilisateur.getTotalDepenses();

		//On réalloue l'espace mémoire pour chaque nouveau pointeur.
		for (unsigned int i = 0; i < depenses_.size(); i++) {
			depenses_[i] = new Depense(*utilisateur.depenses_[i]);
		}
	}
	return *this;
}

// Destructeur
Utilisateur::~Utilisateur()
{
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
}


// Getters
string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getInteret() const {
	return interet_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_;
}

double Utilisateur::getTotalDepenses() const {
	return totalDepenses_;
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_;
}

unsigned int Utilisateur::getNombreDepenses() const {
	return depenses_.size();
}


// Méthodes de modifications
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::calculerTotalDepenses() {
	totalDepenses_ = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		totalDepenses_ += depenses_[i]->getMontant();
	}
}

void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}


// Méthode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur) {
	os << "Utilisateur " << utilisateur.getNom() << " (" << utilisateur.getType() << ") a depense pour un total de : " << utilisateur.getTotalDepenses() << ", PolyCount prend en interet : "
		<< utilisateur.getInteret() << ". Voici les depenses :" << endl;
	for (unsigned int i = 0; i < utilisateur.getNombreDepenses(); i++) {
		os << "\t\t";
		os << *utilisateur.getDepenses()[i];
	}
	return os;
}
