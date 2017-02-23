#include "PlugBoard.hpp"
#include <map>

using namespace std;

// Constructeur

/**
*************************************************************************************
*
* Constructeur par defaut (aucune permutation dnas le tableau de connection
*
*************************************************************************************
**/
PlugBoard::PlugBoard()
{
	// m_permutation['A']='A', m_permutation['B']='B', ect...
	for (int i(0); i<26; i++)
	{
		m_permutation[i+65] = i+65;
	}
}


/**
*************************************************************************************
*
* Constructeur 
*
*************************************************************************************
**/
PlugBoard::PlugBoard(char listeInput[2][13])
{

	// m_permutation['A']='A', m_permutation['B']='B', ect...
	for (int i(0); i<26; i++)
	{
		m_permutation[i + 65] = i + 65;
	}

	// on effectue les permutations
    for (int i(0); i<13; ++i)
    {
		if ((listeInput[0][i] >= 'a' && listeInput[0][i] <= 'z')) { listeInput[0][i] = listeInput[0][i] - 32; }
		if ((listeInput[1][i] >= 'a' && listeInput[1][i] <= 'z')) { listeInput[1][i] = listeInput[1][i] - 32; }
		//else 	/*Throw exception: initor initialisation pb */

        m_permutation[listeInput[0][i]]=listeInput[1][i];
        m_permutation[listeInput[1][i]]=listeInput[0][i];
    }
}


/**
*************************************************************************************
*
* Methode qui transforme un caractere en focntion de la table de connection
*
* @param[in] charToPermute	: Caractere à permuter (char)
* @param[out] return		: Caractere permuter grace à la table de connection (char)
*
*************************************************************************************
**/
char PlugBoard::activate(char charToPermute)
{
	return m_permutation[charToPermute];
}


/**
*************************************************************************************
*
* Methode qui affiche permet d'afficher la table de connection
*
*************************************************************************************
**/
void PlugBoard::DisplayPermutationTab()
{
    map<char,char>::iterator p;

    cout<<"voici la table de connection"<<endl;

    for(p=m_permutation.begin(); p!=m_permutation.end(); p++)
    {
        cout<<p->first<<"  devient :   "<<p->second<<endl;
    }
    cout<<endl;
}
