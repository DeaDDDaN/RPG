#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "Magic.h"
#include "Weapon.h"
#include "Heroes.h"
#include "ListOfSpells.h"
#include "ListOfHeroes.h"
#include "Constants.h"
#include "EnemyTypes.h"
#include "WeaponCollection.h"
#include <string>

int main(int argc, char *argv[])
{
    WeaponCollection wc;
    Weapon sword("Sword", 30, ":/resource/Images/sword.png");
    wc.add(sword); //1
    Weapon club("Club", 30, ":/resource/Images/club.png");
    wc.add(club); //2
    Weapon bow("Bow", 30, ":/resource/Images/bow.png");
    wc.add(bow); //3
    Weapon crossbow("Crossbow", 30, ":/resource/Images/crossbow.png");
    wc.add(crossbow); //4
    Weapon staff("Staff", 30, ":/resource/Images/staff.png");
    wc.add(staff); //5
    Weapon goodstaff("Goodstaff", 30, ":/resource/Images/goodstaff.png");
    wc.add(goodstaff); //6
    Weapon greatsword("Greatsword", 30, ":/resource/Images/greatsword.png");
    wc.add(greatsword); //7
    Weapon axe("Axe", 30, ":/resource/Images/axe.png");
    wc.add(axe); //8
    Weapon knife("Knife", 30, ":/resource/Images/knife.png");
    wc.add(knife); //9
    Weapon morgenstern("Morgenstern", 30, ":/resource/Images/morgenstern.png");
    wc.add(morgenstern); //10

    BookOfMagic warriorBook;
    BookOfMagic archerBook;
    BookOfMagic wizardBook;
    BookOfMagic priestBook;
    BookOfMagic enemyBook;
    Fireball skill1;
    //Treatment skill2;
    enemyBook.addEnd(&skill1, 3);
    //book.addEnd(&skill2, 2);
    Warrior warrior("shit", WARRIOR_HP, &(wc.getItem(1)->weapon), &warriorBook);
    warrior.setMaxHealth(WARRIOR_HP);

    Archer archer("shit", ARCHER_HP, &(wc.getItem(3)->weapon), &warriorBook);
    archer.setMaxHealth(ARCHER_HP);

    Wizard wizard("shit", MAG_HP, &(wc.getItem(6)->weapon), &warriorBook);
    wizard.setMaxHealth(MAG_HP);

    Priest priest("shit", PRIEST_HP, &(wc.getItem(5)->weapon), &warriorBook);
    priest.setMaxHealth(PRIEST_HP);

    TeamOfHeroes teamOfHeroes(4);

    teamOfHeroes.add(&warrior, 1);
    teamOfHeroes.add(&archer, 2);
    teamOfHeroes.add(&wizard, 3);
    teamOfHeroes.add(&priest, 4);

    Skeleton skeleton;
    skeleton.setWeapon(&(wc.getItem(7)->weapon));
    Witch witch;
    witch.setBook(&enemyBook);
    witch.setWeapon(&(wc.getItem(5)->weapon));
    Orc orc;
    orc.setWeapon(&(wc.getItem(2)->weapon));
    Goblin goblin;
    goblin.setWeapon(&(wc.getItem(9)->weapon));


    TeamOfEnemy teamOfEnemy;
    teamOfEnemy.add(&skeleton);
    teamOfEnemy.add(&witch);
    teamOfEnemy.add(&orc);
    teamOfEnemy.add(&goblin);

    QApplication a(argc, argv);
    MainWindow w;
    w.setTeamOfHeroes(&teamOfHeroes);
    w.setTeamOfEnemy(&teamOfEnemy);
    w.createScene();
    w.createAttackFrame();
    w.EnemyUpdate();
    w.show();
    return a.exec();
}
