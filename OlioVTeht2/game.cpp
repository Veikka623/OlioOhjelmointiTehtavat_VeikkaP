#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Game::Game(int max) {
    maxNumber = max;
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
    numOfGuesses = 0;
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value." << endl;
}


Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory." << endl;
}


void Game::play() {
    cout << "Give your guess between 1-" << maxNumber << endl;

    do {
        cout << "Your guess: ";
        cin >> playerGuesses;
        numOfGuesses++;

        if (playerGuesses < randomNumber) {
            cout << "Your guess is too small." << endl;
        } else if (playerGuesses > randomNumber) {
            cout << "Your guess is too big." << endl;
        } else {
            cout << "Your guess is right = " << playerGuesses << endl;
        }
    } while (playerGuesses != randomNumber);
}


void Game::printGameResult() {
    cout << "You guessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses." << endl;
}
