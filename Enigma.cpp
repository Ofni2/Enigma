#include "Enigma.hpp"

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_iterator.hpp>

using namespace std;
using boost::property_tree::ptree;

Enigma::Enigma()
{
}

Enigma::~Enigma()
{

}

Machine Enigma::get_machine(std::string name)
{
	return m_availableMachine[name];
}



void Enigma::init()
{
	string name,wirring,stepping,comment,rotors,reflectors,plugBoard;
	
	int rotorsNumber;
	int i(0);

	char listPermutation[2][13];

	vector<Rotor> rotorList;
	vector<Reflector> reflectorList;

	ptree pt;
	
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	boost::char_separator<char> sep(",");


	//parse Enigma configuration file, and populate ptree
	read_xml("Enigma.xml", pt);

	// create rotors from configuration file. the list of available rotors are placed in a vector
	BOOST_FOREACH(ptree::value_type const& v, pt.get_child("xml.RotorList") )
	{
		if (v.first == "rotor")
		{
			name=v.second.get<std::string>("name");
			
			wirring=v.second.get<std::string>("wirring");

			stepping=v.second.get<std::string>("stepping");
			tokenizer tokens(stepping, sep);
			char steppings[2];

			i = 0;
			for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
			{	steppings[i]=(*tok_iter)[0];
				i++;}
			
			comment=v.second.get<std::string>("comment");

			Rotor r(wirring, 1, 1, steppings[0], steppings[1],name);

			m_availableRotor[name] = r;
		}
	}


	// create reflector from configuration file. the list of available reflectors are placed in a vector
	BOOST_FOREACH(ptree::value_type const& v, pt.get_child("xml.ReflectorList"))
	{
		if (v.first == "reflector")
		{
			name = v.second.get<std::string>("name");

			wirring = v.second.get<std::string>("wirring");

			//parse the plugboard with ','
			tokenizer tokens(wirring, sep);
			
			i=0;
			for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
			{	listPermutation[0][i] = (*tok_iter)[0];
				listPermutation[1][i] = (*tok_iter)[1];
				i++;}
			
			comment = v.second.get<std::string>("comment");
			
			Reflector r(name,listPermutation);
			
			m_availableReflector[name] = r;
		}
	}


	BOOST_FOREACH(ptree::value_type const& v, pt.get_child("xml.MachineList"))
	{
		if (v.first == "machine")
		{
			name = v.second.get<std::string>("name");
			rotors = v.second.get<std::string>("AllowableRotor");
			reflectors = v.second.get<std::string>("AllowableReflector");
			plugBoard = v.second.get<std::string>("PlugBoard");
			rotorsNumber= v.second.get<int>("RotorNumber");
			comment = v.second.get<std::string>("comment");

			//parse the plugboard with ','
			tokenizer rotorsTokens(rotors, sep);
			tokenizer reflectorsTokens(reflectors, sep);
			tokenizer plugboardsTokens(plugBoard, sep);

			std::map<std::string, Rotor> MRotor;

			for (tokenizer::iterator tok_iter = rotorsTokens.begin(); tok_iter != rotorsTokens.end(); ++tok_iter)
			{
				MRotor[*tok_iter] = m_availableRotor[*tok_iter];
			}

			std::map<std::string, Reflector> Mreflec;

			for (tokenizer::iterator tok_iter = reflectorsTokens.begin(); tok_iter != reflectorsTokens.end(); ++tok_iter)
			{
				Mreflec[*tok_iter] = m_availableReflector[*tok_iter];
			}

			char Mplug[2][6];

			for (tokenizer::iterator tok_iter = plugboardsTokens.begin(); tok_iter != plugboardsTokens.end(); ++tok_iter)
			{
				Mplug[0][(*tok_iter)[0]] = Mplug[1][ (*tok_iter)[1] ];
			}


			PlugBoard usedPlugboard(Mplug);
			Machine m(name, MRotor, Mreflec, rotorsNumber,usedPlugboard);

			m_availableMachine[name] = m;
		}
	}
}


