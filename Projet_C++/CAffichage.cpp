#include "CAffichage.h"
#include "CGrapheOriente.h"

void CAffichage::AFC_AffichageSupprArc(string sDepart, string sArrive)
{
	cout << "+"<<CAffichage::AFC_Calcul_tirets(sDepart+sArrive,'-',TAILLE_SUPPR_ARC)<<"+" << endl;
	cout << "| " << ERREUR_couleur << " Suppression de l arc <" << sDepart << "> --> <" << sArrive << ">" << RESTAURER_couleur <<CAffichage::AFC_Calcul_vide_Ajout(sDepart+sArrive,' ') <<"|" << endl;
	cout << "+" << CAffichage::AFC_Calcul_tirets(sDepart + sArrive, '-', TAILLE_SUPPR_ARC) << "+" << endl<< endl;
}

void CAffichage::AFC_AffichageSupprSommet(string sID)
{
	cout << "+" << CAffichage::AFC_Calcul_tirets(sID, '-', TAILLE_SUPPR_SOMMET) << "+" << endl;
	cout << "| " << ERREUR_couleur << " Suppression du sommet <" <<sID<<">" << RESTAURER_couleur << CAffichage::AFC_Calcul_vide_Ajout(sID, ' ') << "|" << endl;
	cout << "+" << CAffichage::AFC_Calcul_tirets(sID, '-', TAILLE_SUPPR_SOMMET) << "+" << endl << endl;
}

void CAffichage::AFC_AffichageAjoutSommet(string sID)
{
	cout << "+" << AFC_Calcul_tirets(sID, '-', TAILLE_CREATION_AJOUT) << "+" << endl;
	cout << "| " << CREATION_couleur << " Cr\202ation du sommet <" << sID << ">" << RESTAURER_couleur << CAffichage::AFC_Calcul_vide_Creation(sID, ' ') << "|" << endl;
	cout << "| " << AJOUT_couleur << " Ajout de <" << sID << "> dans le vecteur vGROsommets" << RESTAURER_couleur << CAffichage::AFC_Calcul_vide_Ajout(sID, ' ') << "|" << endl;
	cout << "+" << AFC_Calcul_tirets(sID, '-', TAILLE_CREATION_AJOUT) << "+" << endl << endl;

}

void CAffichage::AFC_AffichageAjoutArc(string sDepart, string sArrive)
{
	cout << "+"<<CAffichage::AFC_Calcul_tirets(sDepart+sArrive,'-',TAILLE_CREATION_AJOUT) << "+" << endl;
	cout << "| " << CREATION_couleur << " cr\202ation arc : <" << sDepart << "> ---> <" << sArrive << "> " << RESTAURER_couleur << endl;
	cout << "| " << AJOUT_couleur << " Ajout dans le vecteur arcs sortants de " << sDepart << RESTAURER_couleur << endl;
	cout << "| " << AJOUT_couleur << " Ajout dans le vecteur arcs Entrant de " << sArrive << RESTAURER_couleur << endl;
	cout << "+" << CAffichage::AFC_Calcul_tirets(sDepart + sArrive, '-', TAILLE_CREATION_AJOUT) << "+" << endl<< endl;
}

void CAffichage::AFC_Affichage_Sommets(CSommet* SOMsommet)
{
	//affichage arc entrant du sommet 
	string sID = SOMsommet->SOM_GetID();
	cout << " <" << sID << "> est un sommet contenant \27" << endl;
	cout << TEXT_Tabultation << "Les arcs Entrants de <" << sID << "> sont : " << endl;
	cout << ARC_Tabultation << ARC_couleur << "+"<<CAffichage::AFC_Calcul_tirets(TAILLE_Encadre_arcs,'-',TAILLE_AFFICHA_GEGRAPH) << "+ " << endl;
	for (unsigned int uiPosition = 0; uiPosition < SOMsommet->SOM_GetEntrants().size(); uiPosition++) {
		cout << ARC_Tabultation << "|  l'arc " << uiPosition << " : provenant du sommet <" << SOMsommet->SOM_GetEntrants()[uiPosition]->ARC_GetSommetDepart() << "> ..." << endl;
	}
	cout << ARC_Tabultation << "+" << CAffichage::AFC_Calcul_tirets(TAILLE_Encadre_arcs, '-', TAILLE_AFFICHA_GEGRAPH) << "+ " <<RESTAURER_couleur<< endl;

	//affichages arcs sortant du sommet
	cout << TEXT_Tabultation << "Les arcs Sortants de <" << sID << "> sont : " << endl;
	cout <<ARC_Tabultation<< ARC_couleur << "+" << CAffichage::AFC_Calcul_tirets(TAILLE_Encadre_arcs, '-', TAILLE_AFFICHA_GEGRAPH) << "+ " << endl;
	for (unsigned int uiPosition = 0; uiPosition < SOMsommet->SOM_GetSortants().size(); uiPosition++) {
		cout << ARC_Tabultation<< "|  l'arc " << uiPosition << " : Allant vers le sommet <" << SOMsommet->SOM_GetSortants()[uiPosition]->ARC_GetSommetArrive() << "> ..."<< endl;
	}
	cout << ARC_Tabultation<< "+" << CAffichage::AFC_Calcul_tirets(TAILLE_Encadre_arcs, '-', TAILLE_AFFICHA_GEGRAPH) << "+ " << RESTAURER_couleur << endl;

}

void CAffichage::AFC_Afficher_Graphe(CGrapheOriente* GROgraph)
{
	for (unsigned int uiPosition = 0; uiPosition < GROgraph->GRO_GetSommets().size(); uiPosition++) {
		AFC_Affichage_Sommets(GROgraph->GRO_GetSommets()[uiPosition]);
	}
}

void CAffichage::AFC_Erreur_ajoutSommet(string sID)
{
	cout << ERREUR_couleur << " ERREUR : impossible d'ajouter un sommet avec le nom de '" << sID << "' un sommet de ce nom existe deja !" << RESTAURER_couleur << endl << endl;
}

void CAffichage::AFC_Erreur_ajoutArc(string sDepart,string sArrive,int iErreur)
{
	switch (iErreur)
	{
		case 1 : //le sommet de départ n'existe pas
			cout << ERREUR_couleur << " ERROR : le sommet <" << sDepart << "> n'existe pas donc on ne peut pas cree l arc <" << sDepart << "> ---> <" << sArrive << "> " << RESTAURER_couleur << endl << endl;
			break;

		case 2 : //le sommet d'arrive n'existe pas 
			cout << ERREUR_couleur << " ERROR : le sommet <" << sArrive << "> n'existe pas donc on ne peut pas cree l arc <" << sDepart << "> ---> <" << sArrive << "> " << RESTAURER_couleur << endl << endl;
			break;

		case 3 : //aucun des sommet n'existe
			cout << ERREUR_couleur << " ERROR : les sommets <" << sDepart << "> et <" << sArrive << " n'existe pas donc on ne peut pas cree l arc <" << sDepart << "> ---> <" << sArrive << "> " << RESTAURER_couleur << endl << endl;
			break;
	}
}

const char* CAffichage::AFC_Calcul_tirets(string sID, const char cMotif,int iType)
{
	unsigned int uiTaille = iType +2 + sID.size();
	char* cNbtirets = new char[uiTaille + 3]; // Ajoutez 1 pour le caractère de fin de chaîne
	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbtirets[uiPosition] = cMotif;
	}
	cNbtirets[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne
	return cNbtirets;
}

const char* CAffichage::AFC_Calcul_vide_Creation(string sID, const char cMotif)
{
	unsigned int uiTaille = strlen(AFC_Calcul_tirets(sID,'-', TAILLE_CREATION_AJOUT))-23-sID.length();
	char* cNbvide = new char[uiTaille];

	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbvide[uiPosition] = cMotif;
	}
	cNbvide[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne
	return cNbvide;
}

const char* CAffichage::AFC_Calcul_vide_Ajout(string sID, const char cMotif)
{
	unsigned int uiTaille = strlen(AFC_Calcul_tirets(sID,'-', TAILLE_CREATION_AJOUT))-sID.length()-41;
	char* cNbvide = new char[uiTaille];

	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbvide[uiPosition] = cMotif;
	}
	cNbvide[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne
	return cNbvide;
}


