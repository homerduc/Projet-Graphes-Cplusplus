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
	//vector<CArc*>::iterator itRechercheArc = find(vGROarcs.begin(), vGROarcs.end(), pSOMtemp);
	for (vector<CArc*>::iterator itRechercheArc = vGROarcs.begin(); itRechercheArc != vGROarcs.end(); itRechercheArc++) {
		if ((*itRechercheArc)->ARC_GetSommetArrive() == sArrive && (*itRechercheArc)->ARC_GetSommetDepart() == sDepart)
			return itRechercheArc;
	}
	return vGROarcs.end();
}

vector<CSommet*>::iterator CGrapheOriente::GRO_RechercheSommets(string sID)
{
	//vector<CSommet*>::iterator itRechercheSommet = find(vGROsommets.begin(), vGROsommets.end(), pSOMtemp);
	for (vector<CSommet*>::iterator itRechercheSommet = vGROsommets.begin(); itRechercheSommet != vGROsommets.end(); itRechercheSommet++) {
		if ((*itRechercheSommet)->SOM_GetID() == sID)
			return itRechercheSommet;
	}
	return vGROsommets.end();
}

void CGrapheOriente::GRO_AjouterSommet(string sID)
{
	vGROsommets.push_back(new CSommet(sID));
	CAffichage::AFC_AffichageAjout(sID);
}

void CGrapheOriente::GRO_AjouterArc(string sDepart, string sArrive)
{
	vector<CSommet*>::iterator itRechercheDepart = GRO_RechercheSommets(sDepart);
	vector<CSommet*>::iterator itRechercheArrive = GRO_RechercheSommets(sArrive);

	if (itRechercheDepart != vGROsommets.end() && itRechercheArrive != vGROsommets.end())
	{
		cout << "+----------------------------------------------------------------+" << endl;
		cout << "| "<<CAffichage::COL_Creation()<<" cr\202ation de l arc : <" << sDepart << "> ---> <" << sArrive << "> "<<CAffichage::COL_Reset()<< endl;
		CArc* pNEWarc = new CArc(sDepart, sArrive);
		vGROarcs.push_back(pNEWarc);
		(*itRechercheDepart)->SOM_Ajouter_Sortants(pNEWarc);
		(*itRechercheArrive)->SOM_Ajouter_Entrants(pNEWarc);
		cout <<CAffichage::COL_Reset()<< "+----------------------------------------------------------------+" << endl << endl;
		return;
	}
	else if(itRechercheDepart == vGROsommets.end() && itRechercheArrive != vGROsommets.end())
	{
		cout << CAffichage::COL_Error() << " ERROR : le sommet <"<<sDepart<<"> n'existe pas donc on ne peut pas cree l arc <" << sDepart << "> ---> <" << sArrive << "> " <<CAffichage::COL_Reset() << endl<< endl;
	}
	else if (itRechercheDepart != vGROsommets.end() && itRechercheArrive == vGROsommets.end())
	{
		cout << CAffichage::COL_Error() << " ERROR : le sommet <" << sArrive << "> n'existe pas donc on ne peut pas cree l arc <" << sDepart << "> ---> <" << sArrive << "> " << CAffichage::COL_Reset() << endl<< endl;
	}
	else {
		cout << CAffichage::COL_Error() << " ERROR : les sommets <" << sDepart << "> et <"<<sArrive<<" n'existe pas donc on ne peut pas cree l arc <" << sDepart << "> ---> <" << sArrive << "> " << CAffichage::COL_Reset() << endl<< endl;

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
	vector<CArc*>::iterator itSupprimerArc = GRO_RechercheArcs(sDepart, sArrive);
	if (itSupprimerArc != vGROarcs.end()) {

		vector<CSommet*>::iterator itRechercheSommeDepart = GRO_RechercheSommets(sDepart);
		vector<CSommet*>::iterator itRechercheSommeArrive = GRO_RechercheSommets(sArrive);

		(*itRechercheSommeDepart)->SOM_SupprimerArc(sDepart,sArrive);
		(*itRechercheSommeArrive)->SOM_SupprimerArc(sDepart,sArrive);

		delete (*itSupprimerArc);
		vGROarcs.erase(itSupprimerArc);
		CAffichage::AFC_AffichageSuppr(sDepart, sArrive);
	}
	else
	{
		cout << CAffichage::COL_Error() << "L arc reliant <" << sDepart << "> et <" << sArrive << " n existe pas, impossible de le supprimer" << endl<< endl;
	}
}

void CGrapheOriente::Afficher_Graph()
{
	for (vector<CSommet*>::iterator itSommets = vGROsommets.begin(); itSommets < vGROsommets.end(); itSommets++) {
		(*itSommets)->Affichage_du_Sommet();
	}
}