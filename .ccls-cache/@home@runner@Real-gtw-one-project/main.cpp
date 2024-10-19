#include <iomanip>
#include <iostream>
#include <string> 
#include <vector>

using namespace std;
// Group 6: Vikash G, Taron R, Heidy L, Anindita B, Emily B
// Purpose: Wordle Group Project (Final version)
// Date: 5/19/24

// Group activity 1 contributers: [Vikash Gangabissoon], [Heidy Loaiza Miranda], 
// [Anindita Banik], [Emily Badoon], [Taron Robinson]

// Group activity 2 contributers: [Vikash Gangabissoon], [Heidy Loaiza Miranda], 
// [Anindita Banik], [Emily Badoon], [Taron Robinson]

// Group activity 3 contributers: [Vikash Gangabissoon], [Heidy Loaiza Miranda], 
// [Anindita Banik], [Emily Badoon], [Taron Robinson]

// Group activity 4 contributers: [Vikash Gangabissoon], [Taron Robinson]

// Group activity 5 contributers: [Vikash Gangabissoon], [Heidy Loaiza Miranda], 
// [Anindita Banik], [Emily Badoon], [Taron Robinson]

void Menu(string p1, string p2, string p3, int s1, int s2, int s3);

void HighScore(string p1, string p2, string p3, int s1, int s2, int s3) {

  // Create vectors of player names and their corresponding scores with a maximum of 3 players and 3 scores.
  vector<string> names (3, "");
  vector<int> points (3, 0);

  string pl1 = p1, pl2 = p2, pl3 = p3;

  int counter = 0;
  // Assigning each index in names vector to players name.
      names.at(0) = pl1;
      names.at(1) = pl2;
      names.at(2) = pl3;


      cout << left;
      cout << "Players" << endl;
      cout << "****************" << endl;
      cout << setfill('.');

  // Conditions to update the score of each player. 
      if (names.at(0) == p1) {
        points.at(0) = s1 + points.at(0);

      } 
      if (names.at(1) == p2) {
        points.at(1) = s2 + points.at(1);

      } 
      if (names.at(2) == p3) { 
        points.at(2) = s3 + points.at(2);

      }
  // When there are no names assigned to the index, it will display the score as 0. 
      if (names.at(0) == "") {
         s1 = 0;
         points.at(0) = 0;
         pl1 = p1;
         names.at(0) = pl1;

      } 
      if (names.at(1) == "") { 
        s2 = 0;
        points.at(1) = 0;
        pl2 = p2;
        names.at(1) = pl2;

      } 
      if (names.at(2) == "") { 
        s3 = 0;
        points.at(2) = 0;
        pl3 = p3;
        names.at(2) = pl3;

      }
// For loop used to display the leaderboard.
      for (int i = 0; i < 3; i++) {

        counter = counter + 1;
        if (counter == 4) {
          counter = 1;
        }

        cout << left << counter << ". " << setw(10) << names.at(i) << setw(2) << points.at(i) << "|" << endl;
      }

    cout << endl;
// Conditional statements used to determine the highest score. 
    if (points.at(0) > points.at(1) && points.at(0) > points.at(2)) {
      cout << "High Score: " << pl1 << "..." << points.at(0);
    } else if (points.at(1) > points.at(0) && points.at(1) > points.at(2)) {
      cout << "High Score: " << pl2 << "..." << points.at(1);
    } else if (points.at(2) > points.at(0) && points.at(2) > points.at(1)) {
      cout << "High Score: " << pl3 << "..." << points.at(2);
    }

}


// Rules of the game 
void rules() { 
  cout << "RULE'S" << endl << endl;

  cout << "-Enter the ammout of players (1-3)" << endl;
  cout << "-If you wish to remove a player, there name and score will be erased" << endl;
  cout << "-Guess a randomly gemnerated FIVE letter word" << endl;
  cout << "-You have SIX chances to guess the random word" << endl;
  cout << "-If the letter in the guessed word is in the random word but in the wrong positon, it will give a clue" << endl;
  cout << "-If the guessed word has TWO instances of the same letter, the clue will show twice. That does not mean there are TWO of that letter in the random word" << endl;
  cout << "-If the letter in the guessed word is in the random word and in the right spot, It will display the letter" << endl;
  cout << "-If the letter is not in the word, it will display a message accordingly" << endl << endl;

  cout << "POINT'S" << endl << endl;

  cout << "-Each word guessed correctly will add 1 point to the players score" << endl;
  cout << "-If the same player play's again, there new points will add on to the previous score" << endl;
  cout << "-The player with the HIGHEST score will be displayed as the high score" << endl << endl << endl;

}

void Game(string p1, string p2, string p3, int s1, int s2, int s3 ) {

  int randomIndex, pgSelect;
  char gameChoice;
  string player1;
  // This is only player 1 game.
  if (p1 != "" && p2 == "" && p3 == "") {

    cout << p1 << "'s Game" << endl;
    cout << endl;

    p2 = "", p3 = "";

    string input;
    int chance = 6;

      vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                    "broad", "there", "among", "month", "exact",
                                    "eager", "three", "prize", "lying", "peace",
                                    "cycle", "worth", "going","dream", "speed",                 
                                    "klutz", "pizza", "quick","dizzy", "junky"};

      srand(time(nullptr));
      randomIndex = rand() %ListofWords.size(); 
      string word = ListofWords.at(randomIndex);
                       // The random generator will generate a big number, to combat
                       // this, we mod the number by the vector size. The size of
                       // the index is 20, so we are still essentialy modding by 25.
                       // This will give us a remainder from 0-24, which is within
                       // the range of the index.

      // Group Activity #3 Contributors: [Vikash Gangabissoon], [Heidy Loaiza Miranda], 
      // [Anindita Banik], [Emily Badoon], [Taron Robinson]

      for (int attempts = chance; attempts > 0; attempts--) {
          cout << "Attempt's left: " << attempts << endl;
          cout << "Guess word: ";
          cin >> input;
          cout << endl;

        while (input.length() < 5 || input.length() > 5) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try Again: ";
            cin >> input;
        }

          vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
          vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
          vector<char> statusChar (5);                         // 5 place holders for status check

          for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
            if (inputChars.at(i) == wordChars.at(i)) {
              statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

            } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
              statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                if (word.find(inputChars.at(i)) != string::npos) {
                  cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                } else {
                  cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                }
          }

          for (int i = 0; i < 5; i++) {                    // Displays status 
            cout << statusChar.at(i);
          }

          if (inputChars == wordChars) {                   // score tracker and allows to continue
            cout << endl;
            cout << "You guessed Correctly!" << endl;
            s1 = s1 + 1;
            cout << endl;
            cout << "Continue? (Y/N): ";
            cin >> gameChoice;
            while (gameChoice == 'Y') {
            Game(p1, p2, p3, s1, s2, s3);
              break;
            } 
            Menu(p1, p2, p3, s1, s2, s3);

          } else if (inputChars != wordChars) { // Try again
              cout << endl;
              cout << "Try Again." << endl;
          }

          if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
          cout << endl;
          cout << "The correct word was " << word << endl;
          cout << "Game Over" << endl;
          cout << "Retry(Y) Exit(N): ";
          cin >> gameChoice;
            while (gameChoice == 'Y') {
              Game(p1, p2, p3, s1, s2, s3);
              break;
            }
              Menu(p1, p2, p3, s1, s2, s3);
            }
          }

    // This is player 2 game
  } else if (p1 == "" && p2 != "" && p3 == "") {

      cout << p2 << "'s Game" << endl;
      cout << endl;


                      p1 = "", p3 = "";


                      string input;
                      int chance = 6;

                        vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                      "broad", "there", "among", "month", "exact",
                                                      "eager", "three", "prize", "lying", "peace",
                                                      "cycle", "worth", "going","dream", "speed",                 
                                                      "klutz", "pizza", "quick","dizzy", "junky"};

                        srand(time(nullptr));
                        randomIndex = rand() %ListofWords.size(); 
                        string word = ListofWords.at(randomIndex);
                                         // The random generator will generate a big number, to combat
                                         // this, we mod the number by the vector size. The size of
                                         // the index is 20, so we are still essentialy modding by 25.
                                         // This will give us a remainder from 0-24, which is within
                                         // the range of the index.

                        for (int attempts = chance; attempts > 0; attempts--) {
                            cout << "Attempt's left: " << attempts << endl;
                            cout << "Guess word: ";
                            cin >> input;
                            cout << endl;

                          while (input.length() < 5 || input.length() > 5) {
                              cin.clear();
                              cin.ignore(10000, '\n');
                              cout << "Invalid input. Try Again: ";
                              cin >> input;
                          }


                            vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                            vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                            vector<char> statusChar (5);                         // 5 place holders for status check

                            for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                              if (inputChars.at(i) == wordChars.at(i)) {
                                statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                              } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                                statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                                  if (word.find(inputChars.at(i)) != string::npos) {
                                    cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                                  } else {
                                    cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                                  }
                            }

                            for (int i = 0; i < 5; i++) {                    // Displays status 
                              cout << statusChar.at(i);
                            }

                            if (inputChars == wordChars) {                   // score tracker and allows to continue
                              cout << endl;
                              cout << "You guessed Correctly!" << endl;
                              s2 = s2 + 1;
                              cout << endl;
                              cout << "Continue? (Y/N): ";
                              cin >> gameChoice;
                              while (gameChoice == 'Y') {
                              Game(p1, p2, p3, s1, s2, s3);
                                break;
                              } 
                              Menu(p1, p2, p3, s1, s2, s3);

                            } else if (inputChars != wordChars) { // Try again
                                cout << endl;
                                cout << "Try Again." << endl;
                            }

                            if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                            cout << endl;
                            cout << "The correct word was " << word << endl;
                            cout << "Game Over" << endl;
                            cout << "Retry(Y) Exit(N): ";
                            cin >> gameChoice;
                              while (gameChoice == 'Y') {
                                Game(p1, p2, p3, s1, s2, s3);
                                break;
                              }
                                Menu(p1, p2, p3, s1, s2, s3);
                              }
                        }

    // This is player 3 game.
  } else if (p1 == "" && p2 == "" && p3 != "") {


      cout << p3 << "'s Game" << endl;
      cout << endl;


                      p1 = "", p2 = "";


                      string input;
                      int chance = 6;

                        vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                      "broad", "there", "among", "month", "exact",
                                                      "eager", "three", "prize", "lying", "peace",
                                                      "cycle", "worth", "going","dream", "speed",                 
                                                      "klutz", "pizza", "quick","dizzy", "junky"};

                        srand(time(nullptr));
                        randomIndex = rand() %ListofWords.size(); 
                        string word = ListofWords.at(randomIndex);
                                         // The random generator will generate a big number, to combat
                                         // this, we mod the number by the vector size. The size of
                                         // the index is 20, so we are still essentialy modding by 25.
                                         // This will give us a remainder from 0-24, which is within
                                         // the range of the index.


                        for (int attempts = chance; attempts > 0; attempts--) {
                            cout << "Attempt's left: " << attempts << endl;
                            cout << "Guess word: ";
                            cin >> input;
                            cout << endl;

                          while (input.length() < 5 || input.length() > 5) {
                              cin.clear();
                              cin.ignore(10000, '\n');
                              cout << "Invalid input. Try Again: ";
                              cin >> input;
                          }


                            vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                            vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                            vector<char> statusChar (5);                         // 5 place holders for status check

                            for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                              if (inputChars.at(i) == wordChars.at(i)) {
                                statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                              } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                                statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                                  if (word.find(inputChars.at(i)) != string::npos) {
                                    cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                                  } else {
                                    cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                                  }
                            }

                            for (int i = 0; i < 5; i++) {                    // Displays status 
                              cout << statusChar.at(i);
                            }

                            if (inputChars == wordChars) {                   // score tracker and allows to continue
                              cout << endl;
                              cout << "You guessed Correctly!" << endl;
                              s3 = s3 + 1;
                              cout << endl;
                              cout << "Continue? (Y/N): ";
                              cin >> gameChoice;
                              while (gameChoice == 'Y') {
                              Game(p1, p2, p3, s1, s2, s3);
                                break;
                              } 
                              Menu(p1, p2, p3, s1, s2, s3);

                            } else if (inputChars != wordChars) { // Try again
                                cout << endl;
                                cout << "Try Again." << endl;
                            }

                            if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                            cout << endl;
                            cout << "The correct word was " << word << endl;
                            cout << "Game Over" << endl;
                            cout << "Retry(Y) Exit(N): ";
                            cin >> gameChoice;
                              while (gameChoice == 'Y') {
                                Game(p1, p2, p3, s1, s2, s3);
                                break;
                              }
                                Menu(p1, p2, p3, s1, s2, s3);
                              }
                        }

  // This is for multiplayer (2 player game).
  } else if (p1 != "" && p2 != "" && p3 == "") {



    cout << "Who's Playing?" << endl;
    cout << "<1> " << p1 << endl;
    cout << "<2> " << p2 << endl;
    cout << "Enter choice: ";
    cin >> pgSelect;

    while (!cin.good() || pgSelect < 1 || pgSelect > 2) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << endl;
      cout << "This is an invalid choice." << endl;
        cout << "******************************" << endl << endl;
      Game(p1, p2, p3, s1, s2, s3);
    }
    cout << endl;
      // When player 1 is chosen, it would go through the entire concept of them trying to guess the word.
        if (pgSelect == 1) {

                  cout << p1 << "'s Game" << endl;
                  cout << endl;

                  p3 = "";


                  string input;
                  int chance = 6;

                    vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                  "broad", "there", "among", "month", "exact",
                                                  "eager", "three", "prize", "lying", "peace",
                                                  "cycle", "worth", "going","dream", "speed",                 
                                                  "klutz", "pizza", "quick","dizzy", "junky"};

                    srand(time(nullptr));
                    randomIndex = rand() %ListofWords.size(); 
                    string word = ListofWords.at(randomIndex);
                                     // The random generator will generate a big number, to combat
                                     // this, we mod the number by the vector size. The size of
                                     // the index is 20, so we are still essentialy modding by 25.
                                     // This will give us a remainder from 0-24, which is within
                                     // the range of the index.


                    for (int attempts = chance; attempts > 0; attempts--) {
                        cout << "Attempt's left: " << attempts << endl;
                        cout << "Guess word: ";
                        cin >> input;
                        cout << endl;

                      while (input.length() < 5 || input.length() > 5) {
                          cin.clear();
                          cin.ignore(10000, '\n');
                          cout << "Invalid input. Try Again: ";
                          cin >> input;
                      }


                        vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                        vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                        vector<char> statusChar (5);                         // 5 place holders for status check

                        for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                          if (inputChars.at(i) == wordChars.at(i)) {
                            statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                          } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                            statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                              if (word.find(inputChars.at(i)) != string::npos) {
                                cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                              } else {
                                cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                              }
                        }

                        for (int i = 0; i < 5; i++) {                    // Displays status 
                          cout << statusChar.at(i);
                        }

                        if (inputChars == wordChars) {                   // score tracker and allows to continue
                          cout << endl;
                          cout << "You guessed Correctly!" << endl;
                          s1 = s1 + 1;
                          cout << endl;
                          cout << "Continue? (Y/N): ";
                          cin >> gameChoice;
                          while (gameChoice == 'Y') {
                          Game(p1, p2, p3, s1, s2, s3);
                            break;
                          } 
                          Menu(p1, p2, p3, s1, s2, s3);

                        } else if (inputChars != wordChars) { // Try again
                            cout << endl;
                            cout << "Try Again." << endl;
                        }

                        if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                        cout << endl;
                        cout << "The correct word was " << word << endl;
                        cout << "Game Over" << endl;
                        cout << "Retry(Y) Exit(N): ";
                        cin >> gameChoice;
                          while (gameChoice == 'Y') {
                            Game(p1, p2, p3, s1, s2, s3);
                            break;
                          }
                            Menu(p1, p2, p3, s1, s2, s3);
                          }
                        }

        // When player 2 is selected, it would go through the entire concept of them trying to guess the word.
        } else if (pgSelect == 2) {

                cout << p2 << "'s Game" << endl;
                cout << endl;

                p3 = "";


                string input;
                int chance = 6;

                  vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                "broad", "there", "among", "month", "exact",
                                                "eager", "three", "prize", "lying", "peace",
                                                "cycle", "worth", "going","dream", "speed",                 
                                                "klutz", "pizza", "quick","dizzy", "junky"};

                  srand(time(nullptr));
                  randomIndex = rand() %ListofWords.size(); 
                  string word = ListofWords.at(randomIndex);
                                   // The random generator will generate a big number, to combat
                                   // this, we mod the number by the vector size. The size of
                                   // the index is 20, so we are still essentialy modding by 25.
                                   // This will give us a remainder from 0-24, which is within
                                   // the range of the index.


                  for (int attempts = chance; attempts > 0; attempts--) {
                      cout << "Attempt's left: " << attempts << endl;
                      cout << "Guess word: ";
                      cin >> input;
                      cout << endl;

                    while (input.length() < 5 || input.length() > 5) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input. Try Again: ";
                        cin >> input;
                    }


                      vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                      vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                      vector<char> statusChar (5);                         // 5 place holders for status check

                      for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                        if (inputChars.at(i) == wordChars.at(i)) {
                          statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                        } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                          statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                            if (word.find(inputChars.at(i)) != string::npos) {
                              cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                            } else {
                              cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                            }
                      }

                      for (int i = 0; i < 5; i++) {                    // Displays status 
                        cout << statusChar.at(i);
                      }

                      if (inputChars == wordChars) {                   // score tracker and allows to continue
                        cout << endl;
                        cout << "You guessed Correctly!" << endl;
                        s2 = s2 + 1;
                        cout << endl;
                        cout << "Continue? (Y/N): ";
                        cin >> gameChoice;
                        while (gameChoice == 'Y') {
                        Game(p1, p2, p3, s1, s2, s3);
                          break;
                        } 
                        Menu(p1, p2, p3, s1, s2, s3);

                      } else if (inputChars != wordChars) { // Try again
                          cout << endl;
                          cout << "Try Again." << endl;
                      }

                      if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                      cout << endl;
                      cout << "The correct word was " << word << endl;
                      cout << "Game Over" << endl;
                      cout << "Retry(Y) Exit(N): ";
                      cin >> gameChoice;
                        while (gameChoice == 'Y') {
                          Game(p1, p2, p3, s1, s2, s3);
                          break;
                        }
                          Menu(p1, p2, p3, s1, s2, s3);
                        }
                      }

        }

    // Same concept as multiplayer, it's just that player 1 name is not present or removed. 
  } else if (p1 == "" && p2 != "" && p3 != "") {


            cout << "Who's Playing?" << endl;
            cout << "<1> " << p2 << endl;
            cout << "<2> " << p3 << endl;
            cout << "Enter choice: ";
            cin >> pgSelect;

            while (!cin.good() || pgSelect < 1 || pgSelect > 2) {
              cin.clear();
              cin.ignore(1000, '\n');
              cout << endl;
              cout << "This is an invalid choice." << endl;
                cout << "******************************" << endl << endl;
              Game(p1, p2, p3, s1, s2, s3);
            }
            cout << endl;
          // When the first player is chosen, it would go through the entire concept of them trying to guess the word.
                if (pgSelect == 1) {

                          cout << p2 << "'s Game" << endl;
                          cout << endl;

                          p1 = "";


                          string input;
                          int chance = 6;

                            vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                          "broad", "there", "among", "month", "exact",
                                                          "eager", "three", "prize", "lying", "peace",
                                                          "cycle", "worth", "going","dream", "speed",                 
                                                          "klutz", "pizza", "quick","dizzy", "junky"};

                            srand(time(nullptr));
                            randomIndex = rand() %ListofWords.size(); 
                            string word = ListofWords.at(randomIndex);
                                             // The random generator will generate a big number, to combat
                                             // this, we mod the number by the vector size. The size of
                                             // the index is 20, so we are still essentialy modding by 25.
                                             // This will give us a remainder from 0-24, which is within
                                             // the range of the index.


                            for (int attempts = chance; attempts > 0; attempts--) {
                                cout << "Attempt's left: " << attempts << endl;
                                cout << "Guess word: ";
                                cin >> input;
                                cout << endl;

                              while (input.length() < 5 || input.length() > 5) {
                                  cin.clear();
                                  cin.ignore(10000, '\n');
                                  cout << "Invalid input. Try Again: ";
                                  cin >> input;
                              }


                                vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                                vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                                vector<char> statusChar (5);                         // 5 place holders for status check

                                for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                                  if (inputChars.at(i) == wordChars.at(i)) {
                                    statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                                  } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                                    statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                                      if (word.find(inputChars.at(i)) != string::npos) {
                                        cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                                      } else {
                                        cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                                      }
                                }

                                for (int i = 0; i < 5; i++) {                    // Displays status 
                                  cout << statusChar.at(i);
                                }

                                if (inputChars == wordChars) {                   // score tracker and allows to continue
                                  cout << endl;
                                  cout << "You guessed Correctly!" << endl;
                                  s2 = s2 + 1;
                                  cout << endl;
                                  cout << "Continue? (Y/N): ";
                                  cin >> gameChoice;
                                  while (gameChoice == 'Y') {
                                  Game(p1, p2, p3, s1, s2, s3);
                                    break;
                                  } 
                                  Menu(p1, p2, p3, s1, s2, s3);

                                } else if (inputChars != wordChars) { // Try again
                                    cout << endl;
                                    cout << "Try Again." << endl;
                                }

                                if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                                cout << endl;
                                cout << "The correct word was " << word << endl;
                                cout << "Game Over" << endl;
                                cout << "Retry(Y) Exit(N): ";
                                cin >> gameChoice;
                                  while (gameChoice == 'Y') {
                                    Game(p1, p2, p3, s1, s2, s3);
                                    break;
                                  }
                                    Menu(p1, p2, p3, s1, s2, s3);
                                  }
                                }

                } else {

                        cout << p3 << "'s Game" << endl;
                        cout << endl;

                        p1 = "";


                        string input;
                        int chance = 6;

                          vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                        "broad", "there", "among", "month", "exact",
                                                        "eager", "three", "prize", "lying", "peace",
                                                        "cycle", "worth", "going","dream", "speed",                 
                                                        "klutz", "pizza", "quick","dizzy", "junky"};

                          srand(time(nullptr));
                          randomIndex = rand() %ListofWords.size(); 
                          string word = ListofWords.at(randomIndex);
                                           // The random generator will generate a big number, to combat
                                           // this, we mod the number by the vector size. The size of
                                           // the index is 25, so we are still essentialy modding by 25.
                                           // This will give us a remainder from 0-24, which is within
                                           // the range of the index.


                          for (int attempts = chance; attempts > 0; attempts--) {
                              cout << "Attempt's left: " << attempts << endl;
                              cout << "Guess word: ";
                              cin >> input;
                              cout << endl;

                            while (input.length() < 5 || input.length() > 5) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "Invalid input. Try Again: ";
                                cin >> input;
                            }


                              vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                              vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                              vector<char> statusChar (5);                         // 5 place holders for status check

                              for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                                if (inputChars.at(i) == wordChars.at(i)) {
                                  statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                                } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                                  statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                                    if (word.find(inputChars.at(i)) != string::npos) {
                                      cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                                    } else {
                                      cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                                    }
                              }

                              for (int i = 0; i < 5; i++) {                    // Displays status 
                                cout << statusChar.at(i);
                              }

                              if (inputChars == wordChars) {                   // score tracker and allows to continue
                                cout << endl;
                                cout << "You guessed Correctly!" << endl;
                                s3 = s3 + 1;
                                cout << endl;
                                cout << "Continue? (Y/N): ";
                                cin >> gameChoice;
                                while (gameChoice == 'Y') {
                                Game(p1, p2, p3, s1, s2, s3);
                                  break;
                                } 
                                Menu(p1, p2, p3, s1, s2, s3);

                              } else if (inputChars != wordChars) { // Try again
                                  cout << endl;
                                  cout << "Try Again." << endl;
                              }

                              if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                              cout << endl;
                              cout << "The correct word was " << word << endl;
                              cout << "Game Over" << endl;
                              cout << "Retry(Y) Exit(N): ";
                              cin >> gameChoice;
                                while (gameChoice == 'Y') {
                                  Game(p1, p2, p3, s1, s2, s3);
                                  break;
                                }
                                  Menu(p1, p2, p3, s1, s2, s3);
                                }
                              }

                }

  } else if (p1 != "" && p2 == "" && p3 != "") {

              cout << "Who's Playing?" << endl;
              cout << "<1> " << p1 << endl;
              cout << "<2> " << p3 << endl;
              cout << "Enter choice: ";
              cin >> pgSelect;

              while (!cin.good() || pgSelect < 1 || pgSelect > 2) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << endl;
                cout << "This is an invalid choice." << endl;
                  cout << "******************************" << endl << endl;
                Game(p1, p2, p3, s1, s2, s3);
              }
              cout << endl;
          // When first player is chosen, it would go through the entire concept of them trying to guess the word.
                  if (pgSelect == 1) {

                            cout << p1 << "'s Game" << endl;
                            cout << endl;

                            p2 = "";


                            string input;
                            int chance = 6;

                              vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                            "broad", "there", "among", "month", "exact",
                                                            "eager", "three", "prize", "lying", "peace",
                                                            "cycle", "worth", "going","dream", "speed",                 
                                                            "klutz", "pizza", "quick","dizzy", "junky"};

                              srand(time(nullptr));
                              randomIndex = rand() %ListofWords.size(); 
                              string word = ListofWords.at(randomIndex);
                                               // The random generator will generate a big number, to combat
                                               // this, we mod the number by the vector size. The size of
                                               // the index is 20, so we are still essentialy modding by 25.
                                               // This will give us a remainder from 0-24, which is within
                                               // the range of the index.


                              for (int attempts = chance; attempts > 0; attempts--) {
                                  cout << "Attempt's left: " << attempts << endl;
                                  cout << "Guess word: ";
                                  cin >> input;
                                  cout << endl;

                                while (input.length() < 5 || input.length() > 5) {
                                    cin.clear();
                                    cin.ignore(10000, '\n');
                                    cout << "Invalid input. Try Again: ";
                                    cin >> input;
                                }


                                  vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                                  vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                                  vector<char> statusChar (5);                         // 5 place holders for status check

                                  for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                                    if (inputChars.at(i) == wordChars.at(i)) {
                                      statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                                    } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                                      statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                                        if (word.find(inputChars.at(i)) != string::npos) {
                                          cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                                        } else {
                                          cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                                        }
                                  }

                                  for (int i = 0; i < 5; i++) {                    // Displays status 
                                    cout << statusChar.at(i);
                                  }

                                  if (inputChars == wordChars) {                   // score tracker and allows to continue
                                    cout << endl;
                                    cout << "You guessed Correctly!" << endl;
                                    s1 = s1 + 1;
                                    cout << endl;
                                    cout << "Continue? (Y/N): ";
                                    cin >> gameChoice;
                                    while (gameChoice == 'Y') {
                                    Game(p1, p2, p3, s1, s2, s3);
                                      break;
                                    } 
                                    Menu(p1, p2, p3, s1, s2, s3);

                                  } else if (inputChars != wordChars) { // Try again
                                      cout << endl;
                                      cout << "Try Again." << endl;
                                  }

                                  if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                                  cout << endl;
                                  cout << "The correct word was " << word << endl;
                                  cout << "Game Over" << endl;
                                  cout << "Retry(Y) Exit(N): ";
                                  cin >> gameChoice;
                                    while (gameChoice == 'Y') {
                                      Game(p1, p2, p3, s1, s2, s3);
                                      break;
                                    }
                                      Menu(p1, p2, p3, s1, s2, s3);
                                    }
                                  }

                // When first player is not chosen, it would go to player 3 turn and gothrough the entire concept of them trying                 // to guess the word.
                  } else {

                          cout << p3 << "'s Game" << endl;
                          cout << endl;

                          p2 = "";


                          string input;
                          int chance = 6;

                            vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                          "broad", "there", "among", "month", "exact",
                                                          "eager", "three", "prize", "lying", "peace",
                                                          "cycle", "worth", "going","dream", "speed",                 
                                                          "klutz", "pizza", "quick","dizzy", "junky"};

                            srand(time(nullptr));
                            randomIndex = rand() %ListofWords.size(); 
                            string word = ListofWords.at(randomIndex);
                                             // The random generator will generate a big number, to combat
                                             // this, we mod the number by the vector size. The size of
                                             // the index is 20, so we are still essentialy modding by 25.
                                             // This will give us a remainder from 0-24, which is within
                                             // the range of the index.


                            for (int attempts = chance; attempts > 0; attempts--) {
                                cout << "Attempt's left: " << attempts << endl;
                                cout << "Guess word: ";
                                cin >> input;
                                cout << endl;

                              while (input.length() < 5 || input.length() > 5) {
                                  cin.clear();
                                  cin.ignore(10000, '\n');
                                  cout << "Invalid input. Try Again: ";
                                  cin >> input;
                              }


                                vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                                vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                                vector<char> statusChar (5);                         // 5 place holders for status check

                                for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                                  if (inputChars.at(i) == wordChars.at(i)) {
                                    statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                                  } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                                    statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                                      if (word.find(inputChars.at(i)) != string::npos) {
                                        cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                                      } else {
                                        cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                                      }
                                }

                                for (int i = 0; i < 5; i++) {                    // Displays status 
                                  cout << statusChar.at(i);
                                }

                                if (inputChars == wordChars) {                   // score tracker and allows to continue
                                  cout << endl;
                                  cout << "You guessed Correctly!" << endl;
                                  s3 = s3 + 1;
                                  cout << endl;
                                  cout << "Continue? (Y/N): ";
                                  cin >> gameChoice;
                                  while (gameChoice == 'Y') {
                                  Game(p1, p2, p3, s1, s2, s3);
                                    break;
                                  } 
                                  Menu(p1, p2, p3, s1, s2, s3);

                                } else if (inputChars != wordChars) { // Try again
                                    cout << endl;
                                    cout << "Try Again." << endl;
                                }

                                if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                                cout << endl;
                                cout << "The correct word was " << word << endl;
                                cout << "Game Over" << endl;
                                cout << "Retry(Y) Exit(N): ";
                                cin >> gameChoice;
                                  while (gameChoice == 'Y') {
                                    Game(p1, p2, p3, s1, s2, s3);
                                    break;
                                  }
                                    Menu(p1, p2, p3, s1, s2, s3);
                                  }
                                }

                  }

  // This is three player game.
  } else if (p1 != "" && p2 != "" && p3 != "") {


    cout << "Who's Playing?" << endl;
    cout << "<1> " << p1 << endl;
    cout << "<2> " << p2 << endl;
    cout << "<3> " << p3 << endl;
    cout << "Enter choice: ";
    cin >> pgSelect;
  // To check if input is valid. 
    while (!cin.good() || pgSelect < 1 || pgSelect > 3) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << endl;
      cout << "This is an invalid choice." << endl;
        cout << "******************************" << endl << endl;
      Game(p1, p2, p3, s1, s2, s3);
    }
    cout << endl;
    // When first player is chosen, it would go through the entire concept of them trying to guess the word.
        if (pgSelect == 1) {

                  cout << p1 << "'s Game" << endl;
                  cout << endl;


                  string input;
                  int chance = 6;

                    vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                  "broad", "there", "among", "month", "exact",
                                                  "eager", "three", "prize", "lying", "peace",
                                                  "cycle", "worth", "going","dream", "speed",                 
                                                  "klutz", "pizza", "quick","dizzy", "junky"};

                    srand(time(nullptr));
                    randomIndex = rand() %ListofWords.size(); 
                    string word = ListofWords.at(randomIndex);
                                     // The random generator will generate a big number, to combat
                                     // this, we mod the number by the vector size. The size of
                                     // the index is 20, so we are still essentialy modding by 25.
                                     // This will give us a remainder from 0-24, which is within
                                     // the range of the index.


                    for (int attempts = chance; attempts > 0; attempts--) {
                        cout << "Attempt's left: " << attempts << endl;
                        cout << "Guess word: ";
                        cin >> input;
                        cout << endl;

                      while (input.length() < 5 || input.length() > 5) {
                          cin.clear();
                          cin.ignore(10000, '\n');
                          cout << "Invalid input. Try Again: ";
                          cin >> input;
                      }


                        vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                        vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                        vector<char> statusChar (5);                         // 5 place holders for status check

                        for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                          if (inputChars.at(i) == wordChars.at(i)) {
                            statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                          } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                            statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                              if (word.find(inputChars.at(i)) != string::npos) {
                                cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                              } else {
                                cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                              }
                        }

                        for (int i = 0; i < 5; i++) {                    // Displays status 
                          cout << statusChar.at(i);
                        }

                        if (inputChars == wordChars) {                   // score tracker and allows to continue
                          cout << endl;
                          cout << "You guessed Correctly!" << endl;
                          s1 = s1 + 1;
                          cout << endl;
                          cout << "Continue? (Y/N): ";
                          cin >> gameChoice;
                          while (gameChoice == 'Y') {
                          Game(p1, p2, p3, s1, s2, s3);
                            break;
                          } 
                          Menu(p1, p2, p3, s1, s2, s3);

                        } else if (inputChars != wordChars) { // Try again
                            cout << endl;
                            cout << "Try Again." << endl;
                        }

                        if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                        cout << endl;
                        cout << "The correct word was " << word << endl;
                        cout << "Game Over" << endl;
                        cout << "Retry(Y) Exit(N): ";
                        cin >> gameChoice;
                          while (gameChoice == 'Y') {
                            Game(p1, p2, p3, s1, s2, s3);
                            break;
                          }
                            Menu(p1, p2, p3, s1, s2, s3);
                          }
                        }

          // When second player is chosen, it would go through the entire concept of them trying to guess the word.
        } else if (pgSelect == 2) {

                cout << p2 << "'s Game" << endl;
                cout << endl;


                string input;
                int chance = 6;

                  vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                "broad", "there", "among", "month", "exact",
                                                "eager", "three", "prize", "lying", "peace",
                                                "cycle", "worth", "going","dream", "speed",                 
                                                "klutz", "pizza", "quick","dizzy", "junky"};

                  srand(time(nullptr));
                  randomIndex = rand() %ListofWords.size(); 
                  string word = ListofWords.at(randomIndex);
                                   // The random generator will generate a big number, to combat
                                   // this, we mod the number by the vector size. The size of
                                   // the index is 20, so we are still essentialy modding by 25.
                                   // This will give us a remainder from 0-24, which is within
                                   // the range of the index.


                  for (int attempts = chance; attempts > 0; attempts--) {
                      cout << "Attempt's left: " << attempts << endl;
                      cout << "Guess word: ";
                      cin >> input;
                      cout << endl;

                    while (input.length() < 5 || input.length() > 5) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input. Try Again: ";
                        cin >> input;
                    }


                      vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                      vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                      vector<char> statusChar (5);                         // 5 place holders for status check

                      for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                        if (inputChars.at(i) == wordChars.at(i)) {
                          statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                        } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                          statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                            if (word.find(inputChars.at(i)) != string::npos) {
                              cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                            } else {
                              cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                            }
                      }

                      for (int i = 0; i < 5; i++) {                    // Displays status 
                        cout << statusChar.at(i);
                      }

                      if (inputChars == wordChars) {                   // score tracker and allows to continue
                        cout << endl;
                        cout << "You guessed Correctly!" << endl;
                        s2 = s2 + 1;
                        cout << endl;
                        cout << "Continue? (Y/N): ";
                        cin >> gameChoice;
                        while (gameChoice == 'Y') {
                        Game(p1, p2, p3, s1, s2, s3);
                          break;
                        } 
                        Menu(p1, p2, p3, s1, s2, s3);

                      } else if (inputChars != wordChars) { // Try again
                          cout << endl;
                          cout << "Try Again." << endl;
                      }

                      if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                      cout << endl;
                      cout << "The correct word was " << word << endl;
                      cout << "Game Over" << endl;
                      cout << "Retry(Y) Exit(N): ";
                      cin >> gameChoice;
                        while (gameChoice == 'Y') {
                          Game(p1, p2, p3, s1, s2, s3);
                          break;
                        }
                          Menu(p1, p2, p3, s1, s2, s3);
                        }
                      }
          // When third player is chosen, it would go through the entire concept of them trying to guess the word.
        } else {

                cout << p3 << "'s Game" << endl;
                cout << endl;


                string input;
                int chance = 6;

                  vector<string> ListofWords = {"earth", "queen", "valid", "phone", "brown",
                                                "broad", "there", "among", "month", "exact",
                                                "eager", "three", "prize", "lying", "peace",
                                                "cycle", "worth", "going","dream", "speed",                 
                                                "klutz", "pizza", "quick","dizzy", "junky"};

                  srand(time(nullptr));
                  randomIndex = rand() %ListofWords.size(); 
                  string word = ListofWords.at(randomIndex);
                                   // The random generator will generate a big number, to combat
                                   // this, we mod the number by the vector size. The size of
                                   // the index is 20, so we are still essentialy modding by 25.
                                   // This will give us a remainder from 0-24, which is within
                                   // the range of the index.


                  for (int attempts = chance; attempts > 0; attempts--) {
                      cout << "Attempt's left: " << attempts << endl;
                      cout << "Guess word: ";
                      cin >> input;
                      cout << endl;

                    while (input.length() < 5 || input.length() > 5) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input. Try Again: ";
                        cin >> input;
                    }


                      vector<char> wordChars(word.begin(), word.end());    // converts word string into chars for vectors
                      vector<char> inputChars(input.begin(), input.end()); // converts input string into chars for vectors
                      vector<char> statusChar (5);                         // 5 place holders for status check

                      for (int i = 0; i < 5; i++) {                     // checks to see which characters are present in the random word.
                        if (inputChars.at(i) == wordChars.at(i)) {
                          statusChar.at(i) = word.at(i);                // updates status if character is in the right spot.

                        } else if (inputChars.at(i) != wordChars.at(i)) // determins if character is in the word or not.
                          statusChar.at(i) = '_';                       // place holder untill correct letter if correct order is guessed.
                            if (word.find(inputChars.at(i)) != string::npos) {
                              cout << "Clue: Character " << input.at(i) << " is in the word" << endl;
                            } else {
                              cout << "-" << inputChars.at(i) << " is not in the word" << endl;
                            }
                      }

                      for (int i = 0; i < 5; i++) {                    // Displays status 
                        cout << statusChar.at(i);
                      }

                      if (inputChars == wordChars) {                   // score tracker and allows to continue
                        cout << endl;
                        cout << "You guessed Correctly!" << endl;
                        s3 = s3 + 1;
                        cout << endl;
                        cout << "Continue? (Y/N): ";
                        cin >> gameChoice;
                        while (gameChoice == 'Y') {
                        Game(p1, p2, p3, s1, s2, s3);
                          break;
                        } 
                        Menu(p1, p2, p3, s1, s2, s3);

                      } else if (inputChars != wordChars) { // Try again
                          cout << endl;
                          cout << "Try Again." << endl;
                      }

                      if (attempts == 1) {   // lose condition reveals answer and allows to retry or exit to main menu
                      cout << endl;
                      cout << "The correct word was " << word << endl;
                      cout << "Game Over" << endl;
                      cout << "Retry(Y) Exit(N): ";
                      cin >> gameChoice;
                        while (gameChoice == 'Y') {
                          Game(p1, p2, p3, s1, s2, s3);
                          break;
                        }
                          Menu(p1, p2, p3, s1, s2, s3);
                        }
                      }

        }

// When no names is assigned or entered, it will output this. 
  } else if (p1 == "" && p2 == "" && p3 == "")
    cout << "******************************" << endl;
    cout << "No Player Data!" << endl;
    cout << "******************************" << endl;
    Menu(p1, p2, p3, s1, s2, s3);

}

void Menu(string p1, string p2, string p3, int s1, int s2, int s3) {

  int menuChoice; // menu input

  cout << "Menu" << endl; // menu display
  cout << "<1> Start Game" << endl;
  cout << "<2> How To Play" << endl;
  cout << "<3> Highscore" << endl;
  cout << "<4> Exit" << endl;
  cout << "Enter Choice: ";
  cin >> menuChoice;


    switch (menuChoice) {

      case 1:
        cout << "******************************" << endl;
        cout << "You chose 1" << endl << endl;

        int oneChoice; // menu choice 1 input 


        cout << "<1> Add Player (3 MAX)" << endl;
        cout << "<2> Remove Player" << endl;
        cout << "<3> Continue Game" << endl;
        cout << "<4> Menu" << endl;
        cout << "Enter Choice: ";
        cin >> oneChoice;

          switch (oneChoice) {
            case 1: 

              char addChoice; // add player choice

              cout << "******************************" << endl;
                if (p1 == "" && p2 == "" && p3 == ""){ // different conditions to add player based on player data

                  cout << "Enter Your Name: ";
                  cin >> p1;

                  cout << "Add another Player? (Y/N): ";
                  cin >> addChoice;

                    if (addChoice == 'Y') {
                      cout << "Enter Your Name: ";
                      cin >> p2;

                      while (p2 == p1){
                        cout << "******************************" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "This name is already taken! Try again: ";
                        cin >> p2;
                      }

                      cout << "Add another Player? (Y/N): ";
                      cin >> addChoice;

                        if (addChoice == 'Y') {
                          cout << "Enter Your Name: ";
                          cin >> p3;

                          while (p3 == p1 || p3 == p2){
                            cout << "******************************" << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "This name is already taken! Try again: ";
                            cin >> p3;
                          }

                          cout << "Max Players Reached!!" << endl;

                          cout << "<1> Continue" << endl;
                          cout << "<2> Menu" << endl;
                          cout << "Enter Choice: ";
                          cin >> oneChoice;

                          if (oneChoice == 1){
                            cout << "******************************" << endl;
                            Game(p1, p2, p3, s1, s2, s3);
                          } else {
                            Menu(p1, p2, p3, s1, s2, s3);
                          }


                        } else {
                          cout << "******************************" << endl;
                          cout << "<1> Continue" << endl;
                          cout << "<2> Menu" << endl;
                          cout << "Enter Choice: ";
                          cin >> oneChoice;

                          if (oneChoice == 1){
                            cout << "******************************" << endl;
                            Game(p1, p2, p3, s1, s2, s3);
                          } else {
                            cout << "******************************" << endl;
                            Menu(p1, p2, p3, s1, s2, s3);
                          }
                        }

                    }  else {
                      cout << "******************************" << endl;
                      cout << "<1> Continue" << endl;
                      cout << "<2> Menu" << endl;
                      cout << "Enter Choice: ";
                      cin >> oneChoice;

                      if (oneChoice == 1){
                        cout << "******************************" << endl;
                        Game(p1, p2, p3, s1, s2, s3);
                      } else {
                        cout << "******************************" << endl;
                        Menu(p1, p2, p3, s1, s2, s3);
                      }
                    }

                } else if (p1 != "" && p2 == "" && p3 == "") {
                    cout << "******************************" << endl;

                    cout << "Enter Your Name: ";
                    cin >> p2;

                      while (p2 == p1){
                        cout << "******************************" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "This name is already taken! Try again: ";
                        cin >> p2;
                      }

                    cout << "Add another Player? (Y/N): ";
                    cin >> addChoice;

                      if (addChoice == 'Y') {
                        cout << "Enter Your Name: ";
                        cin >> p3;

                        while (p3 == p1 || p3 == p2){
                          cout << "******************************" << endl;
                          cin.clear();
                          cin.ignore(1000, '\n');
                          cout << "This name is already taken! Try again: ";
                          cin >> p3;
                        }

                            cout << "Max Players Reached!!" << endl;
                        cout << "******************************" << endl;

                            cout << "<1> Continue" << endl;
                            cout << "<2> Menu" << endl;
                            cout << "Enter Choice: ";
                            cin >> oneChoice;


                            if (oneChoice == 1){
                              cout << "******************************" << endl;
                              Game(p1, p2, p3, s1, s2, s3);
                            } else {
                              cout << "******************************" << endl;
                              Menu(p1, p2, p3, s1, s2, s3);
                            }


                          } else {
                        cout << "******************************" << endl;
                            cout << "<1> Continue" << endl;
                            cout << "<2> Menu" << endl;
                            cout << "Enter Choice: ";
                            cin >> oneChoice;

                            if (oneChoice == 1){
                              cout << "******************************" << endl;
                              Game(p1, p2, p3, s1, s2, s3);
                            } else {
                              cout << "******************************" << endl;
                              Menu(p1, p2, p3, s1, s2, s3);
                            }
                          }

                } else if (p1 != "" && p2 != "" && p3 == "") {
                    cout << "******************************" << endl;

                    cout << "Enter Your Name: ";
                    cin >> p3;

                    while (p3 == p1 || p3 == p2){
                      cout << "******************************" << endl;
                      cin.clear();
                      cin.ignore(1000, '\n');
                      cout << "This name is already taken! Try again: ";
                      cin >> p3;
                    }
                    cout << "******************************" << endl;

                        cout << "Max Players Reached!!" << endl;
                        cout << "<1> Continue" << endl;
                        cout << "<2> Menu" << endl;
                        cout << "Enter Choice: ";
                        cin >> oneChoice;

                        if (oneChoice == 1){
                          cout << "******************************" << endl;
                          Game(p1, p2, p3, s1, s2, s3);
                        } else {
                          cout << "******************************" << endl;
                          Menu(p1, p2, p3, s1, s2, s3);
                        }


                } else if (p1 != "" && p2 != "" && p3 != "") {
                  cout << "******************************" << endl;

                  cout << "Max Players Reached!!" << endl;
                  cout << "<1> Continue" << endl;
                  cout << "<2> Menu" << endl;
                  cout << "Enter Choice: ";
                  cin >> oneChoice;

                  if (oneChoice == 1){
                    cout << "******************************" << endl;
                    Game(p1, p2, p3, s1, s2, s3);
                  } else {
                    cout << "******************************" << endl;
                    Menu(p1, p2, p3, s1, s2, s3);
                  }

                } else if (p1 == "" && p2 != "" && p3 == "") {

                    cout << "******************************" << endl;

                    cout << "Enter Your Name: ";
                    cin >> p1;

                      while (p1 == p2){
                        cout << "******************************" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "This name is already taken! Try again: ";
                        cin >> p1;
                      }

                    cout << "Add another Player? (Y/N): ";
                    cin >> addChoice;

                      if (addChoice == 'Y') {
                        cout << "Enter Your Name: ";
                        cin >> p3;

                          while (p3 == p1 || p3 == p2){
                            cout << "******************************" << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "This name is already taken! Try again: ";
                            cin >> p3;
                          }

                            cout << "Max Players Reached!!" << endl;
                        cout << "******************************" << endl;

                            cout << "<1> Continue" << endl;
                            cout << "<2> Menu" << endl;
                            cout << "Enter Choice: ";
                            cin >> oneChoice;

                            if (oneChoice == 1){
                              cout << "******************************" << endl;
                              Game(p1, p2, p3, s1, s2, s3);
                            } else {
                              cout << "******************************" << endl;
                              Menu(p1, p2, p3, s1, s2, s3);
                            }


                          } else {
                        cout << "******************************" << endl;
                            cout << "<1> Continue" << endl;
                            cout << "<2> Menu" << endl;
                            cout << "Enter Choice: ";
                            cin >> oneChoice;

                            if (oneChoice == 1){
                              cout << "******************************" << endl;
                              Game(p1, p2, p3, s1, s2, s3);
                            } else {
                              cout << "******************************" << endl;
                              Menu(p1, p2, p3, s1, s2, s3);
                            }
                          }
                } else if (p1 == "" && p2 == "" && p3 != "") {

                    cout << "******************************" << endl;

                    cout << "Enter Your Name: ";
                    cin >> p1;

                      while (p1 == p3){
                        cout << "******************************" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "This name is already taken! Try again: ";
                        cin >> p1;
                      }

                    cout << "Add another Player? (Y/N): ";
                    cin >> addChoice;

                      if (addChoice == 'Y') {
                        cout << "Enter Your Name: ";
                        cin >> p2;

                          while (p2 == p1 || p2 == p3){
                            cout << "******************************" << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "This name is already taken! Try again: ";
                            cin >> p2;
                          }

                            cout << "Max Players Reached!!" << endl;
                        cout << "******************************" << endl;

                            cout << "<1> Continue" << endl;
                            cout << "<2> Menu" << endl;
                            cout << "Enter Choice: ";
                            cin >> oneChoice;

                            if (oneChoice == 1){
                              cout << "******************************" << endl;
                              Game(p1, p2, p3, s1, s2, s3);
                            } else {
                              cout << "******************************" << endl;
                              Menu(p1, p2, p3, s1, s2, s3);
                            }


                          }  else {
                        cout << "******************************" << endl;
                            cout << "<1> Continue" << endl;
                            cout << "<2> Menu" << endl;
                            cout << "Enter Choice: ";
                            cin >> oneChoice;

                            if (oneChoice == 1){
                              cout << "******************************" << endl;
                              Game(p1, p2, p3, s1, s2, s3);
                            } else {
                              cout << "******************************" << endl;
                              Menu(p1, p2, p3, s1, s2, s3);
                            }
                          }

                } else if (p1 == "" && p2 != "" && p3 != "") {
                    cout << "******************************" << endl;

                    cout << "Enter Your Name: ";
                    cin >> p1;

                    while (p1 == p2 || p1 == p3){
                      cout << "******************************" << endl;
                      cin.clear();
                      cin.ignore(1000, '\n');
                      cout << "This name is already taken! Try again: ";
                      cin >> p1;
                    }

                    cout << "******************************" << endl;

                        cout << "Max Players Reached!!" << endl;
                        cout << "<1> Continue" << endl;
                        cout << "<2> Menu" << endl;
                        cout << "Enter Choice: ";
                        cin >> oneChoice;

                        if (oneChoice == 1){
                          cout << "******************************" << endl;
                          Game(p1, p2, p3, s1, s2, s3);
                        } else {
                          cout << "******************************" << endl;
                          Menu(p1, p2, p3, s1, s2, s3);
                        }


              } else if (p1 != "" && p2 == "" && p3 != "") {
                cout << "******************************" << endl;

                cout << "Enter Your Name: ";
                cin >> p2;

                while (p2 == p1 || p2 == p3){
                  cout << "******************************" << endl;
                  cin.clear();
                  cin.ignore(1000, '\n');
                  cout << "This name is already taken! Try again: ";
                  cin >> p2;
                }

                cout << "******************************" << endl;

                    cout << "Max Players Reached!!" << endl;
                    cout << "<1> Continue" << endl;
                    cout << "<2> Menu" << endl;
                    cout << "Enter Choice: ";
                    cin >> oneChoice;

                    if (oneChoice == 1){
                      cout << "******************************" << endl;
                      Game(p1, p2, p3, s1, s2, s3);
                    } else {
                      cout << "******************************" << endl;
                      Menu(p1, p2, p3, s1, s2, s3);
                    }
            break;
            case 2:

              int removeChoice;
              cout << "******************************" << endl;

              cout << "Select Player To Remove" << endl << endl;
              cout << "<1> " << p1 << endl;
              cout << "<2> " << p2 << endl;
              cout << "<3> " << p3 << endl;
              cout << "<4> Menu" << endl;
              cout << "Enter Choice: ";
              cin >> removeChoice;

                  switch (removeChoice) {
                    case 1:
                        if (p1 != "") {
                            cout << p1 << " Removed!" << endl;
                            p1 = "";
                            s1 = 0; // Reset score for player 1
                            cout << endl;
                            Menu(p1, p2, p3, s1, s2, s3);
                        } else {
                            cout << "Player 1 doesn't exist!" << endl;
                            Menu(p1, p2, p3, s1, s2, s3);
                        }
                        break;
                    case 2:
                        if (p2 != "") {
                            cout << p2 << " Removed!" << endl;
                            p2 = "";
                            s2 = 0; // Reset score for player 2
                            cout << endl;
                            Menu(p1, p2, p3, s1, s2, s3);
                        } else {
                            cout << "Player 2 doesn't exist!" << endl;
                            Menu(p1, p2, p3, s1, s2, s3);
                        }
                        break;
                    case 3:
                        if (p3 != "") {
                            cout << p3 << " Removed!" << endl;
                            p3 = "";
                            s3 = 0; // Reset score for player 3
                            cout << endl;
                            Menu(p1, p2, p3, s1, s2, s3);
                        } else {
                            cout << "Player 3 doesn't exist!" << endl;
                            Menu(p1, p2, p3, s1, s2, s3);
                        }
                        break;
                    case 4:
                        Menu(p1, p2, p3, s1, s2, s3);
                        break;
                    default:
                      while (!cin.good() || removeChoice < 1 || removeChoice > 4) {
                          cin.clear();
                          cin.ignore(1000, '\n');
                          cout << endl;
                          cout << "This is an invalid choice. Try again. " << endl;
                          cout << "******************************" << endl
                               << endl;
                          Menu(p1, p2, p3, s1, s2, s3);
                        }
                        cout << endl;
                        break;

                }
            break;
            case 3:
              Game(p1, p2, p3, s1, s2, s3);
            break;
            case 4:
              cout << "******************************" << endl << endl;
              Menu(p1, p2, p3, s1, s2, s3);
            break;
            default:
                while (!cin.good() || oneChoice < 1 || oneChoice > 3) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << endl;
                    cout << "This is an invalid choice." << endl;
                    cout << "******************************" << endl;
                    Menu(p1, p2, p3, s1, s2, s3);
                  }
                  cout << endl;

            break;
                }

          }

      break;
      case 2:
        cout << "******************************" << endl;
        cout << "You chose 2" << endl;
        cout << endl;
        rules();
        cout << "******************************" << endl;
        Menu(p1, p2, p3, s1, s2, s3);
      break;
      case 3:
        cout << "******************************" << endl;
        cout << "You chose 3" << endl;
        HighScore(p1, p2, p3, s1, s2, s3);
        cout << endl;
        cout << "******************************" << endl;
        Menu(p1, p2, p3, s1, s2, s3);

      break;
      case 4:
        cout << "******************************" << endl;
        cout << "You chose 4" << endl;
        cout << "Bye!";
        exit(0);
      break;
      default:
        while (!cin.good() || menuChoice < 1 || menuChoice > 4) {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << endl;
          cout << "This is an invalid choice." << endl;
            cout << "******************************" << endl << endl;
          Menu(p1, p2, p3, s1, s2, s3);
        }
        cout << endl;

      break;
    }

}


int main() {

  string p1, p2, p3; // variables for player names
  int s1 = 0, s2 = 0, s3 = 0; // variables for scores

  cout << "Welcome to Wordle!!!" << endl << endl; // Welcome message
  cout << "Created by:" << endl << endl;          // Our names
  cout << "Vikash Gangabissoon " << endl;
  cout << "Heidy Loaiza Miranda" << endl;
  cout << "Anindita Banik" << endl;
  cout << "Emily Badoon " << endl;
  cout << "Taron Robinson" << endl << endl;
  Menu(p1, p2, p3, s1, s2, s3);
}