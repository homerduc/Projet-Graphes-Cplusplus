#include "CGrapheOriente.h"
#include "CAffichage.h"

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
	vector<CSommet*>::iterator itRechercheDepart = GRO_RechercheSommets(sID);
	if (itRechercheDepart == vGROsommets.end()) {
		vGROsommets.push_back(new CSommet(sID));
		CAffichage::AFC_AffichageAjoutSommet(sID);
	}
	else {
		CAffichage::AFC_Erreur_ajoutSommet(sID);
	}
}

void CGrapheOriente::GRO_AjouterArc(string sDepart, string sArrive)
{
	vector<CSommet*>::iterator itRechercheDepart = GRO_RechercheSommets(sDepart);
	vector<CSommet*>::iterator itRechercheArrive = GRO_RechercheSommets(sArrive);
	//vector<CArc*>::iterator itRechercherAce = GRO_RechercheArcs(sDepart, sArrive);

		if (itRechercheDepart != vGROsommets.end() && itRechercheArrive != vGROsommets.end())
		{
#pragma region LES DEUX SOMMETS EXISTENT
			CArc* pNEWarc = new CArc(sDepart, sArrive);
			vGROarcs.push_back(pNEWarc);
			(*itRechercheDepart)->SOM_Ajouter_Sortants(pNEWarc);
			(*itRechercheArrive)->SOM_Ajouter_Entrants(pNEWarc);

			CAffichage::AFC_AffichageAjoutArc(sDepart, sArrive);
			return;
#pragma endregion
		}
		else if (itRechercheDepart == vGROsommets.end() && itRechercheArrive != vGROsommets.end())
		{
#pragma region DEPART INEXISTANT 
			CAffichage::AFC_Erreur_ajoutArc(sDepart, sArrive, DEPART_inconnu);
#pragma endregion
		}
		else if (itRechercheDepart != vGROsommets.end() && itRechercheArrive == vGROsommets.end())
		{
#pragma region ARRIVEE INEXISTANTE
			CAffichage::AFC_Erreur_ajoutArc(sDepart, sArrive, ARRIVE_inconnu);
#pragma endregion
		}
		else 
		{
#pragma region LES DEUX INEXISTANT
			CAffichage::AFC_Erreur_ajoutArc(sDepart, sArrive, DEPART_ARRIVE_inconnu);
#pragma endregion
		}
}

void CGrapheOriente::GRO_SupprimerSommet(string sID)
{

	string sArrive, sDepart;
	vector<CSommet*>::iterator itSupprimerSommet = GRO_RechercheSommets(sID);
	if (itSupprimerSommet != vGROsommets.end()) {

		string sArrive, sDepart;
		for (unsigned int uiPositionArc = 0; uiPositionArc < vGROarcs.size(); )
		{

			sDepart = vGROarcs[uiPositionArc]->ARC_GetSommetDepart();
			sArrive = vGROarcs[uiPositionArc]->ARC_GetSommetArrive();
			if (sDepart == sID || sArrive == sID) {
				GRO_SupprimerArc(sDepart, sArrive);
			}
			else
			{
				uiPositionArc++;
			}
		}

		CAffichage::AFC_AffichageSupprSommet(sID);
		//delete (*itSupprimerSommet);
		vGROsommets.erase(itSupprimerSommet);
	}

}

void CGrapheOriente::GRO_SupprimerArc(string sDepart, string sArrive)
{
#pragma region CA FONCTIONNE !!!!!!!
	vector<CArc*>::iterator itSupprimerArc = GRO_RechercheArcs(sDepart, sArrive);
	if (itSupprimerArc != vGROarcs.end()) {

		vector<CSommet*>::iterator itRechercheSommeDepart = GRO_RechercheSommets(sDepart);
		vector<CSommet*>::iterator itRechercheSommeArrive = GRO_RechercheSommets(sArrive);

		(*itRechercheSommeDepart)->SOM_SupprimerArcSortant(sArrive);
		(*itRechercheSommeArrive)->SOM_SupprimerArcEntrant(sDepart);

		//delete (*itSupprimerArc);
		CAffichage::AFC_AffichageSupprArc(sDepart, sArrive);
		vGROarcs.erase(itSupprimerArc);

	}
	else
	{
		cout << ERREUR_couleur << "ERROR : L arc reliant <" << sDepart << "> et <" << sArrive << " n existe pas, impossible de le supprimer" << RESAURER_couleur << endl << endl;
	}
#pragma endregion
}

void CGrapheOriente::Afficher_Graph()
{
	CAffichage::AFC_Afficher_Graph(this);
}