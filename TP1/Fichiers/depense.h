#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense 
{
    public :
		// Constructeurs
		Depense();
		Depense(string& titre, double montant);
    
		// Getters
		string getTitre() const;
		double getMontant() const;
    
		// Setters
		void setTitre(string& titre);
		void setMontant(double montant);
		// Méthode d'affichage
		void afficherDepense();
    
    private :
        string titre_;
        double montant_;
};
#endif
