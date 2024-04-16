// Projet_C++.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CGrapheOriente.h"
#include "CAffichage.h"
#include"CGraphe.h"
#include "CParser.h"

using namespace std;

int main()
{
	//CGraphe Graphe;

	////  Graphe.GRO_AjouterSommet(sId);
	//Graphe.GRO_AjouterSommet("Lilian");
	//Graphe.GRO_AjouterSommet("Alexandre");
	//Graphe.GRO_AjouterSommet("Simon");

	////  Graphe.GRO_AjouterArc(string sDepart,string sArrive);
	//Graphe.GRO_AjouterArc("Lilian", "Alexandre");
	//Graphe.GRO_AjouterArc("Alexandre", "Alexandre");

	//// Graphe.GRO_SupprimerSommet("mathieu");    
	//Graphe.Afficher_Graphe();

	//Graphe.GRO_SupprimerSommet("Alexandre");

	//Graphe.Afficher_Graphe();
;

    CParser parsetest;
    parsetest.PAR_Afficher_fichier();
}
