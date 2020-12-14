#include "TeamOfEnemy.h"
#include "Enemy.h"
#include <iostream>
using namespace std;
TeamOfEnemy::TeamOfEnemy() {
    array = new Enemy * [4];
    for (int i = 0; i < 4; i++) array[i] = NULL;
    count = 0;
}
TeamOfEnemy::TeamOfEnemy(const TeamOfEnemy& collection) {
    this->count = collection.getCount();
    array = new Enemy * [4];
    for (int i = 1; i <= count; i++) array[i - 1] = collection.getItem(i);
    for (int i = count + 1; i <= 4; i++) array[i - 1] = NULL;
}
TeamOfEnemy::~TeamOfEnemy() {
    delALL();
}
void TeamOfEnemy::del(int pos) {
    if (pos >= 1 && pos <= 4) array[pos - 1] = NULL;
    else cout << "Incorrect position." << endl;
}
void TeamOfEnemy::delALL() {
    delete[] array;
}
void TeamOfEnemy::add(Enemy* const enemy) {
    int i = 0;
    for (i = 0; i < 4; i++) {
        if (array[i] == NULL) break;
    }
    if (i == 8) cout << "Team is full." << endl;
    else {
        array[i] = enemy;
        count++;
    }
}
Enemy* TeamOfEnemy::getItem(int pos) const {
    if (pos >= 1 && pos <= 4) return array[pos - 1];
    else {
        cout << "Incorrect position." << endl;
        return NULL;
    }
}
int TeamOfEnemy::getCount() const {
    return this->count;
}
