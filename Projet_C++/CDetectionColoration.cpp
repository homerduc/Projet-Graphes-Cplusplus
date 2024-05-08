#include "CDetectionColoration.h"


bool CDetectionColoration::DTCTousColores(map<string, unsigned int>& Map)
{
	map<string, unsigned int>::const_iterator itMap = Map.begin();
	while (itMap != Map.end())
	{
		if (Map.at((*itMap).first) == 0)
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
	unsigned int taille_list_sommet = Graphe->GRO_GetSommets().size() - 1;
	if (i == taille_list_sommet)
	{
		return true;
	}
	else
	{
		for (unsigned int c = 0; c < k; c++)
		{
			//recherche dans la liste des sommets la liste des les couleurs des voisins
			for (auto& it : Graphe->GRO_GetSommets()[i]->SOM_GetEntrants())
			{
				if (sommetCouleur[(*it).ARC_GetSommetDepart()] == c)
				{
					// ne ren faire
				}
				else
				{
					sommetCouleur[(*it).ARC_GetSommetDepart()] = c;
					if (DTCDetecter( k, i + 1)) {
						return true;
					}
					sommetCouleur[(*it).ARC_GetSommetDepart()] = 0;
				}
			}
		}
		return false;
	}
}



