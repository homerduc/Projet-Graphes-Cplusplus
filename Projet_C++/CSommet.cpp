#include "CSommet.h"
#include "CArc.h"
#include <iostream>

CSommet::CSommet()
{
	sSOMid = "";
}

CSommet::CSommet(const CSommet& SOMsommet)
{
	sSOMid = SOMsommet.SOM_GetID();

	vSOM_ArcEntrants.reserve(SOMsommet.SOM_GetEntrants().size()); // On alloue d'avance la taille voulue
	for (CArc* iIterateurArc : SOMsommet.SOM_GetEntrants()) {
		vSOM_ArcEntrants.push_back(new CArc(*iIterateurArc)); // On ajoute une copie de chaque arc dans la liste de notre nouveau sommet
	}

	vSOM_ArcSortants.reserve(SOMsommet.SOM_GetSortants().size());
	for (CArc* iIterateurArc : SOMsommet.SOM_GetSortants()) {
		vSOM_ArcSortants.push_back(new CArc(*iIterateurArc));
	}
}

CSommet::~CSommet()
{
	sSOMid.clear();

	for (CArc* iIterateurArc : vSOM_ArcEntrants) {
		delete iIterateurArc;
	}
	vSOM_ArcEntrants.clear();

	for (CArc* iIterateurArc : vSOM_ArcSortants) {
		delete iIterateurArc;
	}
	vSOM_ArcSortants.clear();
}

void CSommet::Affichage_du_Sommet()
{
	cout << "Le sommet est <" << SOM_GetID() << ">" << endl;
	SOM_Afficher_Entrants();
	SOM_Afficher_Sortants();
}

void CSommet::SOM_Afficher_Entrants()
{
	cout << "           Les arcs Entrants de <" << SOM_GetID() << "> sont : " << endl;
	cout <<CColor::COL_Arcs()<< "           +---------------------------------------------------------+" << endl;
	for (unsigned int uiPosition = 0; uiPosition < vSOM_ArcEntrants.size(); uiPosition++) {
		cout << "           | l'arc " << uiPosition << " : provenant du sommet <" << vSOM_ArcEntrants[uiPosition]->ARC_GetSommetDepart() << "> ..." << endl;
	}
	cout << "           +---------------------------------------------------------+" << CColor::COL_Reset() << endl;
}

void  CSommet::SOM_Afficher_Sortants()
{
	cout << "           Les arcs Sortants de <" << SOM_GetID() << "> sont : " << endl;
	cout <<CColor::COL_Arcs()<< "           +---------------------------------------------------------+" << endl;
	for (unsigned int uiPosition = 0; uiPosition < vSOM_ArcSortants.size(); uiPosition++) {
		cout << "           | l'arc " << uiPosition << " : allant vers le sommet <" << vSOM_ArcSortants[uiPosition]->ARC_GetSommetArrive() << "> ... " << endl;
	}
	cout << "           +---------------------------------------------------------+" << CColor::COL_Reset() << endl;

}

void CSommet::SOM_Ajouter_Entrants(CArc* pARCarc)
{
	if (pARCarc->ARC_GetSommetArrive() == SOM_GetID())
	{
		vSOM_ArcEntrants.push_back(pARCarc);
		cout << "| " << CColor::COL_Ajout() << " Ajout dans le vecteur arcs Entrant de "<< SOM_GetID() << CColor::COL_Reset() << endl;
	}
	else
	{
		cout << CColor::COL_Error() << " ERROR : Cet arc n'arrive pas jusque <" << SOM_GetID() << "> donc ajout dans arc entrant impossible" << CColor::COL_Reset() << endl;
	}
}

void CSommet::SOM_Ajouter_Sortants(CArc* pARCarc)
{
	if (pARCarc->ARC_GetSommetDepart() == SOM_GetID())
	{
		vSOM_ArcSortants.push_back(pARCarc);
		cout <<"| " << CColor::COL_Ajout() << " Ajout dans le vecteur arcs sortants de " << SOM_GetID() << CColor::COL_Reset() << endl;
	}
	else {
		cout <<CColor::COL_Error()<< " ERROR : Cet arc ne sort pas de <" << SOM_GetID() << "> donc ajout dans arc_sortant impossible" << CColor::COL_Reset() << endl;
	}
}

vector<CArc*>::iterator  CSommet::SOM_RechercheEntrant(string sDepart)
{
	vector<CArc*>::iterator it;
	CArc* parctemp = new CArc(sDepart, sSOMid);
	it = find(vSOM_ArcEntrants.begin(), vSOM_ArcEntrants.end(), parctemp);
	if (it != vSOM_ArcEntrants.end())
		return it;
	return it;
}

vector<CArc*>::iterator CSommet::SOM_RechercheSortant(string sArrive)
{
	vector<CArc*>::iterator it;
	CArc* parctemp = new CArc(sSOMid, sArrive);
	it = find(vSOM_ArcEntrants.begin(), vSOM_ArcEntrants.end(), parctemp);
	if (it != vSOM_ArcEntrants.end())
		return it;
	return it;
}

void CSommet::SOM_SupprimerArc(string sDepart, string sArrive)
{
	vector<CArc*>::iterator itSupprimerArc = SOM_RechercheEntrant(sDepart);
	if (itSupprimerArc != vSOM_ArcEntrants.end())
	{
		delete (*itSupprimerArc);
		vSOM_ArcEntrants.erase(itSupprimerArc);
	}

	itSupprimerArc = SOM_RechercheSortant(sDepart);
	if (itSupprimerArc != vSOM_ArcSortants.end())
	{
		delete (*itSupprimerArc);
		vSOM_ArcEntrants.erase(itSupprimerArc);
	}
}

