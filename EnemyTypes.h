#pragma once
#include "Enemy.h"
#include "Magic.h"

class Witch : public Enemy {
private:
    BookOfMagic* book;
public:
    Witch();
    void attack(TeamOfHeroes* team) override;
    void setBook(BookOfMagic* book);
    BookOfMagic* getBook() const;
};

class Skeleton : public Enemy {
public:
    Skeleton();
    void attack(TeamOfHeroes* team) override;
};

class Orc : public Enemy {
public:
    Orc();
    void attack(TeamOfHeroes* team) override;
};

class Goblin : public Enemy {
public:
    Goblin();
    void attack(TeamOfHeroes* team) override;
};

