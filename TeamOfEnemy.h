#pragma once
#include "Enemy.h"
class TeamOfEnemy{
private:
    Enemy** array;
    int count;
public:
    TeamOfEnemy();
    TeamOfEnemy(const TeamOfEnemy& collection);
    ~TeamOfEnemy();
    void del(int pos);
    void delALL();
    void add(Enemy* const enemy);
    int getCount() const;
    Enemy* getItem(int pos) const;
};

