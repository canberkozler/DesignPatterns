#include "facade.h"
#include <iostream>

// client test
int main() {
    ArmorBuilderFacade abf;

    std::cout << abf.getHeavyArmor() << '\n';
    std::cout << abf.getMediumArmor() << '\n';
    std::cout << abf.getLightArmor() << '\n';

}