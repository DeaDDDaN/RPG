#pragma once
#include "Weapon.h"
struct ListofWeapons {
    Weapon weapon;
    ListofWeapons* next, * prev;
};

class WeaponCollection {
private:
    ListofWeapons* object;
    int count;
public:
    WeaponCollection();
    WeaponCollection(const WeaponCollection& collection);
    ~WeaponCollection();
    void del(int pos);
    void delALL();
    void add(const Weapon& weapon);
    int getCount() const;
    ListofWeapons* getItem(int pos) const;
};

