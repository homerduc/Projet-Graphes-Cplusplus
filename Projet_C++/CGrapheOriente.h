/**
 * @file CGrapheOriente.h
 * @brief D�finition de la classe CGrapheOriente.
 */

#ifndef CGRAPHORIENTE_H
#define CGRAPHORIENTE_H

#include "CArc.h"
#include "CSommet.h"

using namespace std;

/**
 * @class CGrapheOriente
 * @brief Classe repr�sentant un graphe orient�.
 *
 * Un graphe orient� est un graphe o� chaque arc a une direction, allant d'un sommet de d�part � un sommet d'arriv�e.
 */
class CGrapheOriente
{
private:
    vector<CArc*> vGROarcs; ///< Vecteur des arcs du graphe.
    vector<CSommet*> vGROsommets; ///< Vecteur des sommets du graphe.

public:

    /**
     * @brief Constructeur par d�faut.
     */
    CGrapheOriente() {}

    /**
     * @brief Constructeur avec param�tres.
     * @param vArcs Vecteur des arcs du graphe.
     * @param vSommets Vecteur des sommets du graphe.
     */
    CGrapheOriente(vector<CArc*> vArcs, vector<CSommet*> vSommets) { vGROarcs = vArcs; vGROsommets = vSommets; }

    /**
     * @brief Constructeur de copie.
     * @param GROgraphe Le graphe � copier.
     */
    CGrapheOriente(const CGrapheOriente& GROgraphe);

    /**
     * @brief Destructeur.
     */
    ~CGrapheOriente();

    /**
     * @brief Accesseur pour les arcs du graphe.
     * @return Le vecteur des arcs du graphe.
     */
    vector<CArc*> GRO_GetArcs() const { return vGROarcs; };

    /**
     * @brief Accesseur pour les sommets du graphe.
     * @return Le vecteur des sommets du graphe.
     */
    vector<CSommet*> GRO_GetSommets() const { return vGROsommets; };

    /**
     * @brief Mutateur pour les arcs du graphe.
     * @param vArcs Le nouveau vecteur des arcs du graphe.
     */
    void GRO_SetArcs(vector<CArc*> vArcs) { vGROarcs = vArcs; }

    /**
     * @brief Mutateur pour les sommets du graphe.
     * @param vSommets Le nouveau vecteur des sommets du graphe.
     */
    void GRO_SetSommets(vector<CSommet*> vSommets) { vGROsommets = vSommets; }

    /**
     * @brief Ajoute un sommet au graphe.
     *
     * Cette m�thode ajoute un sommet au graphe si un sommet avec le m�me identifiant n'existe pas d�j�.
     * Si un sommet avec le m�me identifiant existe d�j�, une exception est lev�e.
     *
     * @param sID L'identifiant du nouveau sommet.
     * @throw invalid_argument Si un sommet avec le m�me identifiant existe d�j�.
     */
    void GRO_AjouterSommet(string sID);

    /**
     * @brief Ajoute un arc au graphe.
     *
     * Cette m�thode ajoute un arc entre deux sommets sp�cifi�s par leurs identifiants.
     * Si les sommets existent, un nouvel arc est cr�� et ajout� � la liste des arcs du graphe,
     * et les sommets de d�part et d'arriv�e sont mis � jour pour inclure ce nouvel arc.
     * Si l'un des sommets ou les deux ne sont pas trouv�s, une exception est lev�e.
     *
     * @param sDepart Identifiant du sommet de d�part de l'arc.
     * @param sArrive Identifiant du sommet d'arriv�e de l'arc.
     * @throw invalid_argument Si le sommet de d�part, le sommet d'arriv�e, ou les deux ne sont pas trouv�s dans le graphe.
     */
    void GRO_AjouterArc(string sDepart, string sArrive);

protected:
    /**
     * @brief Recherche un arc dans le graphe.
     * @param sDepart L'identifiant du sommet de d�part de l'arc � rechercher.
     * @param sArrive L'identifiant du sommet d'arriv�e de l'arc � rechercher.
     * @return Un it�rateur vers l'arc recherch�, ou vGROarcs.end() si l'arc n'est pas trouv�.
     */
    vector<CArc*>::iterator GRO_RechercheArcs(string sDepart, string sArrive);

    /**
     * @brief Recherche un sommet dans le graphe.
     * @param sID L'identifiant du sommet � rechercher.
     * @return Un it�rateur vers le sommet recherch�, ou vGROsommets.end() si le sommet n'est pas trouv�.
     */
    vector<CSommet*>::iterator GRO_RechercheSommets(string sID);

public:

    /**
     * @brief Supprime un sommet du graphe.
     *
     * Cette m�thode supprime un sommet du graphe, sp�cifi� par son identifiant.
     * Si le sommet existe, il est supprim� de la liste des sommets du graphe,
     * et tous les arcs entrants et sortants de ce sommet sont �galement supprim�s.
     * Si le sommet n'existe pas, une exception est lev�e.
     *
     * @param sID L'identifiant du sommet � supprimer.
     * @throw invalid_argument Si le sommet sp�cifi� n'existe pas dans le graphe.
     */
    void GRO_SupprimerSommet(string sRecherche);

    /**
     * @brief Supprime un arc du graphe.
     *
     * Cette fonction recherche un arc sp�cifique dans le graphe orient� en utilisant les identifiants de d�part et d'arriv�e fournis.
     * Si l'arc est trouv�, il est supprim� du graphe. Si l'arc n'est pas trouv�, un message d'erreur est affich�.
     *
     * @param sDepart L'identifiant du sommet de d�part de l'arc � supprimer.
     * @param sArrive L'identifiant du sommet d'arriv�e de l'arc � supprimer.
     */
    void GRO_SupprimerArc(string sDepart, string sArrive);

    CGrapheOriente* GRO_Inverse();

    /**
     * @brief Affiche le graphe.
     */
    void Afficher_Graphe();
};

#endif // !CGRAPHORIENTE_H
