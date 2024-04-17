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
			if (sOk.find('[') == string::npos && sOk.find('=') != string::npos) { // Si nous sommes sur une ligne de type cl�/valeur
				string sCle = PAR_TrouverCle(sOk);
				mValeurs[sCle] = PAR_TrouverValUnique(sOk);

			}
			else if (sOk.find('[') != string::npos) { // On a trouv� l'entr�e d'un bloc type dictionnaire
				while (sOk.find("]") == string::npos) { // Tant que nous sommes toujours � l'int�rieur
					getline(fichier, sOk); // On passe � la ligne suivante
				}
			}
			else { // On a trouv� une ligne inutile/parasite
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
			if (sOk.find('[') == string::npos && sOk.find('=') != string::npos) { // Si nous sommes sur une ligne de type cl�/valeur
				// On fait rien
			}
			else if (sOk.find('[') != string::npos) { // On a trouv� l'entr�e d'un bloc type dictionnaire
				string sCle = PAR_TrouverCle(sOk);
				getline(fichier, sOk);

				while (sOk.find(']') == string::npos) { // Tant que nous sommes toujours � l'int�rieur

					// ICI NOUS SOMMES SUR UNE LIGNE TYPE Debut=9, Fin=3
					// JE DOIS SEPARER AVEC LES VIRGULES PUIS DANS CHAQUE BLOC OBTENU JE DOIS FAIRE EXACTEMENT PAREIL QUE DANS CLE VALEUR
					
					string sBloc;
					while (sOk != "") { // Tant qu'on a pas r�cup�r� tous les blocs
						uiIndiceEspace = 0;
						while (sOk[uiIndiceEspace] == ' ') { // Tant qu'il y a des espaces au d�but du bloc (ex : "     cl�=valeur,   cl�=valeur")
							uiIndiceEspace++;
						}
						sOk = sOk.substr(uiIndiceEspace); // On �crase sOk avec les espaces du d�but retir�s

						if (sOk.find(',') != string::npos) { // Si on trouve une virgule
							sBloc = sOk.substr(0, sOk.find(',')); // On r�cup�re un bloc de type cle = valeur et on le met dans sBloc

							map<string, string> mSousMap;
							mSousMap[PAR_TrouverCle(sBloc)] = PAR_TrouverValUnique(sBloc);
							mValeurs[sCle].push_back(mSousMap);

							sOk = sOk.substr(sOk.find(',') + 1); // On enl�ve le bloc de sOk pour r�cup�rer les suivants
						}
						else { // S'il n'y a pas ou plus de virgules
							sBloc = sOk; // On r�cup�re un bloc de type cle = valeur et on le met dans sBloc

							map<string, string> mSousMap;
							mSousMap[PAR_TrouverCle(sBloc)] = PAR_TrouverValUnique(sBloc);
							mValeurs[sCle].push_back(mSousMap);

							sOk = ""; // On arr�te la boucle car on a r�cup�r� tous les blocs
						}
					}
					getline(fichier, sOk); // On passe � la ligne suivante
				}
			}
			else { // On a trouv� une ligne inutile/parasite
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

