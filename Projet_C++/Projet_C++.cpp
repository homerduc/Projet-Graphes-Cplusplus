// Projet_C++.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CGrapheOriente.h"
#include "CAffichage.h"
#include"CGraphe.h"
#include "CParser.h"
#include "CCreationGraphe.h"

using namespace std;

int main()
{
    /*
    CGrapheOriente Graphe;
    CGrapheOriente* pGraphe2;

    ////  Graphe.GRO_AjouterSommet(sId);
    Graphe.GRO_AjouterSommet("Lilian");
    Graphe.GRO_AjouterSommet("Alexandre");
    Graphe.GRO_AjouterSommet("Simon");

    ////  Graphe.GRO_AjouterArc(string sDepart,string sArrive);
    Graphe.GRO_AjouterArc("Lilian", "Alexandre");
    Graphe.GRO_AjouterArc("Simon", "Lilian");
    Graphe.GRO_AjouterArc("Alexandre", "Simon");

     Graphe.GRO_SupprimerSommet("mathieu");    
    Graphe.Afficher_Graphe();

    pGraphe2 = Graphe.GRO_Inverse();

    pGraphe2->Afficher_Graphe();
    */

    CParser::PAR_Afficher("C:\\Users\\alexa\\Desktop\\test parser.txt");

    CCreationGraphe::CRE_CreerGraphe();
}
