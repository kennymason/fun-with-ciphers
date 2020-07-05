// Author: Kenneth Mason
// ROT13 Cipher
#include <iostream>
#include <string>
#include <limits>
using namespace std;

bool alpha = true;

string rot(string txt){
  // Shifts each alphabetic character by k % 26, all others remain the same
  int shift = 13;
  string ret = "";
  unsigned int i;
  for(i = 0; i < txt.length(); i++){
    char offset = 'A';
    char c = txt[i];
    if(isalpha(c)){
      if (c >= 'a' && c <= 'z') offset = 'a';
      if(shift < 0) offset += 25;
      ret += (c - offset + shift) % 26 + offset;
    } else{
      alpha = false;
      ret += c;
    }
  }
  return ret;
}

int main() {
  // Takes a numerical key and a string to be encoded as input. A negative key denotes a left-shift
  string ptext;
  bool again = false;
  string c = "n";
  cout << "**** ROT13 ****" << endl;
  do {
    cout << "Plaintext to be encoded: ";
    getline(cin, ptext);
    cout << "Ciphertext: " << rot(ptext) << endl;
    if(!alpha){
      cout << "Warning: This text contains the non-alphabetic characters. Only alphabetic characters will be shifted during encryption" << endl;
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
