#include "depenseGroupe.h"

// Constructeur
DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu, TypeDepense type, unsigned int nombreParticipants) : Depense(nom, montant, lieu), nombreParticipants_(nombreParticipants)
{}

// Constructeur par copie
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense)
{
}

// Getters
unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const {
	double montantTotal = Depense::getMontant();
	if (nombreParticipants_ == 0) {
		return 0;
	}
	else {
		double montantPerso = montantTotal / nombreParticipants_;
		return montantPerso;
	}
}

// Setters
void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}

// Méthode d'affichage
ostream& operator<<(ostream& os, const DepenseGroupe &depense) {
	os << "Achat : " << depense.getNom() << " - Prix : " << depense.getMontant() << "; " << endl << "Nombre de personnes impliquées : " << depense.getNombreParticipants() 
		<< " - Montant personnel à payer : " << depense.getMontantPersonnel() << "; " << endl;

	return os;
}
