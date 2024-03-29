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
        * Postconditions : les pointeurs de sommets sont initialisés à NULL
        *******************************************************************************************************************
        */
        CArc();

        /******************************************************************************************************************
        * CArc(CArc &arcParam)
        * *****************************************************************************************************************
        * Entree : un CArc par référence
        * Préconditions : rien
        * Sortie : rien
        * Postconditions : le nouvel objet a créé une copie du graphe entier
        *******************************************************************************************************************
        */
        CArc(CArc& arcParam);

        /******************************************************************************************************************
        * CArc(CSommet* pSortant, CSommet* pEntrant)
        * *****************************************************************************************************************
        * Entree : deux pointeurs vers les objets CSommet de départ et d'arrivée de l'arc
        * Préconditions : il n'existe pas déjà un arc avec les mêmes départ et arrivée
        * Sortie : rien
        * Postconditions : rien
        *******************************************************************************************************************
        */
        CArc(string sSortant, string sEntrant) { sARC_SommetDepart = sSortant; sARC_SommetArrive = sEntrant; };

        //~CArc

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




