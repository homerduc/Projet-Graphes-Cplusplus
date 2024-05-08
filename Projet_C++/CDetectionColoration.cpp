#include "CDetectionColoration.h"


bool CDetectionColoration::DTCTousColores()
{
	map<string, unsigned int>::const_iterator itMap = sommetCouleur.begin();
	while (itMap != sommetCouleur.end())
	{
		if (sommetCouleur.at((*itMap).first) == 0)
		{
			return false;
		}
		itMap++;
	}
	return true;
}

/*bool CDetectionColoration::DTCDetecter(const CGrapheOriente* graphe, const unsigned int k)
{
	vector<unsigned int> couleursSommetsVoisins;
	CSommet* sommetCourant;
	//initialisation map
	map<string, unsigned int> sommetCouleur;
	for (auto it : graphe->GRO_GetSommets())
	{
		sommetCouleur[(*it).SOM_GetID()] = 0;
	}

	//initialisation couleurs
	vector<unsigned int> couleurs;
	for (unsigned int i = 1; i <= k; i++)
	{
		couleurs.push_back(i);
	}

	//debut algo
	if (DTCTousColores(sommetCouleur))
	{
		return true;
	}
	else
	{

		for (unsigned int i = 0; i < graphe->GRO_GetSommets().size(); i++)
		{
			sommetCourant = graphe->GRO_GetSommets()[i];
			if (sommetCouleur[sommetCourant->SOM_GetID()] == 0)
			{
				//on va faire un vecteru de tous les voisins
				couleursSommetsVoisins.clear();
				for (auto& it : sommetCourant->SOM_GetEntrants())
				{
					// Si la couleur est pas déjà dans la liste
					if (find(couleursSommetsVoisins.begin(), couleursSommetsVoisins.end(), sommetCouleur[(*it).ARC_GetSommetDepart()]) == couleursSommetsVoisins.end()) {
						couleursSommetsVoisins.push_back(sommetCouleur[(*it).ARC_GetSommetDepart()]);
					}
					if (couleursSommetsVoisins.size() == k)
					{
						return false;
					}
					for (unsigned int i = 0; i < k; i++)
					{
						//Recherche dans la liste des couleurs voisine, si i n'y est pas alors on prend la couleur 
						if (find(couleursSommetsVoisins.begin(), couleursSommetsVoisins.end(), i) == couleursSommetsVoisins.end()) {
							sommetCouleur[sommetCourant->SOM_GetID()] = i;
							if (DTCDetecter(graphe, k)) {
								return true;
							}
							sommetCouleur[sommetCourant->SOM_GetID()] = 0;
						}

					}
					return false;
				}
			}
		}
	}



	return false;
}*/


CDetectionColoration::CDetectionColoration(const CGrapheOriente* graphe)
{
	//initialisation de l'attribut Graphes
	Graphe = new CGrapheOriente(*graphe);

	//initialisation de la map avec le graph mis en paramètre
	for (unsigned int i = 0; i < graphe->GRO_GetSommets().size(); i++)
	{
		sommetCouleur[graphe->GRO_GetSommets()[i]->SOM_GetID()] = 0;
	}
}

bool CDetectionColoration::DTCDetecter(const unsigned int k,unsigned int i)
{
	unsigned int taille_list_sommet = Graphe->GRO_GetSommets().size();
	if (i == taille_list_sommet)
	{
		return true;
	}
	else
	{
		// 0 représente le non-coloriage donc c va de 1 à k inclus
		for (unsigned int c = 1; c <= k; c++)
		{
			bool couleurValide = true;
			// On parcourt tous les arcs du sommet pour choper les voisins
			for (auto& it : Graphe->GRO_GetSommets()[i]->SOM_GetEntrants())
			{
				// Si le voisin actuel a la même couleur
				if (sommetCouleur[(*it).ARC_GetSommetDepart()] == c)
				{
					// Alors la couleur c n'est pas valide
					couleurValide = false;
				}
			}
			// Si la couleur est valide (aucun voisin n'a la même)
			if (couleurValide)
			{
				// Attribue la couleur c au sommet actuel
				sommetCouleur[Graphe->GRO_GetSommets()[i]->SOM_GetID()] = c;
				// Si on arrive à bien colorier le graphe entier avec ceci alors on a fini
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



