#pragma once
#include "Magic.h"
#include "Weapon.h"
#include "Enemy.h"
#include "TeamOfEnemy.h"
#include <string>
#include <iostream>

class Hero {
private:
    string name;
    int health;
    Weapon* weapon;
    BookOfMagic* book;
    int maxHealth;
    bool attacked = false;
public:
    Hero();
    Hero(string name, int health, Weapon* weapon, BookOfMagic* book);
    virtual void attack(Enemy* enemy) = 0;
    void changeHealth(int change);
    void useSpell(int pos, Hero* hero = NULL, Enemy* enemy = NULL, TeamOfHeroes* team1 = NULL, TeamOfEnemy*  team2 = NULL);
    string getName() const;
    int getHealth() const;
    Weapon* getWeapon() const;
    BookOfMagic* getBook() const;
    int getMaxHealth() const;
    bool getAttacked();
    void setName(const string name);
    void setHealth(const int health);
    void setWeapon(Weapon* weapon);
    void setBookOfMagic(BookOfMagic* book);
    void setMaxHealth(int maxHealth);
    void setAttacked();

};

class TeamOfHeroes {
private:
    Hero** list;
    int count;
public:
    TeamOfHeroes(const int count);
    TeamOfHeroes(TeamOfHeroes& team);
    ~TeamOfHeroes();
    Hero* getItem(int pos) const;
    void add(Hero* const hero, int pos);
    void del(int pos);
    int getCount() const;
};

