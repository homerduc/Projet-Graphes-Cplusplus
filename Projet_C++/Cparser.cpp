#include "CParser.h"

string CParser::PAR_TrouverCle(const string& sLigne)
{
	unsigned int uiIndiceEgal = sLigne.find('=') - 1;
	while (uiIndiceEgal > 0 && sLigne[uiIndiceEgal - 1] == ' ') {
		uiIndiceEgal--;
	}
	return sLigne.substr(0, uiIndiceEgal+1);
}

string CParser::PAR_TrouverValUnique(const string& sLigne)
{
	unsigned int uiIndiceEgal = sLigne.find('=') + 1;
	while (uiIndiceEgal > 0 && sLigne[uiIndiceEgal] == ' ') {
		uiIndiceEgal++;
	}
	return sLigne.substr(uiIndiceEgal);
}

map<string, string> CParser::PAR_GetCleValeur(const string& sPARChemin)
{
	ifstream fichier(sPARChemin);
	string sOk;
	map<string, string> mValeurs;
	if (fichier) {

		while (getline(fichier, sOk)) { // Boucle principale
			if (sOk.find('[') == string::npos && sOk.find('=') != string::npos) { // Si nous sommes sur une ligne de type clé/valeur
				string sCle = PAR_TrouverCle(sOk);
				mValeurs[sCle] = PAR_TrouverValUnique(sOk);

			}
			else if (sOk.find('[') != string::npos) { // On a trouvé l'entrée d'un bloc type dictionnaire
				while (sOk.find("]") == string::npos) { // Tant que nous sommes toujours à l'intérieur
					getline(fichier, sOk); // On passe à la ligne suivante
				}
			}
			else { // On a trouvé une ligne inutile/parasite
				// On fait rien
			}
		}
	}
	else {
		cout << "Erreur : impossible d'ouvrir " << sPARChemin << endl;
	}
	return mValeurs;
}


map<string, vector<map<string, string>>> CParser::PAR_GetCleListeValeur(const string& sPARChemin)
{
	ifstream fichier(sPARChemin);
	string sOk;
	map<string, vector<map<string, string>>> mValeurs;
	unsigned int uiIndiceEspace;

	if (fichier) {

		while (getline(fichier, sOk)) { // Boucle principale
			if (sOk.find('[') == string::npos && sOk.find('=') != string::npos) { // Si nous sommes sur une ligne de type clé/valeur
				// On fait rien
			}
			else if (sOk.find('[') != string::npos) { // On a trouvé l'entrée d'un bloc type dictionnaire
				string sCle = PAR_TrouverCle(sOk);
				getline(fichier, sOk);

				while (sOk.find(']') == string::npos) { // Tant que nous sommes toujours à l'intérieur

					// ICI NOUS SOMMES SUR UNE LIGNE TYPE Debut=9, Fin=3
					// JE DOIS SEPARER AVEC LES VIRGULES PUIS DANS CHAQUE BLOC OBTENU JE DOIS FAIRE EXACTEMENT PAREIL QUE DANS CLE VALEUR
					
					string sBloc;
					while (sOk != "") { // Tant qu'on a pas récupéré tous les blocs
						uiIndiceEspace = 0;
						while (sOk[uiIndiceEspace] == ' ') { // Tant qu'il y a des espaces au début du bloc (ex : "     clé=valeur,   clé=valeur")
							uiIndiceEspace++;
						}
						sOk = sOk.substr(uiIndiceEspace); // On écrase sOk avec les espaces du début retirés

						if (sOk.find(',') != string::npos) { // Si on trouve une virgule
							sBloc = sOk.substr(0, sOk.find(',')); // On récupère un bloc de type cle = valeur et on le met dans sBloc

							map<string, string> mSousMap;
							mSousMap[PAR_TrouverCle(sBloc)] = PAR_TrouverValUnique(sBloc);
							mValeurs[sCle].push_back(mSousMap);

							sOk = sOk.substr(sOk.find(',') + 1); // On enlève le bloc de sOk pour récupérer les suivants
						}
						else { // S'il n'y a pas ou plus de virgules
							sBloc = sOk; // On récupère un bloc de type cle = valeur et on le met dans sBloc

							map<string, string> mSousMap;
							mSousMap[PAR_TrouverCle(sBloc)] = PAR_TrouverValUnique(sBloc);
							mValeurs[sCle].push_back(mSousMap);

							sOk = ""; // On arrête la boucle car on a récupéré tous les blocs
						}
					}
					getline(fichier, sOk); // On passe à la ligne suivante
				}
			}
			else { // On a trouvé une ligne inutile/parasite
				// On fait rien
			}
		}
	}
	else {
		cout << "Erreur : impossible d'ouvrir " << sPARChemin << endl;
	}
	return mValeurs;
}

void CParser::PAR_Afficher(const string& sPARChemin)
{
	map<string, string> mResultat1 = PAR_GetCleValeur(sPARChemin);
	for (const auto& pair : mResultat1) {
		cout << "Cle unique : " << pair.first << ", Valeur : " << pair.second << endl;
	}

	map<string, vector<map<string, string>>> mResultat2 = PAR_GetCleListeValeur(sPARChemin);
	for (const auto& pair : mResultat2) {
		cout << "Cle groupe : " << pair.first << endl;
		for (const auto& mTest : pair.second) {
			cout << "bla" << endl;
			for (const auto& element : mTest) {
				cout << "Cle : " << element.first << ", Valeur : " << element.second << endl;
			}
		}
	}
}

