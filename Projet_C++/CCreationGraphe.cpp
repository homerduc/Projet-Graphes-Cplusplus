#include "CCreationGraphe.h"
#include "CGrapheOriente.h"
#include "CParser.h"


void CCreationGraphe::CRE_CreerGraphe()
{
    CGrapheOriente GrapheOriente;
    unsigned int uiNBSommets = 0;
    unsigned int uiNBArcs = 0;
    string sChemin;
    cout << "Veuillez entrer le chemin absolu vers le fichier de donnees" << endl;
    cin >> sChemin;

    map<string, string> mCleVal = CParser::PAR_GetCleValeur(sChemin);
    map<string,vector<map<string,string>>> mCleListeVar = CParser::PAR_GetCleListeValeur(sChemin);

    string sDebutArc; // La string qui va stocker le debut de l'arc entre deux itérations


    for (const auto& mPaire : mCleVal) {
        if (mPaire.first == "NBSommets") {
            uiNBSommets = (unsigned int)stoi(mPaire.second);
        }
        else if (mPaire.first == "NBArcs") {
            uiNBArcs = (unsigned int)stoi(mPaire.second);
        }
    }

    // Nous créons les sommets d'abord
    for (const auto& mPaire : mCleListeVar) {
        if (mPaire.first == "Sommets") { // Si nous sommes dans le bloc des sommets
            for (const auto& mMapSommets : mPaire.second) { // On parcourt le vector contenant tous les sommets sous formes de maps
                for (const auto& pPaireSommet : mMapSommets) { // On parcourt la map (elle ne contient qu'une valeur type Numero=x)
                    GrapheOriente.GRO_AjouterSommet(pPaireSommet.second); // On crée le sommet
                }
            }
        }
    }

    // Puis nous créons les arcs
    for (const auto& mPaire : mCleListeVar) {
        if (mPaire.first == "Arcs") { // Si nous sommes dans le bloc des arcs
            for (const auto& mMapArcs : mPaire.second) {
                for (const auto& pPaireArcs : mMapArcs) { // On parcourt debut, fin, debut, fin, etc
                    if (pPaireArcs.first == "Debut") {
                        sDebutArc = pPaireArcs.second; // On garde la valeur de Debut pour créer l'arc à la prochaine itération
                    }
                    else if (pPaireArcs.first == "Fin") {
                        GrapheOriente.GRO_AjouterArc(sDebutArc, pPaireArcs.second); // On ajoute l'arc
                    }
                }
            }
        }
    }

    try
    {
        if (uiNBSommets != GrapheOriente.GRO_GetSommets().size() || uiNBArcs != GrapheOriente.GRO_GetArcs().size()) {
            throw exception("ATTENTION : Le nombre de sommets ou d'arcs indique ne correspond pas aux valeurs que vous avez rentrees");
        }
    }
    catch (const std::exception& eException)
    {
        cout << eException.what() << endl;
        exit(EXIT_FAILURE);
    }

    GrapheOriente.Afficher_Graphe();
}