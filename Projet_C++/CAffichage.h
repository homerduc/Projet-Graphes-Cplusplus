#pragma once
#include <string>
#include<iostream>
using namespace std;
class CAffichage
{
public:

	#pragma region COULEURS TEXT
		static const char* COL_Creation() { return "\033[38;5;37m"; }
		static const char* COL_Error() { return "\033[48;5;52m"; }
		static const char* COL_Suppr() { return "\033[38;5;2m"; }
		static const char* COL_Arcs() { return "\033[38;5;166m"; }
		static const char* COL_Ajout() { return "\033[38;5;27m"; }
		static const char* COL_Reset() { return "\033[0m"; }
	#pragma endregion

	
	 static void AFC_AffichageSuppr(string sDepart, string sArrive);

	 static void AFC_AffichageAjout(string sID);
	 
	 static const char* AFC_Calcultirets(string sID,const char cMotif);
	 static const char* AFC_Calculvide_Creation(string sID, const char cMotif);
	 static const char* AFC_Calculvide_Ajout(string sID, const char cMotif);
};

