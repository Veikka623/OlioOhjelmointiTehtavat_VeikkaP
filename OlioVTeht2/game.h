#ifndef GAME_H
#define GAME_H

class Game
{
public:

    Game(int max);
    ~Game();
    void play();
    void printGameResult();
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;
    void printGameResult();

protected:


};



#endif // GAME_H
