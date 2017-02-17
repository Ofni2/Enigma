#include "Machine.hpp"

#include <fstream>
#include <iostream>

using namespace std;

Machine::Machine()
{
    //ctor
}

Machine::~Machine()
{
    //dtor
}

void Machine::initMachine(string name)
{
	string line;

	ifstream configFile("Enigma.cfg");
	if (configFile.is_open())
		{
	//http://www.cplusplus.com/doc/tutorial/files/
			while (getline(configFile, line))
				{
				cout << line << '\n';
				}

			configFile.close();
		}
	else cout << "can not open file" << endl;


}
