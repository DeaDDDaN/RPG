#include "EnemyTypes.h"
#include "Heroes.h"

Witch::Witch() {
    this->setName("Witch");
    this->setHP(200);
    this->book = NULL;
    this->setCritchance(10);
    this->setImage(":/resource/Images/witch.png");
    this->setScale(120);
}
void Witch::attack(TeamOfHeroes* team) {
    int crit = rand() % 10 + 1;
    if (crit <= this->getCritchance() / 10){
        crit = this->getDamage() * 0.5;
    }
    else{
        crit = 0;
    }
    int choice = rand() % 5 + 1;
    if (choice > 3) {
        choice = rand() % 4 + 1;
        Hero* hero = team->getItem(choice);
        while(hero == NULL){
            choice = rand() % 4 + 1;
            hero = team->getItem(choice);
        }
        choice = rand() % book->getCount() + 1;
        Spell* spell = ((this->book)->get(choice))->spell;
        if (spell->identification() == 0){
            spell->targetSpell(hero);
            cout << "shitmagic" << endl;
        }
        else{
            spell->massSpell(team);
        }
    }
    else {
        int choice = rand() % 4 + 1;
        Hero* hero = team->getItem(choice);
        while(hero == NULL){
            choice = rand() % 4 + 1;
            hero = team->getItem(choice);
        }
        hero->changeHealth(-(this->getDamage() + crit));
    }
}
void Witch::setBook(BookOfMagic* book){
    this->book = book;
}
BookOfMagic* Witch::getBook() const{
    return this->book;
}

Skeleton::Skeleton() {
    this->setName("Skeleton");
    this->setHP(300);
    this->setCritchance(20);
    this->setImage(":/resource/Images/skeleton.png");
    this->setScale(160);
}
void Skeleton::attack(TeamOfHeroes* team) {
    int crit = rand() % 10 + 1;
    if (crit <= this->getCritchance() / 10){
        crit = this->getDamage() * 0.5;
    }
    else{
        crit = 0;
    }
    int choice = rand() % 4 + 1;
    cout << "shit1" << endl;
    Hero* hero = team->getItem(choice);
    cout << "shit12" << endl;
    while(hero == NULL){
        cout << "shitw12" << endl;
        choice = rand() % 4 + 1;
        hero = team->getItem(choice);
    }
    cout << "shit" << endl;
    hero->changeHealth(-(this->getDamage() + crit));
    cout << "shit3" << endl;
}

Orc::Orc() {
    this->setName("Orc");
    this->setHP(500);
    this->setCritchance(20);
    this->setImage(":/resource/Images/orc.png");
    this->setScale(160);
}
void Orc::attack(TeamOfHeroes* team) {
    int crit = rand() % 10 + 1;
    if (crit <= this->getCritchance() / 10){
        crit = this->getDamage();
    }
    else{
        crit = 0;
    }
    int choice = rand() % 4 + 1;
    Hero* hero = team->getItem(choice);
    while(hero == NULL){
        choice = rand() % 4 + 1;
        hero = team->getItem(choice);
    }
    hero->changeHealth(-(this->getDamage() + crit));
}

Goblin::Goblin() {
    this->setName("Goblin");
    this->setHP(350);
    this->setCritchance(10);
    this->setImage(":/resource/Images/goblin.png");
    this->setScale(130);
}
void Goblin::attack(TeamOfHeroes* team) {
    int crit = rand() % 10 + 1;
    if (crit <= this->getCritchance() / 10){
        crit = this->getDamage();
    }
    else{
        crit = 0;
    }
    int choice = rand() % 4 + 1;
    Hero* hero = team->getItem(choice);
    while(hero == NULL){
        choice = rand() % 4 + 1;
        hero = team->getItem(choice);
    }
    hero->changeHealth(-(this->getDamage() + crit));
}
