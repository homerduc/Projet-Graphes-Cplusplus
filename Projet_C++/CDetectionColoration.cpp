#include "CDetectionColoration.h"

CDetectionColoration::CDetectionColoration(const CGrapheOriente& graphe)
{
	Graphe = &graphe;
	//initialisation de la map avec le graph mis en param�tre
	for (unsigned int i = 0; i < graphe.GRO_GetSommets().size(); i++)
	{
		sommetCouleur[graphe.GRO_GetSommets()[i]->SOM_GetID()] = 0;
	}
}


bool CDetectionColoration::DTCDetecter(const unsigned int k,unsigned int i)
{
	unsigned int taille_list_sommet = (unsigned int)Graphe->GRO_GetSommets().size();
	if (i == taille_list_sommet)
	{
		return true;
	}
	else
	{
		// 0 repr�sente le non-coloriage donc c va de 1 � k inclus
		for (unsigned int c = 1; c <= k; c++)
		{
			bool couleurValide = true;
			couleurValide = DTCCouleurEstValide(c, i);
			if (couleurValide)
			{
				// Attribue la couleur c au sommet actuel
				sommetCouleur[Graphe->GRO_GetSommets()[i]->SOM_GetID()] = c;
				// Si on arrive � bien colorier le graphe entier avec ceci alors on a fini
				if (DTCDetecter( k, i + 1)) {
					return true;
				}
				// Sinon c'est que la couleur n'est pas bonne donc on backtrack
				sommetCouleur[Graphe->GRO_GetSommets()[i]->SOM_GetID()] = 0;
			}
		}
		return false;
	}
}

map<string, unsigned int> CDetectionColoration::DTCGetSommetCouleur()
{
	return sommetCouleur;
}

bool CDetectionColoration::DTCCouleurEstValide(unsigned int couleur, unsigned int i)
{
	// On parcourt tous les arcs du sommet pour aller chercher les voisins
	for (auto& it : Graphe->GRO_GetSommets()[i]->SOM_GetEntrants())
	{
		// Si le voisin actuel a la m�me couleur
		if (sommetCouleur[(*it).ARC_GetSommetDepart()] == couleur)
		{
			// Alors la couleur c n'est pas valide
			return false;
		}
	}
	return true;
	// Si la couleur est valide (aucun voisin n'a la m�me)
}



