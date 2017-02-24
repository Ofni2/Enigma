#ifndef PLUGBOARD_H
#define PLUGBOARD_H

// To use without precompilation

#include <string>
#include <iostream>
#include <map>



class PlugBoard
{

public:

	//constructeur
	PlugBoard();
	PlugBoard(char list[2][13]);

	//methode
	void DisplayPermutationTab();
	char activate(char charToPermute);


private:

	std::map<char,char> m_permutation;


};

#endif
