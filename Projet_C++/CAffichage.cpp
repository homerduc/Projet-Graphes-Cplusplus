#include "CAffichage.h"
#include "CGrapheOriente.h"

void CAffichage::AFC_AffichageSupprArc(const string& sDepart, const string& sArrive)
{	
	const char* pcLigneTirets = AFC_Calcul_tirets(sDepart + sArrive, '-', TAILLE_SUPPR_ARC);

	cout << "+"<< pcLigneTirets <<"+" << endl;
	cout << "| " << ERREUR_couleur << " Suppression de l arc <" << sDepart << "> --> <" << sArrive << ">" << RESTAURER_couleur <<CAffichage::AFC_Calcul_vide_Ajout(sDepart+sArrive,' ') <<"|" << endl;
	cout << "+" << pcLigneTirets << "+" << endl<< endl;

	delete pcLigneTirets;
}

void CAffichage::AFC_AffichageSupprSommet(const string& sID)
{
	const char* pcLigneTirets = AFC_Calcul_tirets(sID, '-', TAILLE_SUPPR_SOMMET);

	cout << "+" << pcLigneTirets << "+" << endl;
	cout << "| " << ERREUR_couleur << " Suppression du sommet <" <<sID<<">" << RESTAURER_couleur << CAffichage::AFC_Calcul_vide_Ajout(sID, ' ') << "|" << endl;
	cout << "+" << pcLigneTirets << "+" << endl << endl;

	delete pcLigneTirets;
}

void CAffichage::AFC_AffichageAjoutSommet(const string& sID)
{
	const char* pcLigneTirets = AFC_Calcul_tirets(sID, '-', TAILLE_CREATION_AJOUT);

	cout << "+" << pcLigneTirets << "+" << endl;
	cout << "| " << CREATION_couleur << " Cr\202ation du sommet <" << sID << ">" << RESTAURER_couleur << CAffichage::AFC_Calcul_vide_Creation(sID, ' ') << "|" << endl;
	cout << "| " << AJOUT_couleur << " Ajout de <" << sID << "> dans le vecteur vGROsommets" << RESTAURER_couleur << CAffichage::AFC_Calcul_vide_Ajout(sID, ' ') << "|" << endl;
	cout << "+" << pcLigneTirets << "+" << endl << endl;

	delete pcLigneTirets;

}

void CAffichage::AFC_AffichageAjoutArc(const string& sDepart, const string& sArrive)
{
	const char* pcLigneTirets = AFC_Calcul_tirets(TAILLE_Encadre_arcs, '-', TAILLE_CREATION_AJOUT);

	cout << "+"<< pcLigneTirets << "+" << endl;
	cout << "| " << CREATION_couleur << " cr\202ation arc : <" << sDepart << "> ---> <" << sArrive << "> " << RESTAURER_couleur << endl;
	cout << "| " << AJOUT_couleur << " Ajout dans le vecteur arcs sortants de " << sDepart << RESTAURER_couleur << endl;
	cout << "| " << AJOUT_couleur << " Ajout dans le vecteur arcs Entrant de " << sArrive << RESTAURER_couleur << endl;
	cout << "+" << pcLigneTirets << "+" << endl<< endl;

	delete pcLigneTirets;
}

void CAffichage::AFC_Affichage_Sommets(CSommet* SOMsommet)
{
	//fonction qui va nous servir a faire un encadrement avec la bonne dimantion
	const char* pcLigneTirets = AFC_Calcul_tirets(TAILLE_Encadre_arcs, '-', TAILLE_AFFICHA_GEGRAPH);

	//affichage arc entrant du sommet 
	const string sID = SOMsommet->SOM_GetID();

	cout << " <" << sID << "> est un sommet contenant \27" << endl;
	cout << TEXT_Tabultation << "Les arcs Entrants de <" << sID << "> sont : " << endl;
	cout << ARC_Tabultation << ARC_couleur << "+" << pcLigneTirets << "+ " << endl;

	//boucle pour afficher les arcs entrant dans le sommet mit en paramètre
	for (unsigned int uiPosition = 0; uiPosition < SOMsommet->SOM_GetEntrants().size(); uiPosition++) 
	{
		cout << ARC_Tabultation << "|  l'arc " << uiPosition << " : provenant du sommet <" << SOMsommet->SOM_GetEntrants()[uiPosition]->ARC_GetSommetDepart() << "> ..." << endl;
	}

	cout << ARC_Tabultation << "+" << pcLigneTirets << "+ " <<RESTAURER_couleur<< endl;

	//affichages arcs sortant du sommet
	cout << TEXT_Tabultation << "Les arcs Sortants de <" << sID << "> sont : " << endl;
	cout <<ARC_Tabultation<< ARC_couleur << "+" << pcLigneTirets << "+ " << endl;

	//boucle pour afficher les arcs sortant du  sommet mit en paramètre
	for (unsigned int uiPosition = 0; uiPosition < SOMsommet->SOM_GetSortants().size(); uiPosition++) 
	{
		cout << ARC_Tabultation<< "|  l'arc " << uiPosition << " : Allant vers le sommet <" << SOMsommet->SOM_GetSortants()[uiPosition]->ARC_GetSommetArrive() << "> ..."<< endl;
	}

	cout << ARC_Tabultation<< "+" << pcLigneTirets << "+ " << RESTAURER_couleur << endl;

	delete pcLigneTirets;
}

void CAffichage::AFC_Afficher_Graphe(CGrapheOriente* GROgraph)
{
	//boucle qui sert a appeler la fonction Afficher sommet pour chaque somet se trouvant dans le graphe
	for (unsigned int uiPosition = 0; uiPosition < GROgraph->GRO_GetSommets().size(); uiPosition++) 
	{
		AFC_Affichage_Sommets(GROgraph->GRO_GetSommets()[uiPosition]);
	}
}

void CAffichage::AFC_Afficher_Graphe(CGraphe* GRAgraph)
{
	string sSommet1, sSommet2,sID;
	cout << "Les sommets du graph non orient\202 :" << endl;
	for (unsigned int uiPosition = 0; uiPosition < GRAgraph->GRO_GetSommets().size(); uiPosition++)
	{
		sID = GRAgraph->GRO_GetSommets()[uiPosition]->SOM_GetID();
		cout <<ARC_Tabultation<< ARC_couleur << "<" << sID << ">" << RESTAURER_couleur << endl;
	}
	cout << "la liste des arcs du graph non orient\202sont sont : " << endl;
	for (unsigned int uiPosition = 0; uiPosition < GRAgraph->GRO_GetArcs().size(); uiPosition++)
	{
		sSommet1 = GRAgraph->GRO_GetArcs()[uiPosition]->ARC_GetSommetDepart();
		sSommet2 = GRAgraph->GRO_GetArcs()[uiPosition]->ARC_GetSommetArrive();
		cout << ARC_Tabultation << ARC_couleur << "<" << sSommet1	 << "> <---> <" << sSommet2 << ">" << RESTAURER_couleur << endl;
	}
}

void CAffichage::AFC_Afficher_Arcs(CArc* pARCarc)
{
	cout << ARC_couleur << "<" << pARCarc->ARC_GetSommetDepart() << "> <---> <" << pARCarc->ARC_GetSommetArrive() << ">" << RESTAURER_couleur << endl;
}

void CAffichage::AFC_Erreur_ajoutSommet(const string& sID)
{
	cout << ERREUR_couleur << " ERREUR : impossible d'ajouter un sommet avec le nom de '" << sID << "' un sommet de ce nom existe deja !" << RESTAURER_couleur << endl << endl;
}

void CAffichage::AFC_Erreur_ajoutArc(const string& sDepart, const string& sArrive, const int& iErreur)
{
	switch (iErreur) //iErreur est une constante pres defini mis en paramètre de la fonction
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

const char* CAffichage::AFC_Calcul_tirets(const string& sID, const char& cMotif,const int& iType)
{
	unsigned int uiTaille = iType +2 + (unsigned int)sID.size(); // taille que devra faire le char* retourné pour avoir une bonne distance
	char* cNbtirets = new char[uiTaille + 3]; // Ajoutez 1 pour le caractère de fin de chaîne

	//boucle pour remplir le char* retrourné en fonction de la taille et du motif mis en paramètre
	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbtirets[uiPosition] = cMotif;
	}
	cNbtirets[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne

	return cNbtirets;
}

const char* CAffichage::AFC_Calcul_vide_Creation(const string& sID, const char& cMotif)
{
	unsigned int uiTaille = (unsigned int)(strlen(AFC_Calcul_tirets(sID,'-', TAILLE_CREATION_AJOUT))-23-sID.length());// taille que devra faire le char* retourné pour avoir une bonne distance
	char* cNbvide = new char[uiTaille];

	//boucle pour remplir le char* retrourné en fonction de la taille et du motif mis en paramètre
	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbvide[uiPosition] = cMotif;
	}

	cNbvide[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne
	return cNbvide;
}

const char* CAffichage::AFC_Calcul_vide_Ajout(const string& sID, const char& cMotif)
{
	const unsigned int uiTaille = (unsigned int)(strlen(AFC_Calcul_tirets(sID,'-', TAILLE_CREATION_AJOUT))-sID.length()-41);// taille que devra faire le char* retourné pour avoir une bonne distance
	char* cNbvide = new char[uiTaille];

	//boucle pour remplir le char* retrourné en fonction de la taille et du motif mis en paramètre
	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbvide[uiPosition] = cMotif;
	}

	cNbvide[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne
	return cNbvide;
}

void CAffichage::AFC_AnnoncerGraphe(const string& sNom)
{
	cout << graph_couleur << "+--------------------------------------------------------------------------------------------+" << endl;
	cout << "|			Affichage de : " << sNom << endl;
	cout << "+--------------------------------------------------------------------------------------------+" <<RESTAURER_couleur<< endl;
}