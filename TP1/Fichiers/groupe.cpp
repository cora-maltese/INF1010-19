#include "groupe.h"
#include <cmath>

// Constructeur par d�faut
Groupe::Groupe()
{
	nom_ = "unknown";
	totalDepenses_ = 0.0;

	tailleTabUtilisateurs_ = 5;
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	nombreUtilisateurs_ = 0;

	tailleTabDepenses_ = 10;
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	nombreDepenses_ = 0;

	comptes_ = new double[nombreUtilisateurs_];

	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	nombreTransferts_ = 0;
}

// Constructeur par param�tres
Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs)
{
	nom_ = nom;
	totalDepenses_ = 0.0;

	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	nombreUtilisateurs_ = 0;

	tailleTabDepenses_ = tailleTabDepenses;
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	nombreDepenses_ = 0;

	comptes_ = new double[nombreUtilisateurs_];

	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	nombreTransferts_ = 0;
}

// Destructeur
Groupe::~Groupe()
{
	// D�sallocation m�moire du tableau dynamique des D�penses
	for (unsigned int i = 0; i < tailleTabDepenses_; i++)
	{
		if (listeDepenses_[i] != nullptr)
			delete listeDepenses_[i];
	}
	delete[] listeDepenses_;
	listeDepenses_ = nullptr;

	// D�sallocation m�moire du tableau dynamique des Utilisateurs
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
	{
		if (listeUtilisateurs_[i] != nullptr)
			delete listeUtilisateurs_[i];
	}
	delete[] listeUtilisateurs_;
	listeUtilisateurs_ = nullptr;

	// D�sallocation m�moire du tableau dynamique des Transferts
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		if (listeTransferts_[i] != nullptr)
			delete listeTransferts_[i];
	}
	delete[] listeTransferts_;
	listeTransferts_ = nullptr;

	// D�sallocation m�moire du tableau des comptes
	// comptes_ ne contient pas des pointeurs mais seulement des double
	delete[] comptes_;
	comptes_ = nullptr;
}

// Getters
string Groupe::getNom() const
{
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const
{
	return nombreDepenses_;
}

double Groupe::getTotal() const
{
	return totalDepenses_;
}

// Setters
void Groupe::setNom(string& nom)
{
	nom_ = nom;
}

/*
M�thode d'ajout d'utilisateur. Attention : v�rifier si la taille du tableau le permet, et
r�agir dans le cas contraire. On doit pouvoir toujours ajouter un utilisateur.
*/
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur)
{
	// Copier le tableau vers un nouveau tableau avec capacite*2
	// Delete le premier tableau
	// Ajouter l'utilisateur
	if (tailleTabUtilisateurs_ == nombreUtilisateurs_)
	{
		tailleTabUtilisateurs_ *= 2;
		Utilisateur ** nouvelleListeUtilisateurs = new Utilisateur*[tailleTabUtilisateurs_];
		for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
			nouvelleListeUtilisateurs[i] = listeUtilisateurs_[i];
		}
		delete[] listeUtilisateurs_;
		listeUtilisateurs_ = nouvelleListeUtilisateurs;
	}
	listeUtilisateurs_[nombreUtilisateurs_] = unUtilisateur;
	nombreUtilisateurs_++;
}

/*
Une m�thode d�ajout de d�pense, prend deux param�tres : un pointeur vers une d�pense et
un pointeur vers un utilisateur, il faudra ajouter la d�pense � l��v�nement mais �galement
� l�utilisateur qui l�a pay�e (attention : v�rifier si la taille du tableau le permet, et r�agir
dans le cas contraire). On doit pouvoir toujours ajouter une d�pense.
*/
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar)
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
	payePar->ajouterDepense(uneDepense);
}

/*
Une m�thode calculerTotalDepenses(), qui met � jour le total de d�penses de l��v�nement
et fait les comptes (soit le montant, positif ou n�gatif, de nos d�penses par rapport � la
moyenne de d�penses de l��v�nement).
*/
void Groupe::calculerTotalDepenses()
{
	for (unsigned int i = 0; i < nombreDepenses_; i++)
	{
		totalDepenses_ += listeDepenses_[i]->getMontant();
	}
	double moyenne = totalDepenses_ / nombreUtilisateurs_;

	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		listeUtilisateurs_[i]->calculerTotal();
		comptes_[i] = (listeUtilisateurs_[i]->getTotal()) - moyenne;
	}
}

/**
*Nom : equilibrerComptes
*Param�tres en entr�e : aucun
*Valeur de retour : void
*
*Description : Une m�thode �quilibrerComptes(), qui cr�� des transferts (de mani�re optimale, 
*soit le nombre minimum de transferts) afin de remettre les comptes � z�ro et les mets 
*dans la liste. Il faut utiliser les attributs comptes_ et listeTransferts_. Il est de 
*votre responsabilit� de concevoir l�algorithme de cette m�thode.
*/
void Groupe::equilibrerComptes()
{
	bool estEquilibre = false;
	cout << "Pour equilibrer : " << endl;
	while (!estEquilibre)
	{
		double min = 0.0, max = 0.0;
		int indiceMin = 0, indiceMax = 0;

		// Trouver le minimum et le maximum dans la liste des comptes
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		{
			if (comptes_[i] <= min)
			{
				min = comptes_[i];
				indiceMin = i;
			}
			else if (comptes_[i] >= max)
			{
				max = comptes_[i];
				indiceMax = i;
			}
		}

		// On entre dans le if seulement si la valeur absolue du compte minimum est inf�rieure ou �gale au compte maximum, la deuxi�me condition permet de ne pas afficher de tranfert nul.
		if (fabs(min) <= max && min != 0.0)
		{	
			comptes_[indiceMin] = 0.0;
			comptes_[indiceMax] = max + min;
			Utilisateur* pour = listeUtilisateurs_[indiceMax];
			Utilisateur* de = listeUtilisateurs_[indiceMin];
			Transfert t(fabs(min), de, pour);
			t.afficherTransfert();
			listeTransferts_[nombreTransferts_] = &t;
			nombreTransferts_++;
		}

		else if (fabs(min) > max && min != 0.0)
		{
			comptes_[indiceMin] = min + max;
			comptes_[indiceMax] = 0.0;
			Utilisateur* de = listeUtilisateurs_[indiceMin];
			Utilisateur* pour = listeUtilisateurs_[indiceMax];
			Transfert t(fabs(max), de, pour);
			t.afficherTransfert();
			listeTransferts_[nombreTransferts_] = &t;
			nombreTransferts_++;
		}
		if (min == 0.0 && max == 0.0)
		{
			estEquilibre = true;
		}
	}
}

/*
Une m�thode d�affichage, qui affiche toutes les d�penses par utilisateur, les comptes 
(s�ils ne sont pas tous nuls), les transferts (si comptes remis � 0).
*/
void Groupe::afficherGroupe()
{
	double sumCheck = 0.0;

	cout << "L'evenement : " << this->getNom() << " a coute un total pour le groupe de : " << this->getTotal() << "." << endl;
	cout << "Voici les depenses du groupe :" << endl << endl;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		listeUtilisateurs_[i]->afficherUtilisateur();
		sumCheck += fabs(comptes_[i]);
	}

	if (sumCheck != 0)
	{
		cout << "Soit les comptes suivants : " << endl;
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		{
			cout << listeUtilisateurs_[i]->getNom() << " : " << comptes_[i] << endl;
		}
		cout << endl;
	}	
}
