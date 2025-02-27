#include "ItalianChef.h"

int main() {
    // Luodaan Chef ja ItalianChef
    Chef basicChef("Gordon");
    ItalianChef italianChef("Mario");

    // Testataan Chef-luokan toimintoja
    basicChef.makeSalad(10);  // 2 salaattia
    basicChef.makeSoup(9);    // 3 keittoa

    // Testataan ItalianChef-luokan toimintoja
    italianChef.askSecret("wrong", 10, 10); // Väärä salasana, ei pizzaa
    italianChef.askSecret("pizza", 10, 10); // Oikea salasana, 2 pizzaa

    return 0;
}
