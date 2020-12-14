#pragma once
#include <string>
using namespace std;
class Weapon {
private:
    string name;
    int damage;
    string image;
public:
    Weapon();
    Weapon(const string name, const int damage, const string image);
    Weapon(const Weapon& weapon);
    string getName() const;
    int getDamage() const;
    string getImage() const;
    void setName(const string name);
    void setDamage(const int damage);
};
