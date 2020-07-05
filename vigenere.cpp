// Author: Kenneth Mason
// Vigenere Cipher
#include <iostream>
#include <string>
#include <limits>
using namespace std;

bool alpha = true;

string encrypt(string txt, string key){
  // Shifts each alphabetic character by k[j], all others remain the same
  string ret = "";
  unsigned int i, j;
  char offset = 'A';
  for(i = 0, j = 0; i < txt.length(); ++i){
    char c = txt[i];
    if(isalpha(c)){
      c = toupper(c);
      ret += (c + key[j] - (2 * offset)) % 26 + offset;
    } else{
      alpha = false;
      ret += c;
    }
    j = (j+1) % key.length();
  }
  return ret;
}

string decrypt(string txt, string key){
  string ret = "";
  unsigned int i, j;
  char offset = 'A';
  for(i = 0, j = 0; i < txt.length(); ++i){
    char c = txt[i];
    if(isalpha(c)){
      c = toupper(c);
      ret += (c - key[j] + 26) % 26 + offset;
    } else{
      alpha = false;
      ret += c;
    }
    j = (j+1) % key.length();
  }
  return ret;
}

int main() {
  // Takes a numerical key and a string to be encoded as input. A negative key denotes a left-shift
  string ptext;
  string key;
  bool again = false;
  string c = "n";
  string eod = "e";

  cout << "**** Vigenere Cipher ****" << endl;

  do {
    cout << "Encryption or Decryption? (e/d): " << endl;
    cin >> eod;
    char e = tolower(eod[0]);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(e == 'e'){
      cout << "Plaintext to be encoded: ";
      getline(cin, ptext);
      cout << "Encryption key (string): ";
      getline(cin, key);
      if(key.empty()){
        cerr << "Only non-empty alphabetical keys are valid" << endl;
        return 1;
      }

      cout << "Ciphertext: " << encrypt(ptext, key) << endl;
      if(!alpha){
        cout << "Warning: This text contains the non-alphabetic characters. Only alphabetic characters will be shifted during encryption" << endl;
        alpha = true;
      }
    }
    else if (e == 'd'){
      cout << "Ciphertext to be decoded: ";
      getline(cin, ptext);
      cout << "Encryption key (case-sensitive): ";
      getline(cin, key);
      if(key.empty()){
        cerr << "Only non-empty alphabetical keys are valid" << endl;
        return 1;
      }

      cout << "Ciphertext: " << decrypt(ptext, key) << endl;
      if(!alpha){
        cout << "Warning: This text contains the non-alphabetic characters. Only alphabetic characters will be shifted during decryption" << endl;
        alpha = true;
      }
    }
    else {
      cerr << "I don't have time for this. Come back when you're done trying to break my program";
      return 1;
    }

    cout << "Again? (y/n): ";
    cin >> c;
    char y = tolower(c[0]);
    if(y == 'y'){
      again = true;
      // Clears newline characters from input buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else{
      again = false;
    }

  } while(again);

  return 0;
}
