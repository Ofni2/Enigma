#include <fstream>
#include <iostream>

#include "Enigma.h"
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace std;

Enigma::Enigma()
{

}

Enigma::~Enigma()
{

}

void Enigma::init()
{
	string line;

	struct rotor
	{
		string  name;
		string wirring;
		string stepping;
		string comment;
	};

	typedef std::vector<rotor> Sked;

	boost::property_tree::ptree pt;
	boost::property_tree::read_xml("Enigma.xml", pt);











	ifstream configFile("Enigma.xml");
	if (configFile.is_open())
	{
		//http://www.cplusplus.com/doc/tutorial/files/

		while (getline(configFile, line))
		{
	//		cout << line << '\n';
		}

		configFile.close();
	}
	else cout << "can not open file" << endl;

}
