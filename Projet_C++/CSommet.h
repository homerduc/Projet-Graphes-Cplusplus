#ifndef CSOMMET_H
#define CSOMMET_H

	#include <iostream>
	#include <string>
	#include <Vector>
	#include "CArc.h"
	using namespace std;

class CSommet
{
private:

	string sSOMid;
	vector<CArc*> vSOM_ArcEntrants;
	vector<CArc*> vSOM_ArcSortants;

public:

	#pragma region CONSTRUCTEURS & DESTRUCTEURS 
		/******************************************************************************************************************
		* 	CSommet()
		* *****************************************************************************************************************
		*	Entree : rien 
		*	Préconditions : rien
		*	Sortie : rien
		*	Postconditions : objet initialiser avec le nom est mis par défaut à "" les vecteur sont vide de bases
		******************************************************************************************************************/
		CSommet();

		/******************************************************************************************************************
		*   	CSommet(const string& sID, const vector<CArc>& vEntrants, const vector<CArc>& vSortants)
		* *****************************************************************************************************************
		*	Entree :reférence d'un string sID, reférence d'un vector d'arc d'Entrants, reférence d'un vector d'arcs de Sortants
		*	Préconditions : rien 
		*	Sortie : rien
		*	Postconditions : objet initialiser avec les paramètres 
		******************************************************************************************************************/
		CSommet(const string& sID, const vector<CArc*>& vEntrants, const vector<CArc*>& vSortants) { sSOMid = sID; vSOM_ArcEntrants = vEntrants; vSOM_ArcSortants = vSortants; }

		CSommet(const string& sID) { sSOMid = sID; }
	
		/******************************************************************************************************************
		* 	CSommet(const CSommet& SOMsommet)
		* *****************************************************************************************************************
		*	Entree : Un CSommet par référence
		*	Préconditions : rien
		*	Sortie : rien
		*	Postconditions : les listes des arcs de SOMsommet ont bien été copiées entièrement
		******************************************************************************************************************/
		CSommet(const CSommet& SOMsommet);
	
		/******************************************************************************************************************
		*   ~CSommet()
		* *****************************************************************************************************************
		*	Entree :rien
		*	Préconditions : rien
		*	Sortie : rien
		*	Postconditions : les attriuts sont nétoyés
		******************************************************************************************************************/
		~CSommet();
	#pragma endregion

	#pragma region ACCESSEURS
		/******************************************************************************************************************
		*   SOM_GetID()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Préconditions : appel sur un objet existant de la classe
		*	Sortie : un string correspondant à l'identifiant du sommet
		*	Postconditions : rien
		******************************************************************************************************************/
		string const& SOM_GetID()const { return sSOMid; }
	
		/******************************************************************************************************************
		*   SOM_GetEntrants()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Préconditions : appel sur un objet existant de la classe
		*	Sortie : un vecteur correspondant à l'identifiant du sommet
		*	Postconditions : rien
		******************************************************************************************************************/
		vector<CArc*> const& SOM_GetEntrants()const { return vSOM_ArcEntrants; }

		/******************************************************************************************************************
		*   SOM_GetSortants()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Préconditions : appel sur un objet existant de la classe
		*	Sortie : un vecteur des arc de Sortant
		*	Postconditions : rien
		******************************************************************************************************************/
		vector<CArc*> const& SOM_GetSortants()const { return vSOM_ArcSortants; }

	#pragma endregion

	#pragma region AFFICHAGE
		/******************************************************************************************************************
		*   Affichage_du_Sommet()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Préconditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Affiche dans la console l'ensemble de l'objet sommet
		******************************************************************************************************************/
		void Affichage_du_Sommet();

		/******************************************************************************************************************
		*   SOM_Afficher_Arrive()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Préconditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Affiche dans la console le contenu du vecteur des arcs d'arrivés
		******************************************************************************************************************/
		void SOM_Afficher_Entrants();

		/******************************************************************************************************************
		*   SOM_Afficher_Sortant()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Préconditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Affiche dans la console le contenu du vecteur des arcs de départs
		******************************************************************************************************************/
		void SOM_Afficher_Sortants();
	
	#pragma endregion

	#pragma region AJOUTER
		/******************************************************************************************************************
		*   SOM_Ajouter_arc_arricee(CArc* pARCarc)
		* *****************************************************************************************************************
		*	Entree : pointeur sur un objet arc
		*	Préconditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Ajoute le l'arc en paramètre à la liste des arc d'arrive du sommet seulement
		*					 si le nom du sommet d'arrive de l'arc est le nom du sommet actuel 
		******************************************************************************************************************/
		void SOM_Ajouter_Entrants(CArc* pARCarc);

		/******************************************************************************************************************
		*   SOM_Ajouter_arc_Sortant(CArc* pARCarc)
		* *****************************************************************************************************************
		*	Entree : pointeur sur un objet arc
		*	Préconditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Ajoute le l'arc en paramètre à la liste des arc de départ du sommet seulement
		*					 si le nom du sommet de départ de l'arc est le nom du sommet actuel 
		******************************************************************************************************************/
		void SOM_Ajouter_Sortants(CArc* pARCarc);
	
	#pragma endregion
	

	vector<CArc*>::iterator SOM_RechercheEntrant(string sArrive);

};



#endif // !CSOMMET_H


