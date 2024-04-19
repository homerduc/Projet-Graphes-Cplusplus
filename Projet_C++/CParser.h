#ifndef CPARSER_H
#define CPARSER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/**
 * @class CParser
 * @brief Classe contenant des m�thodes statiques de parser
 */
class CParser
{
public:
	/**
	 * @brief Renvoie la cl� d'une string de la forme "cl� = ************" peu importe le nombre d'espaces
	 *
	 * @param sLigne la ligne sur laquelle trouver la cl�
	 *
	 * @return La cl� insol�e
	 */
	static string PAR_TrouverCle(const string& sLigne);

	/**
	 * @brief Renvoie la valeur d'une string de la forme "cl� = valeur" peu importe le nombre d'espaces
	 *
	 * @param sLigne la ligne sur laquelle trouver la valeur
	 *
	 * @return La valeur unique isol�e
	 */
	static string PAR_TrouverValUnique(const string& sLigne);

	/**
	 * @brief Parcourt tout le fichier texte et renvoie une map de toutes les paires de type "cl� = valeurunique" peu importe le nombre d'espaces
	 *
	 * @param sChemin le chemin absolu vers le fichier texte
	 *
	 * @return Une map associant une cl� � une valeur
	 */
	static map<string, string> PAR_GetCleValeur(const string& sChemin);

	/**
	 * @brief Parcourt tout le fichier texte et renvoie une map de toutes les paires de type "cl� = valeursmultiples" peu importe le nombre d'espaces
	 *
	 * @param sChemin le chemin absolu vers le fichier texte
	 *
	 * @return Une map associant une cl� � un vecteur de map contenant elle-m�me des paires cl�/valeur
	 */
	static map<string, vector<map<string, string>>> PAR_GetCleListeValeur(const string& sChemin);

};
#endif // !CPARSER_H


