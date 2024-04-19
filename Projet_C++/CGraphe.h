#ifndef CGRAPHE_H
#define CGRAPHE_H
#include "CGrapheOriente.h"

/**
 * @class CGraphe
 * @brief Classe représentant un graphe non-orienté
 */
class CGraphe : public CGrapheOriente
{
private:
	//vector<CArc*> vGROarcs; // Vecteur des arcs du graphe.
	//vector<CSommet*> vGROsommets; // Vecteur des sommets du graphe.
public:

	/**
	 * Ajoute un arc au graphe non-orienté
	 *
	 * @param sDepart Le sommet de départ de l'arc
	 *
	 * @param sArrive Le sommet d'arrivée de l'arc
	 */
	void GRA_AjouterArc(const string& sDepart, const string& sArrive);
};

#endif // !CGRAPHE