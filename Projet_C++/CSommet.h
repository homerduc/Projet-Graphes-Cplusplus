#ifndef CSOMMET_H
#define CSOMMET_H

#include <iostream>
#include <string>
#include <Vector>
#include "CArc.h"

using namespace std;

/**
 * @class CSommet
 * @brief Classe repr�sentant un sommet dans un graphe
 */
class CSommet
{
private:

	string sSOMid; ///< Identifiant du sommet
	vector<CArc*> vSOM_ArcEntrants; ///< Vecteur des arcs entrants du sommet
	vector<CArc*> vSOM_ArcSortants; ///< Vecteur des arcs sortants du sommet

public:

	/**
	 * @brief Constructeur par d�faut
	 *
	 * Initialise l'identifiant du sommet � "" et les vecteurs d'arcs entrants et sortants � vide
	 */
	CSommet();

	/**
	 * @brief Constructeur avec param�tres
	 *
	 * Initialise l'identifiant du sommet et les vecteurs d'arcs entrants et sortants avec les valeurs donn�es
	 *
	 * @param sID Identifiant du sommet
	 * @param vEntrants Vecteur des arcs entrants du sommet
	 * @param vSortants Vecteur des arcs sortants du sommet
	 */
	CSommet(const string& sID, const vector<CArc*>& vEntrants, const vector<CArc*>& vSortants) { sSOMid = sID; vSOM_ArcEntrants = vEntrants; vSOM_ArcSortants = vSortants; }

	/**
	 * @brief Constructeur avec un seul param�tre
	 *
	 * Initialise l'identifiant du sommet avec la valeur donn�e et les vecteurs d'arcs entrants et sortants � vide.
	 *
	 * @param sID Identifiant du sommet
	 */
	CSommet(const string& sID) { sSOMid = sID; }

	/**
	 * @brief Constructeur de copie
	 *
	 * Cr�e un nouveau graphe copi� de celui auquel appartient SOMsommet
	 *
	 * @param SOMsommet Le sommet � copier
	 */
	CSommet(const CSommet& SOMsommet);


	/**
	 * @brief Accesseur pour l'identifiant du sommet
	 *
	 * @return L'identifiant du sommet
	 */
	string const& SOM_GetID() const { return sSOMid; }

	/**
	 * @brief Accesseur pour les arcs entrants du sommet
	 *
	 * @return Le vecteur des arcs entrants du sommet
	 */
	vector<CArc*> const& SOM_GetEntrants() const { return vSOM_ArcEntrants; }

	/**
	 * @brief Accesseur pour les arcs sortants du sommet
	 *
	 * @return Le vecteur des arcs sortants du sommet
	 */
	vector<CArc*> const& SOM_GetSortants() const { return vSOM_ArcSortants; }

	/**
	 * @brief Ajoute un arc entrant au sommet
	 *
	 * Ajoute l'arc donn� � la liste des arcs entrants du sommet seulement si l'identifiant du sommet d'arriv�e de l'arc est le m�me que l'identifiant du sommet actuel
	 *
	 * @param pARCarc Pointeur sur l'arc � ajouter
	 */
	void SOM_Ajouter_Entrants(CArc* pARCarc);

	/**
	 * @brief Ajoute un arc sortant au sommet
	 *
	 * Ajoute l'arc donn� � la liste des arcs sortants du sommet seulement si l'identifiant du sommet de d�part de l'arc est le m�me que l'identifiant du sommet actuel
	 *
	 * @param pARCarc Pointeur sur l'arc � ajouter
	 */
	void SOM_Ajouter_Sortants(CArc* pARCarc);

	/**
	 * @brief Recherche un arc entrant dans le sommet
	 *
	 * @param sDepart Identifiant du sommet de d�part de l'arc � rechercher
	 * @return Un it�rateur vers l'arc recherch� ou vSOM_ArcEntrants.end() si l'arc n'est pas trouv�
	 */
	vector<CArc*>::iterator SOM_RechercheEntrant(const string& sDepart);

	/**
	 * @brief Recherche un arc sortant dans le sommet
	 *
	 * @param sArrive Identifiant du sommet d'arriv�e de l'arc � rechercher.
	 * @return Un it�rateur vers l'arc recherch� ou vSOM_ArcSortants.end() si l'arc n'est pas trouv�
	 */
	vector<CArc*>::iterator SOM_RechercheSortant(const string& sArrive);

	/**
	 * @brief Supprime un arc entrant du sommet
	 *
	 * @param sDepart Identifiant du sommet de d�part de l'arc � supprimer
	 */
	void SOM_SupprimerArcEntrant(const string& sDepart);

	/**
	 * @brief Supprime un arc sortant du sommet
	 *
	 * @param sArrive Identifiant du sommet d'arriv�e de l'arc � supprimer
	 */
	void SOM_SupprimerArcSortant(const string& sArrive);
};

#endif // !CSOMMET_H
