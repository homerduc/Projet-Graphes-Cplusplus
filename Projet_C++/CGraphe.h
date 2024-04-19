#ifndef CGRAPHE_H
#define CGRAPHE_H
#include "CGrapheOriente.h"

/**
 * @class CGraphe
 * @brief Classe repr�sentant un graphe non-orient�
 */
class CGraphe : public CGrapheOriente
{
private:
	//vector<CArc*> vGROarcs; // Vecteur des arcs du graphe.
	//vector<CSommet*> vGROsommets; // Vecteur des sommets du graphe.
public:

	/**
	 * Ajoute un arc au graphe non-orient�
	 *
	 * @param sDepart Le sommet de d�part de l'arc
	 *
	 * @param sArrive Le sommet d'arriv�e de l'arc
	 */
	void GRA_AjouterArc(const string& sDepart, const string& sArrive);
};

#endif // !CGRAPHE