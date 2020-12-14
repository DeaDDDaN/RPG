#include "Heroes.h"

Hero::Hero() {
    name = "No";
    health = 0;
    weapon = NULL;
    book = NULL;
}

void Hero::setWeapon(Weapon* weapon_) {
    weapon = weapon_;
}

void Hero::setBookOfMagic(BookOfMagic* book_) {
    book = book_;
}

void Hero::setName(const string name_) {
    name = name_;
}

void Hero::setHealth(const int health_) {
    health = health_;
}

Hero::Hero(string name_, int health_, Weapon* weapon_, BookOfMagic* book_) {
    name = name_;
    health = health_;
    weapon = weapon_;
    book = book_;
}

string Hero::getName() const {
    return name;
}

int Hero::getHealth() const {
    return health;
}

Weapon* Hero::getWeapon() const {
    return weapon;
}

BookOfMagic* Hero::getBook() const {
    return book;
}

void Hero::useSpell(int pos, Hero* hero, Enemy* enemy, TeamOfHeroes* team1, TeamOfEnemy* team2) {
    if (!book->get(pos)->recharge) {
        if (team1 == NULL || team2 == NULL) {
            if (hero != NULL && enemy == NULL)
                book->get(pos)->spell->targetSpell(hero);

            if (hero == NULL && enemy != NULL)
                book->get(pos)->spell->targetSpell(NULL, enemy);
        }
        else {
            if (team1 != NULL && team2 == NULL)
                book->get(pos)->spell->massSpell(team1);

            if (team1 == NULL && team2 != NULL)
                book->get(pos)->spell->massSpell(NULL, team2);
        }
        book->get(pos)->recharge = true;
    }
}

void Hero::changeHealth(int change) {
    if (this->getHealth() + change < 0)
        this->setHealth(0);
    else if (this->getHealth() + change > maxHealth)
        this->setHealth(maxHealth);
    else
        this->setHealth(this->getHealth() + change);
}

int Hero::getMaxHealth() const{
    return maxHealth;
}

void Hero::setMaxHealth(int maxHealth_){
    maxHealth = maxHealth_;
}

TeamOfHeroes::TeamOfHeroes(const int count) {
    if (count >= 1 && count <= 4)
    list = new Hero*[count];
}

TeamOfHeroes::TeamOfHeroes(TeamOfHeroes& team) {
    count = team.getCount();
    list = new Hero * [count];
    for (int i = 1; i <= count; i++)
        list[i] = team.getItem(i);
}

TeamOfHeroes::~TeamOfHeroes() {
    delete[] list;
}

Hero* TeamOfHeroes::getItem(int pos) const {
    if (pos >= 1 && pos <= 4)
        return list[pos - 1];
    else
        return NULL;
}

void TeamOfHeroes::add(Hero* const hero, int pos) {
    if (pos >= 1 && pos <= 4)
        list[pos - 1] = hero;
}

void TeamOfHeroes::del(int pos) {
    if (pos >= 1 && pos <= 4)
        list[pos - 1] = NULL;
}

int TeamOfHeroes::getCount() const {
    return count;
}
bool Hero::getAttacked(){
    return this->attacked;
}
void Hero::setAttacked(){
    if (this->attacked == false) this->attacked = true;
    else this->attacked = false;
}



