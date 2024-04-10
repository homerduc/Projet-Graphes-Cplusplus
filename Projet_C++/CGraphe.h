#pragma once
#include "CGrapheOriente.h"

class CGraphe : public CGrapheOriente
{
private:
	//vector<CArc*> vGROarcs; // Vecteur des arcs du graphe.
	//vector<CSommet*> vGROsommets; // Vecteur des sommets du graphe.
public:

	void GRA_AjouterArc(string sDepart, string sArrive);
   
	void Afficher_Graphe();
};

