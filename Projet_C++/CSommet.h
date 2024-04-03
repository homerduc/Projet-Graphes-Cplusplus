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
		*	Pr�conditions : rien
		*	Sortie : rien
		*	Postconditions : objet initialiser avec le nom est mis par d�faut � "" les vecteur sont vide de bases
		******************************************************************************************************************/
		CSommet();

		/******************************************************************************************************************
		*   	CSommet(const string& sID, const vector<CArc>& vEntrants, const vector<CArc>& vSortants)
		* *****************************************************************************************************************
		*	Entree :ref�rence d'un string sID, ref�rence d'un vector d'arc d'Entrants, ref�rence d'un vector d'arcs de Sortants
		*	Pr�conditions : rien 
		*	Sortie : rien
		*	Postconditions : objet initialiser avec les param�tres 
		******************************************************************************************************************/
		CSommet(const string& sID, const vector<CArc*>& vEntrants, const vector<CArc*>& vSortants) { sSOMid = sID; vSOM_ArcEntrants = vEntrants; vSOM_ArcSortants = vSortants; }

		CSommet(const string& sID) { sSOMid = sID; }
	
		/******************************************************************************************************************
		* 	CSommet(const CSommet& SOMsommet)
		* *****************************************************************************************************************
		*	Entree : Un CSommet par r�f�rence
		*	Pr�conditions : rien
		*	Sortie : rien
		*	Postconditions : les listes des arcs de SOMsommet ont bien �t� copi�es enti�rement
		******************************************************************************************************************/
		CSommet(const CSommet& SOMsommet);
	
		/******************************************************************************************************************
		*   ~CSommet()
		* *****************************************************************************************************************
		*	Entree :rien
		*	Pr�conditions : rien
		*	Sortie : rien
		*	Postconditions : les attriuts sont n�toy�s
		******************************************************************************************************************/
		~CSommet();
	#pragma endregion

	#pragma region ACCESSEURS
		/******************************************************************************************************************
		*   SOM_GetID()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : un string correspondant � l'identifiant du sommet
		*	Postconditions : rien
		******************************************************************************************************************/
		string const& SOM_GetID()const { return sSOMid; }
	
		/******************************************************************************************************************
		*   SOM_GetEntrants()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : un vecteur correspondant � l'identifiant du sommet
		*	Postconditions : rien
		******************************************************************************************************************/
		vector<CArc*> const& SOM_GetEntrants()const { return vSOM_ArcEntrants; }

		/******************************************************************************************************************
		*   SOM_GetSortants()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Pr�conditions : appel sur un objet existant de la classe
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
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Affiche dans la console l'ensemble de l'objet sommet
		******************************************************************************************************************/
		void Affichage_du_Sommet();

		/******************************************************************************************************************
		*   SOM_Afficher_Arrive()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Affiche dans la console le contenu du vecteur des arcs d'arriv�s
		******************************************************************************************************************/
		void SOM_Afficher_Entrants();

		/******************************************************************************************************************
		*   SOM_Afficher_Sortant()
		* *****************************************************************************************************************
		*	Entree : rien
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Affiche dans la console le contenu du vecteur des arcs de d�parts
		******************************************************************************************************************/
		void SOM_Afficher_Sortants();
	
	#pragma endregion

	#pragma region AJOUTER
		/******************************************************************************************************************
		*   SOM_Ajouter_arc_arricee(CArc* pARCarc)
		* *****************************************************************************************************************
		*	Entree : pointeur sur un objet arc
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Ajoute le l'arc en param�tre � la liste des arc d'arrive du sommet seulement
		*					 si le nom du sommet d'arrive de l'arc est le nom du sommet actuel 
		******************************************************************************************************************/
		void SOM_Ajouter_Entrants(CArc* pARCarc);

		/******************************************************************************************************************
		*   SOM_Ajouter_arc_Sortant(CArc* pARCarc)
		* *****************************************************************************************************************
		*	Entree : pointeur sur un objet arc
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Ajoute le l'arc en param�tre � la liste des arc de d�part du sommet seulement
		*					 si le nom du sommet de d�part de l'arc est le nom du sommet actuel 
		******************************************************************************************************************/
		void SOM_Ajouter_Sortants(CArc* pARCarc);
	
	#pragma endregion
	

	vector<CArc*>::iterator SOM_RechercheEntrant(string sArrive);

};



#endif // !CSOMMET_H


