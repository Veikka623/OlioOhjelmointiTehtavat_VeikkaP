#ifndef CHEF_H
#define CHEF_H

#include <iostream>
#include <string>
using namespace std;

class Chef {
public:
    Chef(std::string chefName);
    ~Chef();
    std::string getName() const;
    int makeSalad(int ingredients) const;
    int makeSoup(int ingredients) const;

private:

protected:
    std::string chefName;
};


#endif // CHEF_H
