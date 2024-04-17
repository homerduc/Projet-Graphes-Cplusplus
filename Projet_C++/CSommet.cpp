#include "CSommet.h"
#include "CArc.h"
#include <iostream>
#include "CAffichage.h"

CSommet::CSommet()
{
	sSOMid = "";
}

CSommet::CSommet(const CSommet& SOMsommet)
{
	sSOMid = SOMsommet.SOM_GetID();

	vSOM_ArcEntrants.reserve(SOMsommet.SOM_GetEntrants().size()); // On alloue d'avance la taille voulue

	for (CArc* iIterateurArc : SOMsommet.SOM_GetEntrants())
	{
		vSOM_ArcEntrants.push_back(new CArc(*iIterateurArc)); // On ajoute une copie de chaque arc dans la liste de notre nouveau sommet
	}

	vSOM_ArcSortants.reserve(SOMsommet.SOM_GetSortants().size());

	for (CArc* iIterateurArc : SOMsommet.SOM_GetSortants())
	{
		vSOM_ArcSortants.push_back(new CArc(*iIterateurArc));
	}
}



void CSommet::SOM_Ajouter_Entrants(CArc* pARCarc)
{
	try
	{
		if (pARCarc->ARC_GetSommetArrive() == SOM_GetID())
		{
			vSOM_ArcEntrants.push_back(pARCarc);
		}
		else
		{
			throw invalid_argument(" ERROR : Cet arc n'arrive pas jusque <" + SOM_GetID() + "> donc ajout dans arc entrant impossible");
		}
	}
	catch (const exception& EXCmessage)
	{
		cout << EXCmessage.what() << endl << endl;
	}
}

void CSommet::SOM_Ajouter_Sortants(CArc* pARCarc)
{
	try
	{
		if (pARCarc->ARC_GetSommetDepart() == SOM_GetID())
		{
			vSOM_ArcSortants.push_back(pARCarc);
		}
		else {
			throw invalid_argument(" ERROR : Cet arc ne sort pas de <" + SOM_GetID() + "> donc ajout dans arc_sortant impossible");
		}
	}
	catch (const exception& EXCmessage)
	{
		cout << EXCmessage.what() << endl << endl;
	}
}

vector<CArc*>::iterator  CSommet::SOM_RechercheEntrant(const string& sDepart)
{
	for (vector<CArc*>::iterator itEntrant = vSOM_ArcEntrants.begin(); itEntrant != vSOM_ArcEntrants.end(); itEntrant++)
	{
		if ((*itEntrant)->ARC_GetSommetArrive() == SOM_GetID() && (*itEntrant)->ARC_GetSommetDepart() == sDepart)
		{
			return itEntrant;
		}
	}
	return vSOM_ArcEntrants.end();
}

vector<CArc*>::iterator CSommet::SOM_RechercheSortant(const string& sArrive)
{
	for (vector<CArc*>::iterator itSortant = vSOM_ArcSortants.begin(); itSortant != vSOM_ArcSortants.end(); itSortant++)
	{
		if ((*itSortant)->ARC_GetSommetDepart() == SOM_GetID() && (*itSortant)->ARC_GetSommetArrive() == sArrive)
		{
			return itSortant;
		}
	}
	return vSOM_ArcSortants.end();
}

void CSommet::SOM_SupprimerArcEntrant(const string& sDepart)
{
	vector<CArc*>::iterator itSupprimerArcEntrant = SOM_RechercheEntrant(sDepart);

	try //utile que quand on allpel la fonction directement sur un sommet
	{
		if (itSupprimerArcEntrant != vSOM_ArcEntrants.end())
		{
			vSOM_ArcEntrants.erase(itSupprimerArcEntrant);
		}
		else 
		{
			throw invalid_argument(" ERROR : Cet arc <" + sDepart + "> --> <"+SOM_GetID()+"> n'existe pas. Impossible de le supprimer des arcs d'entr\202e de <" + SOM_GetID() + ">");
		}
	}
	catch (const exception& EXCmessage)
	{
		cout << EXCmessage.what() << endl << endl;
	}
}

void CSommet::SOM_SupprimerArcSortant(const string& sArrive)
{
	vector<CArc*>::iterator itSupprimerArcSortantant = SOM_RechercheSortant(sArrive);
	try
	{
		if (itSupprimerArcSortantant != vSOM_ArcSortants.end())
		{
			vSOM_ArcSortants.erase(itSupprimerArcSortantant);
		}
		else
		{
			throw invalid_argument(" ERROR : Cet arc <" + SOM_GetID() + "> --> <" + sArrive + "> n'existe pas. Impossible de le supprimer des arcs de sortie de <"+SOM_GetID()+">");
		}
	}
	catch (const exception& EXCmessage)
	{
		cout << EXCmessage.what() << endl << endl;
	}
}





