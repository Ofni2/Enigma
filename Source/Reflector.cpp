#include "Reflector.hpp"

using namespace std;

//Constructeur

//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* initialisation par defaut
*
**/
Reflector::Reflector()
{
	for (int i(0); i<26; ++i) {	m_permutationReflector[i + 65] = i + 65;}
	m_name = "none";

}
//--------------------------------------------------------------
//--------------------------------------------------------------



//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* initialisation du Reflector en fonction d'un tableau de permutation
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
Reflector::Reflector(string name,char listPermutation[2][13])
{
    for (int i(0); i<13; ++i)
    {


		if ((listPermutation[0][i] >= 'a' && listPermutation[0][i] <= 'z')) {listPermutation[0][i] = listPermutation[0][i] - 32;}
		if ((listPermutation[1][i] >= 'a' && listPermutation[1][i] <= 'z')) { listPermutation[1][i] = listPermutation[1][i] - 32; }
		//else 	/*Throw exception: initor initialisation pb */
		
		m_permutationReflector[listPermutation[0][i]]=listPermutation[1][i];
        m_permutationReflector[listPermutation[1][i]]=listPermutation[0][i];
    }
	m_name = name;
}

/**
*
* Methode qui transforme un caracter en focntion de la table de reflection
*
* @param[in]    charactere à permuter
* @param[out]   charater permuté à partir de la table
*
**/
char Reflector::activate(char charToPermute)
{
return m_permutationReflector[charToPermute];
}



//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* Methode d'affichage du Reflector
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
void Reflector::DisplayPermutationTab()
{
    map<char,char>::iterator p;
    cout<<"voici la table de permutation du Reflector"<<endl;
    for(p=m_permutationReflector.begin(); p!=m_permutationReflector.end(); p++)
    {
        cout<<p->first<<"   <--->   "<<p->second<<endl;

    }

}




