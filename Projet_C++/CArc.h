#ifndef CARC_H
#define CARC_H
#include <string>
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
        * Postconditions : rien
        *******************************************************************************************************************
        */
        CArc(CArc& arcParam);

        /******************************************************************************************************************
        * CArc(CSommet* pSortant, CSommet* pEntrant)
        * *****************************************************************************************************************
        * Entree : deux strings qui sont les noms des sommets d'arrivée et de départ
        * Préconditions : il n'existe pas déjà un arc avec les mêmes départ et arrivée
        * Sortie : rien
        * Postconditions : rien
        *******************************************************************************************************************
        */
        CArc(string sSommetDepart, string sSommetArrivee) { sARC_SommetDepart = sSommetDepart; sARC_SommetArrive = sSommetArrivee; };


    #pragma endregion

    #pragma region ACCESSEURS
        /******************************************************************************************************************
        * ARC_GetSommetSortant()
        * *****************************************************************************************************************
        * Entree : rien
        * Préconditions : rien
        * Sortie : CSommet*, pointeur vers le sommet de départ de l'arc
        * Postconditions : rien
        *******************************************************************************************************************
        */
            string ARC_GetSommetDepart() const { return sARC_SommetDepart; }
            /******************************************************************************************************************
           * ARC_GetSommetEntrant()
           * *****************************************************************************************************************
           * Entree : rien
           * Préconditions : rien
           * Sortie : CSommet*, pointeur vers le sommet d'Entrant de l'arc
           * Postconditions : rien
           *******************************************************************************************************************
           */

            string ARC_GetSommetArrive() const { return sARC_SommetArrive; }
            /******************************************************************************************************************
            * ARC_SetSommetSortant(CSommet* pNewSommet)
            * *****************************************************************************************************************
            * Entree : un CSommet* qui va devenir le sommet de départ de l'arc
            * Préconditions : rien
            * Sortie : rien
            * Postconditions : rien
            *******************************************************************************************************************
            */
            void ARC_SetSommetDepart(string sNewSommet) { sARC_SommetDepart = sNewSommet; }

            /******************************************************************************************************************
            * ARC_SetSommetEntrant(CSommet* pNewSommet)
            * *****************************************************************************************************************
            * Entree : un CSommet* qui va devenir le sommet d'Entrant de l'arc
            * Préconditions : rien
            * Sortie : rien
            * Postconditions : rien
            *******************************************************************************************************************
            */
            void ARC_SetSommetArrive(string sNewSommet) { sARC_SommetArrive = sNewSommet; }
    #pragma endregion
   
};



#endif // !CARC_H




