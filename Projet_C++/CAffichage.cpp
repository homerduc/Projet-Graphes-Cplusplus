#include "CAffichage.h"
#include "CGrapheOriente.h"

void CAffichage::AFC_AffichageSupprArc(const string& sDepart, const string& sArrive)
{
	string pcLigneTirets = AFC_Calcul_tirets(sDepart + sArrive, '-', TAILLE_SUPPR_ARC);
	string cVide = CAffichage::AFC_Calcul_vide_Ajout(sDepart + sArrive, ' ');

	cout << "+" << pcLigneTirets << "+" << endl;
	cout << "| " << " Suppression de l'arc <" << sDepart << "> --> <" << sArrive << ">" << cVide << "|" << endl;
	cout << "+" << pcLigneTirets << "+" << endl << endl;


}

void CAffichage::AFC_AffichageSupprSommet(const string& sID)
{
	string pcLigneTirets = AFC_Calcul_tirets(sID, '-', TAILLE_SUPPR_SOMMET);
	string cVide = CAffichage::AFC_Calcul_vide_Ajout(sID, ' ');

	cout << "+" << pcLigneTirets << "+" << endl;
	cout << "| " << " Suppression du sommet <" << sID << ">" << cVide << "|" << endl;
	cout << "+" << pcLigneTirets << "+" << endl << endl;


}

void CAffichage::AFC_AffichageAjoutSommet(const string& sID)
{
	string pcLigneTirets = AFC_Calcul_tirets(sID, '-', TAILLE_CREATION_AJOUT);
	string cVide1 = CAffichage::AFC_Calcul_vide_Creation(sID, ' ');
	string cVide2 = CAffichage::AFC_Calcul_vide_Ajout(sID, ' ');

	cout << "+" << pcLigneTirets << "+" << endl;
	cout << "| " << " Creation du sommet <" << sID << ">" << cVide1 << "|" << endl;
	cout << "| " << " Ajout de <" << sID << "> dans le vecteur vGROsommets" << cVide2 << "|" << endl;
	cout << "+" << pcLigneTirets << "+" << endl << endl;

}

void CAffichage::AFC_AffichageAjoutArc(const string& sDepart, const string& sArrive)
{
	string pcLigneTirets = AFC_Calcul_tirets(TAILLE_Encadre_arcs, '-', TAILLE_CREATION_AJOUT);

	cout << "+" << pcLigneTirets << "+" << endl;
	cout << "| " << " creation arc : <" << sDepart << "> ---> <" << sArrive << "> " << endl;
	cout << "| " << " Ajout dans le vecteur arcs sortants de " << sDepart << endl;
	cout << "| " << " Ajout dans le vecteur arcs Entrant de " << sArrive << endl;
	cout << "+" << pcLigneTirets << "+" << endl << endl;

	//delete pcLigneTirets;
}

void CAffichage::AFC_Affichage_Sommets(CSommet* SOMsommet)
{
	//fonction qui va nous servir a faire un encadrement avec la bonne dimantion
	string pcLigneTirets = AFC_Calcul_tirets(TAILLE_Encadre_arcs, '-', TAILLE_AFFICHA_GEGRAPH);

	//affichage arc entrant du sommet 
	const string sID = SOMsommet->SOM_GetID();

	cout << " <" << sID << "> est un sommet contenant \27" << endl;
	cout << TEXT_Tabultation << "Les arcs Entrants de <" << sID << "> sont : " << endl;
	cout << ARC_Tabultation << "+" << pcLigneTirets << "+ " << endl;

	//boucle pour afficher les arcs entrant dans le sommet mit en paramètre
	for (unsigned int uiPosition = 0; uiPosition < SOMsommet->SOM_GetEntrants().size(); uiPosition++)
	{
		cout << ARC_Tabultation << "|  l'arc " << uiPosition << " : provenant du sommet <" << SOMsommet->SOM_GetEntrants()[uiPosition]->ARC_GetSommetDepart() << "> ..." << endl;
	}

	cout << ARC_Tabultation << "+" << pcLigneTirets << "+ " << endl;

	//affichages arcs sortant du sommet
	cout << TEXT_Tabultation << "Les arcs Sortants de <" << sID << "> sont : " << endl;
	cout << ARC_Tabultation << "+" << pcLigneTirets << "+ " << endl;

	//boucle pour afficher les arcs sortant du  sommet mit en paramètre
	for (unsigned int uiPosition = 0; uiPosition < SOMsommet->SOM_GetSortants().size(); uiPosition++)
	{
		cout << ARC_Tabultation << "|  l'arc " << uiPosition << " : Allant vers le sommet <" << SOMsommet->SOM_GetSortants()[uiPosition]->ARC_GetSommetArrive() << "> ..." << endl;
	}

	cout << ARC_Tabultation << "+" << pcLigneTirets << "+ " << endl << endl;

	//delete pcLigneTirets;
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
	string sSommet1, sSommet2, sID;
	cout << "Les sommets du graphe non oriente :" << endl;
	for (unsigned int uiPosition = 0; uiPosition < GRAgraph->GRO_GetSommets().size(); uiPosition++)
	{
		sID = GRAgraph->GRO_GetSommets()[uiPosition]->SOM_GetID();
		cout << ARC_Tabultation << "<" << sID << ">" << endl;
	}
	cout << "la liste des arcs du graphz non oriente sont : " << endl;
	for (unsigned int uiPosition = 0; uiPosition < GRAgraph->GRO_GetArcs().size(); uiPosition++)
	{
		sSommet1 = GRAgraph->GRO_GetArcs()[uiPosition]->ARC_GetSommetDepart();
		sSommet2 = GRAgraph->GRO_GetArcs()[uiPosition]->ARC_GetSommetArrive();
		cout << ARC_Tabultation << "<" << sSommet1 << "> <---> <" << sSommet2 << ">" << endl;
	}
}

void CAffichage::AFC_Afficher_Arcs(CArc* pARCarc)
{
	cout << "<" << pARCarc->ARC_GetSommetDepart() << "> <---> <" << pARCarc->ARC_GetSommetArrive() << ">" << endl;
}

void CAffichage::AFC_Erreur_ajoutSommet(const string& sID)
{
	cout << " ERREUR : impossible d'ajouter un sommet avec le nom de '" << sID << "' un sommet de ce nom existe deja !" << endl << endl;
}

void CAffichage::AFC_Erreur_ajoutArc(const string& sDepart, const string& sArrive, const int& iErreur)
{
	switch (iErreur) //iErreur est une constante pres defini mis en paramètre de la fonction
	{
	case 1: //le sommet de départ n'existe pas 
		cout << " ERROR : le sommet <" << sDepart << "> n'existe pas donc on ne peut pas creer l arc <" << sDepart << "> ---> <" << sArrive << "> " << endl << endl;
		break;

	case 2: //le sommet d'arrive n'existe pas 
		cout << " ERROR : le sommet <" << sArrive << "> n'existe pas donc on ne peut pas creer l arc <" << sDepart << "> ---> <" << sArrive << "> " << endl << endl;
		break;

	case 3: //aucun des sommet n'existe
		cout << " ERROR : les sommets <" << sDepart << "> et <" << sArrive << " n'existe pas donc on ne peut pas creer l arc <" << sDepart << "> ---> <" << sArrive << "> " << endl << endl;
		break;
	}
}

string CAffichage::AFC_Calcul_tirets(const std::string& sID, const char& cMotif, const int& iType)
{
	unsigned int uiTaille = iType + 2 + (unsigned int)sID.size(); // taille que devra faire le char* retourné pour avoir une bonne distance
	string strTirets(uiTaille, cMotif); // Créez une std::string de la taille souhaitée, remplie avec le motif

	return strTirets;
}

string CAffichage::AFC_Calcul_vide_Creation(const std::string& sID, const char& cMotif)
{
	string cTirets = AFC_Calcul_tirets(sID, '-', TAILLE_CREATION_AJOUT);
	unsigned int uiTaille = (unsigned int)(cTirets.length() - 23 - sID.length());// taille que devra faire le char* retourné pour avoir une bonne distance
	string strVide(uiTaille, cMotif); // Créez une std::string de la taille souhaitée, remplie avec le motif

	return strVide;
}

string CAffichage::AFC_Calcul_vide_Ajout(const std::string& sID, const char& cMotif)
{
	string cTirets = AFC_Calcul_tirets(sID, '-', TAILLE_CREATION_AJOUT);
	unsigned int uiTaille = (unsigned int)(cTirets.length()) - (unsigned int)sID.length() - (unsigned int)41; // taille que devra faire le char* retourné pour avoir une bonne distance
	string strVide(uiTaille, cMotif); // Créez une std::string de la taille souhaitée, remplie avec le motif

	return strVide;
}

void CAffichage::AFC_AnnoncerGraphe(const string& sNom)
{
	cout << "+--------------------------------------------------------------------------------------------+" << endl;
	cout << "|			Affichage de : " << sNom << endl;
	cout << "+--------------------------------------------------------------------------------------------+" << endl << endl;
}

void CAffichage::AFC_DemanderColoration(CDetectionColoration& Detection)
{
	unsigned int NbCouleurs = 0;
	cout << "combien de couleurs voulez-vous tenter de mettre sur le graphe ? : ";
	cin >> NbCouleurs;
	
	switch (Detection.DTCDetecter(NbCouleurs))
	{
	case 0: cout << "On ne peut pas colorer le graphe" << endl; break;
	case 1: cout << "On peut colorer le graphe" << endl; break;
	}
}