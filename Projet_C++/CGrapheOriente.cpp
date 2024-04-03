#include "CGrapheOriente.h"


CGrapheOriente::CGrapheOriente(const CGrapheOriente& GROgraphe)
{
	vGROarcs.reserve(GROgraphe.GRO_GetArcs().size()); // On alloue d'avance la taille voulue
	for (CArc* iIterateurArc : GROgraphe.GRO_GetArcs()) {
		vGROarcs.push_back(new CArc(*iIterateurArc)); // On ajoute une copie de chaque arc dans la liste de notre nouveau sommet
	}

	vGROsommets.reserve(GROgraphe.GRO_GetSommets().size());
	for (CSommet* iIterateurSommet : GROgraphe.GRO_GetSommets()) {
		vGROsommets.push_back(new CSommet(*iIterateurSommet));
	}
}

CGrapheOriente::~CGrapheOriente()
{
	for (CArc* iIterateurArc : vGROarcs) {
		delete iIterateurArc;
	}
	vGROarcs.clear();

	for (CSommet* iIterateurSommet : vGROsommets) {
		delete iIterateurSommet;
	}
	vGROsommets.clear();
}

vector<CArc*>::iterator CGrapheOriente::GRO_RechercheArcs(string sDepart, string sArrive)
{
	CArc* pSOMtemp = new CArc(sDepart,sArrive);
	vector<CArc*>::iterator itRechercheArc = find(vGROarcs.begin(), vGROarcs.end(), pSOMtemp);
	if (itRechercheArc != vGROarcs.end())
		return itRechercheArc;
}

vector<CSommet*>::iterator CGrapheOriente::GRO_RechercheSommets(string sID)
{
	CSommet* pSOMtemp = new CSommet(sID);
	vector<CSommet*>::iterator itRechercheSommet = find(vGROsommets.begin(), vGROsommets.end(), pSOMtemp);
	if (itRechercheSommet != vGROsommets.end())
		return itRechercheSommet;

}

void CGrapheOriente::GRO_AjouterSommet(CSommet* pSOMsommet) 
{
		vGROsommets.push_back(pSOMsommet);
		cout << endl << "Ajout dans le vecteur vGROsommets effectue !!!" << endl << endl;
}

void CGrapheOriente::GRO_AjouterArc(string sDepart,string sArrive) 
{
	
}

void CGrapheOriente::GRO_SupprimerSommet(string sID)
{
	vector<CSommet*>::iterator itSupprimerSommet = GRO_RechercheSommets(sID);
	vGROsommets.erase(itSupprimerSommet);


}

void CGrapheOriente::GRO_SupprimerArc(string sDepart, string sArrive)
{
	vector<CArc*>::iterator itSupprimerArc = GRO_RechercheArcs(sDepart,sArrive);
}

