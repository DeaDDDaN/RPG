#include "Magic.h"
#include <string>
#include <iostream>

using namespace std;

Spell::Spell() {
    name = "No";
}

Spell::Spell(string name_) {
    name = name_;
}

void Spell::setName(string name_) {
    name = name_;
}

string Spell::getName() const {
    return name;
}

BookOfMagic::BookOfMagic() {
    head = tail = NULL;
    count = 0;
};

BookOfMagic::BookOfMagic(const BookOfMagic& book) {
    head = tail = NULL;
    count = 0;
    ListElement* temp = book.get(1);
    while (temp != NULL) {
        addEnd(temp->spell, temp->rechargeTime);
        temp = temp->next;
    }
};

BookOfMagic::~BookOfMagic() {
    delAll();
};

void BookOfMagic::addEnd(Spell* const spell, int rechargeTime_) {
    ListElement* temp = new ListElement;
    temp->next = NULL;
    temp->spell = spell;
    if (tail != NULL) {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else {
        temp->prev = NULL;
        head = tail = temp;
    }
    temp->rechargeTime = rechargeTime_;
    count++;
};


void BookOfMagic::del(int pos) {
    if (pos < 1 || pos > count + 1) {
        cout << "Incorrect position !" << endl;
        return;
    }
    int i = 1;
    ListElement* ind = head;
    while (i < pos) {
        ind = ind->next;
        i++;
    }
    ListElement* prevInd = ind->prev;
    ListElement* afterInd = ind->next;
    if (prevInd != NULL)
        prevInd->next = afterInd;
    if (afterInd != NULL)
        afterInd->prev = prevInd;

    if (pos == 1)
        head = afterInd;
    if (pos == count)
        tail = prevInd;
    delete ind;
    count--;
}

void BookOfMagic::delAll() {
    while (count != 0)
        del(1);
};

ListElement* BookOfMagic::get(int pos) const {
    if (pos < 1 || pos > count + 1) {
        cout << "Incorrect position !" << endl;
        return NULL;
    }
    ListElement* temp = head;
    int i = 1;
    while (i < pos) {
        temp = temp->next;
        i++;
    }
    return temp;
}
int BookOfMagic::getCount() const {
    return count;
}

void BookOfMagic::renewTime() {
    for (int i = 1; i <= this->getCount(); i++) {
        if (this->get(i)->recharge && this->get(i)->curRechargeTime < this->get(i)->rechargeTime)
            this->get(i)->curRechargeTime++;
        else {
            this->get(i)->recharge = false;
            this->get(i)->curRechargeTime = 0;
        }
    }
}

