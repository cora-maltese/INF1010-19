/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :
	nom_(""),
	nombreDepenses_(0),
	nombreUtilisateurs_(0),
	nombreTransferts_(0)
{
}

Groupe::Groupe(const string& nom) :
	nom_(nom),
	nombreDepenses_(0),
	nombreUtilisateurs_(0),
	nombreTransferts_(0)
{
}

//Destructeur
Groupe::~Groupe() {
	for (unsigned int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
		transferts_[i] = nullptr;
	}

	for (unsigned int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}

	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		delete utilisateurs_[i];
		utilisateurs_[i] = nullptr;
	}
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return nombreDepenses_;
}

double Groupe::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Nouvelle méthode pour ajouter une dépense au groupe
Groupe& Groupe::ajouterDepense(Depense *depense, Utilisateur *utilisateur) {
	depenses_.push_back(depense);
	*utilisateur+=depense;
	nombreDepenses_++;
	return *this;
}

/* Ancienne méthode pour ajouter un utilisateur au groupe
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
	if (nombreUtilisateurs_ >= tailleTabUtilisateurs_) {
		tailleTabUtilisateurs_ *= 2;

		Utilisateur** listeTemp = new Utilisateur*[tailleTabUtilisateurs_];

		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			listeTemp[i] = utilisateurs_[i];
		}
		delete[] utilisateurs_;

		utilisateurs_ = listeTemp;
	}
	utilisateurs_[nombreUtilisateurs_++] = unUtilisateur;
}*/

// Surcharge de l'operateur += pour remplacer la methode ajouterUtilisateur
Groupe& Groupe::operator+=(Utilisateur* unUtilisateur) {
	utilisateurs_.push_back(unUtilisateur);
	nombreUtilisateurs_++;
	return *this;
}

// Méthodes de calculs
void Groupe::calculerComptes()
{
	double moyenne = getTotalDepenses() / nombreUtilisateurs_;
	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		comptes_.push_back((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= nombreUtilisateurs_ - 1) {
			calcul = false;
		}
	}
}

/* Ancienne méthode d'affichage
void Groupe::afficherGroupe() const {
	cout << "L'evenement " << nom_ << " a coute un total de " << getTotalDepenses() << " :  \n\n";
	for (int i = 0; i < nombreUtilisateurs_; i++) {
		utilisateurs_[i]->afficherUtilisateur();
	}
	cout << endl;

	if (nombreTransferts_ != 0) {
		cout << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
		for (int i = 0; i < nombreTransferts_; i++) {
			cout << "\t";
			transferts_[i]->afficherTransfert();
		}
	}
	else {
		cout << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	cout << endl;
}*/

// Surcharge de l'operateur << pour l'affichage
ostream& operator<<(ostream& os, const Groupe &groupe){
	os << "L'evenement " << groupe.getNom() << " a coute un total de " << groupe.getTotalDepenses() << " :  \n\n";
	for (int i = 0; i < groupe.utilisateurs_.size(); i++) {
		os << *groupe.utilisateurs_[i];
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Les transferts suivants ont ete realises pour equilibrer  : " << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++) {
			os << "\t";
			os << *groupe.transferts_[i];
		}
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	os << endl;
	return os;
}
