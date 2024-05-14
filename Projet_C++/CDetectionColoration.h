#ifndef CDETECTIONCOLORATION
#define CDETECTIONCOLORATION
#include "CGrapheOriente.h"
#include <map>

class CDetectionColoration
{
private:

	map<string, unsigned int> sommetCouleur;
	const CGrapheOriente* Graphe;
	
public:

	CDetectionColoration(const CGrapheOriente& graphe);

	bool DTCDetecter(const unsigned int k, unsigned int i = 0);
	map<string, unsigned int> DTCGetSommetCouleur();
private:
	bool DTCCouleurEstValide(unsigned int couleur, unsigned int i);
};

#endif //CDETECTIONCOLORATION

