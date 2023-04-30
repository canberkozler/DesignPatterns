#pragma once
#include"creature.h"
#include<vector>
class Spawner {
public:
	virtual ~Spawner(){}
	virtual Creature* spawnCreature() const = 0;
};

class DogSpawner : public Spawner {
public:
	Creature* spawnCreature() const override { return new Dog(); }

	void spawnPack(std::vector<Creature*>& out_pack) const {
		for (size_t i{ 0 }; i < 5 ; ++i) {
			out_pack.emplace_back(new Dog());
		}
	}
};
class CatSpawner : public Spawner {
public:
	Creature* spawnCreature() const override { return new Cat(); }
};
class MouseSpawner : public Spawner {
public:
	Creature* spawnCreature() const override { return new Mouse(); }
};

class LizardSpawner : public Spawner {
public:
	Creature* spawnCreature() const override { return new Lizard(22,3,2); }
};

