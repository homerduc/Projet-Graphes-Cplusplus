// Projet_C++.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CGrapheOriente.h"
using namespace std;

int main()
{
    /*vector<CArc*> arc_arrive;
    vector<CArc*> arc_Sortant;

    CSommet sommet2("12", arc_arrive, arc_Sortant);
    CSommet sommet1("11",arc_arrive,arc_Sortant);

    CArc arc("11", "12");  // sortant de sommet 1 et allant vers sommet 2
    //arc.affichage_arc();
    CArc arc2("12", "11"); // sortant de sommet 2 et allant vers sommet 1 
    //arc2.affichage_arc();
   
    sommet1.SOM_Ajouter_Sortants(&arc);
    sommet1.SOM_Ajouter_Entrants(&arc2);

    sommet1.Affichage_du_Sommet();*/



    CGrapheOriente Graphe;
    Graphe.GRO_AjouterSommet(&sommet1);
}

