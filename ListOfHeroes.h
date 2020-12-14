#pragma once
#include "Heroes.h"
#include "Enemy.h"
#include "Constants.h"


class Warrior : public Hero {
public:

    Warrior() : Hero() {};

	Warrior(string name, int health, Weapon* weapon, BookOfMagic* book) : Hero(name, health, weapon, book) {};

	void attack(Enemy* enemy) {
        enemy->takeDamage(getWeapon()->getDamage());
        this->setAttacked();
	}

};

class Archer : public Hero {
public:

    Archer () : Hero() {};

    Archer (string name, int health, Weapon* weapon, BookOfMagic* book) : Hero(name, health, weapon, book) {};

    void attack(Enemy* enemy) {
        enemy->takeDamage(getWeapon()->getDamage());
        this->setAttacked();
    }

};

class Wizard : public Hero {
public:

    Wizard () : Hero() {};

    Wizard (string name, int health, Weapon* weapon, BookOfMagic* book) : Hero(name, health, weapon, book) {};

    void attack(Enemy* enemy) {
        enemy->takeDamage(getWeapon()->getDamage());
        this->setAttacked();
    }

};

class Priest : public Hero {
public:

    Priest() : Hero() {};

    Priest(string name, int health, Weapon* weapon, BookOfMagic* book) : Hero(name, health, weapon, book) {};

    void attack(Enemy* enemy) {
        enemy->takeDamage(getWeapon()->getDamage());
        this->setAttacked();
    }

};
