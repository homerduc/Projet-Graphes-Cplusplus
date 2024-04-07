// Projet_C++.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CGrapheOriente.h"
#include "CAffichage.h"

using namespace std;

int main()
{

    #pragma region TEST SUPPRESSION ARC
        //CGrapheOriente Graphe;

        ////  Graphe.GRO_AjouterSommet(sId);
        //Graphe.GRO_AjouterSommet("lilian");
        //Graphe.GRO_AjouterSommet("ghesquiere");
        //Graphe.GRO_AjouterSommet("mathieu");

        ////  Graphe.GRO_AjouterArc(string sDepart,string sArrive);
        //Graphe.GRO_AjouterArc("lilian", "ghesquiere");
        //Graphe.GRO_AjouterArc("ghesquiere", "lilian");
        //Graphe.GRO_AjouterArc("mathieu", "lilian");

        ////  AFC_Affichage_Sommets(Csommet* pSOMsommet);
        //CAffichage::AFC_Affichage_Sommets(*Graphe.GRO_RechercheSommets("lilian"));
        //CAffichage::AFC_Affichage_Sommets(*Graphe.GRO_RechercheSommets("mathieu"));

        ////  GRO_SupprimerArc(string sDepart, string sArrive);
        //Graphe.GRO_SupprimerArc("mathieu", "lilian");

        //CAffichage::AFC_Affichage_Sommets(*Graphe.GRO_RechercheSommets("lilian"));
        //CAffichage::AFC_Affichage_Sommets(*Graphe.GRO_RechercheSommets("mathieu"));
    #pragma endregion

     CGrapheOriente Graphe;

    //  Graphe.GRO_AjouterSommet(sId);
    Graphe.GRO_AjouterSommet("lilian");
    Graphe.GRO_AjouterSommet("ghesquiere");
    Graphe.GRO_AjouterSommet("mathieu");

    //  Graphe.GRO_AjouterArc(string sDepart,string sArrive);
    Graphe.GRO_AjouterArc("lilian", "ghesquiere");
    Graphe.GRO_AjouterArc("lilian", "mathieu");

    Graphe.GRO_AjouterArc("ghesquiere", "lilian");
    Graphe.GRO_AjouterArc("ghesquiere", "mathieu");

    Graphe.GRO_AjouterArc("mathieu", "lilian");
    Graphe.GRO_AjouterArc("mathieu", "ghesquiere");

    Graphe.Afficher_Graph();

    //Graphe.GRO_SupprimerSommet("mathieu");
    Graphe.GRO_SupprimerSommet("lilian");

    Graphe.Afficher_Graph();



}

