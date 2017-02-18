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
Reflector::Reflector(char listPermutation[2][26])
{
    for (int i(0); i<26; ++i)
    {
        m_permutationReflector[listPermutation[0][i]]=listPermutation[1][i];
        m_permutationReflector[listPermutation[1][i]]=listPermutation[0][i];
    }
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
void Reflector::get_permutationTab()
{
    map<char,char>::iterator p;
    cout<<"voici la table de permutation du Reflector"<<endl;
    for(p=m_permutationReflector.begin(); p!=m_permutationReflector.end(); p++)
    {
        cout<<p->first<<"   <--->   "<<p->second<<endl;

    }

}




