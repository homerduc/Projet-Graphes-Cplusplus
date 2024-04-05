
#ifndef CAFFICHAGE_H
#define CAFFICHAGE_H 

#include <string>
#include<iostream>
#include "CGrapheOriente.h"

	#pragma region TAILLES AFFICHAGE
		#define TAILLE_CREATION_AJOUT 41
		#define TAILLE_SUPPR 32  
		#define TAILLE_AFFICHA_GEGRAPH 38  
		#define TAILLE_Encadre_arcs "latailleestde16 "  

	#pragma endregion

	#pragma region TYPES ERREURS
		#define DEPART_inconnu 1
		#define ARRIVE_inconnu 2
		#define DEPART_ARRIVE_inconnu 3
	#pragma endregion


	#pragma region COULEURS
	#define CREATION_couleur "\033[38;5;37m"
	#define AJOUT_couleur "\033[38;5;27m"
	#define ERREUR_couleur "\033[48;5;52m"
	#define SUPPR_couleur "\033[38;5;2m"
	#define RESAURER_couleur "\033[0m"
	#define ARC_couleur "\033[38;5;166m"  
	#define ARC_Tabultation "		"
	#define TEXT_Tabultation "	"

	#pragma endregion

using namespace std;


class CAffichage
{
public:

	static void AFC_AffichageSuppr(string sDepart, string sArrive);
	static void AFC_AffichageAjoutSommet(string sID);
	static void AFC_AffichageAjoutArc(string sDepart,string sArrive);
	static void AFC_Affichage_Sommets(CSommet* SOMsommet);
	static void AFC_Afficher_Graph(CGrapheOriente* GROgraph);
	static void AFC_Erreur_ajoutSommet(string sID);
	static void AFC_Erreur_ajoutArc(string sDepart, string sArrive, int iErreur);



	static const char* AFC_Calcul_tirets(string sID, const char cMotif, int iType);
	static const char* AFC_Calcul_vide_Creation(string sID, const char cMotif);
	static const char* AFC_Calcul_vide_Ajout(string sID, const char cMotif);

};

#endif // CAFFICHAGE_H


