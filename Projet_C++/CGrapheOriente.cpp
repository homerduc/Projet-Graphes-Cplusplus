#include "CGrapheOriente.h"


CGrapheOriente::CGrapheOriente(const CGrapheOriente& GROgraphe)
{
	// Copie de la liste des arcs
	vGROarcs.reserve(GROgraphe.GRO_GetArcs().size()); // On alloue d'avance la taille voulue
	for (CArc* iIterateurArc : GROgraphe.GRO_GetArcs()) {
		vGROarcs.push_back(new CArc(*iIterateurArc)); // On ajoute une copie de chaque arc dans la liste de notre nouveau sommet
	}

	// Copie de la liste des sommets
	vGROsommets.reserve(GROgraphe.GRO_GetSommets().size());
	for (CSommet* iIterateurSommet : GROgraphe.GRO_GetSommets()) {
		vGROsommets.push_back(new CSommet(*iIterateurSommet));
	}
}

CGrapheOriente::~CGrapheOriente()
{
	// Suppression de la liste des arcs
	for (CArc* iIterateurArc : vGROarcs) {
		delete iIterateurArc;
	}
	vGROarcs.clear();

	// Suppression de la liste des sommets
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

void CGrapheOriente::GRO_AjouterSommet(string sID) 
{
		vGROsommets.push_back(new CSommet(sID));
		cout << endl << "Ajout dans le vecteur vGROsommets effectué !!!" << endl << endl;
}

void CGrapheOriente::GRO_AjouterArc(string sDepart,string sArrive) 
{
	vector<CSommet*>::iterator itRechercheDepart = GRO_RechercheSommets(sDepart);
	vector<CSommet*>::iterator itRechercheArrive = GRO_RechercheSommets(sArrive);

	if (itRechercheDepart != vGROsommets.end() && itRechercheArrive!=vGROsommets.end())
	{
		CArc* pNEWarc = new CArc(sDepart, sArrive);
		(*itRechercheDepart)->SOM_Ajouter_Entrants(pNEWarc);
		(*itRechercheArrive)->SOM_Ajouter_Sortants(pNEWarc);
		vGROarcs.push_back(pNEWarc);
		cout << endl << "Ajout dans le vecteur vGROarcs et les vecteurs des sommets concerné par l'arc!!!" << endl << endl;
	}
}

void CGrapheOriente::GRO_SupprimerSommet(string sID)
{
	vector<CSommet*>::iterator itSupprimerSommet = GRO_RechercheSommets(sID);
	
	for (vector<CArc*>::iterator itRecherche = vGROarcs.end(); itRecherche != vGROarcs.begin(); itRecherche--) {
		if ((*itRecherche)->ARC_GetSommetArrive() == sID || (*itRecherche)->ARC_GetSommetDepart() == sID)
		{
			GRO_SupprimerArc((*itRecherche)->ARC_GetSommetDepart(), (*itRecherche)->ARC_GetSommetArrive());
		}
	}
	vGROsommets.erase(itSupprimerSommet);
}

void CGrapheOriente::GRO_SupprimerArc(string sDepart, string sArrive)
{
	vector<CArc*>::iterator itSupprimerArc = GRO_RechercheArcs(sDepart,sArrive);

	vector<CSommet*>::iterator itRechercheSommetArrive= GRO_RechercheSommets(sArrive);
	(*itRechercheSommetArrive)->SOM_SupprimerArc((*itSupprimerArc)->ARC_GetSommetDepart(), (*itSupprimerArc)->ARC_GetSommetArrive());
	
	itRechercheSommetArrive = GRO_RechercheSommets(sDepart);
	(*itRechercheSommetArrive)->SOM_SupprimerArc((*itSupprimerArc)->ARC_GetSommetDepart(), (*itSupprimerArc)->ARC_GetSommetArrive());

	delete (*itSupprimerArc);
	vGROarcs.erase(itSupprimerArc);
}

void CGrapheOriente::Afficher_Graph()
{
	for (vector<CSommet*>::iterator itSommets = vGROsommets.begin(); itSommets < vGROsommets.end(); itSommets++) {
		cout << (*itSommets);
	}
}

