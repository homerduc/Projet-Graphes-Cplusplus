// Projet_C++.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CGrapheOriente.h"
#include "CAffichage.h"
#include"CGraphe.h"
#include "CParser.h"
#include "CCreationGraphe.h"
#include <crtdbg.h>

using namespace std;

int main()
{
	CCreationGraphe::CRE_FonctionPrincipale();
	_CrtDumpMemoryLeaks();
	system("pause");
}
