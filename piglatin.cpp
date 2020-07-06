// Author: Kenneth Mason
// Pig Latin
#include <iostream>
#include <string>
#include <limits>
using namespace std;

bool alpha = true;

string translate(string word){
  // RULES:
  // Words that begin with consonants: all letters before initial vowel are placed at the end, then "ay" is added
  // Words that begin with vowels: "yay" is added to end of word
  // Hyphenated words should be split up and translated separately
  


}

int main() {
  string str;
  bool again = false;
  string c = "n";

  cout << "**** Pig Latin ****" << endl;
  do {
    cout << "English: ";
    getline(cin, str);
    istringstream ss(str);
    cout << "Pig Latin: "

    do {
      string word;
      ss >> word;
      cout << translate(word) << " ";
    } while (ss);

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
