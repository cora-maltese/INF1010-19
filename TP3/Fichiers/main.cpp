#include <iostream>
#include "depense.h"
#include "utilisateur.h"
#include "transfert.h"
#include "groupe.h"

using namespace std;

int main() {

	// Initialisation des utilisateurs 
	UtilisateurPremium* alex = new UtilisateurPremium("Alex");
	UtilisateurPremium* max = new UtilisateurPremium("Max");
	UtilisateurPremium* henri = new UtilisateurPremium("Henri");
	UtilisateurPremium* louis = new UtilisateurPremium("Louis"); 

	UtilisateurRegulier* albert = new UtilisateurRegulier("Albert");
	UtilisateurRegulier* charles = new UtilisateurRegulier("Charles");
	UtilisateurRegulier* allan = new UtilisateurRegulier("Allan");
	UtilisateurRegulier* clemence = new UtilisateurRegulier("Clemence");

	// Initialisation des dépenses 
	Depense* d1 = new Depense("d1", 10, "Bruxelles");
	Depense* d2 = new Depense("d2", 30, "Bruxelles");
	Depense* d3 = new Depense("d3", 15, "Bruxelles");
	Depense* d4 = new Depense("d4", 100, "Bruxelles");
	Depense* d5 = new Depense("d5", 120, "Bruxelles");

	DepenseGroupe* d6 = new DepenseGroupe("d6", 1000, "Montreal");
	DepenseGroupe* d7 = new DepenseGroupe("d7", 430, "Montreal");
	DepenseGroupe* d8 = new DepenseGroupe("d8", 50, "Montreal");
	DepenseGroupe* d9 = new DepenseGroupe("d9", 330, "Montreal");

	// Initialisation des groupes
	Groupe vacances("Madrid");
	Groupe collocation("Collocation");

	// Changement du nombre de jours restants pour l'abonnement Premium de Louis
	louis->setJoursRestants(0); 

	// Ajouts des utilisateurs dans les groupes
	(((((((vacances += alex) += max) += henri) += albert) += charles) += allan) += clemence) += louis; 

	// Ajout des dépenses individuelles 
	*henri += d1; 
	*henri += d2; 
	*henri += d3; 
	*henri += d4;
	*henri += d5; 

	// Ajout des dépenses de groupe

	// Vecteur pour le partage de la dépense
	vector<Utilisateur*> payePour1;
	payePour1.push_back(alex);
	payePour1.push_back(max);
	payePour1.push_back(charles);
	payePour1.push_back(allan);

	vacances.ajouterDepense(d1, clemence, payePour1); 
	vacances.ajouterDepense(d6, clemence, payePour1); 

	// Vecteur pour le partage de la dépense
	vector<Utilisateur*> payePour2;
	payePour2.push_back(charles);
	payePour2.push_back(henri);
	payePour2.push_back(max);
	payePour2.push_back(allan);
	vacances.ajouterDepense(d7, albert, payePour2);

	vector<Utilisateur*> payePour3;
	payePour3.push_back(alex);
	payePour3.push_back(max);
	vacances.ajouterDepense(d8, louis, payePour3); 

	
	vacances.calculerTotalDepenses();
	vacances.equilibrerComptes(); 

	// Ajout d'un utilisateur regulier déjà groupé au groupe collocation
	collocation += clemence;

	// Affichage du groupe vacances 
	cout << vacances; 


	// Fin du programme
	/*
	delete d1; 
	d1 = nullptr; 
	delete d2;
	d2 = nullptr;
	delete d3;
	d3 = nullptr;
	delete d4;
	d4 = nullptr;
	delete d5;
	d5 = nullptr;
	delete d6;
	d6 = nullptr;
	delete d7;
	d7 = nullptr;
	delete d8;
	d8 = nullptr;
	delete d9;
	d9 = nullptr;
	
	delete alex; 
	delete charles; 
 	delete henri; 
	delete louis; 

	delete albert; 
	delete max; 
	delete allan;
	delete clemence; 
	*/

	system("pause");
	return 0;
}

/*
Réponses aux questions :

1) Il est logique de dériver une classe UtilisateurPremium et une classe UtilisateurRégulier d'une classe Utilisateur car ces deux premières classes partagent plusieurs attributs. 
En effet, le fait de les dériver d'une classe mère commune nous permet d'avoir accès à ces attributs communs tout en ayant la possiblité d'ajouter des fonctionnalité propres à chacune des deux classes dérivées.
De plus, l'héritage est une relation de type "est un" et on voit clairement ici que l'UtilisateurPremium est un Utilisateur et UtilisateurRégulier est un Utilisateur.

2.1) La fonctionalité static_cast nous permet d'effectuer des opérations de conversion par exemple, d'un pointeur vers une classe mère à un poineur vers une classe fille.Or, dans la surcharge de l'opérateur << 
dans la classe Groupe nous n'avons utilisé que des attributs de la classe Groupe. Nous n'avons donc pas eu de conversion à faire.Son utilisation n'était donc pas nécéssaire.

2.2) Il n'y avait pas de conversion à faire dans ce cas spécifique donc cela n'aura pas d'effet si on ne le considère pas dans l'implémentation.par contre, lorsqu'il y a une conversion à faire,
il est impératif d'inclure static_cast dans l'implémentation car sinon certains attributs d'une classe dérivé ne seront pas accessible ou le format ne sera pas compatible et cela causera une erreur.

*/
