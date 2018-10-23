#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "depenseGroupe.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include "transfert.h"

using namespace std;

class Groupe {
public:
	// Constructeur
	Groupe(const string& nom = "");

	// Destructeur
	~Groupe();

	// Getters
	string getNom() const;
	double getTotalDepenses() const;
	vector<DepenseGroupe*> getDepenses() const;
	vector<Utilisateur*> getUtilisateurs() const;
	vector<Transfert*> getTransferts() const; 

	// Setters
	void setNom(const string& nom);

	// Méthodes d'ajout
	Groupe& ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour);
	Groupe& operator+=(Utilisateur* utilisateur);

	// Méthodes de calculs
	void equilibrerComptes();
	void calculerTotalDepenses();
	void calculerComptes();

	// Méthode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	double totalDepenses_;
	vector<Utilisateur*> utilisateurs_;
	vector<DepenseGroupe*> depenses_;
	vector<Transfert*> transferts_;
	vector<double> comptes_; 
};

#endif
