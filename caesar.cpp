// Author: Kenneth Mason
// Caesar Cipher
#include <iostream>
#include <string>
#include <limits>
using namespace std;

bool alpha = true;

string shift(string txt, int shift){
  // Shifts each alphabetic character by k % 26, all others remain the same
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
  int key;
  bool again = false;
  string c = "n";
  cout << "**** Caesar Cipher ****" << endl;
  do {
    cout << "Plaintext to be encoded: ";
    getline(cin, ptext);
    cout << "Integer encryption key: ";
    cin >> key;
    if(key == 0){
      cerr << "Only non-zero integer keys are valid" << endl;
      return 1;
    }

    cout << "Ciphertext: " << shift(ptext, key) << endl;
    if(!alpha){
      cout << "Warning: This text contains the non-alphabetic characters. Only alphabetic characters will be shifted during encryption" << endl;
      alpha = true;
    }
    // Informs user that they can decode with negated keys. Only prints if 'again' bool is false so the user only sees notification once.
    if(!again) cout << "Note: Ciphertext encoded with key k can be decoded with key -k" << endl;

    cout << "Again? (y/n): ";
    cin >> c;
    if(c == "Y" || c == "y" || c == "Yes" || c == "yes"){
      again = true;
      // Clears newline characters from input buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else{
      again = false;
    }
  } while(again);
  return 0;
}
