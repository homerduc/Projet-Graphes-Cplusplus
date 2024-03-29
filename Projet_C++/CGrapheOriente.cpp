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

unsigned int CGrapheOriente::GRO_RechercheArcs(string sDepart, string sArrive)
{
	for (unsigned int uiPosition = 0; uiPosition < vGROarcs.size(); uiPosition++)
	{
		if (vGROarcs[uiPosition]->ARC_GetSommetDepart() == sDepart && vGROarcs[uiPosition]->ARC_GetSommetArrive() == sArrive) {
			cout << "l'arc défini par le sommet de départ <" << sDepart << "> et le sommet d'arrive <" << sArrive << "> est a la position "<<uiPosition<< endl;
			return uiPosition;
		}
	}
	cout << "l'arc défini par le sommet de départ <" << sDepart << "> et le sommet d'arrive <" << sArrive << "> n'existe pas ! " << endl;
	return 0;
}

unsigned int CGrapheOriente::GRO_RechercheSommets(string sID)
{
	for (unsigned int uiPosition = 0; uiPosition < vGROsommets.size(); uiPosition++)
	{
		if (vGROsommets[uiPosition]->SOM_GetID() == sID) {
			cout << "Le sommet ayant comme identifiant <" << sID << "> se trouve a la position!"<<uiPosition<< endl;
			return uiPosition;
		}
	}
	cout << "Le sommet ayant comme identifiant <" << sID << "> n'existe pas ! " << endl;
	return 0;
}

void CGrapheOriente::GRO_AjouterSommet(CSommet* pSOMsommet)
{
		vGROsommets.push_back(pSOMsommet);
		cout << endl << "Ajout dans le vecteur vGROsommets effectue !!!" << endl << endl;
}

void CGrapheOriente::GRO_AjouterArc(string sDepart,string sArrive) 
{
	unsigned int uiVerifDepart = GRO_RechercheSommets(sDepart);
	unsigned int uiVerifArrive = GRO_RechercheSommets(sArrive);
	if (uiVerifArrive !=0 && uiVerifDepart !=0)
	{
		CArc* pARCnewArc = new CArc(sDepart, sArrive);
		vGROsommets[uiVerifDepart]->SOM_Ajouter_Sortants(pARCnewArc);
		vGROsommets[uiVerifArrive]->SOM_Ajouter_Entrants(pARCnewArc);
		vGROarcs.push_back(pARCnewArc);
		cout << endl << "Ajout dans le vecteur vGROarcs effectue !!!" << endl << endl;
	}
}

void CGrapheOriente::GRO_SupprimerSommet(string sRecherche)
{
	unsigned int uiPosition = GRO_RechercheSommets(sRecherche);
	if (uiPosition != 0)
	{
		delete vGROsommets[uiPosition] ;
		cout << "Le sommet <" << sRecherche << "> a ete supprimer ! " << endl << endl;
	}
}

void CGrapheOriente::GRO_SupprimerArc(string sDepart, string sArrive)
{
	unsigned int uiPosition = GRO_RechercheArcs(sDepart,sArrive);
	if (uiPosition != 0)
	{
		vGROsommets.erase(vGROsommets.begin() + uiPosition);
		cout << "L'arc defini par son sommet de depart <" << sDepart << "> et son sommet d arrive <" << sArrive << "> a ete supprimer !" << endl << endl;
	}
	/*l'arc doit aussi etre supprimer dans le vecteur de la Csommet*/
}

