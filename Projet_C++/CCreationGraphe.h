#ifndef CCREATIONGRAPHE_H
#define CCREATIONGRAPHE_H
#include <iostream>
#include <string>

#include "CGrapheOriente.h"
#include "CParser.h"
#include "CAffichage.h"
#include "CInverse.h"

using namespace std;

/**
 * @class CCreationGraphe
 * 
 * @brief Classe liant CParser et CGrapheOriente et contenant la fonction principale
 */
class CCreationGraphe
{
public:
	/**
	 * @class CGrapheOriente
	 * 
	 * @brief Classe représentant un graphe orienté
	 */
	static CGrapheOriente CRE_CreerGraphe();

	/**
	 * @brief Fonction principale, crée un graphe à partir d'un fichier texte dont le chemin est tapé par l'utilisateur
	 * dans la console, l'affiche, en crée une copie inversée, et affiche cette copie
	 */
	static void CRE_FonctionPrincipale();
};

#endif // !CCREATIONGRAPHE_H
