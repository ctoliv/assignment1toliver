#include "logic.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Constructor initializes score, word counts, and used-word arrays
logic::logic()
{
    numCorrect = 0;
    smallWordLength = 0;
    mediumWordLength = 0;
    largeWordLength = 0;

    // Set all words as unused at the start of the game
    for (int i = 0; i < 50; i++)
    {
        smallUsed[i] = false;
        mediumUsed[i] = false;
        largeUsed[i] = false;
    }

    // Seed random number generator
    srand((unsigned int)time(NULL));
}

// Prints the game introduction and rules
void logic::introduction()
{
    cout << "Welcome to the Word Intellect Challenge!" << endl;
    cout << "You will unscramble five words." << endl;
    cout << "The first two words are shorter words." << endl;
    cout << "The next two words are medium length words." << endl;
    cout << "The final word is a longer word." << endl;
    cout << "You have 60 seconds for each word." << endl;
    cout << "Good luck!" << endl;
}

// Reads dictionary.txt and sorts words into small, medium, and large arrays
bool logic::createLists()
{
    ifstream file("dictionary.txt");

    // Return false if the dictionary file cannot be opened
    if (!file)
    {
        return false;
    }

    string word;

    // Read each word from the dictionary file
    while (file >> word)
    {
        word = cleanWord(word);
        int length = (int)word.length();

        // Store 4-5 letter words in the small word array
        if (length >= 4 && length <= 5 && smallWordLength < 50)
        {
            smallWords[smallWordLength] = word;
            smallWordLength++;
        }
        // Store 6-7 letter words in the medium word array
        else if (length >= 6 && length <= 7 && mediumWordLength < 50)
        {
            mediumWords[mediumWordLength] = word;
            mediumWordLength++;
        }
        // Store 8 or more letter words in the large word array
        else if (length >= 8 && largeWordLength < 50)
        {
            largeWords[largeWordLength] = word;
            largeWordLength++;
        }
    }

    file.close();

    // Make sure there are enough words to play the full game
    if (smallWordLength < 2 || mediumWordLength < 2 || largeWordLength < 1)
    {
        cout << "The dictionary does not have enough words for the assignment." << endl;
        return false;
    }

    return true;
}

// Gets the correct word type depending on the round number
string logic::getWordForRound(int round)
{
    // Rounds 1 and 2 use small words
    if (round == 1 || round == 2)
    {
        return getRandomWord(smallWords, smallUsed, smallWordLength);
    }
    // Rounds 3 and 4 use medium words
    else if (round == 3 || round == 4)
    {
        return getRandomWord(mediumWords, mediumUsed, mediumWordLength);
    }
    // Round 5 uses a large word
    else
    {
        return getRandomWord(largeWords, largeUsed, largeWordLength);
    }
}

// Selects a random unused word from a word array
string logic::getRandomWord(string words[], bool used[], int length)
{
    int index = rand() % length;

    // Keep choosing until an unused word is found
    while (used[index])
    {
        index = rand() % length;
    }

    used[index] = true;
    return words[index];
}

// Scrambles the letters of a word
string logic::scrambler(string word)
{
    string scrambled = word;

    random_device rd;
    mt19937 generator(rd());

    // Try to make sure the scrambled word is different from the original
    for (int i = 0; i < 10 && scrambled == word; i++)
    {
        shuffle(scrambled.begin(), scrambled.end(), generator);
    }

    return scrambled;
}

// Checks the player's answer against the correct word and time limit
void logic::checkAnswer(string correctWord, string userAnswer, int secondsUsed, int timeLimit)
{
    // Clean the player's answer before comparing it
    userAnswer = cleanWord(userAnswer);

    // If the player took too long, the answer is incorrect
    if (secondsUsed > timeLimit)
    {
        cout << "Too slow! You took " << secondsUsed << " seconds." << endl;
        cout << "The correct word was: " << correctWord << endl;
    }
    // If the answer matches, increase the score
    else if (userAnswer == correctWord)
    {
        cout << "Correct! You solved it in " << secondsUsed << " seconds." << endl;
        numCorrect++;
    }
    // Otherwise, the answer is incorrect
    else
    {
        cout << "Incorrect. The correct word was: " << correctWord << endl;
    }
}

// Displays final score and intellect rating
void logic::end()
{
    cout << endl;
    cout << "Game Over!" << endl;
    cout << "You got " << numCorrect << " out of 5 correct." << endl;

    if (numCorrect <= 1)
    {
        cout << "Intellect Rating: Sleepy Pebble Mind" << endl;
        cout << "Your brain is still warming up. Try again!" << endl;
    }
    else if (numCorrect == 2)
    {
        cout << "Intellect Rating: Wandering Goblin Mind" << endl;
        cout << "You solved a few, but the words fought back." << endl;
    }
    else if (numCorrect == 3)
    {
        cout << "Intellect Rating: Clever Apprentice Mind" << endl;
        cout << "Not bad. Your word magic is getting stronger." << endl;
    }
    else if (numCorrect == 4)
    {
        cout << "Intellect Rating: Scholar of Scrambles" << endl;
        cout << "Great job. Your intellect is sharp." << endl;
    }
    else
    {
        cout << "Intellect Rating: Grand Master Word Sage" << endl;
        cout << "Perfect score! Your intelligence is legendary." << endl;
    }
}

// Cleans a word by keeping only letters and converting to lowercase
string logic::cleanWord(string word)
{
    string cleaned = "";

    for (char c : word)
    {
        if (isalpha(c))
        {
            cleaned += (char)tolower(c);
        }
    }

    return cleaned;
}