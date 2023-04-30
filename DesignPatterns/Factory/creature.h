#pragma once
#include<iostream>

class Creature {
public:
	virtual ~Creature(){}
	virtual Creature* Clone() { return nullptr; }

	Creature() = default;
	Creature(int hp, int speed, int attack) : HitPoints{ hp }, Speed{ speed }, Attack{ attack } {}

	int getHP() const { return HitPoints; }
	int getSpeed() const { return Speed; }
	int getAttack() const { return Attack; }
protected:
	int HitPoints{ 0 };
	int Speed{ 0 };
	int Attack{ 0 };
};

class Dog : public Creature {
public:
	Dog() { HitPoints = 3; Speed = 3; Attack = 3; }

	void Bark() const { std::cout << "Woof!!\n"; }
};
class Cat : public Creature {
public: 
	Cat() { HitPoints = 2; Speed = 2; Attack = 2; }

	void Meow() const { std::cout << "Meow!!\n"; }
};
class Mouse : public Creature {
public:
	Mouse() { HitPoints = 1; Speed = 1; Attack = 1; }
	void Squeak() const { std::cout << "eekeekek!!\n"; }
};

// Prototype Creature

class Lizard : public Creature {
public:
	Lizard(int hp, int speed, int attack) : Creature{ hp , speed, attack} {}

	Creature* Clone() { return new Lizard( HitPoints, Speed, Attack ); }

	void Hiss() const { std::cout << "sssssssssssssssss\n"; }
};