#include "CGraphe.h"
#include "CAffichage.h"

void CGraphe::GRA_AjouterArc(const string& sDepart, const string& sArrive)
{
	CGrapheOriente::GRO_AjouterArc(sDepart, sArrive);
	CGrapheOriente::GRO_AjouterArc(sArrive, sDepart);
}
