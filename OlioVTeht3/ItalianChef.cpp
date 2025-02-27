#include "ItalianChef.h"

ItalianChef::ItalianChef(std::string name) : Chef(name), flour(0), water(0) {
    std::cout << "ItalianChef " << chefName << " created.\n";
}

ItalianChef::~ItalianChef() {
    std::cout << "ItalianChef " << chefName << " destroyed.\n";
}

bool ItalianChef::askSecret(std::string pw, int flourAmount, int waterAmount) {
    if (pw == password) {
        flour = flourAmount;
        water = waterAmount;
        int pizzas = makePizza();
        std::cout << "Chef " << chefName << " made " << pizzas << " pizzas.\n";
        return true;
    } else {
        std::cout << "Wrong password!\n";
        return false;
    }
}

int ItalianChef::makePizza() {
    int possiblePizzas = std::min(flour / 5, water / 5);
    flour -= possiblePizzas * 5;
    water -= possiblePizzas * 5;
    return possiblePizzas;
}
