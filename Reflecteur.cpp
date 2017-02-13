#include "Reflecteur.hpp"

using namespace std;

//Constructeur

//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* initialisation par defaut
*
**/
Reflecteur::Reflecteur()
{
}
//--------------------------------------------------------------
//--------------------------------------------------------------



//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* initialisation du reflecteur en fonction d'un tableau de permutation
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
Reflecteur::Reflecteur(char listPermutation[2][26])
{
    for (int i(0); i<26; ++i)
    {
        m_permutationReflecteur[listPermutation[0][i]]=listPermutation[1][i];
        m_permutationReflecteur[listPermutation[1][i]]=listPermutation[0][i];
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
char Reflecteur::activate(char charToPermute)
{
return m_permutationReflecteur[charToPermute];
}



//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* Methode d'affichage du reflecteur
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
void Reflecteur::get_permutationTab()
{
    map<char,char>::iterator p;
    cout<<"voici la table de permutation du reflecteur"<<endl;
    for(p=m_permutationReflecteur.begin(); p!=m_permutationReflecteur.end(); p++)
    {
        cout<<p->first<<"   <--->   "<<p->second<<endl;

    }

}




