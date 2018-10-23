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

	// Initialisation des d�penses 
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

	// Ajout des d�penses individuelles 
	*henri += d1; 
	*henri += d2; 
	*henri += d3; 
	*henri += d4;
	*henri += d5; 

	// Ajout des d�penses de groupe

	// Vecteur pour le partage de la d�pense
	vector<Utilisateur*> payePour1;
	payePour1.push_back(alex);
	payePour1.push_back(max);
	payePour1.push_back(charles);
	payePour1.push_back(allan);

	vacances.ajouterDepense(d1, clemence, payePour1); 
	vacances.ajouterDepense(d6, clemence, payePour1); 

	// Vecteur pour le partage de la d�pense
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

	// Ajout d'un utilisateur regulier d�j� group� au groupe collocation
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
R�ponses aux questions :

1) Il est logique de d�river une classe UtilisateurPremium et une classe UtilisateurR�gulier d'une classe Utilisateur car ces deux premi�res classes partagent plusieurs attributs. 
En effet, le fait de les d�river d'une classe m�re commune nous permet d'avoir acc�s � ces attributs communs tout en ayant la possiblit� d'ajouter des fonctionnalit� propres � chacune des deux classes d�riv�es.
De plus, l'h�ritage est une relation de type "est un" et on voit clairement ici que l'UtilisateurPremium est un Utilisateur et UtilisateurR�gulier est un Utilisateur.

2.1) La fonctionalit� static_cast nous permet d'effectuer des op�rations de conversion par exemple, d'un pointeur vers une classe m�re � un poineur vers une classe fille.Or, dans la surcharge de l'op�rateur << 
dans la classe Groupe nous n'avons utilis� que des attributs de la classe Groupe. Nous n'avons donc pas eu de conversion � faire.Son utilisation n'�tait donc pas n�c�ssaire.

2.2) Il n'y avait pas de conversion � faire dans ce cas sp�cifique donc cela n'aura pas d'effet si on ne le consid�re pas dans l'impl�mentation.par contre, lorsqu'il y a une conversion � faire,
il est imp�ratif d'inclure static_cast dans l'impl�mentation car sinon certains attributs d'une classe d�riv� ne seront pas accessible ou le format ne sera pas compatible et cela causera une erreur.

*/
