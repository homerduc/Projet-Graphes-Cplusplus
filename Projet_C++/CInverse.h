#ifndef CINVERSE_H
#define CINVERSE_H
#include "CGrapheOriente.h"

/**
 * @class CInverse
 * @brief Classe contenant une seule m�thode d'inverserment de graphe
 */
class CInverse
{
public :
	/**
	 * @brief Cr�e et alloue une version invers�e de oGraphe et renvoie un pointeur vers cette version
	 *
	 * @param oGraphe un objet CGrapheoriente qu'on veut inverser
	 * 
	 * @return Un pointeur vers le nouveau graphe invers�
	 */
	static CGrapheOriente* INV_Inverse(const CGrapheOriente& oGraphe);
};

#endif // !CINVERSE_H