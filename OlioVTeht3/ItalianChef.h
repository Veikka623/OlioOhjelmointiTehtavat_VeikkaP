#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "Chef.h"
#include <iostream>
#include <string>
using namespace std;
class ItalianChef : public Chef {

public:
    ItalianChef(std::string);
    ~ItalianChef();
    bool askSecret(std::string pw, int flourAmount, int waterAmount);
private:
    int flour;
    int water;
    std::string password = "pizza";
    int makePizza();

};
#endif // ITALIANCHEF_H
