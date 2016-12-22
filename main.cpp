#include <iostream>

#include "ConnectionTab.hpp"
#include "Rotor.hpp"
#include "Reflecteur.hpp"


using namespace std;

int main()
{

 // dinifition des
 char Permutation[2][6]={{'a','b','c','d','e','f'},{'f','e','d','c','b','a'}};
 char Ro_I[2][26]={{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'e','k','m','f','l','g','d','q','v','z','n','t','o','w','y','h','x','u','s','p','a','i','b','r','c','j'}};
 char Ro_II[2][26]={{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'a','j','d','k','s','i','r','u','x','b','l','h','w','t','m','c','q','g','z','n','p','y','f','v','o','e'}};
 char Ro_III[2][26]={{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'b','d','f','h','j','l','c','p','r','t','x','v','z','n','y','e','i','w','g','a','k','m','u','s','q','o'}};
 char Re_B[2][26]={{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'y','r','u','h','q','s','l','d','p','x','n','g','o','k','m','i','e','b','f','z','c','w','v','j','a','t'}};

 char char_to_crypt('a');
 char char_crypted(' ');

 /* Permutation used by Enigma are defined by usera */


 /* Rotor used for Enigma
 I 	    EKMFLGDQVZNTOWYHXUSPAIBRCJ 	    1930 	    Enigma I
 II 	AJDKSIRUXBLHWTMCQGZNPYFVOE 	    1930 	    Enigma I
 III    BDFHJLCPRTXVZNYEIWGAKMUSQO 	    1930 	    Enigma I
 IV     ESOVPZJAYQUIRHXLNFTGKDCMWB 	    Dec. 1938 	M3 Army
 V 	    VZBRGITYUPSDNHLXAWMJQOFECK 	    Dec. 1938 	M3 Army
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
// 2 - initialisation du premier rotor
// 3 - initialisation du deuxieme rotor
// 4 - initialisation du troisieme rotor
// 5 - initialisation du reflecteur
 ConnectionTab connectTab(Permutation);
 Rotor rotor1(Ro_I);
 Rotor rotor2(Ro_II);
 Rotor rotor3(Ro_III);
 Reflecteur reflecteur(Re_B);


 // Zone de test
reflecteur.get_permutationTab();
connectTab.get_PermutationTab();
rotor1.get_permutationTab();
rotor2.get_permutationTab();
rotor3.get_permutationTab();

 cout<<"caractere a crypter : "<<endl;
 cin>>char_to_crypt;

 char_crypted=connectTab.activate(char_to_crypt);
 char_crypted=rotor1.activate(char_crypted,0);
 char_crypted=rotor2.activate(char_crypted,0);
 char_crypted=rotor3.activate(char_crypted,0);
 char_crypted=reflecteur.activate(char_crypted);
 char_crypted=rotor3.activate(char_crypted,0);
 char_crypted=rotor2.activate(char_crypted,0);
 char_crypted=rotor1.activate(char_crypted,0);
 char_crypted=connectTab.activate(char_crypted);

 cout<<"caractere crypte : "<<char_crypted<<endl;




/*
 cout<<"permutation de a : "<<rotor1.permuteRotor('a',0)<<endl;
 cout<<"apres permutation"<<endl;
 rotor1.get_permutationRotorTab();

  cout<<"permutation de a : "<<rotor2.permuteRotor('a',-1)<<endl;
 cout<<"apres permutation"<<endl;
 rotor2.get_permutationRotorTab();

   cout<<"permutation de a : "<<rotor2.permuteRotor('a',1)<<endl;
 cout<<"apres permutation"<<endl;
 rotor3.get_permutationRotorTab();

 //cout<<"permutation de a : "<<rotor2.permuteRotor('a',0)<<endl;
 //cout<<"apres permutation"<<endl;
 //rotor2.get_permutationRotorTab();
*/

return 0;
}
