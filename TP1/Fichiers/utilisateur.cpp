#include "utilisateur.h"

// Constructeur par défaut
Utilisateur::Utilisateur()
{
	nom_ = "unknown";
	tailleTabDepenses_ = 5;
	nombreDepenses_ = 0;
	totalDepenses_ = 0.0;
	listeDepenses_ = new Depense*[tailleTabDepenses_];
}

// Constructeur par paramètres
Utilisateur::Utilisateur(string& nom)
{
	nom_ = nom;
	tailleTabDepenses_ = 5;
	nombreDepenses_ = 0;
	totalDepenses_ = 0.0;
	listeDepenses_ = new Depense*[tailleTabDepenses_];
}

// Destructeur
Utilisateur::~Utilisateur()
{
	for (unsigned int i = 0; i < tailleTabDepenses_; i++)
	{
		if (listeDepenses_[i] != nullptr)
			delete listeDepenses_[i];
	}
	delete[] listeDepenses_;
	listeDepenses_ = nullptr;
}

// Getters
string Utilisateur::getNom() const
{
	return nom_;
}

unsigned int Utilisateur::getNombreDepenses() const
{
	return nombreDepenses_;
}

double Utilisateur::getTotal() const
{
	return totalDepenses_;
}

// Setters
void Utilisateur::setNom(string& nom)
{
	nom_ = nom;
}

/* 
Méthode d'ajout de dépense. Attention : vérifier si la taille du tableau le 
permet, et réagir dans le cas contraire. On doit toujours pouvoir ajouter une 
dépense. 
*/
void Utilisateur::ajouterDepense(Depense* uneDepense)
{
	// Copier le tableau vers un nouveau tableau avec capacite*2
	// Ajouter la depense
	// Delete le premier tableau
	if (tailleTabDepenses_ == nombreDepenses_)
	{
		tailleTabDepenses_ *= 2;
		Depense ** nouvelleListeDepenses = new Depense*[tailleTabDepenses_];
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
			nouvelleListeDepenses[i] = listeDepenses_[i];
		}
		delete[] listeDepenses_;
		listeDepenses_ = nouvelleListeDepenses;
	}
	listeDepenses_[nombreDepenses_] = uneDepense;
	nombreDepenses_++;
}

// Méthode qui calcule le montant total des dépenses effectuées.
void Utilisateur::calculerTotal()
{
	for (unsigned int i = 0; i < nombreDepenses_; i++)
	{
		totalDepenses_ += listeDepenses_[i]->getMontant();
	}
}

// Méthode d'affichage
void Utilisateur::afficherUtilisateur()
{
	cout << fixed << setprecision(2) << "L'utilisateur " << this->getNom() << " a depense un total de " << this->getTotal() << "." << endl;
	cout << "Liste de ses depenses : " << endl;
	for (unsigned int i = 0; i < this->getNombreDepenses(); i++)
	{
		listeDepenses_[i]->afficherDepense();
	}
	cout << endl;
}
