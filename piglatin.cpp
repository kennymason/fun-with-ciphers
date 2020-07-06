// Author: Kenneth Mason
// Pig Latin
#include <iostream>
#include <string.h>
#include <limits>
#include <sstream>
using namespace std;

bool is_vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string translate(string word){
  // RULES:
  // Words that begin with consonants: all letters before initial vowel are placed at the end, then "ay" is added
  // Words that begin with vowels: "yay" is added to end of word
  // Hyphenated words should be split up and translated separately
  if (word.find('-') != string::npos){
    char *wrd = &word[0];
    char *token = strtok(wrd, "-");
    string ret;
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
      ret += (translate(token) + "-");
      token = strtok(NULL, "-");
    }
    ret.pop_back();
    return ret;
  } else {
    char f = tolower(word.front());
    for (int i = 0; i < word.length(); i++){
      if (is_vowel(tolower(word[i]))){
        if (i == 0){
          // First character of the word is a vowel
          word += "yay";
          return word;
        }
        // First character of the word is a consonant
        // returns a string of all letters from the first vowel to the end of the word, then the letters up to the first vowel, then "ay"
        return word.substr(i, word.length() - 1) + word.substr(0, i) + "ay";
      }
    }
    return word + "ay";
  }
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
    cout << "Pig Latin: ";

    while (ss) {
      string word;
      ss >> word;
      if(!word.empty()) cout << translate(word) << " ";
    }

    cout << endl << "Again? (y/n): ";
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
