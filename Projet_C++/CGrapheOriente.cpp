#include "CGrapheOriente.h"
#include "CAffichage.h"

CGrapheOriente::CGrapheOriente(const CGrapheOriente& GROgraphe)
{
	// Copie de la liste des arcs
	vGROarcs.reserve(GROgraphe.GRO_GetArcs().size()); // On alloue d'avance la taille voulue

	for (CArc* iIterateurArc : GROgraphe.GRO_GetArcs()) 
	{
		vGROarcs.push_back(new CArc(*iIterateurArc)); // On ajoute une copie de chaque arc dans la liste de notre nouveau sommet
	}

	// Copie de la liste des sommets
	vGROsommets.reserve(GROgraphe.GRO_GetSommets().size());

	for (CSommet* iIterateurSommet : GROgraphe.GRO_GetSommets()) 
	{
		vGROsommets.push_back(new CSommet(*iIterateurSommet));
	}
}

CGrapheOriente::~CGrapheOriente()
{

	for (CArc* pArc : vGROarcs)
	{
		delete pArc;
	}
	vGROarcs.clear();

	for (CSommet* pSommet : vGROsommets)
	{
		delete pSommet;
	}
	vGROsommets.clear();

}

vector<CArc*>::iterator CGrapheOriente::GRO_RechercheArcs(string sDepart, string sArrive)
{
	//vector<CArc*>::iterator itRechercheArc = find(vGROarcs.begin(), vGROarcs.end(), pSOMtemp);
	for (vector<CArc*>::iterator itRechercheArc = vGROarcs.begin(); itRechercheArc != vGROarcs.end(); itRechercheArc++) 
	{
		if ((*itRechercheArc)->ARC_GetSommetArrive() == sArrive && (*itRechercheArc)->ARC_GetSommetDepart() == sDepart)
		{ 
			return itRechercheArc;
		}
			
	}
	return vGROarcs.end();
}

vector<CSommet*>::iterator CGrapheOriente::GRO_RechercheSommets(string sID)
{
	//vector<CSommet*>::iterator itRechercheSommet = find(vGROsommets.begin(), vGROsommets.end(), pSOMtemp);
	for (vector<CSommet*>::iterator itRechercheSommet = vGROsommets.begin(); itRechercheSommet != vGROsommets.end(); itRechercheSommet++) 
	{
		if ((*itRechercheSommet)->SOM_GetID() == sID)
		{
			return itRechercheSommet;
		}
	}
	return vGROsommets.end();
}

void CGrapheOriente::GRO_AjouterSommet(string sID)
{
	vector<CSommet*>::iterator itRechercheDepart = GRO_RechercheSommets(sID);
	try
	{
		if (itRechercheDepart == vGROsommets.end()) 
		{
			vGROsommets.push_back(new CSommet(sID));
			CAffichage::AFC_AffichageAjoutSommet(sID);
		}
		else 
		{
			throw invalid_argument(ERREUR_couleur + string("ERREUR : Le sommet <") + sID + string("> existe d\202ja, impossible de l'ajouter de nouveau") + RESTAURER_couleur);
		}
	}
	catch (const exception& message_erreur)
	{
		cout << message_erreur.what() << endl << endl;
	}

}

void CGrapheOriente::GRO_AjouterArc(string sDepart, string sArrive)
{
	vector<CArc*>::iterator itRechercheArc = GRO_RechercheArcs(sDepart,sArrive);
	vector<CSommet*>::iterator itRechercheDepart = GRO_RechercheSommets(sDepart);
	vector<CSommet*>::iterator itRechercheArrive = GRO_RechercheSommets(sArrive);
	
	try // Les else if ici servent à rendre l'exception plus précise pour l'utilisateur
	{
		if (itRechercheArc == vGROarcs.end())
		{
			if (itRechercheDepart != vGROsommets.end() && itRechercheArrive != vGROsommets.end())
			{
				CArc* pNEWarc = new CArc(sDepart, sArrive);
				vGROarcs.push_back(pNEWarc);
				(*itRechercheDepart)->SOM_Ajouter_Sortants(pNEWarc);
				(*itRechercheArrive)->SOM_Ajouter_Entrants(pNEWarc);

				CAffichage::AFC_AffichageAjoutArc(sDepart, sArrive);
				return;
			}
			else if (itRechercheDepart == vGROsommets.end() && itRechercheArrive != vGROsommets.end()) //le sommet de départ inexistant
			{
				throw invalid_argument(ERREUR_couleur + string("ERREUR : Le sommet de d\202part <") + sDepart + string("> mis en param\212tre n'existe pas. Impossible de crée l'arc <") + sDepart + string("> --> <") + sArrive + string(">") + RESTAURER_couleur);
			}
			else if (itRechercheDepart != vGROsommets.end() && itRechercheArrive == vGROsommets.end()) //le sommet d'arrive inexistant
			{
				throw invalid_argument(ERREUR_couleur + string("ERREUR : Le sommet d'arriv\202e <") + sArrive + string("> mis en param\212tre n'existe pas. Impossible de cr\202er l'arc <") + sDepart + string("> --> <") + sArrive + string(">") + RESTAURER_couleur);
			}
			else // les deux sommets sont inexistant 
			{
				throw invalid_argument(ERREUR_couleur + string("ERREUR : Les sommets  <") + sDepart + string("> & <") + sArrive + string("> mis en param\212tre n'existent pas. Impossible de cr\202er l'arc <") + sDepart + string("> --> <") + sArrive + string(">") + RESTAURER_couleur);
			}
		}
		else // le sommet existe deja 
		{
			throw invalid_argument(ERREUR_couleur + string("ERREUR : L'arc  <") + sDepart + string("> --> <") + sArrive + string("> existe deja. Impossible de cr\202er une deuxi\212me fois l'arc <") + sDepart + string("> --> <") + sArrive + string(">") + RESTAURER_couleur);
		}
	}
	catch (const exception& Message_Erreur)
	{
		cout << Message_Erreur.what() << endl << endl;
	}
}

void CGrapheOriente::GRO_SupprimerSommet(string sID)
{

	string sArrive, sDepart;
	vector<CSommet*>::iterator itSupprimerSommet = GRO_RechercheSommets(sID);
	try
	{
		if (itSupprimerSommet != vGROsommets.end()) 
		{
			for (unsigned int uiPositionArc = 0; uiPositionArc < vGROarcs.size(); )
			{
				sDepart = vGROarcs[uiPositionArc]->ARC_GetSommetDepart();
				sArrive = vGROarcs[uiPositionArc]->ARC_GetSommetArrive();
				if (sDepart == sID || sArrive == sID) 
				{
					GRO_SupprimerArc(sDepart, sArrive);
				}
				else
				{
					uiPositionArc++; // l'incrémentation est dans le else car comme les vecteurs changent de taille quand on suprime un element on ne veut pas sauter d'éléments
				}
			}
			CAffichage::AFC_AffichageSupprSommet(sID);
			delete *itSupprimerSommet;
			vGROsommets.erase(itSupprimerSommet);
		}
		else
		{
			throw invalid_argument(ERREUR_couleur + string("ERREUR.Le sommet <") + sID + "> mis en param\212tre n'existent pas. Impossible de supprimer le sommet <" + sID + ">" + RESTAURER_couleur);
		}
	}
	catch (const exception& Message_Erreur)
	{
		cout << Message_Erreur.what() << endl << endl;
	}
}

void CGrapheOriente::GRO_SupprimerArc(string sDepart, string sArrive)
{

	vector<CArc*>::iterator itSupprimerArc = GRO_RechercheArcs(sDepart, sArrive);
	try
	{
		if (itSupprimerArc != vGROarcs.end()) {

			vector<CSommet*>::iterator itRechercheSommeDepart = GRO_RechercheSommets(sDepart);
			vector<CSommet*>::iterator itRechercheSommeArrive = GRO_RechercheSommets(sArrive);

			(*itRechercheSommeDepart)->SOM_SupprimerArcSortant(sArrive);
			(*itRechercheSommeArrive)->SOM_SupprimerArcEntrant(sDepart);

			delete *itSupprimerArc;
			CAffichage::AFC_AffichageSupprArc(sDepart, sArrive);
			vGROarcs.erase(itSupprimerArc);
		}
		else
		{
			throw invalid_argument(ERREUR_couleur + string("ERREUR : L'arc  <") + sDepart + string("> --> <") + sArrive + string("> mis en param\212tre n'existe pas. Impossible de supprimer un arc inexistant") + RESTAURER_couleur);
		}
	}
	catch (const exception& EXPmessage)
	{
		cout << EXPmessage.what() << endl << endl;;
	}

}

CGrapheOriente* CGrapheOriente::GRO_Inverse()
{
	CGrapheOriente *nouveauGraphe = new CGrapheOriente(); // a delete un fois l'affichage fait 

	for (CSommet* SOMsommet : vGROsommets)
	{
		nouveauGraphe->GRO_AjouterSommet(SOMsommet->SOM_GetID());
	}
	for (CArc* ARCarc : vGROarcs)
	{
		nouveauGraphe->GRO_AjouterArc(ARCarc->ARC_GetSommetArrive(), ARCarc->ARC_GetSommetDepart());
	}


	return nouveauGraphe; // a ne pas oublier de delete ce qui va recevoir ce pointeur 
}

void CGrapheOriente::Afficher_Graphe()
{
	CAffichage::AFC_Afficher_Graphe(this);
}

