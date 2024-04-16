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
private :
	// ATTRIBUTS
	string sPARChemin = "C:\\Users\\alexa\\Desktop\\test parser.txt";

	/*
	string sNBSommets = "NBSommets";
	string sNBArcs = "NBArcs";
	string sSommets = "Sommets";
	string sNumero = "Numero";
	string sArcs = "Arcs";
	string sDebut = "Debut";
	string sFin = "Fin";
	*/

public :
	// CONSTRUCTEURS & DESTRUCTEUR
	CParser();

	// METHODES
	// Faire une methode qui va chercher les infos de la ligne clé/valeur
	// Faire une methode qui va chercher les infos de la ligne dictionnaire (ex: Arcs= et Sommets=)


	map<string, string> PAR_GetCleValeur();
	map<string, vector<string>> PAR_GetCleListeValeur();
};
#endif // !CPARSER_H


