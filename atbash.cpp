// Author: Kenneth Mason
// Atbash Cipher
#include <iostream>
#include <string>
#include <limits>
using namespace std;

bool alpha = true;

string atbash(string txt){
  // Substitutes each alphabetic character with it's reverse, non-letter characters remain the same
  // a -> z; b -> y; etc.

  string ret = "";
  unsigned int i;
  for(i = 0; i < txt.length(); i++){
    char offset = 'A' + 'Z';
    char c = txt[i];
    if(isalpha(c)){
      if (c >= 'a' && c <= 'z') offset = 'a' + 'z';
      ret += offset - c;
    } else{
      alpha = false;
      ret += c;
    }
  }
  return ret;
}

int main() {
  string ptext;
  bool again = false;
  string c = "n";
  cout << "**** Atbash Cipher ****" << endl;
  do {
    cout << "Plaintext to be encoded: ";
    getline(cin, ptext);
    cout << "Ciphertext: " << atbash(ptext) << endl;
    if(!alpha){
      cout << "Warning: This text contains the non-alphabetic characters. Only alphabetic characters will be encrypted" << endl;
      alpha = true;
    }

    cout << "Again? (y/n): ";
    cin >> c;
    char a = tolower(c[0]);
    if(a == 'y'){
      again = true;
      // Clears newline characters from input buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else{
      again = false;
    }
  } while(again);
  return 0;
}
