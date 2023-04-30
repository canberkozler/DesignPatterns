#include"spawner.h"

int main() {
	DogSpawner ds;
	CatSpawner cs;
	MouseSpawner ms;

	Creature* creature[3]{nullptr, nullptr, nullptr };

	creature[0] = ds.spawnCreature();
	creature[1] = cs.spawnCreature();
	creature[2] = ms.spawnCreature();
	
	for (size_t i{ 0 }; i < std::size(creature); ++i) {
		if (Dog* dog = dynamic_cast<Dog*>(creature[i]); dog) {
			dog->Bark();
			
		}
		else if (Cat* cat = dynamic_cast<Cat*>(creature[i]); cat) {
			cat->Meow();
		}
		else if (Mouse* mouse = dynamic_cast<Mouse*>(creature[i]); mouse) {
			mouse->Squeak();
		}
	}

	// Spawn a bunch of dogs test

	std::vector<Creature*> dogPack;

	ds.spawnPack(dogPack);

	for (const auto& thing: dogPack) {
		if (Dog* dog = dynamic_cast<Dog*>(thing); dog) {
			dog->Bark();
		}
		else if (Cat* cat = dynamic_cast<Cat*>(thing); cat) {
			cat->Meow();
		}
		else if (Mouse* mouse = dynamic_cast<Mouse*>(thing); mouse) {
			mouse->Squeak();
		}
	}

	// clone test
	LizardSpawner ls;

	Creature* lizard = ls.spawnCreature();

	if (Lizard* lz = dynamic_cast<Lizard*>(lizard); lz) {
		lz->Hiss();

		Creature* clone_lz = lizard->Clone();
		if (Lizard* clz = dynamic_cast<Lizard*>(clone_lz); clz) {
			clz->Hiss();
		}
	}
}