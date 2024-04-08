#ifndef CGRAPHORIENTE_H
#define CGRAPHORIENTE_H

#include "CArc.h"
#include "CSommet.h"

using namespace std;



class CGrapheOriente
{
private:
	vector<CArc*> vGROarcs;
	vector<CSommet*> vGROsommets;
public:

	#pragma region CONSTRUCTEURS & DESTRUCTEUR

	CGrapheOriente() {}
	CGrapheOriente(vector<CArc*> vArcs, vector<CSommet*> vSommets) { vGROarcs = vArcs; vGROsommets = vSommets; }
	CGrapheOriente(const CGrapheOriente& GROgraphe);
	~CGrapheOriente();

	#pragma endregion

	#pragma region ACCESSEURS SET & GET

	vector<CArc*> GRO_GetArcs() const { return vGROarcs; };
	vector<CSommet*> GRO_GetSommets() const { return vGROsommets; };

	void GRO_SetArcs(vector<CArc*> vArcs) { vGROarcs = vArcs; }
	void GRO_SetSommets(vector<CSommet*> vSommets) { vGROsommets = vSommets; }

	#pragma endregion

	#pragma region RECHERCHE SOMMET & ARC 
		vector<CArc*>::iterator GRO_RechercheArcs(string sDepart, string sArrive);
		vector<CSommet*>::iterator GRO_RechercheSommets(string sID);
	#pragma endregion

	#pragma region AJOUT SOMMET & ARC
		void GRO_AjouterSommet(string sID);
		void GRO_AjouterArc(string sDepart, string sArrive);
	#pragma endregion

	#pragma region SUPPRIMER SOMMET & ARC
		void GRO_SupprimerSommet(string sRecherche);

		/**
		 * @brief Supprime un arc du graphe orient�.
		 *
		 * Cette fonction recherche un arc sp�cifique dans le graphe orient� en utilisant les identifiants de d�part et d'arriv�e fournis.
		 * Si l'arc est trouv�, il est supprim� du graphe. Si l'arc n'est pas trouv�, un message d'erreur est affich�.
		 *
		 * @param sDepart L'identifiant du sommet de d�part de l'arc � supprimer.
		 * @param sArrive L'identifiant du sommet d'arriv�e de l'arc � supprimer.
		 */
		void GRO_SupprimerArc(string sDepart, string sArrive);
	#pragma endregion

	void Afficher_Graph();
	
};

#endif // !CGRAPHORIENTE_H




