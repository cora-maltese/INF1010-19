#include "groupe.h"

// Constructeur
Groupe::Groupe(const string& nom) : nom_(nom) 
{
}

// Destructeur
Groupe::~Groupe() {
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}

	for (int i = 0; i < utilisateurs_.size(); i++) {
		delete utilisateurs_[i];
	}

	for (int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
	}
}

// Getters
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const {
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const {
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}

double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Setters
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour) {
	int check = 0;

	for (int i = 0; i < payePour.size(); i++) {
		for (int j = 0; j < utilisateurs_.size(); j++) {
			if (payePour[i] == utilisateurs_[j])
				check++;
		}
	}

	if (payePour.size() == check && check == static_cast<DepenseGroupe*>(depense)->getNombreParticipants()) {
		if (depense->getType() == groupe) {
			*payePar += depense;
			equilibrerComptes();
			depenses_.push_back(static_cast<DepenseGroupe*>(depense));
		}
		else {
			cout << "Erreur : Vous tentez d'ajouter une depense individuelle au groupe." << endl;
		}
	}
	else {
		cout << "Erreur : Les personnes impliquees dans la depense de groupe ne sont pas dans le groupe." << endl;
	}
	return *this;
}

// Méthode de surcharge de l'opérateur +=
Groupe& Groupe::operator+=(Utilisateur* utilisateur) {
	if (utilisateur->getType() == Regulier && static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe() == false) {
		utilisateurs_.push_back(utilisateur);
		static_cast<UtilisateurRegulier*>(utilisateur)->setEtatGroupe(true);
	}
	else if (utilisateur->getType() == Premium) {
		utilisateurs_.push_back(utilisateur);
	}
	return *this;
}

void Groupe::calculerComptes() {
	double moyenne = getTotalDepenses() / utilisateurs_.size();
	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		comptes_.push_back((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}

// Méthode pour équilibrer les comptes
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
		for (int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande, on ajoute l'interet à l'expéditeur
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			utilisateurs_[indexMin]->ajouterInteret(-min);
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			utilisateurs_[indexMin]->ajouterInteret(max);
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
}

void Groupe::calculerTotalDepenses() {
	totalDepenses_ = 0;
	double depense;
	for (int i = 0; i < utilisateurs_.size(); i++) {
		utilisateurs_[i]->calculerTotalDepenses();
		depense = utilisateurs_[i]->getTotalDepenses();
		totalDepenses_ += depense;
	}
}

// Méthode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe) {
	os << "L'evenement " << groupe.getNom() << " a coute un total de " << groupe.getTotalDepenses() << " :  \n\n";
	for (int i = 0; i < groupe.utilisateurs_.size(); i++) {
		os << *groupe.utilisateurs_[i];
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Les transferts suivants ont ete realises pour equilibrer  : " << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++) {
			os << "\t";
			os << groupe.transferts_[i];
		}
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	os << endl;
	return os;
}
