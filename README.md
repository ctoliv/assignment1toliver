# Assignment 1 - Word Intellect Challenge

This repository contains my Game Programming Assignment 1 project for CPSC 440.

## Description

This program is a C++ console game where the player unscrambles five words. The program reads words from `dictionary.txt`, separates them into different word-length groups, scrambles selected words, and gives the player 60 seconds to answer each one.

At the end of the game, the player receives an intellect rating based on how many words they unscrambled correctly.

## Word Groups

The program separates words into three arrays:

- Small words: 4-5 letters
- Medium words: 6-7 letters
- Large words: 8 or more letters

The game uses:

- First two rounds: small words
- Next two rounds: medium words
- Final round: large word

## Features

- Reads words from `dictionary.txt`
- Stores words in three separate arrays
- Randomly selects words for each round
- Scrambles each selected word
- Gives the player 60 seconds per word
- Tracks correct answers
- Displays a final intellect rating
- Separates `main.cpp` from the game logic files

## Project Files

- `main.cpp` - Starts the program, runs the five rounds, and handles the timer
- `logic.h` - Defines the game logic class and function names
- `logic.cpp` - Contains the game logic, word loading, scrambling, answer checking, and final rating
- `dictionary.txt` - Contains the words used by the game

## How to Run

1. Open `assignment1toliver.sln` in Visual Studio.
2. Make sure `dictionary.txt` is included in the project folder.
3. Build the project.
4. Run the program.
5. Type the unscrambled word for each round.

## Author

Christian Toliver
