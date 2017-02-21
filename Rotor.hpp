#ifndef DEF_ROTOR
#define DEF_ROTOR

#include <vector>
#include <string>
#include <iostream>
#include <string>


class Rotor
{
public:
    // Constructeur
    Rotor();
    Rotor(std::string internalWiring, const int &ringSetting, const int &startPosition, const char &stepping1 = 'z', const char &stepping2 = ' ', const std::string &name = "noName");
    
	// Methodes
    void DisplayPermutationTab();
	int get_ringSetting();
	int get_rotorPosition();
	char get_stepping1();
	char get_stepping2();
	std::string get_name();

	void set_rotorPosition(int i);
	void set_ringSetting(int i);
	//void set_name(std::string name);

    char activate(char charToPermute,int sens=1);
    void rotate(int decalage=0);
	int isValidChar(char c);


private :
    // Attributs

	std::string m_name;

	int m_ringSetting;
	int m_startPosition;
	int m_position;

	char m_steppingPosition1;
	char m_steppingPosition2;

	char m_internalWiringTab[2][26];

    //Methodes
    int m_seek(char x, char S);
	int charToInt(char x);
	char intToChar(int i);

};

#endif


