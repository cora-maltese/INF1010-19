#ifndef TRANSFERT_H
#define TRANSFERT_H

#include "utilisateur.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class Transfert
{
    public :
		// Constructeurs
		Transfert();
		Transfert(double montant, Utilisateur* de, Utilisateur* pour);
    
		// Getters
		Utilisateur* getDonneur() const;
		Utilisateur* getReceveur() const;
		double getMontant() const;
    
		// Setters
		void setDonneur(Utilisateur* donneur);
		void setMontant(double montant);
		void setReceveur(Utilisateur* receveur);
    
		// Méthode d'affichage
		void afficherTransfert() ;
    
    private :
        double montant_;
        Utilisateur* donneur_;
        Utilisateur* receveur_;
};
#endif
