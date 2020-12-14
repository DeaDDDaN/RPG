#pragma once
#include "Heroes.h"
#include "Enemy.h"

using namespace std;

class Fireball : public Spell {
public:
	Fireball() : Spell() {};
	Fireball(string name) : Spell(name) {};
	void targetSpell(Hero* const hero, Enemy* const enemy);
	void massSpell(TeamOfHeroes* const team1, TeamOfEnemy* const team2) {} ;
	int identification() { return 0; };
};

class Treatment : public Spell {
public:
	Treatment() : Spell() {};
	Treatment(string name) : Spell(name) {};
	void targetSpell(Hero* const hero, Enemy* const enemy);
	void massSpell(TeamOfHeroes* const team1, TeamOfEnemy* const team2) {};
	int identification() { return 1; };
};

