#include "CArc.h"

CArc::CArc()
{
	sARC_SommetArrive = "";
	sARC_SommetDepart = "";
}

CArc::CArc(CArc& arcParam)
{
	sARC_SommetArrive = arcParam.ARC_GetSommetArrive();
	sARC_SommetDepart = arcParam.ARC_GetSommetDepart();
}
