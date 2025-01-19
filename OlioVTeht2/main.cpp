#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    int max;
    cout << "Anna suurin arvottava luku: ";
    cin >> max;


    Game game(max);


    game.play();


    game.printGameResult();

    return 0;
}
