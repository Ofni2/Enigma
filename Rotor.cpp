#include "Rotor.hpp"


using namespace std;



/**
************************
* Constructeur par defaut
************************
**/
Rotor::Rotor()
{
	m_name = "noName";

	m_ringSetting = 1;
	m_startPosition = 1;
	m_position = 0;

	m_steppingPosition1 = 'z';
	m_steppingPosition2 = ' ';
	
	for (int i(0); i < 26; ++i)
	{
		m_internalWiringTab[0][i] = 97+i;
		m_internalWiringTab[1][i] = 97+i;
	}
}



/**
************************
* Constructeur
************************
**/
Rotor::Rotor(char internalWiring[2][26], const int &ringSetting, const int &startPosition, const char &stepping1, const char &stepping2, const string &name)
{
		m_name = name;

		m_ringSetting = ringSetting;
		m_startPosition = startPosition;
		m_position = 0;

		m_steppingPosition1 = stepping1;
		m_steppingPosition2 = stepping2;

		for (int i(0); i < 26; ++i)
		{
			m_internalWiringTab[0][i] = internalWiring[0][i];
			m_internalWiringTab[1][i] = internalWiring[1][i];
		}
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

			offset = m_startPosition - (m_ringSetting + m_position) + (charToPermute - 96) - 1 ;
			if (offset < 0) { offset = 26 - offset; }
			charPermuted = offset % 26 + 1;

			for (int i(0); i<26; i++) {
				if (m_internalWiringTab[0][i] == (charPermuted + 96)) { index = i; } }

			charPermuted = m_internalWiringTab[1][index] - 96;
			offset = -m_startPosition + (m_ringSetting + m_position) + charPermuted - 1;
			if (offset < 0) { offset = 26 + offset; }
			charPermuted = offset % 26 + 1 + 96;

            break;

        case -1:

			offset = m_startPosition - (m_ringSetting + m_position) + (charToPermute - 96) - 1 ;
			if (offset < 0) { offset = 26 - offset; }
			charPermuted = offset % 26 + 1;

			for (int i(0); i<26; i++) { if (m_internalWiringTab[1][i] == (charPermuted + 96)) { index = i; } }

			charPermuted = m_internalWiringTab[0][index] - 96;
			offset = -m_startPosition + (m_ringSetting + m_position) + charPermuted - 1;
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
        cout<<m_internalWiringTab[0][i]<<"  <-->  "<<m_internalWiringTab[1][0]<<endl;
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
                if (m_internalWiringTab[i][0]== x)
                {
                    return i;
                }
            }

            break;

        case 'R':

            for (int i(0); i<26; i++)
            {
                if (m_internalWiringTab[i][1]== x)
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
	return m_startPosition;
}

void Rotor::set_rotorPosition(int i)
{
	m_startPosition = i;
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