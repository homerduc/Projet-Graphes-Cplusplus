#include "CParser.h"

CParser::CParser()
{
	// Demander chemin au clavier
}

vector<string> CParser::PAR_GetCleValeur()
{
	vector<string> valeurs;
	ifstream fichier(sPARChemin);
	string sOk;
	map<string, vector<string>> mValeurs;
	unsigned int uiIndiceEgal;
	if (fichier) {
		cout << "Test parser :" << endl;

		while (getline(fichier, sOk)) { // Boucle principale
			if (sOk.find("[") == string::npos) { // Si nous sommes sur une ligne de type clé/valeur
				uiIndiceEgal = sOk.find('=');
				while (sOk[uiIndiceEgal-1] == ' ') {
					uiIndiceEgal--;
				}
				string sCle = sOk.substr(0, uiIndiceEgal);

				uiIndiceEgal = sOk.find('=') + 1;
				while (sOk[uiIndiceEgal] == ' ') {
					uiIndiceEgal++;
				}
				string sValeur = sOk.substr(uiIndiceEgal);

				mValeurs[sCle].push_back(sValeur);

			}
			else { // On a trouvé l'entrée d'un bloc type dictionnaire
				while (sOk.find("]") == string::npos) { // Tant que nous sommes toujours à l'intérieur
					getline(fichier, sOk); // On passe à la ligne suivante
				}
			}
		}
	}
	else {
		cout << "Erreur : impossible d'ouvrir " << sPARChemin << endl;
	}

	cout << "Affichage de la map : " << endl;
	map<string, vector<string>>::iterator it = mValeurs.begin();
	while (it != mValeurs.end()) {
		cout << "Key: " << it->first
			<< ", Value: " << it->second[0] << endl;
		++it;
	}

	return valeurs;
}
