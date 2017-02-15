#include "Rotor.hpp"


using namespace std;



/**
************************
* Constructeur par defaut
************************
**/
Rotor::Rotor()
{
	internalWiringTab[0][0] = 'a'; internalWiringTab[0][1] = 'a';
	internalWiringTab[1][0] = 'b'; internalWiringTab[1][1] = 'b';
	internalWiringTab[2][0] = 'c'; internalWiringTab[2][1] = 'c';
	internalWiringTab[3][0] = 'd'; internalWiringTab[3][1] = 'd';
	internalWiringTab[4][0] = 'e'; internalWiringTab[4][1] = 'e';
	internalWiringTab[5][0] = 'f'; internalWiringTab[5][1] = 'f';
	internalWiringTab[6][0] = 'g'; internalWiringTab[6][1] = 'g';
	internalWiringTab[7][0] = 'h'; internalWiringTab[7][1] = 'h';
	internalWiringTab[8][0] = 'i'; internalWiringTab[8][1] = 'i';
	internalWiringTab[9][0] = 'j'; internalWiringTab[9][1] = 'j';
	internalWiringTab[10][0] = 'k'; internalWiringTab[10][1] = 'k';
	internalWiringTab[11][0] = 'l'; internalWiringTab[11][1] = 'l';
	internalWiringTab[12][0] = 'm'; internalWiringTab[12][1] = 'm';
	internalWiringTab[13][0] = 'n'; internalWiringTab[13][1] = 'n';
	internalWiringTab[14][0] = 'o'; internalWiringTab[14][1] = 'o';
	internalWiringTab[15][0] = 'p'; internalWiringTab[15][1] = 'p';
	internalWiringTab[16][0] = 'q'; internalWiringTab[16][1] = 'q';
	internalWiringTab[17][0] = 'r'; internalWiringTab[17][1] = 'r';
	internalWiringTab[18][0] = 's'; internalWiringTab[18][1] = 's';
	internalWiringTab[19][0] = 't'; internalWiringTab[19][1] = 't';
	internalWiringTab[20][0] = 'u'; internalWiringTab[20][1] = 'u';
	internalWiringTab[21][0] = 'v'; internalWiringTab[21][1] = 'v';
	internalWiringTab[22][0] = 'w'; internalWiringTab[22][1] = 'w';
	internalWiringTab[23][0] = 'x'; internalWiringTab[23][1] = 'x';
	internalWiringTab[24][0] = 'y'; internalWiringTab[24][1] = 'y';
	internalWiringTab[25][0] = 'z'; internalWiringTab[25][1] = 'z';

	m_rotorStartPosition = 1;
	m_ringSetting = 1;
	m_position = 0;

	m_steppingPosition1 = 'a';
	m_steppingPosition2 = ' ';

}



	/**
	************************
	* Constructeur
	************************
	**/
Rotor::Rotor(const char listPermutation[2][26],int ringSetting, int startPosition,char stepping1,char stepping2)
{
		for (int i(0); i < 26; ++i)
		{
			internalWiringTab[i][0] = listPermutation[0][i];
			internalWiringTab[i][1] = listPermutation[1][i];
		}

		m_ringSetting = ringSetting;
		m_rotorStartPosition = startPosition;
		m_position = 0;

		m_steppingPosition1 = stepping1;
		m_steppingPosition2 = stepping2;
}



/**
*************************************************************************************
* Methode pour transformer un caratere à partir d'un table de correspondance
* la table peut etre lue de gauche à droite ou de droite à gauche en fonction
* de la variable "sens"
*
* @param[in]   sens          : indique dans quel sens lire la table de correspondance
* @param[in]   charToPermute : charactere à crypter
* @param[out]  charPermuted  : charactere crypté
*
*************************************************************************************
**/
char Rotor::activate(char charToPermute,int sens)
{
    char charPermuted(' ');
	int offset,index;

    switch (sens)
    {
        case 1:

			offset = m_rotorStartPosition - (m_ringSetting + m_position) + (charToPermute - 96) - 1 ;
			if (offset < 0) { offset = 26 - offset; }
			charPermuted = offset % 26 + 1;

			for (int i(0); i<26; i++) {
				if (internalWiringTab[i][0] == (charPermuted + 96)) { index = i; } }

			charPermuted = internalWiringTab[index][1] - 96;
			offset = -m_rotorStartPosition + (m_ringSetting + m_position) + charPermuted - 1;
			if (offset < 0) { offset = 26 + offset; }
			charPermuted = offset % 26 + 1 + 96;

            break;

        case -1:

			offset = m_rotorStartPosition - (m_ringSetting + m_position) + (charToPermute - 96) - 1 ;
			if (offset < 0) { offset = 26 - offset; }
			charPermuted = offset % 26 + 1;

			for (int i(0); i<26; i++) { if (internalWiringTab[i][1] == (charPermuted + 96)) { index = i; } }

			charPermuted = internalWiringTab[index][0] - 96;
			offset = -m_rotorStartPosition + (m_ringSetting + m_position) + charPermuted - 1;
			if (offset < 0) { offset = 26 + offset; }
			charPermuted = offset % 26 + 1 + 96;

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
        cout<<internalWiringTab[i][0]<<"  <-->  "<<internalWiringTab[i][1]<<endl;
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
    
	switch (decalage)
	{

	case -1:
		m_position--;
		break;

	case 1:
		m_position++;
		break;

	case 0:
		break;
	}
	
	/* old code
	char tmp(' ');
    switch(decalage)
    {

        case -1:

            tmp=internalWiringTab[0][1];
            for (int i(0);i<25;i++)
            {
                internalWiringTab[i][1]=internalWiringTab[i+1][1];
            }
            internalWiringTab[25][1]=tmp;

            break;

        case 1:
            tmp=internalWiringTab[25][1];
            for (int i(25);i>0;i--)
            {
                internalWiringTab[i][1]=internalWiringTab[i-1][1];
            }
            internalWiringTab[0][1]=tmp;

            break;

        case 0:
            break;
    }
	*/
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
int Rotor::m_seek(char x,char S)
{
    switch (S)
    {
        case 'L':

            for (int i(0); i<26; i++)
            {
                if (internalWiringTab[i][0]== x)
                {
                    return i;
                }
            }

            break;

        case 'R':

            for (int i(0); i<26; i++)
            {
                if (internalWiringTab[i][1]== x)
                {
                    return i;
                }
            }
        default :
            break;

    }

    return -1;
}


int Rotor::charToInt(char x)
{
	return x;
}

char Rotor::intToChar(int i)
{
	return char(i);
}

int Rotor::get_ringSetting()
{
	return m_ringSetting;
}

int Rotor::get_rotorPosition()
{
	return m_rotorStartPosition;
}

void Rotor::set_rotorPosition(int i)
{
	m_rotorStartPosition = i;
}

void Rotor::set_ringSetting(int i)
{
	m_ringSetting = i;
}

int Rotor::isValidChar(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {return 0;	}

	return -1;
}