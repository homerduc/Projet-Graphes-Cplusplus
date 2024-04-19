#pragma once

#include <iostream>
#include <string>

#include "CGrapheOriente.h"
#include "CParser.h"
#include "CAffichage.h"
#include "CInverse.h"

using namespace std;

class CCreationGraphe
{
public:
	static CGrapheOriente CRE_CreerGraphe();
	static void CRE_FonctionPrincipale();
};