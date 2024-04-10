#include "CParser.h"

CParser::CParser()
{
	// Demander chemin au clavier
}

void CParser::PAR_ItererFichier()
{
	ifstream fichier(sPARChemin);
	string ok;
	getline(fichier, ok);
	cout << "test parser :" << ok << endl;

	while (getline(fichier, ok)) {

	}
	return;
}

