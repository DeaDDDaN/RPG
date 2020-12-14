#include "ListOfSpells.h"

void Fireball::targetSpell(Hero* hero, Enemy* enemy) {
    hero->changeHealth(-50);
}

void Treatment::targetSpell(Hero* hero, Enemy* enemy = NULL) {
	hero->changeHealth(50);
}

