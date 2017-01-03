#include "Rotor.hpp"


using namespace std;



/**
************************
* Constructeur par defaut
************************
**/
Rotor::Rotor()
{
    rotor_tab[0][0]='a'; rotor_tab[0][1]='a';
    rotor_tab[1][0]='b'; rotor_tab[1][1]='b';
    rotor_tab[2][0]='c'; rotor_tab[2][1]='c';
    rotor_tab[3][0]='d'; rotor_tab[3][1]='d';
    rotor_tab[4][0]='e'; rotor_tab[4][1]='e';
    rotor_tab[5][0]='f'; rotor_tab[5][1]='f';
    rotor_tab[6][0]='g'; rotor_tab[6][1]='g';
    rotor_tab[7][0]='h'; rotor_tab[7][1]='h';
    rotor_tab[8][0]='i'; rotor_tab[8][1]='i';
    rotor_tab[9][0]='j'; rotor_tab[9][1]='j';
    rotor_tab[10][0]='k'; rotor_tab[10][1]='k';
    rotor_tab[11][0]='l'; rotor_tab[11][1]='l';
    rotor_tab[12][0]='m'; rotor_tab[12][1]='m';
    rotor_tab[13][0]='n'; rotor_tab[13][1]='n';
    rotor_tab[14][0]='o'; rotor_tab[14][1]='o';
    rotor_tab[15][0]='p'; rotor_tab[15][1]='p';
    rotor_tab[16][0]='q'; rotor_tab[16][1]='q';
    rotor_tab[17][0]='r'; rotor_tab[17][1]='r';
    rotor_tab[18][0]='s'; rotor_tab[18][1]='s';
    rotor_tab[19][0]='t'; rotor_tab[19][1]='t';
    rotor_tab[20][0]='u'; rotor_tab[20][1]='u';
    rotor_tab[21][0]='v'; rotor_tab[21][1]='v';
    rotor_tab[22][0]='w'; rotor_tab[22][1]='w';
    rotor_tab[23][0]='x'; rotor_tab[23][1]='x';
    rotor_tab[24][0]='y'; rotor_tab[24][1]='y';
    rotor_tab[25][0]='z'; rotor_tab[25][1]='z';

}
/**
************************
* Constructeur
************************
**/
Rotor::Rotor(const char listPermutation[2][26])
{

    for (int i(0); i<26; ++i)
    {
     rotor_tab[i][0]=listPermutation[0][i];
     rotor_tab[i][1]=listPermutation[1][i];
    }
}

/**
*************************************************************************************
* Methode pour transformer un caratere � partir d'un table de correspondance
* la table peut etre lue de gauche � droite ou de droite � gauche en fonction
* de la variable "sens"
*
* @param[in]   sens          : indique dans quel sens lire la table de correspondance
* @param[in]   charToPermute : charactere � crypter
* @param[out]  charPermuted  : charactere crypt�
*
*************************************************************************************
**/
char Rotor::activate(char charToPermute,int sens)
{
    char charPermuted(' ');

    switch (sens)
    {
        case 1:
            charPermuted=rotor_tab[seek(charToPermute,'L')][1];
            break;

        case -1:
            charPermuted=rotor_tab[seek(charToPermute,'R')][0];
            break;
    }

    return charPermuted;
}



/**
*************************************************************************************
* Methode pour afficher la table de correspondance
*
*************************************************************************************
**/
void Rotor::get_permutationTab()
{
    cout<<endl<<"voici la table de permutation"<<endl;

    for (int i(0);i<26;i++)
    {
        cout<<rotor_tab[i][0]<<"  <-->  "<<rotor_tab[i][1]<<endl;
    }
}



/**
*************************************************************************************
* Methode pour decaler d'un cran les elements de la table de correspondance
*
* @param[in] decalage : indique le sens de decalage de la table
*************************************************************************************
**/
void Rotor::rotate(int decalage)
{
    char tmp(' ');

    switch(decalage)
    {

        case -1:

            tmp=rotor_tab[0][1];
            for (int i(0);i<25;i++)
            {
                rotor_tab[i][1]=rotor_tab[i+1][1];
            }
            rotor_tab[25][1]=tmp;

            break;

        case 1:
            tmp=rotor_tab[25][1];
            for (int i(25);i>0;i--)
            {
                rotor_tab[i][1]=rotor_tab[i-1][1];
            }
            rotor_tab[0][1]=tmp;

            break;

        case 0:
            break;
    }
}



/**
*************************************************************************************
* Methode pour
*
* @param[in]  x :
* @param[out]   :
*
*************************************************************************************
**/
int Rotor::seek(char x,char S)
{
    switch (S)
    {
        case 'L':

            for (int i(0); i<26; i++)
            {
                if (rotor_tab[i][0]== x)
                {
                    return i;
                }
            }

            break;

        case 'R':

            for (int i(0); i<26; i++)
            {
                if (rotor_tab[i][1]== x)
                {
                    return i;
                }
            }
        default :
            break;

    }

    return -1;
}
