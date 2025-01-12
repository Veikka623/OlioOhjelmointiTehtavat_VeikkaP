#include <iostream>
#include <cstdlib>
using namespace std;

int game(int maxnum) {
    srand(time(0));
    float arvaus = 0;
    int random = std::rand() % maxnum;
    int lasku = 0;
    while (arvaus != random) {
        cout << "Arvaa luku 1 ja " << maxnum << ":n valilta: " << endl;
        cin >> arvaus;
        if (arvaus < random) {
            cout << "Luku on suurempi." << endl;
        }
        else if (arvaus > random) {
            cout << "Luku on pienempi." << endl;
        }
        else if (arvaus == random) {
            cout << "Oikea vastaus!" << endl;
        }
        lasku++;
    }
    cout << "Arvausten maara oli " << lasku << endl;
    return 0;
}

int main()
{
    game(45);
}

