#ifndef DEF_ROTOR
#define DEF_ROTOR

#include <vector>
#include <string>
#include <iostream>

// #ascii chiffré = [#ascii-97+decalage]%26+97

class Rotor
{
public:
    // Constructeur
    Rotor();
    Rotor(const char listPermutation[2][26],int ringSetting,int startPosition);

    // Methodes
    void get_permutationTab();
	int get_ringSetting();
	int get_rotorPosition();

	void set_rotorPosition(int i);
	void set_ringSetting(int i);

    char activate(char charToPermute,int sens=1);
    void rotate(int decalage=0);
	int isValidChar(char c);


private :
    // Attributs
    char internalWiringTab[26][2];
	int m_steppingPosition;
	int m_ringSetting;
	int m_rotorStartPosition;
	int m_position;


    //Methodes
    int m_seek(char x, char S);
	int charToInt(char x);
	char intToChar(int i);

};

#endif


