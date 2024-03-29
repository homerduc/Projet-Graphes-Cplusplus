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
        * Pr�conditions : rien
        * Sortie : rien
        * Postconditions : les pointeurs de sommets sont initialis�s � NULL
        *******************************************************************************************************************
        */
        CArc();

        /******************************************************************************************************************
        * CArc(CArc &arcParam)
        * *****************************************************************************************************************
        * Entree : un CArc par r�f�rence
        * Pr�conditions : rien
        * Sortie : rien
        * Postconditions : le nouvel objet a cr�� une copie du graphe entier
        *******************************************************************************************************************
        */
        CArc(CArc& arcParam);

        /******************************************************************************************************************
        * CArc(CSommet* pSortant, CSommet* pEntrant)
        * *****************************************************************************************************************
        * Entree : deux pointeurs vers les objets CSommet de d�part et d'arriv�e de l'arc
        * Pr�conditions : il n'existe pas d�j� un arc avec les m�mes d�part et arriv�e
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
        * Pr�conditions : rien
        * Sortie : CSommet*, pointeur vers le sommet de d�part de l'arc
        * Postconditions : rien
        *******************************************************************************************************************
        */
            string ARC_GetSommetDepart() const { return sARC_SommetDepart; }
            /******************************************************************************************************************
           * ARC_GetSommetEntrant()
           * *****************************************************************************************************************
           * Entree : rien
           * Pr�conditions : rien
           * Sortie : CSommet*, pointeur vers le sommet d'Entrant de l'arc
           * Postconditions : rien
           *******************************************************************************************************************
           */

            string ARC_GetSommetArrive() const { return sARC_SommetArrive; }
            /******************************************************************************************************************
            * ARC_SetSommetSortant(CSommet* pNewSommet)
            * *****************************************************************************************************************
            * Entree : un CSommet* qui va devenir le sommet de d�part de l'arc
            * Pr�conditions : rien
            * Sortie : rien
            * Postconditions : rien
            *******************************************************************************************************************
            */
            void ARC_SetSommetDepart(string sNewSommet) { sARC_SommetDepart = sNewSommet; }

            /******************************************************************************************************************
            * ARC_SetSommetEntrant(CSommet* pNewSommet)
            * *****************************************************************************************************************
            * Entree : un CSommet* qui va devenir le sommet d'Entrant de l'arc
            * Pr�conditions : rien
            * Sortie : rien
            * Postconditions : rien
            *******************************************************************************************************************
            */
            void ARC_SetSommetArrive(string sNewSommet) { sARC_SommetArrive = sNewSommet; }
    #pragma endregion
   
};



#endif // !CARC_H




