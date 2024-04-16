#include "CParser.h"

CParser::CParser()
{
	// Demander chemin au clavier
}

void CParser::Par_Recherche()
{
	string sRecherche;
}

void CParser::PAR_Afficher_fichier()
{
	ifstream fichier(sPARChemin);
	string ligne;
	cout << "test parser :" << ligne << endl;
	while (getline(fichier, ligne))
	{
		cout <<ligne<< endl;
	}
	return;
}

