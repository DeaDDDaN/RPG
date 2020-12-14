#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFrame>
#include "Heroes.h"
#include "TeamOfEnemy.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow* getUI();
    ~MainWindow();
    QGraphicsScene* getScene();
    TeamOfEnemy* getTeamOfEnemy();
    void createScene();
    void createAttackFrame();
    void setTeamOfHeroes(TeamOfHeroes* teamOfHeroes);
    void setTeamOfEnemy(TeamOfEnemy* teamOfEnemy);
    int getCurrentHero();
    int getRegimeBattle() {return regimeBattle;};
    void EnemyUpdate();
    void isHeroesAttacked();
    void EnemiesAttack();

private slots:
    void on_WarriorButton_clicked();

    void on_ArcherButton_clicked();

    void on_WizardButton_clicked();

    void on_PriestButton_clicked();

    void on_SpellButton_clicked();

    void on_attackButton_clicked();

    void on_pushButton_3_clicked();

    void activateAttack1();

    void activateAttack2();

    void activateAttack3();

    void activateAttack4();

    void on_Skill1_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene_;
    TeamOfHeroes* teamOfHeroes;
    int currentHero = 1;
    TeamOfEnemy* teamOfEnemy;
    int regimeBattle = 0;
    QPushButton *buttonForMoster1_;
    QPushButton *buttonForMoster2_;
    QPushButton *buttonForMoster3_;
    QPushButton *buttonForMoster4_;
};
#endif // MAINWINDOW_H
