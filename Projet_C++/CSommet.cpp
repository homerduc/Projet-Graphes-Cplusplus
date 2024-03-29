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
	vSOM_ArcEntrants = SOMsommet.SOM_GetEntrants(); // non 
	vSOM_ArcSortants = SOMsommet.SOM_GetSortants(); // non 
}

CSommet::~CSommet()
{
	sSOMid.clear();
	vSOM_ArcEntrants.clear();
	vSOM_ArcSortants.clear();
	//changer car les objets retent en mémoire
	
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

void CSommet::operator+(CArc* pArc)
{
	char choix;
	cout << "Dans quelle liste de <"<<SOM_GetID()<<"> voulais vous ajouter l'arc"<<endl<<"Liste d arc Entrant(e) | Liste d arc Sortant(s) : ";
	cin >> choix;
	switch (choix)
	{
	case'e': SOM_Ajouter_Entrants(pArc);
		break;

	case's': SOM_Ajouter_Sortants(pArc);
		break;
	}
}



