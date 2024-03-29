#ifndef CGRAPHORIENTE_H
#define CGRAPHORIENTE_H

#include "CArc.h"
#include "CSommet.h"

#include <iostream>
using namespace std;

class CGrapheOriente
{
private:
	vector<CArc*> vGROarcs;
	vector<CSommet*> vGROsommets;
public:

	//CGrapheOriente() {};
	CGrapheOriente(vector<CArc*> vArcs, vector<CSommet*> vSommets) { vGROarcs = vArcs; vGROsommets = vSommets; }
	CGrapheOriente(const CGrapheOriente& GROgraphe);
	//~CGrapheOriente();

	vector<CArc*> GRO_GetArcs();
	vector<CSommet*> GRO_GetSommets();

	GRO_SetArcs();
	GRO_SetSommets();



	GRO_RechercheArcs();
	GRO_RechercheSommets();


	
};

#endif // !CGRAPHORIENTE_H




