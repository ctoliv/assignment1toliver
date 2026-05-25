#ifndef LOGIC_H
#define LOGIC_H

#include <string>
using namespace std;

class logic
{
public:
    // Constructor sets all starting values
    logic();

    // Prints the introduction and rules for the game
    void introduction();

    // Reads dictionary.txt and separates words into three arrays
    bool createLists();

    // Gets the correct word list based on the current round
    string getWordForRound(int round);

    // Scrambles the letters of a word
    string scrambler(string word);

    // Checks the player's answer and updates the score
    void checkAnswer(string correctWord, string userAnswer, int secondsUsed, int timeLimit);

    // Displays the final score and intellect rating
    void end();

private:
    // Tracks how many words the player answers correctly
    int numCorrect;

    // Tracks how many words are stored in each word array
    int smallWordLength;
    int mediumWordLength;
    int largeWordLength;

    // Stores words by length
    string smallWords[50];   // 4-5 letter words
    string mediumWords[50];  // 6-7 letter words
    string largeWords[50];   // 8 or more letter words

    // Tracks which words have already been used
    bool smallUsed[50];
    bool mediumUsed[50];
    bool largeUsed[50];

    // Cleans a word by removing non-letters and making it lowercase
    string cleanWord(string word);

    // Gets a random unused word from a given array
    string getRandomWord(string words[], bool used[], int length);
};

#endif