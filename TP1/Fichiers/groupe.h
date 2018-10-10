#ifndef GROUPE_H
#define GROUPE_H

#include "transfert.h"
#include <string>

using namespace std;

class Groupe
{
    public :
		//Constructeurs
		Groupe();
		Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs);
    
		//Destructeur
		~Groupe();
    
		// Getters
		string getNom() const;
		unsigned int getNombreDepenses() const;
		double getTotal() const;
    
		// Setters
		void setNom(string& nom);
    
		// Methodes d'ajout
		void ajouterDepense(Depense* uneDepense, Utilisateur* payePar);
		void ajouterUtilisateur(Utilisateur* unUtilisateur);
    
		// Méthode de calculs
		void calculerTotalDepenses();
		void equilibrerComptes();
    
		// Méthode d'affichage
		void afficherGroupe();
    
    private :
        string nom_;
        double totalDepenses_;
        Utilisateur** listeUtilisateurs_;
        unsigned int nombreDepenses_;
        unsigned int nombreUtilisateurs_;
        unsigned int tailleTabUtilisateurs_;
        unsigned int tailleTabDepenses_;
        Depense** listeDepenses_;
        double* comptes_;
        Transfert** listeTransferts_;
        unsigned int nombreTransferts_; 
};
#endif
