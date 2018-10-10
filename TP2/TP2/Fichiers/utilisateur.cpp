/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : 
	nom_(""), 
	nombreDepenses_(0) 
{
}

Utilisateur::Utilisateur(const string& nom) : 
	nom_(nom), 
	nombreDepenses_(0) 
{
}

// Constructeur par copie
Utilisateur::Utilisateur(const Utilisateur& utilisateur) {
	nom_ = utilisateur.getNom();
	nombreDepenses_ = utilisateur.getNombreDepense();
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		depenses_[i] = new Depense(*utilisateur.depenses_[i]);
	}
}

// Methode surcharge de l'operateur =
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
		nombreDepenses_ = utilisateur.getNombreDepense();

		//On réalloue l'espace mémoire pour chaque nouveau pointeur
		for (unsigned int i = 0; i < depenses_.size(); i++) {
			depenses_[i] = new Depense(*utilisateur.depenses_[i]);
		}
	}
	return *this;
}

//Destructeur
Utilisateur::~Utilisateur() {
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return nombreDepenses_;
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

vector<Depense*> Utilisateur::getDepenses() const {
	return depenses_;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

/* Ancienne méthode pour ajouter une depense à l'utilisateur
void Utilisateur::ajouterDepense(Depense* depense) {
	if (nombreDepenses_ == tailleTabDepense_) {
		tailleTabDepense_ *= 2;

		Depense** listeTemp = new Depense*[tailleTabDepense_];
		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			listeTemp[i] = depenses_[i];
		}
		delete[] depenses_;

		depenses_ = listeTemp;
	}
	depenses_[nombreDepenses_++] = depense;
}
*/

// Methode surcharge de l'operateur +=
Utilisateur& Utilisateur::operator+=(Depense *uneDepense) {
	depenses_.push_back(uneDepense);
	nombreDepenses_++;
	return *this;
}

/* Ancienne methode d'affichage
void Utilisateur::afficherUtilisateur() const {
	cout << "Utilisateur : " << nom_ << " a depense pour un total de : " << getTotalDepenses() << endl;
	cout << "\t Liste de depenses : " << endl;
	for (int i = 0; i < nombreDepenses_; i++) {
		cout << "\t\t";
		depenses_[i]->afficherDepense();
	}
}*/

// Methode surcharge de l'operateur <<
ostream& operator<<(ostream& os, const Utilisateur &utilisateur) {
	os << "Utilisateur : " << utilisateur.getNom() << " a depense pour un total de : " << utilisateur.getTotalDepenses() << endl;
	os << "\t Liste de depenses : " << endl;
	for (unsigned int i = 0; i < utilisateur.getDepenses().size(); i++) {
		os << "\t\t";
		os << *utilisateur.getDepenses()[i];
	}
	return os;
}
