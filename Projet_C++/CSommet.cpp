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

/*void CSommet::Affichage_du_Sommet()
{
	cout << " <" << SOM_GetID() << "> est un sommet contenant \27" << endl;
	SOM_Afficher_Entrants();
	SOM_Afficher_Sortants();
}

void CSommet::SOM_Afficher_Entrants()
{
	cout << "           Les arcs Entrants de <" << SOM_GetID() << "> sont : " << endl;
	cout << ARC_couleur << "           +---------------------------------------------------------+" << endl;
	for (unsigned int uiPosition = 0; uiPosition < vSOM_ArcEntrants.size(); uiPosition++) {
		cout << "           | l'arc " << uiPosition << " : provenant du sommet <" << vSOM_ArcEntrants[uiPosition]->ARC_GetSommetDepart() << "> ..." << endl;
	}
	cout << "           +---------------------------------------------------------+" << RESAURER_couleur << endl;
}

void  CSommet::SOM_Afficher_Sortants()
{
	cout << "           Les arcs Sortants de <" << SOM_GetID() << "> sont : " << endl;
	cout << ARC_couleur << "           +---------------------------------------------------------+" << endl;
	for (unsigned int uiPosition = 0; uiPosition < vSOM_ArcSortants.size(); uiPosition++) {
		cout << "           | l'arc " << uiPosition << " : allant vers le sommet <" << vSOM_ArcSortants[uiPosition]->ARC_GetSommetArrive() << "> ... " << endl;
	}
	cout << "           +---------------------------------------------------------+" << RESAURER_couleur << endl<< endl;

}*/

void CSommet::SOM_Ajouter_Entrants(CArc* pARCarc)
{
	if (pARCarc->ARC_GetSommetArrive() == SOM_GetID())
	{
		vSOM_ArcEntrants.push_back(pARCarc);
		//cout << "| " <<AJOUT_couleur << " Ajout dans le vecteur arcs Entrant de " << SOM_GetID() << RESAURER_couleur << endl;
	}
	else
	{
		cout << " ERROR : Cet arc n'arrive pas jusque <" << SOM_GetID() << "> donc ajout dans arc entrant impossible" << endl;
	}
}

void CSommet::SOM_Ajouter_Sortants(CArc* pARCarc)
{
	if (pARCarc->ARC_GetSommetDepart() == SOM_GetID())
	{
		vSOM_ArcSortants.push_back(pARCarc);
		//cout << "| " <<AJOUT_couleur << " Ajout dans le vecteur arcs sortants de " << SOM_GetID() << RESAURER_couleur << endl;
	}
	else {
		cout << " ERROR : Cet arc ne sort pas de <" << SOM_GetID() << "> donc ajout dans arc_sortant impossible" << endl;
	}
}

vector<CArc*>::iterator  CSommet::SOM_RechercheEntrant(string sDepart)
{
	for (vector<CArc*>::iterator itEntrant = vSOM_ArcEntrants.begin(); itEntrant != vSOM_ArcEntrants.end(); itEntrant++) {
		if ((*itEntrant)->ARC_GetSommetArrive() == SOM_GetID() && (*itEntrant)->ARC_GetSommetDepart() == sDepart)
			return itEntrant;
	}
	return vSOM_ArcEntrants.end();
}

vector<CArc*>::iterator CSommet::SOM_RechercheSortant(string sArrive)
{
	for (vector<CArc*>::iterator itSortant = vSOM_ArcSortants.begin(); itSortant != vSOM_ArcSortants.end(); itSortant++) {
		if ((*itSortant)->ARC_GetSommetDepart() == SOM_GetID() && (*itSortant)->ARC_GetSommetArrive()== sArrive)
			return itSortant;
	}
	return vSOM_ArcSortants.end();
}

void CSommet::SOM_SupprimerArcEntrant(string sDepart)
{
	vector<CArc*>::iterator itSupprimerArcEntrant = SOM_RechercheEntrant(sDepart);

	if (itSupprimerArcEntrant != vSOM_ArcEntrants.end())
	{
		//delete (*itSupprimerArcEntrant);
		vSOM_ArcEntrants.erase(itSupprimerArcEntrant);
	}
	
}

void CSommet::SOM_SupprimerArcSortant(string sArrive)
{
	vector<CArc*>::iterator itSupprimerArcSortantant = SOM_RechercheSortant(sArrive);
	if (itSupprimerArcSortantant != vSOM_ArcSortants.end())
	{
		//delete (*itSupprimerArcSortantant);
		vSOM_ArcSortants.erase(itSupprimerArcSortantant);
	}
}

