#ifndef CGRAPHORIENTE_H
#define CGRAPHORIENTE_H

#include "CArc.h"
#include "CSommet.h"

using namespace std;

/**
 * @class CGrapheOriente
 * @brief Classe représentant un graphe orienté
 */
class CGrapheOriente
{
private:
    vector<CArc*> vGROarcs; ///< Vecteur des arcs du graphe
    vector<CSommet*> vGROsommets; ///< Vecteur des sommets du graphe

public:

    /**
     * @brief Constructeur par défaut, ne fait rien de spécial
     */
    CGrapheOriente() {}

    /**
     * @brief Constructeur avec paramètres
     * 
     * @param vArcs Vecteur des arcs du graphe
     * @param vSommets Vecteur des sommets du graphe
     */
    CGrapheOriente(vector<CArc*> vArcs, vector<CSommet*> vSommets) { vGROarcs = vArcs; vGROsommets = vSommets; }

    /**
     * @brief Constructeur de copie
     * 
     * @param GROgraphe Le graphe à copier.
     */
    CGrapheOriente(const CGrapheOriente& GROgraphe);

    /**
     * @brief Destructeur
     */
    ~CGrapheOriente();

    /**
     * @brief Accesseur pour les arcs du graphe
     * 
     * @return Le vecteur des arcs du graphe
     */
    vector<CArc*> GRO_GetArcs() const { return vGROarcs; };

    /**
     * @brief Accesseur pour les sommets du graphe
     * 
     * @return Le vecteur des sommets du graphe
     */
    vector<CSommet*> GRO_GetSommets() const { return vGROsommets; };

    /**
     * @brief Mutateur pour les arcs du graphe
     * 
     * @param vArcs Le nouveau vecteur des arcs du graphe
     */
    void GRO_SetArcs(vector<CArc*> vArcs) { vGROarcs = vArcs; }

    /**
     * @brief Mutateur pour les sommets du graphe
     * 
     * @param vSommets Le nouveau vecteur des sommets du graphe
     */
    void GRO_SetSommets(vector<CSommet*> vSommets) { vGROsommets = vSommets; }

    /**
     * @brief Ajoute un sommet au graphe si un sommet avec le même identifiant n'existe pas déjà
     * Si un sommet avec le même identifiant existe déjà, une exception est levée
     *
     * @param sID L'identifiant du nouveau sommet
     * 
     * @throw invalid_argument Si un sommet avec le même identifiant existe déjà
     */
    void GRO_AjouterSommet(const string& sID);

    /**
     * @brief Ajoute un arc entre deux sommets spécifiés par leurs identifiants
     * Si les sommets existent, un nouvel arc est créé et ajouté à la liste des arcs du graphe,
     * et les sommets de départ et d'arrivée sont mis à jour pour inclure ce nouvel arc
     * Si l'un des sommets ou les deux ne sont pas trouvés, une exception est levée
     *
     * @param sDepart Identifiant du sommet de départ de l'arc
     * @param sArrive Identifiant du sommet d'arrivée de l'arc
     * 
     * @throw invalid_argument Si le sommet de départ, le sommet d'arrivée, ou les deux ne sont pas trouvés dans le graphe
     */
    void GRO_AjouterArc(const string& sDepart, const string& sArrive);

protected:
    /**
     * @brief Recherche un arc dans le graphe
     * 
     * @param sDepart L'identifiant du sommet de départ de l'arc à rechercher
     * @param sArrive L'identifiant du sommet d'arrivée de l'arc à rechercher
     * 
     * @return Un itérateur vers l'arc recherché ou vGROarcs.end() si l'arc n'est pas trouvé
     */
    vector<CArc*>::iterator GRO_RechercheArcs(const string& sDepart, const string& sArrive);

    /**
     * @brief Recherche un sommet dans le graphe
     * 
     * @param sID L'identifiant du sommet à rechercher
     * 
     * @return Un itérateur vers le sommet recherché, ou vGROsommets.end() si le sommet n'est pas trouvé
     */
    vector<CSommet*>::iterator GRO_RechercheSommets(const string& sID);

public:

    /**
     * @brief Supprime un sommet du graphe
     *
     * Cette méthode supprime un sommet du graphe spécifié par son identifiant
     * Si le sommet existe il est supprimé de la liste des sommets du graphe,
     * et tous les arcs entrants et sortants de ce sommet sont aussi supprimés
     * Si le sommet n'existe pas une exception est levée
     *
     * @param sID L'identifiant du sommet à supprimer
     * 
     * @throw invalid_argument Si le sommet spécifié n'existe pas dans le graphe
     */
    void GRO_SupprimerSommet(const string& sRecherche);

    /**
     * @brief Supprime un arc du graphe
     *
     * Cette fonction recherche un arc spécifique dans le graphe orienté en utilisant les identifiants de départ et d'arrivée fournis
     * Si l'arc est trouvé, il est supprimé du graphe, et si l'arc n'est pas trouvé, un message d'erreur est affiché
     *
     * @param sDepart L'identifiant du sommet de départ de l'arc à supprimer
     * @param sArrive L'identifiant du sommet d'arrivée de l'arc à supprimer
     */
    void GRO_SupprimerArc(const string& sDepart, const string& sArrive);
};

#endif // !CGRAPHORIENTE_H
