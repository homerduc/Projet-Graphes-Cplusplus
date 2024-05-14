#ifndef CAFFICHAGE_H
#define CAFFICHAGE_H 

#include <string>
#include<iostream>
#include "CGraphe.h"
#include "CDetectionColoration.h"

#pragma region TAILLES AFFICHAGE
#define TAILLE_CREATION_AJOUT 41
#define TAILLE_SUPPR_ARC 32  
#define TAILLE_SUPPR_SOMMET 26
#define TAILLE_AFFICHA_GEGRAPH 38  
#define TAILLE_Encadre_arcs "latailleestde16 "  
#pragma endregion

#pragma region TYPES ERREURS
#define DEPART_inconnu 1
#define ARRIVE_inconnu 2
#define DEPART_ARRIVE_inconnu 3
#pragma endregion

#define ARC_Tabultation "		"
#define TEXT_Tabultation "	"

using namespace std;

/**
 * @class CAffichage
 * @brief Classe pour l'affichage des informations du graphe
 *
 * Cette classe contient des méthodes statiques pour afficher les informations du graphe et pour afficher certaines erreurs
 */
class CAffichage
{
public:

    /**
     * @brief Affiche l'information de suppression d'un arc
     *
     * @param sDepart Identifiant du sommet de départ de l'arc
     * @param sArrive Identifiant du sommet d'arrivée de l'arc
     */
    static void AFC_AffichageSupprArc(const string& sDepart, const string& sArrive);

    /**
     * @brief Affiche l'information de suppression d'un sommet
     *
     * @param sID L'identifiant du sommet
     */
    static void AFC_AffichageSupprSommet(const string& sID);

    /**
     * @brief Affiche l'information d'ajout d'un sommet
     *
     * @param sID L'identifiant du sommet.
     */
    static void AFC_AffichageAjoutSommet(const string& sID);

    /**
     * @brief Affiche l'information d'ajout d'un arc
     *
     * @param sDepart Identifiant du sommet de départ de l'arc
     * @param sArrive Identifiant du sommet d'arrivée de l'arc
     */
    static void AFC_AffichageAjoutArc(const string& sDepart, const string& sArrive);

    /**
     * @brief Affiche les informations d'un sommet
     *
     * @param SOMsommet Pointeur vers le sommet à afficher
     */
    static void AFC_Affichage_Sommets(CSommet* SOMsommet);

    /**
     * @brief Affiche les informations d'un graphe
     *
     * @param GROgraph Pointeur vers le graphe à afficher
     */
    static void AFC_Afficher_Graphe(CGrapheOriente* GROgraph);


    /**
     * @brief Affiche l'erreur d'ajout d'un sommet
     *
     * @param sID Identifiant du sommet
     */
    static void AFC_Erreur_ajoutSommet(const string& sID);

    /**
     * @brief Affiche l'erreur d'ajout d'un arc
     *
     * @param sDepart Identifiant du sommet de départ de l'arc
     * @param sArrive Identifiant du sommet d'arrivée de l'arc
     * @param iErreur Type d'erreur
     */
    static void AFC_Erreur_ajoutArc(const string& sDepart, const string& sArrive, const int& iErreur);

    /**
     * @brief Calcule les tirets pour l'affichage
     *
     * @param sID Identifiant du sommet ou de l'arc
     * @param cMotif Caractère pour le motif des tirets
     * @param iType Type de l'affichage
     * @return Une chaîne de caractères contenant les tirets calculés
     */
    static string AFC_Calcul_tirets(const string& sID, const char& cMotif, const int& iType);

    /**
     * @brief Calcule l'espace vide pour l'affichage de la création
     *
     * @param sID Identifiant du sommet ou de l'arc
     * @param cMotif Caractère pour le motif de l'espace vide
     * 
     * @return Une chaîne de caractères contenant l'espace vide calculé
     */
    static string AFC_Calcul_vide_Creation(const string& sID, const char& cMotif);

    /**
     * @brief Calcule l'espace vide pour l'affichage de l'ajout
     *
     * @param sID Identifiant du sommet ou de l'arc
     * @param cMotif Caractère pour le motif de l'espace vide
     * 
     * @return Une chaîne de caractères contenant l'espace vide calculé
     */
    static string AFC_Calcul_vide_Ajout(const string& sID, const char& cMotif);


    /**
     * @brief Affiche toutes les informations d'un graphe
     *
     * @param GRAgraph Pointeur vers le graphe à afficher
     */
    static void AFC_Afficher_Graphe(CGraphe* GRAgraph);

    /**
     * @brief Affiche les informations des arcs d'un graphe
     *
     * @param pARCarc Pointeur vers le premier arc du graphe
     */
    static void AFC_Afficher_Arcs(CArc* pARCarc);

    /**
     * @brief Annonce le nom d'un graphe pour différencier un graphe de sa version inversée
     *
     * @param sNom Le nom du graphe à annoncer
     */
    static void AFC_AnnoncerGraphe(const string& sNom);

    static void AFC_DemanderColoration(CDetectionColoration& Detection);
};

#endif // CAFFICHAGE_H
