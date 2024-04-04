#ifndef CARC_H
#define CARC_H
#include <string>
#include "CColor.h"
using namespace std;

class CArc
{
private:

    string sARC_SommetDepart;
    string sARC_SommetArrive;

public:

    #pragma region CONSTRUCTEURS & DESTRUCTEUR
        /******************************************************************************************************************
        * CArc()
        * *****************************************************************************************************************
        * Entree : rien
        * Préconditions : rien
        * Sortie : rien
        * Postconditions : les sommets de départ et d'arrivée sont égaux à ""
        *******************************************************************************************************************
        */
        CArc();

        /******************************************************************************************************************
        * CArc(CArc &arcParam)
        * *****************************************************************************************************************
        * Entree : un CArc par référence
        * Préconditions : rien
        * Sortie : rien
        * Postconditions : les sommets (string) de arcParam sont copiés dans l'objet
        *******************************************************************************************************************
        */
        CArc(CArc& arcParam);

        /******************************************************************************************************************
        * CArc(CSommet* pSortant, CSommet* pEntrant)
        * *****************************************************************************************************************
        * Entree : deux strings qui sont les noms des sommets d'arrivée et de départ
        * Préconditions : il n'existe pas déjà un arc avec les mêmes départ et arrivée
        * Sortie : rien
        * Postconditions : l'objet prend les paramètres pour sommets de départ et d'arrivée
        *******************************************************************************************************************
        */
        CArc(string sSommetDepart, string sSommetArrivee) { 
            sARC_SommetDepart = sSommetDepart; 
            sARC_SommetArrive = sSommetArrivee; 
        };


    #pragma endregion

    #pragma region ACCESSEURS
        /******************************************************************************************************************
        * ARC_GetSommetDepart()
        * *****************************************************************************************************************
        * Entree : rien
        * Préconditions : rien
        * Sortie : le nom du sommet de départ de l'arc
        * Postconditions : rien
        *******************************************************************************************************************
        */
        string ARC_GetSommetDepart() const { return sARC_SommetDepart; }

        /******************************************************************************************************************
        * ARC_GetSommetArrivee()
        * *****************************************************************************************************************
        * Entree : rien
        * Préconditions : rien
        * Sortie : le nom du sommet d'arrivée de l'arc
        * Postconditions : rien
        *******************************************************************************************************************
        */
        string ARC_GetSommetArrive() const { return sARC_SommetArrive; }

        /******************************************************************************************************************
        * ARC_SetSommetDepart(string sNewSommet)
        * *****************************************************************************************************************
        * Entree : une string qui va devenir le sommet de départ de l'arc
        * Préconditions : le sommet existe
        * Sortie : rien
        * Postconditions : le sommet de départ de l'arc est maintenant sNewSommet
        *******************************************************************************************************************
        */
        void ARC_SetSommetDepart(string sNewSommet) { sARC_SommetDepart = sNewSommet; }

        /******************************************************************************************************************
        * ARC_SetSommetArrivee(string sNewSommet)
        * *****************************************************************************************************************
        * Entree : une string qui va devenir le sommet entrant de l'arc
        * Préconditions : le sommet existe
        * Sortie : rien
        * Postconditions : le sommet d'arrivée de l'arc est maintenant sNewSommet
        *******************************************************************************************************************
        */
        void ARC_SetSommetArrive(string sNewSommet) { sARC_SommetArrive = sNewSommet; }
    #pragma endregion
   
};



#endif // !CARC_H




