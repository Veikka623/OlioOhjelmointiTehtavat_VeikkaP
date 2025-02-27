#include "chef.h"



Chef::Chef(std::string chefName) {
    std::cout << "Chef" << chefName << "created." << endl;
}

Chef::~Chef() {
    std::cout << "Chef " << chefName << " destroyed.\n";
}

std::string Chef::getName() const {
    return chefName;
}


int Chef::makeSalad(int ingredients) const {

    int amount = ingredients / 5;
    std::cout << "Chef " << chefName << " made " << amount << " salads.\n";
    return amount;
}


int Chef::makeSoup(int ingredients) const {
    int amount = ingredients / 3;
    std::cout << "Chef " << chefName << " made " << amount << " soups.\n";
    return amount;
}



