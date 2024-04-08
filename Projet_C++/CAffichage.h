/**
 * @file CAffichage.h
 * @brief Définition de la classe CAffichage.
 */

#ifndef CAFFICHAGE_H
#define CAFFICHAGE_H 

#include <string>
#include<iostream>
#include "CGrapheOriente.h"

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

#pragma region COULEURS
#define CREATION_couleur "\033[38;5;37m"
#define AJOUT_couleur "\033[38;5;27m"
#define ERREUR_couleur "\033[48;5;52m"
#define SUPPR_couleur "\033[38;5;2m"
#define RESAURER_couleur "\033[0m"
#define ARC_couleur "\033[38;5;166m"  
#define ARC_Tabultation "		"
#define TEXT_Tabultation "	"
#pragma endregion

using namespace std;

/**
 * @class CAffichage
 * @brief Classe pour l'affichage des informations du graphe.
 *
 * Cette classe contient des méthodes statiques pour afficher les informations du graphe, comme l'ajout et la suppression de sommets et d'arcs, et pour afficher les erreurs.
 */
class CAffichage
{
public:

    /**
     * @brief Affiche l'information de suppression d'un arc.
     *
     * @param sDepart Identifiant du sommet de départ de l'arc.
     * @param sArrive Identifiant du sommet d'arrivée de l'arc.
     */
    static void AFC_AffichageSupprArc(string sDepart, string sArrive);

    /**
     * @brief Affiche l'information de suppression d'un sommet.
     *
     * @param sID Identifiant du sommet.
     */
    static void AFC_AffichageSupprSommet(string sID);

    /**
     * @brief Affiche l'information d'ajout d'un sommet.
     *
     * @param sID Identifiant du sommet.
     */
    static void AFC_AffichageAjoutSommet(string sID);

    /**
     * @brief Affiche l'information d'ajout d'un arc.
     *
     * @param sDepart Identifiant du sommet de départ de l'arc.
     * @param sArrive Identifiant du sommet d'arrivée de l'arc.
     */
    static void AFC_AffichageAjoutArc(string sDepart, string sArrive);

    /**
     * @brief Affiche les informations d'un sommet.
     *
     * @param SOMsommet Pointeur vers le sommet à afficher.
     */
    static void AFC_Affichage_Sommets(CSommet* SOMsommet);

    /**
     * @brief Affiche les informations d'un graphe.
     *
     * @param GROgraph Pointeur vers le graphe à afficher.
     */
    static void AFC_Afficher_Graph(CGrapheOriente* GROgraph);

    /**
     * @brief Affiche l'erreur d'ajout d'un sommet.
     *
     * @param sID Identifiant du sommet.
     */
    static void AFC_Erreur_ajoutSommet(string sID);

    /**
     * @brief Affiche l'erreur d'ajout d'un arc.
     *
     * @param sDepart Identifiant du sommet de départ de l'arc.
     * @param sArrive Identifiant du sommet d'arrivée de l'arc.
     * @param iErreur Type d'erreur.
     */
    static void AFC_Erreur_ajoutArc(string sDepart, string sArrive, int iErreur);

    /**
     * @brief Calcule les tirets pour l'affichage.
     *
     * @param sID Identifiant du sommet ou de l'arc.
     * @param cMotif Caractère pour le motif des tirets.
     * @param iType Type de l'affichage.
     * @return Une chaîne de caractères contenant les tirets calculés.
     */
    static const char* AFC_Calcul_tirets(string sID, const char cMotif, int iType);

    /**
     * @brief Calcule l'espace vide pour l'affichage de la création.
     *
     * @param sID Identifiant du sommet ou de l'arc.
     * @param cMotif Caractère pour le motif de l'espace vide.
     * @return Une chaîne de caractères contenant l'espace vide calculé.
     */
    static const char* AFC_Calcul_vide_Creation(string sID, const char cMotif);

    /**
     * @brief Calcule l'espace vide pour l'affichage de l'ajout.
     *
     * @param sID Identifiant du sommet ou de l'arc.
     * @param cMotif Caractère pour le motif de l'espace vide.
     * @return Une chaîne de caractères contenant l'espace vide calculé.
     */
    static const char* AFC_Calcul_vide_Ajout(string sID, const char cMotif);

};

#endif // CAFFICHAGE_H
