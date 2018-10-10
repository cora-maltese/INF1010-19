#include "groupe.h"
#include <cmath>

// Constructeur par défaut
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

// Constructeur par paramètres
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
	// Désallocation mémoire du tableau dynamique des Dépenses
	for (unsigned int i = 0; i < tailleTabDepenses_; i++)
	{
		if (listeDepenses_[i] != nullptr)
			delete listeDepenses_[i];
	}
	delete[] listeDepenses_;
	listeDepenses_ = nullptr;

	// Désallocation mémoire du tableau dynamique des Utilisateurs
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
	{
		if (listeUtilisateurs_[i] != nullptr)
			delete listeUtilisateurs_[i];
	}
	delete[] listeUtilisateurs_;
	listeUtilisateurs_ = nullptr;

	// Désallocation mémoire du tableau dynamique des Transferts
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		if (listeTransferts_[i] != nullptr)
			delete listeTransferts_[i];
	}
	delete[] listeTransferts_;
	listeTransferts_ = nullptr;

	// Désallocation mémoire du tableau des comptes
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
Méthode d'ajout d'utilisateur. Attention : vérifier si la taille du tableau le permet, et
réagir dans le cas contraire. On doit pouvoir toujours ajouter un utilisateur.
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
Une méthode d’ajout de dépense, prend deux paramètres : un pointeur vers une dépense et
un pointeur vers un utilisateur, il faudra ajouter la dépense à l’évènement mais également
à l’utilisateur qui l’a payée (attention : vérifier si la taille du tableau le permet, et réagir
dans le cas contraire). On doit pouvoir toujours ajouter une dépense.
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
Une méthode calculerTotalDepenses(), qui met à jour le total de dépenses de l’évènement
et fait les comptes (soit le montant, positif ou négatif, de nos dépenses par rapport à la
moyenne de dépenses de l’évènement).
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
*Paramètres en entrée : aucun
*Valeur de retour : void
*
*Description : Une méthode équilibrerComptes(), qui créé des transferts (de manière optimale, 
*soit le nombre minimum de transferts) afin de remettre les comptes à zéro et les mets 
*dans la liste. Il faut utiliser les attributs comptes_ et listeTransferts_. Il est de 
*votre responsabilité de concevoir l’algorithme de cette méthode.
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

		// On entre dans le if seulement si la valeur absolue du compte minimum est inférieure ou égale au compte maximum, la deuxième condition permet de ne pas afficher de tranfert nul.
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
Une méthode d’affichage, qui affiche toutes les dépenses par utilisateur, les comptes 
(s’ils ne sont pas tous nuls), les transferts (si comptes remis à 0).
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
