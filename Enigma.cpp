#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Enigma.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_iterator.hpp>

using namespace std;

Enigma::Enigma()
{

}

Enigma::~Enigma()
{

}

void Enigma::init()
{
	string name,wirring,stepping,comment;

	 
	using boost::property_tree::ptree;

	boost::property_tree::ptree pt;
	boost::property_tree::read_xml("Enigma.xml", pt);

	vector<Rotor> rotorList;
	vector<Reflector> reflectorList;

	BOOST_FOREACH(ptree::value_type const& v, pt.get_child("xml.RotorList") ){
		if (v.first == "rotor") {
		
			name=v.second.get<std::string>("name");
			wirring=v.second.get<std::string>("wirring");
			stepping=v.second.get<std::string>("stepping");
			comment=v.second.get<std::string>("comment");
			Rotor r(wirring, 1, 1,'z',' ',name);
			rotorList.push_back(r);
		}
	}


	BOOST_FOREACH(ptree::value_type const& v, pt.get_child("xml.ReflectorList")) {
		if (v.first == "reflector") {

			name = v.second.get<std::string>("name");
			
			wirring = v.second.get<std::string>("wirring");

			typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
			
			boost::char_separator<char> sep(",");
			//tokenizer tokens(wirring, sep);

			//for (tokenizer::iterator tok_iter = tokens.begin; tok_iter != tokens.end(); ++tok_iter)
		//	{
		//		cout << " " << *tok_iter << " " << endl;
		//	}


			//typedef boost::tokenizer<boost::char_separator<char> >
			//	tokenizer;
			//boost::char_separator<char> sep("-;|");

			tokenizer tokens(wirring, sep);
			
			string kk;

			for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
			{
				kk = *tok_iter;
				std::cout << " <" << kk[0] << "> ";
			}
				std::cout << "\n";
			



			comment = v.second.get<std::string>("comment");
			Reflector r;
			reflectorList.push_back(r);
		}
	}
}
