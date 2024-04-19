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
 * @brief Classe contenant des méthodes statiques de parser
 */
class CParser
{
public:
	/**
	 * @brief Renvoie la clé d'une string de la forme "clé = ************" peu importe le nombre d'espaces
	 *
	 * @param sLigne la ligne sur laquelle trouver la clé
	 *
	 * @return La clé insolée
	 */
	static string PAR_TrouverCle(const string& sLigne);

	/**
	 * @brief Renvoie la valeur d'une string de la forme "clé = valeur" peu importe le nombre d'espaces
	 *
	 * @param sLigne la ligne sur laquelle trouver la valeur
	 *
	 * @return La valeur unique isolée
	 */
	static string PAR_TrouverValUnique(const string& sLigne);

	/**
	 * @brief Parcourt tout le fichier texte et renvoie une map de toutes les paires de type "clé = valeurunique" peu importe le nombre d'espaces
	 *
	 * @param sChemin le chemin absolu vers le fichier texte
	 *
	 * @return Une map associant une clé à une valeur
	 */
	static map<string, string> PAR_GetCleValeur(const string& sChemin);

	/**
	 * @brief Parcourt tout le fichier texte et renvoie une map de toutes les paires de type "clé = valeursmultiples" peu importe le nombre d'espaces
	 *
	 * @param sChemin le chemin absolu vers le fichier texte
	 *
	 * @return Une map associant une clé à un vecteur de map contenant elle-même des paires clé/valeur
	 */
	static map<string, vector<map<string, string>>> PAR_GetCleListeValeur(const string& sChemin);

};
#endif // !CPARSER_H


