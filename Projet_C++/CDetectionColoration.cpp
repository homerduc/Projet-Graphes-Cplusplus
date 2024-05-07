#include "CDetectionColoration.h"


bool CDetectionColoration::DTCTousColores(map<string, unsigned int>& Map)
{
	map<string, unsigned int>::const_iterator itMap = Map.begin();
	while (itMap != Map.end())
	{
		if (Map.at((*itMap).first) != 0)
		{
			return false;
		}
		itMap++;
	}
	return true;
}

bool CDetectionColoration::DTCDetecter(const CGrapheOriente* graphe, const unsigned int& k)
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
					if (find(couleursSommetsVoisins.begin(), couleursSommetsVoisins.end(), (*it).ARC_GetSommetDepart()) == couleursSommetsVoisins.end()) {
						couleursSommetsVoisins.push_back(sommetCouleur[(*it).ARC_GetSommetDepart()]);
					}
				}
			}
		}
	}



	return false;
}
