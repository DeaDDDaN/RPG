#pragma once
#include "Weapon.h"
class TeamOfHeroes;
class Enemy{
private:
    int HP;
    string name;
    Weapon* weapon = NULL;
    int critchance;
    string image = "";
    int scale;
public:
    virtual void attack(TeamOfHeroes* team) = 0;
    int getDamage();
    string getName();
    int getHP();
    int getCritchance();
    string getImage();
    Weapon* getWeapon();
    int getScale();
    void setScale(int scale);
    void setName(string name);
    void setHP(const int hp);
    void setCritchance(const int crit);
    void setWeapon(Weapon* weapon);
    void setImage(const string image);
    void takeDamage(const int damage);
};

