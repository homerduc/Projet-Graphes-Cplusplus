#ifndef CGRAPHORIENTE_H
#define CGRAPHORIENTE_H

#include "CArc.h"
#include "CSommet.h"
#include <iostream>
#include <algorithm>
using namespace std;

class CGrapheOriente
{
private:
	vector<CArc*> vGROarcs;
	vector<CSommet*> vGROsommets;
public:

	#pragma region CONSTRUCTEURS & DESTRUCTEUR

	CGrapheOriente() {}
	CGrapheOriente(vector<CArc*> vArcs, vector<CSommet*> vSommets) { vGROarcs = vArcs; vGROsommets = vSommets; }
	CGrapheOriente(const CGrapheOriente& GROgraphe);
	~CGrapheOriente();

	#pragma endregion

	#pragma region ACCESSEURS SET & GET

	vector<CArc*> GRO_GetArcs() const { return vGROarcs; };
	vector<CSommet*> GRO_GetSommets() const { return vGROsommets; };

	void GRO_SetArcs(vector<CArc*> vArcs) { vGROarcs = vArcs; }
	void GRO_SetSommets(vector<CSommet*> vSommets) { vGROsommets = vSommets; }

	#pragma endregion

	unsigned int GRO_RechercheArcs(string sDepart,string sArrive);
	unsigned int GRO_RechercheSommets(string sID);

	void GRO_AjouterSommet(CSommet* pSOMsommet);
	void GRO_AjouterArc(string sDepart, string sArrive);

	void GRO_SupprimerSommet(string sRecherche);
	void GRO_SupprimerArc(string sDepart, string sArrive);

	
};

#endif // !CGRAPHORIENTE_H




