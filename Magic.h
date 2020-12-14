#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"
#include "Enemy.h"
#include "TeamOfEnemy.h"

class Hero;
class TeamOfHeroes;

using namespace std;

class Spell {
private:
    string name;
public:
    Spell();
    Spell(string name_);
    void setName(const string name_);
    string getName() const;
    virtual void targetSpell(Hero* const hero = NULL, Enemy* const enemy = NULL) = 0;
    virtual void massSpell(TeamOfHeroes* const team1 = NULL , TeamOfEnemy* const team2 = NULL) = 0;
    virtual int identification() = 0; //0 - targetSpell, 1 - massSpell
};

struct ListElement {
    Spell* spell;
    int rechargeTime;
    int curRechargeTime = 0;
    bool recharge = false;
    ListElement* next, * prev;
};

class BookOfMagic {

private:
    ListElement* head, * tail;
    int count;
public:
    BookOfMagic();
    BookOfMagic(const BookOfMagic& book);
    ~BookOfMagic();
    void del(int pos);
    void delAll();
    void addEnd(Spell* const spell, int rechargeTime);
    ListElement* get(int pos) const;
    int getCount() const;
    void renewTime();
};

