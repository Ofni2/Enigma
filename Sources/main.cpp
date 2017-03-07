#include "PlugBoard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Machine.hpp"
#include "Enigma.hpp"

#include "MainWindow.h"
#include "EnigmaGUI.h"

#include <QApplication>



using namespace std;

int main(int argc, char *argv[])
{
    int i(0),j(0);
    char char_crypted(' ');
    string text(" ");
    string text_c("");
	
	QApplication app(argc, argv);
	EnigmaGUI enigmaGUIMain;

	enigmaGUIMain.show();

	Enigma t;
	Machine M;

	t.init();


	M=t.get_machine("Enigma I");

	M.setRotor("V", 1);
	M.setRotor("II", 2);
	M.setRotor("I", 3);

	M.initRingSetting(1, 14);
	M.initRingSetting(2, 22);
	M.initRingSetting(3, 6);

	M.initStartPosition(1, 2);
	M.initStartPosition(2, 23);
	M.initStartPosition(3, 24);

	text = "QBLTWLDAHHYEOEFPTWYBLENDPMKOXLDFAMUDWIJDXRJZ";
	//solution = DERFU EHRER ISTTO DXDER KAMPF GEHTW EITER XDOEN ITZX

	int textSize(text.size());
	j=1;
	for (i=0; i<textSize; i++)
	{
		if (text[i] == ' ')
		{
			text_c = text_c + ' ';
			continue;
		}

		char_crypted=M.activate(text[i]);
		text_c = text_c + char_crypted;
		if (j%9 == 0) { text_c = text_c + " "; }
		j++;

	}

	cout << "RESULTAT ---> " << text_c << endl;

    return app.exec();
}
