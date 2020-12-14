#include "Weapon.h"
#include <string>
using namespace std;
Weapon::Weapon() {
    this->name = "";
    this->damage = 0;
}
Weapon::Weapon(const string name, const int damage, const string image) {
    this->name = name;
    this->damage = damage;
    this->image = image;
}
Weapon::Weapon(const Weapon& weapon) {
    this->damage = weapon.getDamage();
    this->name = weapon.getName();
    this->image = weapon.getImage();
}
string Weapon::getName() const{
    return this->name;
}
int Weapon::getDamage() const {
    return this->damage;
}
string Weapon::getImage() const{
    return this->image;
}
void Weapon::setName(const string name) {
    this->name = name;
}
void Weapon::setDamage(const int damage) {
    this->damage = damage;
}
