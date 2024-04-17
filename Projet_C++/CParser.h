#ifndef CPARSER_H
#define CPARSER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class CParser
{
public :
	static string PAR_TrouverCle(const string& sLigne);
	static string PAR_TrouverValUnique(const string& sLigne);
	static map<string, string> PAR_GetCleValeur(const string& sPARChemin);
	static map<string, vector<map<string, string>>> PAR_GetCleListeValeur(const string& sPARChemin);

	static void PAR_Afficher(const string& sPARChemin);

	
};
#endif // !CPARSER_H


