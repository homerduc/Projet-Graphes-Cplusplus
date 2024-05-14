#include "CCreationGraphe.h"



CGrapheOriente CCreationGraphe::CRE_CreerGraphe()
{
    CGrapheOriente oGrapheOriente;
    unsigned int uiNBSommets = 0;
    unsigned int uiNBArcs = 0;
    string sDebutArc; // La string qui va stocker le debut de l'arc entre deux it�rations
    string sChemin;
    cout << "Veuillez entrer le chemin absolu vers le fichier de donnees" << endl;
    cin >> sChemin;

    map<string, string> mCleVal = CParser::PAR_GetCleValeur(sChemin);
    map<string,vector<map<string,string>>> mCleListeVar = CParser::PAR_GetCleListeValeur(sChemin);


    // On v�rifie que nbsommets et nbarcs sont bel et bien des entiers
    try {
        for (const auto& mPaire : mCleVal) {
            if (mPaire.first == "NBSommets") {
                uiNBSommets = (unsigned int)stoi(mPaire.second);
            }
            else if (mPaire.first == "NBArcs") {
                uiNBArcs = (unsigned int)stoi(mPaire.second);
            }
        }
    }
    catch (const std::invalid_argument& e) {
        cout << e.what() << " : Entrez une valeur correcte pour le nombre de sommets et d'arcs ! " << endl;
        exit(EXIT_FAILURE);
    }
    catch (const std::out_of_range&) {
        cout << "Entrez une valeur correcte pour le nombre de sommets et d'arcs ! " << endl;
        exit(EXIT_FAILURE);
    }

    // Nous cr�ons les sommets d'abord
    for (const auto& mPaire : mCleListeVar) {
        if (mPaire.first == "Sommets") { // Si nous sommes dans le bloc des sommets
            for (const auto& mMapSommets : mPaire.second) { // On parcourt le vector contenant tous les sommets sous formes de maps
                for (const auto& pPaireSommet : mMapSommets) { // On parcourt la map (elle ne contient qu'une valeur type Numero=x)
                    oGrapheOriente.GRO_AjouterSommet(pPaireSommet.second); // On cr�e le sommet
                }
            }
        }
    }

    // Nous n'avons pas trouv� de moyen logique de factoriser le code + que cela, justification dans le rapport
    
    // Puis nous cr�ons les arcs
    for (const auto& mPaire : mCleListeVar) {
        if (mPaire.first == "Arcs") { // Si nous sommes dans le bloc des arcs
            for (const auto& mMapArcs : mPaire.second) {
                for (const auto& pPaireArcs : mMapArcs) { // On parcourt debut, fin, debut, fin, etc
                    if (pPaireArcs.first == "Debut") {
                        sDebutArc = pPaireArcs.second; // On garde la valeur de Debut pour cr�er l'arc � la prochaine it�ration
                    }
                    else if (pPaireArcs.first == "Fin") {
                        oGrapheOriente.GRO_AjouterArc(sDebutArc, pPaireArcs.second); // On ajoute l'arc
                    }
                }
            }
        }
    }

    try
    {
        if (uiNBSommets != oGrapheOriente.GRO_GetSommets().size() || uiNBArcs != oGrapheOriente.GRO_GetArcs().size()) {
            throw invalid_argument("ATTENTION : Le nombre de sommets ou d'arcs indique ne correspond pas aux valeurs que vous avez rentrees");
        }
    }
    catch (const std::exception& eException)
    {
        cout << eException.what() << endl;
        exit(EXIT_FAILURE); // On arr�te l'ex�cution
    }

    return oGrapheOriente;
}

void CCreationGraphe::CRE_FonctionPrincipale()
{
    // Sujet de Base
    /*
    CGrapheOriente oGrapheOriente = CRE_CreerGraphe(); // Cr�ation du graphe orient� "normal"
    CAffichage::AFC_AnnoncerGraphe("Creation des elements du graphe classique");
    CAffichage::AFC_AnnoncerGraphe("Graphe classique");
    CAffichage::AFC_Afficher_Graphe(&oGrapheOriente);
    CAffichage::AFC_AnnoncerGraphe("Creation des elements du graphe inverse");
    CGrapheOriente* oGrapheOrienteInverse = CInverse::INV_Inverse(oGrapheOriente); // Cr�ation du graphe orient� invers�
    CAffichage::AFC_AnnoncerGraphe("Graphe inverse");
    CAffichage::AFC_Afficher_Graphe(oGrapheOrienteInverse);
    delete oGrapheOrienteInverse;
    */


    // D�monstration d�tection coloration avec un graphe repr�sentant un pentagone, fonctionne pour k sup�rieur ou �gal � 3
    CGraphe oGrapheNonOriente;
    oGrapheNonOriente.GRO_AjouterSommet("1");
    oGrapheNonOriente.GRO_AjouterSommet("2");
    oGrapheNonOriente.GRO_AjouterSommet("3");
    oGrapheNonOriente.GRO_AjouterSommet("4");
    oGrapheNonOriente.GRO_AjouterSommet("5");
    oGrapheNonOriente.GRA_AjouterArc("1", "2");
    oGrapheNonOriente.GRA_AjouterArc("2", "3");
    oGrapheNonOriente.GRA_AjouterArc("3", "4");
    oGrapheNonOriente.GRA_AjouterArc("4", "5");
    oGrapheNonOriente.GRA_AjouterArc("5", "1");

    // Cr�ation d'un objet Detection de couleur
    CDetectionColoration oDetectionColoration(oGrapheNonOriente);
    unsigned int k = 3;
    cout << "R�sultat de l'algorithme pour k =  " << k << " : " << oDetectionColoration.DTCDetecter(k) << endl;

    
    // Version avec interface pour faire des tests plus rapidement
    // CAffichage::AFC_DemanderColoration(oDetectionColoration);
}
