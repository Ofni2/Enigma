#include "PlugBoard.hpp"
#include <map>

using namespace std;

// Constructeur

//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* initialisation par defaut
* (la table de connection est nulle par defaut)
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
PlugBoard::PlugBoard()
{
    m_permutation['A']='A';
    m_permutation['B']='B';
    m_permutation['C']='C';
    m_permutation['D']='D';
    m_permutation['E']='E';
    m_permutation['F']='F';
    m_permutation['G']='G';
    m_permutation['H']='H';
    m_permutation['I']='I';
    m_permutation['J']='J';
    m_permutation['K']='K';
    m_permutation['L']='L';
    m_permutation['M']='M';
    m_permutation['N']='N';
    m_permutation['O']='O';
    m_permutation['P']='P';
    m_permutation['Q']='Q';
    m_permutation['R']='R';
    m_permutation['S']='S';
    m_permutation['T']='T';
    m_permutation['U']='U';
    m_permutation['V']='V';
    m_permutation['W']='W';
    m_permutation['X']='X';
    m_permutation['Y']='Y';
    m_permutation['Z']='Z';
}

//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* initialisation la table de connection en fonction du tableau listeInut
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
PlugBoard::PlugBoard(char listeInput[2][6])
{
	m_permutation['A'] = 'A';
	m_permutation['B'] = 'B';
	m_permutation['C'] = 'C';
	m_permutation['D'] = 'D';
	m_permutation['E'] = 'E';
	m_permutation['F'] = 'F';
	m_permutation['G'] = 'G';
	m_permutation['H'] = 'H';
	m_permutation['I'] = 'I';
	m_permutation['J'] = 'J';
	m_permutation['K'] = 'K';
	m_permutation['L'] = 'L';
	m_permutation['M'] = 'M';
	m_permutation['N'] = 'N';
	m_permutation['O'] = 'O';
	m_permutation['P'] = 'P';
	m_permutation['Q'] = 'Q';
	m_permutation['R'] = 'R';
	m_permutation['S'] = 'S';
	m_permutation['T'] = 'T';
	m_permutation['U'] = 'U';
	m_permutation['V'] = 'V';
	m_permutation['W'] = 'W';
	m_permutation['X'] = 'X';
	m_permutation['Y'] = 'Y';
	m_permutation['Z'] = 'Z';

    for (int i(0); i<6; ++i)
    {
		if ((listeInput[0][i] >= 'a' && listeInput[0][i] <= 'z')) { listeInput[0][i] = listeInput[0][i] - 32; }
		if ((listeInput[1][i] >= 'a' && listeInput[1][i] <= 'z')) { listeInput[1][i] = listeInput[1][i] - 32; }
		//else 	/*Throw exception: initor initialisation pb */

        m_permutation[listeInput[0][i]]=listeInput[1][i];
        m_permutation[listeInput[1][i]]=listeInput[0][i];
    }
}




// Methode


//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* Methode qui transforme un caracter en focntion d'une table de connection
*
* @param[in]    charactere à permuter
* @param[out]   charater permuté à partir de la table
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
char PlugBoard::activate(char charToPermute)
{
	/*
	char charPermuted(' ');

	if ((charToPermute >= 'A' && charToPermute <= 'Z') || (charToPermute >= 'a' && charToPermute <= 'z'))
	{
		charPermuted = m_permutation[charToPermute];
		if (charPermuted = ' ') charPermuted = charToPermute;
	 }

    return charPermuted ;
	*/

	return m_permutation[charToPermute];
}






//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* Methode qui affiche permet d'afficher la table de connection
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
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
