#include "CCreationGraphe.h"



CGrapheOriente CCreationGraphe::CRE_CreerGraphe()
{
    CGrapheOriente oGrapheOriente;
    unsigned int uiNBSommets = 0;
    unsigned int uiNBArcs = 0;
    string sDebutArc; // La string qui va stocker le debut de l'arc entre deux itérations
    string sChemin;
    cout << "Veuillez entrer le chemin absolu vers le fichier de donnees" << endl;
    cin >> sChemin;

    map<string, string> mCleVal = CParser::PAR_GetCleValeur(sChemin);
    map<string,vector<map<string,string>>> mCleListeVar = CParser::PAR_GetCleListeValeur(sChemin);


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
    catch (const std::out_of_range& e) {
        cout << "Entrez une valeur correcte pour le nombre de sommets et d'arcs ! " << endl;
        exit(EXIT_FAILURE);
    }

    // Nous créons les sommets d'abord
    for (const auto& mPaire : mCleListeVar) {
        if (mPaire.first == "Sommets") { // Si nous sommes dans le bloc des sommets
            for (const auto& mMapSommets : mPaire.second) { // On parcourt le vector contenant tous les sommets sous formes de maps
                for (const auto& pPaireSommet : mMapSommets) { // On parcourt la map (elle ne contient qu'une valeur type Numero=x)
                    oGrapheOriente.GRO_AjouterSommet(pPaireSommet.second); // On crée le sommet
                }
            }
        }
    }

    // Nous n'avons pas trouvé de moyen de factoriser le code + que cela, nous avons élaboré sur cela dans le rapport
    
    // Puis nous créons les arcs
    for (const auto& mPaire : mCleListeVar) {
        if (mPaire.first == "Arcs") { // Si nous sommes dans le bloc des arcs
            for (const auto& mMapArcs : mPaire.second) {
                for (const auto& pPaireArcs : mMapArcs) { // On parcourt debut, fin, debut, fin, etc
                    if (pPaireArcs.first == "Debut") {
                        sDebutArc = pPaireArcs.second; // On garde la valeur de Debut pour créer l'arc à la prochaine itération
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
        exit(EXIT_FAILURE); // On arrête l'exécution
    }

    return oGrapheOriente;
}

void CCreationGraphe::CRE_FonctionPrincipale()
{
    CGrapheOriente oGrapheOriente = CRE_CreerGraphe(); // Création du graphe orienté "normal"
    CAffichage::AFC_AnnoncerGraphe("Creation des elements du graphe classique");
  
    CAffichage::AFC_AnnoncerGraphe("Graphe classique");
    CAffichage::AFC_Afficher_Graphe(&oGrapheOriente);

    CAffichage::AFC_AnnoncerGraphe("Creation des elements du graphe inverse");
    CGrapheOriente* oGrapheOrienteInverse = CInverse::INV_Inverse(oGrapheOriente); // Création du graphe orienté inversé

    CAffichage::AFC_AnnoncerGraphe("Graphe inverse");
    CAffichage::AFC_Afficher_Graphe(oGrapheOrienteInverse);
    delete oGrapheOrienteInverse;
}