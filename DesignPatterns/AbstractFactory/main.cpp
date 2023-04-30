#include <iostream>
#include "characterfactory.h"

//abstract factory
int main() {
    if (PlayerCharacter* Bob_The_Rogue = CharacterFactory::create("Rogue"); Bob_The_Rogue) {
        std::cout << "classname: " << Bob_The_Rogue->getClass() << '\n';
        std::cout << "hp: " << Bob_The_Rogue->getHP() << '\n';
        std::cout << "armor: " << Bob_The_Rogue->getArmor() << '\n';
        std::cout << "weapon: " << Bob_The_Rogue->getWeapon() << '\n';
        delete Bob_The_Rogue;
    }
        
    if (PlayerCharacter* Chet_The_Warrior = CharacterFactory::create("Warrior");  Chet_The_Warrior) {
        std::cout << "classname: " << Chet_The_Warrior->getClass() << '\n';
        std::cout << "hp: " << Chet_The_Warrior->getHP() << '\n';
        std::cout << "armor: " << Chet_The_Warrior->getArmor() << '\n';
        std::cout << "weapon: " << Chet_The_Warrior->getWeapon() << '\n';
        delete Chet_The_Warrior;
    }
}