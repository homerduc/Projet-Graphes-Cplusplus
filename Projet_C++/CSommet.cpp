#include "CSommet.h"
#include "CArc.h"
#include <iostream>

CSommet::CSommet()
{
	sSOMid = "Bonjour";
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
	cout << " Les arcs Entrants de <" << SOM_GetID() << "> sont : " << endl;
	cout << "   +----------------------------------------------------------------------------------------+" << endl;
	for (unsigned int uiPosition = 0; uiPosition < vSOM_ArcEntrants.size(); uiPosition++) {
		cout << "   | l'arc " << uiPosition << " : provenant du sommet <" << vSOM_ArcEntrants[uiPosition]->ARC_GetSommetDepart()<< "> ..." << endl;
	}
	cout<< "   +----------------------------------------------------------------------------------------+" << endl << endl;
}

void  CSommet::SOM_Afficher_Sortants()
{
	cout << " Les arcs Sortants de <"<<SOM_GetID()<<"> sont : " << endl;
	cout << "   +----------------------------------------------------------------------------------------+" << endl;
	for (unsigned int uiPosition = 0; uiPosition < vSOM_ArcSortants.size(); uiPosition++) {
		cout << "   | l'arc " << uiPosition << " : allant vers le sommet <" << vSOM_ArcSortants[uiPosition]->ARC_GetSommetArrive() << "> ... " << endl;
	}
	cout << "   +----------------------------------------------------------------------------------------+" << endl << endl;

}

void CSommet::SOM_Ajouter_Entrants(CArc* pARCarc)
{
	if (pARCarc->ARC_GetSommetArrive() == SOM_GetID())
	{
		vSOM_ArcEntrants.push_back(pARCarc);
		cout << endl << "Ajout dans le vecteur arcs entrants effectue !!!" << endl << endl;
	}
	else
	{
		cout << endl << " ERROR : Cet arc n'arrive pas jusque <" << SOM_GetID() << "> donc ajout dans arc entrant impossible" << endl << endl;
	}
}

void CSommet::SOM_Ajouter_Sortants(CArc* pARCarc)
{
	if (pARCarc->ARC_GetSommetDepart() == SOM_GetID())
	{
		vSOM_ArcSortants.push_back(pARCarc);
		cout << endl << "Ajout dans le vecteur arcs sortants effectue !!!" << endl << endl;
	}
	else {
		cout << " ERROR : Cet arc ne sort pas de <" << SOM_GetID() << "> donc ajout dans arc_sortant impossible" << endl << endl;
	}
}

vector<CArc*>::iterator  CSommet::SOM_RechercheEntrant(string sArrive)
{
	vector<CArc*>::iterator it;
	CArc* parctemp = new CArc(sSOMid, sArrive);
	it = find(vSOM_ArcEntrants.begin(), vSOM_ArcEntrants.end(), parctemp);
	if (it != vSOM_ArcEntrants.end())
		return it;

}


