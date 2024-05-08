#ifndef CCREATIONGRAPHE_H
#define CCREATIONGRAPHE_H
#include <iostream>
#include <string>

#include "CGrapheOriente.h"
#include "CParser.h"
#include "CAffichage.h"
#include "CInverse.h"
#include "CDetectionColoration.h"

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
	 * @brief Cr�e un objet CGrapheOriente � partir du fichier texte indiqu� par l'utilisateur
	 *
	 * @return Un objet CGrapheOriente
	 */
	static CGrapheOriente CRE_CreerGraphe();

	/**
	 * @brief Fonction principale, cr�e un graphe � partir d'un fichier texte dont le chemin est tap� par l'utilisateur
	 * dans la console, l'affiche, en cr�e une copie invers�e, et affiche cette copie
	 */
	static void CRE_FonctionPrincipale();

	
};

#endif // !CCREATIONGRAPHE_H
