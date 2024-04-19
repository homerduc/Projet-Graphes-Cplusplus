#pragma once
#include "CGrapheOriente.h"

class CGraphe : public CGrapheOriente
{
private:
	//vector<CArc*> vGROarcs; // Vecteur des arcs du graphe.
	//vector<CSommet*> vGROsommets; // Vecteur des sommets du graphe.
public:

	void GRA_AjouterArc(const string& sDepart, const string& sArrive);
   
	void Afficher_Graphe();
};

