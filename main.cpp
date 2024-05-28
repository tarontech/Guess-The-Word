#include <iostream>
#include <array>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  
  int randomWord;
  
  vector<string> ListofWords = {"earth" , "queen", "valid", "phone", "brown", "broad", "there", "among", "month", "exact", "eager", "three", "prize", "lying", "peace", "cycle", "worth", "going", "dream", "speed"};
  srand(time(nullptr));
  randomWord = rand() % ListofWords.size();
  //cout << ListofWords.at(randomWord) << endl;
  if (ListofWords.at(randomWord) == "earth")
  {cout << "Its the rock we live on:" << endl;}

   string word = ListofWords.at(randomWord);
    char input;
    vector<char> guessedLetters(word.size(), '_');
    cout << "Guess the word by entering one letter at a time:" << endl;

    for (int i = 0; i < word.size(); i++) {
      cout << "Enter letter: ";
      cin >> input;
      if (input == word[i]) {
        guessedLetters[i] = input;
        // cout << "You entered: " << input << endl;
      } else {
        cout << "Wrong letter! Try again." << endl;
        //i--; // To stay at the same index for the next iteration
      }
      cout << "Current Progress: ";
      //for (char letter : guessedLetters) {
        //cout << letter << " ";
        // OR
        for (int i = 0; i < word.size(); i++) {
         cout << guessedLetters[i] << " ";
      }
      cout << endl;
    }
    cout << "The guessed word is: " << word << endl;
    
}
