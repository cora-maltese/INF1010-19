#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <iomanip>
#include "depense.h"

using namespace std;

class Utilisateur
{
    public :
		// Constructeurs
		Utilisateur();
		Utilisateur(string& nom);
    
		// Destructeur
		~Utilisateur(); 
    
		// Getters
		string getNom() const;
		unsigned int getNombreDepenses() const;
		double getTotal() const;
  
		// Setters
		void setNom(string& nom);
    
		// Methode d'ajout de dépense
		void ajouterDepense(Depense* uneDepense);
    
		// Methode de calcul total
		void calculerTotal();
    
		// Méthode d'affichage
		void afficherUtilisateur();
    
    private :
        string nom_;
        unsigned int tailleTabDepenses_;
        unsigned int nombreDepenses_;
        double totalDepenses_;
        Depense ** listeDepenses_;
};
#endif /* utilisateur_hpp */
