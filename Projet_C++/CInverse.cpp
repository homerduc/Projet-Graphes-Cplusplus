#include "CInverse.h"

CGrapheOriente* CInverse::INV_Inverse(const CGrapheOriente& oGraphe)
{
	CGrapheOriente* nouveauGraphe = new CGrapheOriente();

	for (CSommet* SOMsommet : oGraphe.GRO_GetSommets())
	{
		nouveauGraphe->GRO_AjouterSommet(SOMsommet->SOM_GetID());
	}
	for (CArc* ARCarc : oGraphe.GRO_GetArcs())
	{
		nouveauGraphe->GRO_AjouterArc(ARCarc->ARC_GetSommetArrive(), ARCarc->ARC_GetSommetDepart());
	}
	return nouveauGraphe;
}
