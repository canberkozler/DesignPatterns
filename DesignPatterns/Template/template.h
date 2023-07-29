#pragma once
#include <iostream>
#include "rand.h"

class IAbstractAI {
public:
	void base_operation() {
		scan_map();
		move_unit();
		attack();
	}

protected:
	void scan_map() {
		//std::cout << "base ai - scan map\n";
		Scanner();
	}

	void move_unit() {
		//std::cout << "base ai - move unit\n";
		Mover();
	}

	void attack() {
		//std::cout << "base ai - attack\n";
		special_attack();
	}

	virtual void Scanner() = 0;
	virtual void Mover() = 0;
	virtual void special_attack() = 0;

	virtual void special1() {}
};


class RangedAlly : public IAbstractAI {
protected:
	virtual void Scanner() override {
		std::cout << "RangedAlly SCANNER\n";
		EnemyInSight = (bool)ZOOR();
		if (EnemyInSight) {
			std::cout << " - Finds enemy in sight...\n";
		}
		else {
			std::cout << " - no enemy in sight...\n";

		}
	}

	virtual void Mover() override {
		if (EnemyInSight) {
			std::cout << " - moves to attack range\n";
			EnemyInRange = true;
		}
	}

	virtual void special_attack() override {
		if (EnemyInSight && EnemyInRange) {
			std::cout << " - fires weapon\n";
			special1();
		}
	}

	// attack with possible crit chance special
	virtual void special1() override {
		if (amount_bullets < 1) {
			reload();
		}
		else {
			auto roll = NTKR(1, 100);
			if (roll > 67) {
				std::cout << " - crits!\n";
			}
			else if (roll > 33) {
				std::cout << " - hits!\n";
			}
			else {
				std::cout << " - misses!\n";
			}
		}
	}


private:
	bool EnemyInSight = false;
	bool EnemyInRange = false;

	int amount_bullets = 4;

	void reload() {
		amount_bullets = 4;
	}
};
