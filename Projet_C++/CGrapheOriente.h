/**
 * @file CGrapheOriente.h
 * @brief D�finition de la classe CGrapheOriente.
 */

#ifndef CGRAPHORIENTE_H
#define CGRAPHORIENTE_H

#include "CArc.h"
#include "CSommet.h"

using namespace std;

/**
 * @class CGrapheOriente
 * @brief Classe repr�sentant un graphe orient�.
 *
 * Un graphe orient� est un graphe o� chaque arc a une direction, allant d'un sommet de d�part � un sommet d'arriv�e.
 */
class CGrapheOriente
{
private:
	vector<CArc*> vGROarcs; ///< Vecteur des arcs du graphe.
	vector<CSommet*> vGROsommets; ///< Vecteur des sommets du graphe.

public:

	/**
	 * @brief Constructeur par d�faut.
	 */
	CGrapheOriente() {}

	/**
	 * @brief Constructeur avec param�tres.
	 * @param vArcs Vecteur des arcs du graphe.
	 * @param vSommets Vecteur des sommets du graphe.
	 */
	CGrapheOriente(vector<CArc*> vArcs, vector<CSommet*> vSommets) { vGROarcs = vArcs; vGROsommets = vSommets; }

	/**
	 * @brief Constructeur de copie.
	 * @param GROgraphe Le graphe � copier.
	 */
	CGrapheOriente(const CGrapheOriente& GROgraphe);

	/**
	 * @brief Destructeur.
	 */
	~CGrapheOriente();

	/**
	 * @brief Accesseur pour les arcs du graphe.
	 * @return Le vecteur des arcs du graphe.
	 */
	vector<CArc*> GRO_GetArcs() const { return vGROarcs; };

	/**
	 * @brief Accesseur pour les sommets du graphe.
	 * @return Le vecteur des sommets du graphe.
	 */
	vector<CSommet*> GRO_GetSommets() const { return vGROsommets; };

	/**
	 * @brief Mutateur pour les arcs du graphe.
	 * @param vArcs Le nouveau vecteur des arcs du graphe.
	 */
	void GRO_SetArcs(vector<CArc*> vArcs) { vGROarcs = vArcs; }

	/**
	 * @brief Mutateur pour les sommets du graphe.
	 * @param vSommets Le nouveau vecteur des sommets du graphe.
	 */
	void GRO_SetSommets(vector<CSommet*> vSommets) { vGROsommets = vSommets; }

	/**
	 * @brief Recherche un arc dans le graphe.
	 * @param sDepart L'identifiant du sommet de d�part de l'arc � rechercher.
	 * @param sArrive L'identifiant du sommet d'arriv�e de l'arc � rechercher.
	 * @return Un it�rateur vers l'arc recherch�, ou vGROarcs.end() si l'arc n'est pas trouv�.
	 */
	vector<CArc*>::iterator GRO_RechercheArcs(string sDepart, string sArrive);

	/**
	 * @brief Recherche un sommet dans le graphe.
	 * @param sID L'identifiant du sommet � rechercher.
	 * @return Un it�rateur vers le sommet recherch�, ou vGROsommets.end() si le sommet n'est pas trouv�.
	 */
	vector<CSommet*>::iterator GRO_RechercheSommets(string sID);

	/**
	 * @brief Ajoute un sommet au graphe.
	 * @param sID L'identifiant du nouveau sommet.
	 */
	void GRO_AjouterSommet(string sID);

	/**
	 * @brief Ajoute un arc au graphe.
	 * @param sDepart L'identifiant du sommet de d�part du nouvel arc.
	 * @param sArrive L'identifiant du sommet d'arriv�e du nouvel arc.
	 */
	void GRO_AjouterArc(string sDepart, string sArrive);

	/**
	 * @brief Supprime un sommet du graphe.
	 * @param sRecherche L'identifiant du sommet � supprimer.
	 */
	void GRO_SupprimerSommet(string sRecherche);

	/**
	 * @brief Supprime un arc du graphe.
	 *
	 * Cette fonction recherche un arc sp�cifique dans le graphe orient� en utilisant les identifiants de d�part et d'arriv�e fournis.
	 * Si l'arc est trouv�, il est supprim� du graphe. Si l'arc n'est pas trouv�, un message d'erreur est affich�.
	 *
	 * @param sDepart L'identifiant du sommet de d�part de l'arc � supprimer.
	 * @param sArrive L'identifiant du sommet d'arriv�e de l'arc � supprimer.
	 */
	void GRO_SupprimerArc(string sDepart, string sArrive);

	/**
	 * @brief Affiche le graphe.
	 */
	void Afficher_Graph();
};

#endif // !CGRAPHORIENTE_H
