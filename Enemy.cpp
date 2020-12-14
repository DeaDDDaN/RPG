#include "Enemy.h"
#include <iostream>
int Enemy::getDamage() {
    return (this->weapon)->getDamage();
}
void Enemy::setName(string name) {
    this->name = name;
}
void Enemy::setHP(int hp) {
    this->HP = hp;
}
void Enemy::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}
void Enemy::setCritchance(const int crit) {
    this->critchance = crit;
}
void Enemy::setImage(const string image){
    this->image = image;
}
string Enemy::getName() {
    return this->name;
}
int Enemy::getHP() {
    return this->HP;
}
void Enemy::takeDamage(const int damage) {
    this->HP = this->HP - damage;
    if (this->HP <= 0) this->HP = 0;
}
int Enemy::getCritchance(){
    return this->critchance;
}
string Enemy::getImage(){
    return this->image;
}
Weapon* Enemy::getWeapon(){
    return this->weapon;
}
int Enemy::getScale(){
    return this->scale;
}
void Enemy::setScale(int scale){
    this->scale = scale;
}


