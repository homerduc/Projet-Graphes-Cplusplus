#include "CGraphe.h"
#include "CAffichage.h"

void CGraphe::GRA_AjouterArc(string sDepart, string sArrive)
{
	CGrapheOriente::GRO_AjouterArc(sDepart, sArrive);
	CGrapheOriente::GRO_AjouterArc(sArrive, sDepart);
}

void CGraphe::Afficher_Graphe()
{
	CAffichage::AFC_Afficher_Graphe(this);
}
