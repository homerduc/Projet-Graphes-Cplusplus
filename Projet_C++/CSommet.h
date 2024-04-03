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
		*	Postconditions : le nom est mis par d�faut � "" et les vecteurs sont vides de base
		******************************************************************************************************************/
		CSommet();

		/******************************************************************************************************************
		*   CSommet(const string& sID, const vector<CArc>& vEntrants, const vector<CArc>& vSortants)
		* *****************************************************************************************************************
		*	Entree :ref�rence d'un string sID, ref�rence d'un vector d'arcs vEntrants, ref�rence d'un vector d'arcs vSortants
		*	Pr�conditions : rien 
		*	Sortie : rien
		*	Postconditions : objet initialis� avec les param�tres recopi�s
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
		*	Sortie : un vecteur des arc sortants
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
		*   SOM_Ajouter_Entrants(CArc* pARCarc)
		* *****************************************************************************************************************
		*	Entree : pointeur sur un objet CArc
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Ajoute l'arc en param�tre � la liste des arc d'arriv�e du sommet seulement
		*					 si le nom du sommet d'arriv�e de l'arc est le nom du sommet actuel 
		******************************************************************************************************************/
		void SOM_Ajouter_Entrants(CArc* pARCarc);

		/******************************************************************************************************************
		*   SOM_Ajouter_arc_Sortant(CArc* pARCarc)
		* *****************************************************************************************************************
		*	Entree : pointeur sur un objet CArc
		*	Pr�conditions : appel sur un objet existant de la classe
		*	Sortie : rien
		*	Postconditions : Ajoute l'arc en param�tre � la liste des arcs de d�part du sommet seulement
		*					 si le nom du sommet de d�part de l'arc est le nom du sommet actuel 
		******************************************************************************************************************/
		void SOM_Ajouter_Sortants(CArc* pARCarc);
	
	#pragma endregion
		
	#pragma region RECHERCHE ARCS ENTRANT ET SORTANT DE L'ARC

			vector<CArc*>::iterator SOM_RechercheEntrant(string sDepart);
			vector<CArc*>::iterator SOM_RechercheSortant(string sArrive);

	#pragma endregion

	#pragma region SUPPRIMER ARC ENTRANT ET SORTANT
				void SOM_SupprimerArc(string sDepart, string sArrive);
	#pragma endregion

};



#endif // !CSOMMET_H


