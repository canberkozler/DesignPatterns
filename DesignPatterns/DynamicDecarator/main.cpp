#include <iostream>
#include "item.h"


int main() {
	ConcreteWeapon weapon1("Basic Sword", 3);
	MagicDecorator magic_weapon1(&weapon1, 2);
	MagicDecorator x2_magic_weapon1(&magic_weapon1, 2);


	magic_weapon1.setName("Armageddon");

	std::cout << weapon1.getName() << " damage: " << weapon1.getDamage() << '\n';
	std::cout << magic_weapon1.getName() << " damage: " << (weapon1.getDamage() + magic_weapon1.getMagicMod()) << '\n';
	std::cout << x2_magic_weapon1.getName() << " damage: " << (weapon1.getDamage() + x2_magic_weapon1.getMagicMod()) << '\n';


	/*
	MagicWeapon weapon2("Magic Sword", 3, 2);
	std::cout << weapon2.getName() << " damage: " << weapon2.getDamage() << '\n';*/
}