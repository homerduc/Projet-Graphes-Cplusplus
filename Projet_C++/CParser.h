#ifndef CPARSER_H
#define CPARSER_H

#include <fstream>
#include <iostream>
#include <string>
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

	void PAR_ItererFichier();
};
#endif // !CPARSER_H


