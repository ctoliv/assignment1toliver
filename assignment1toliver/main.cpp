#include <iostream>
#include <string>
#include <chrono>
#include "logic.h"

using namespace std;

int main()
{
    // Create the game object from the logic class
    logic game;

    // Display the game introduction to the player
    game.introduction();

    // Load the dictionary file and create the word lists
    if (!game.createLists())
    {
        cout << "Could not load dictionary.txt. Make sure it is in the project folder." << endl;
        return 1;
    }

    // Each player has 60 seconds to answer each word
    const int TIME_LIMIT = 60;

    // The game has five total rounds
    for (int round = 1; round <= 5; round++)
    {
        // Get the correct word for the current round
        string word = game.getWordForRound(round);

        // Scramble the word before showing it to the player
        string scrambled = game.scrambler(word);

        cout << endl;
        cout << "Round " << round << " of 5" << endl;
        cout << "Unscramble this word: " << scrambled << endl;
        cout << "You have 60 seconds." << endl;
        cout << "Your answer: ";

        // Start the timer before the player enters an answer
        auto start = chrono::steady_clock::now();

        string answer;
        getline(cin, answer);

        // Stop the timer after the player enters an answer
        auto end = chrono::steady_clock::now();

        // Calculate how many seconds the player used
        int secondsUsed = (int)chrono::duration_cast<chrono::seconds>(end - start).count();

        // Check if the answer was correct and within the time limit
        game.checkAnswer(word, answer, secondsUsed, TIME_LIMIT);
    }

    // Display the final score and intellect rating
    game.end();

    cout << endl << "Press Enter to exit...";
    cin.get();

    return 0;
}