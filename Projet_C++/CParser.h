#ifndef CPARSER_H
#define CPARSER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


using namespace std;

class CParser
{
private:
	// ATTRIBUTS
	//string sPARChemin = "C:\\Users\\alexa\\Desktop\\test parser.txt";
	string sPARChemin = "C:\\Users\\ghesq\\Desktop\\test.txt";
	string sNBSommets;
	string sNBArcs;
	string sSommets;
	string sNumero;
	string sArcs;
	string sDebut;
	string sFin;


public:
	// CONSTRUCTEURS & DESTRUCTEUR
	CParser();
	CParser(char* const& cheminFichier) { sPARChemin = cheminFichier; }

	void Par_Recherche();

	// METHODES
	// Faire une methode qui va chercher les infos de la ligne clé/valeur
	// Faire une methode qui va chercher les infos de la ligne dictionnaire (ex: Arcs= et Sommets=)


	vector<string> PAR_GetCleValeur();
};
#endif // !CPARSER_H


