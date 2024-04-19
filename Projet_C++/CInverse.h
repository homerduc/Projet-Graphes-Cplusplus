#ifndef CINVERSE_H
#define CINVERSE_H
#include "CGrapheOriente.h"

/**
 * @class CInverse
 * @brief Classe contenant une seule méthode d'inverserment de graphe
 */
class CInverse
{
public :
	/**
	 * @brief Crée et alloue une version inversée de oGraphe et renvoie un pointeur vers cette version
	 *
	 * @param oGraphe un objet CGrapheoriente qu'on veut inverser
	 * 
	 * @return Un pointeur vers le nouveau graphe inversé
	 */
	static CGrapheOriente* INV_Inverse(const CGrapheOriente& oGraphe);
};

#endif // !CINVERSE_H