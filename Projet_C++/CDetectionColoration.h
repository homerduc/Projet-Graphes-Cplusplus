#ifndef CDETECTIONCOLORATION
#define CDETECTIONCOLORATION
#include "CGrapheOriente.h"
#include <map>

class CDetectionColoration
{
private:
	bool DTCTousColores(map<string, unsigned int>& map);
public:
	bool DTCDetecter(const CGrapheOriente* graphe, const unsigned int& k);

};

#endif //CDETECTIONCOLORATION

