#include <iostream>

#include "ConnectionTab.hpp"
#include "Rotor.hpp"
#include "Reflecteur.hpp"


using namespace std;

int main()
{
    char char_to_crypt(' ');
    char char_crypted(' ');


// configuration de la machine
    char Permutation[2][6]= {{'a','b','c','d','e','f'},{'f','e','d','c','b','a'}};
    char Ro_I[2][26]= {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'e','k','m','f','l','g','d','q','v','z','n','t','o','w','y','h','x','u','s','p','a','i','b','r','c','j'}};
    char Ro_II[2][26]= {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'a','j','d','k','s','i','r','u','x','b','l','h','w','t','m','c','q','g','z','n','p','y','f','v','o','e'}};
    char Ro_III[2][26]= {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'b','d','f','h','j','l','c','p','r','t','x','v','z','n','y','e','i','w','g','a','k','m','u','s','q','o'}};
    char Re_B[2][26]= {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'y','r','u','h','q','s','l','d','p','x','n','g','o','k','m','i','e','b','f','z','c','w','v','j','a','t'}};



    /* Permutation used by Enigma are defined by usera */

    /* Rotor used for Enigma
    I 	   EKMFLGDQVZNTOWYHXUSPAIBRCJ 	    1930 	    Enigma I
    II 	   AJDKSIRUXBLHWTMCQGZNPYFVOE 	    1930 	    Enigma I
    III    BDFHJLCPRTXVZNYEIWGAKMUSQO 	    1930 	    Enigma I
    IV     ESOVPZJAYQUIRHXLNFTGKDCMWB 	    Dec. 1938 	M3 Army
    V 	   VZBRGITYUPSDNHLXAWMJQOFECK 	    Dec. 1938 	M3 Army
    VI     JPGVOUMFYQBENHZRDKASXLICTW 	    1939 	    M3 & M4 Naval (FEB 1942)
    VII    NZJHGRCXMYSWBOUFAIVLPEKQDT 	    1939 	    M3 & M4 Naval (FEB 1942)
    VIII   FKQHTLXOCBJSPDZRAMEWNIUYGV
    */

    /* Reflector used for Enigma
    reflector B	    (AY) (BR) (CU) (DH) (EQ) (FS) (GL) (IP) (JX) (KN) (MO) (TZ) (VW)
    reflector C	    (AF) (BV) (CP) (DJ) (EI) (GO) (HY) (KR) (LZ) (MX) (NW) (TQ) (SU)
    reflector B Dünn	(AE) (BN) (CK) (DQ) (FU) (GY) (HW) (IJ) (LO) (MP) (RX) (SZ) (TV)
    reflector C Dünn	(AR) (BD) (CO) (EJ) (FN) (GT) (HK) (IV) (LM) (PW) (QZ) (SX) (UY)
    */

//initialisation de la machine
// 1 - initialisation du tableau de permutation
    ConnectionTab connectTab(Permutation);

// 2 - initialisation du premier rotor
    Rotor rotor1(Ro_I);

// 3 - initialisation du deuxieme rotor
    Rotor rotor2(Ro_II);

// 4 - initialisation du troisieme rotor
    Rotor rotor3(Ro_III);

// 5 - initialisation du reflecteur
    Reflecteur reflecteur(Re_B);



//--------------
// Zone de test
//--------------

// Affichage des tables de correspondance
//reflecteur.get_permutationTab();
//connectTab.get_PermutationTab();
//rotor1.get_permutationTab();
//rotor2.get_permutationTab();
//rotor3.get_permutationTab();


    cout<<"caractere a crypter : "<<endl;
    cin>>char_to_crypt;

// Sequence de cryptage d'un caractere
    char_crypted=connectTab.activate(char_to_crypt);
    char_crypted=rotor1.activate(char_crypted,1);
    char_crypted=rotor2.activate(char_crypted,1);
    char_crypted=rotor3.activate(char_crypted,1);
    char_crypted=reflecteur.activate(char_crypted);
    char_crypted=rotor3.activate(char_crypted,-1);
    char_crypted=rotor2.activate(char_crypted,-1);
    char_crypted=rotor1.activate(char_crypted,-1);
    char_crypted=connectTab.activate(char_crypted);

    cout<<"caractere crypte : "<<char_crypted<<endl;

rotor1.get_permutationTab();
    rotor1.rotate(1);
rotor1.get_permutationTab();
    cout<<"caractere a crypter : "<<endl;
    cin>>char_to_crypt;

// Sequence de cryptage d'un caractere
    char_crypted=connectTab.activate(char_to_crypt);
    char_crypted=rotor1.activate(char_crypted,1);
    char_crypted=rotor2.activate(char_crypted,1);
    char_crypted=rotor3.activate(char_crypted,1);
    char_crypted=reflecteur.activate(char_crypted);
    char_crypted=rotor3.activate(char_crypted,-1);
    char_crypted=rotor2.activate(char_crypted,-1);
    char_crypted=rotor1.activate(char_crypted,-1);
    char_crypted=connectTab.activate(char_crypted);

    cout<<"caractere crypte : "<<char_crypted<<endl;


    return 0;
}
