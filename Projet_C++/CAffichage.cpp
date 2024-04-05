#include "CAffichage.h"

void CAffichage::AFC_AffichageSuppr(string sDepart, string sArrive)
{
	cout << "+----------------------------------------------------------------------------+" << endl;
	cout << "| " << COL_Suppr() << " Suppression de l arc <" << sDepart << "> --> <" << sArrive << ">" << COL_Reset() << endl;
	cout << "+----------------------------------------------------------------------------+" << endl << endl;
}

void CAffichage::AFC_AffichageAjout(string sID)
{
	cout << "+" << AFC_Calcultirets(sID, '-') << "+" << endl;
	cout << "| " << CAffichage::COL_Creation() << " Cr\202ation du sommet <" << sID << ">" << CAffichage::COL_Reset()<<CAffichage::AFC_Calculvide_Creation(sID,' ')<<"|" << endl;
	cout << "| " << CAffichage::COL_Ajout() << " Ajout de <" << sID << "> dans le vecteur vGROsommets" << CAffichage::COL_Reset() << CAffichage::AFC_Calculvide_Ajout(sID, ' ') << "|" << endl;
	cout << "+" << AFC_Calcultirets(sID, '-') << "+" << endl<< endl;
}

const char* CAffichage::AFC_Calcultirets(string sID, const char cMotif)
{
	unsigned int uiTaille = 43 + sID.size();
	char* cNbtirets = new char[uiTaille + 3]; // Ajoutez 1 pour le caractère de fin de chaîne
	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbtirets[uiPosition] = cMotif;
	}
	cNbtirets[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne
	return cNbtirets;
}

const char* CAffichage::AFC_Calculvide_Creation(string sID, const char cMotif)
{
	unsigned int uiTaille = strlen(AFC_Calcultirets(sID,'-'))-23-sID.length();
	char* cNbvide = new char[uiTaille];

	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbvide[uiPosition] = cMotif;
	}
	cNbvide[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne
	return cNbvide;
}
const char* CAffichage::AFC_Calculvide_Ajout(string sID, const char cMotif)
{
	unsigned int uiTaille = strlen(AFC_Calcultirets(sID,'-'))-sID.length()-41;
	char* cNbvide = new char[uiTaille];

	for (unsigned int uiPosition = 0; uiPosition < uiTaille; uiPosition++)
	{
		cNbvide[uiPosition] = cMotif;
	}
	cNbvide[uiTaille] = '\0'; // Ajoutez le caractère de fin de chaîne
	return cNbvide;
}

