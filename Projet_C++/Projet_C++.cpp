// Projet_C++.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CGrapheOriente.h"

using namespace std;

int main()
{
    CGrapheOriente Graphe;

    //  Graphe.GRO_AjouterSommet(sId);
    Graphe.GRO_AjouterSommet("lilian");
    Graphe.GRO_AjouterSommet("ghesquiere");
    Graphe.GRO_AjouterSommet("lilian1");
    Graphe.GRO_AjouterSommet("ghesquiere1");

    //  Graphe.GRO_AjouterArc(sDepart, sArrive);
    Graphe.GRO_AjouterArc("lilian", "ghesquiere");
    Graphe.GRO_AjouterArc("ghesquiere1", "lilian1");
    
    Graphe.Afficher_Graph();

    Graphe.GRO_SupprimerSommet("lilian");

    Graphe.Afficher_Graph();

    


  

 
    
}

