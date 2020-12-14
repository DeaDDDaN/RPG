#include "WeaponCollection.h"
#include "Weapon.h"
#include <iostream>
using namespace std;
WeaponCollection::WeaponCollection() {
    object = NULL;
    count = 0;
}
WeaponCollection::WeaponCollection(const WeaponCollection& collection) {
    if (collection.getCount() != 0) {
        object = new ListofWeapons();
        object->prev = NULL;
        object->next = NULL;
        ListofWeapons* ind = object;
        ListofWeapons* temp = collection.getItem(1);
        while (temp != NULL) {
            ind->weapon = temp->weapon;
            ind->next = new ListofWeapons();
            (ind->next)->prev = ind;
            ind = ind->next;
            ind->next = NULL;
            temp = temp->next;
        }
        (ind->prev)->next = NULL;
        delete ind;
    }
    this->count = collection.getCount();
}
WeaponCollection::~WeaponCollection() {
    delALL();
}
void WeaponCollection::del(int pos) {
    if (pos < 1 || pos > count + 1) {
        cout << "Incorrect position !" << endl;
        return;
    }
    int i = 1;
    ListofWeapons* ind = object;
    while (i < pos) {
        ind = ind->next;
        i++;
    }
    ListofWeapons* prevInd = ind->prev;
    ListofWeapons* afterInd = ind->next;
    if (prevInd != NULL)
        prevInd->next = afterInd;
    if (afterInd != NULL)
        afterInd->prev = prevInd;

    if (pos == 1)
        object = afterInd;
    delete ind;
    count--;
}
void WeaponCollection::delALL() {
    while (count != 0) del(1);
}
void WeaponCollection::add(const Weapon& weapon) {
    if (this->count == 0) {
        object = new ListofWeapons();
        object->next = NULL;
        object->prev = NULL;
        object->weapon = weapon;
        count++;
    }
    else {
        ListofWeapons* ind = object;
        while (ind->next != NULL) {
            ind = ind->next;
        }
        ListofWeapons* temp = new ListofWeapons();
        ind->next = temp;
        temp->next = NULL;
        temp->prev = ind;
        temp->weapon = weapon;
        count++;
    }
}
ListofWeapons * WeaponCollection::getItem(int pos) const{
    if (pos < 1 || pos > count) {
        cout << "Incorrect position!" << endl;
        return NULL;
    }
    ListofWeapons* ind = object;
    for (int i = 1; i < pos; i++) {
        ind = ind->next;
    }
    return ind;
}
int WeaponCollection::getCount() const {
    return this->count;
}
