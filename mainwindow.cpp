#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QFontDatabase>
#include <iostream>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsItem>
#include <enemywidget.h>
#include <QMainWindow>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->SpellBook->hide();
    ui->statusbar->hide();
    QPixmap pixbcgrd(":/resource/Images/background.png");
    ui->label_background->setPixmap(pixbcgrd.scaled(800,400,Qt::KeepAspectRatioByExpanding));
    QPixmap pixgoblin(":/resource/Images/goblin.png");
    QPixmap pixorc(":/resource/Images/orc.png");
    QPixmap pixskeleton(":/resource/Images/skeleton.png");
    QPixmap pixwitch(":/resource/Images/witch.png");
    QPixmap sword(":/resource/Images/sword.png");

    ui->EnemyWeapon2->setPixmap(sword);
    /*
    goblin 130 130
    orc 160 160
    skeleton 160 160
    witch 120 120
    */
    ui->Enemy1->setPixmap(pixgoblin.scaled(130,130,Qt::KeepAspectRatioByExpanding));
    ui->Enemy2->setPixmap(pixorc.scaled(160,160,Qt::KeepAspectRatioByExpanding));
    ui->Enemy3->setPixmap(pixorc.scaled(160,160,Qt::KeepAspectRatioByExpanding));
    ui->Enemy4->setPixmap(pixwitch.scaled(120,120,Qt::KeepAspectRatioByExpanding));

    //buttonForMoster1->setText(QString(teamOfEnemy->getItem(1)->getName()))
}

Ui::MainWindow* MainWindow::getUI(){
    return this->ui;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_WarriorButton_clicked()
{
    currentHero = 1;
    if (teamOfHeroes->getItem(currentHero)->getAttacked())
        ui->attackButton->setEnabled(false);
    else
        ui->attackButton->setEnabled(true);
    ui->HeroImage->scene()->removeItem(ui->HeroImage->scene()->items().takeFirst());
    QImage image(":/resource/Images/WarriorOrig.png");
    image = image.scaled(120, 130, Qt::IgnoreAspectRatio);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    getScene()->addItem(item);
    ui->HeroClass->setText("Warrior");
    QString string = "Health " + QString::number(teamOfHeroes->getItem(1)->getHealth());
    ui->HeroHP->setText(string);


}

void MainWindow::on_ArcherButton_clicked()
{
    currentHero = 2;
    if (teamOfHeroes->getItem(currentHero)->getAttacked())
        ui->attackButton->setEnabled(false);
    else
        ui->attackButton->setEnabled(true);

    ui->HeroImage->scene()->removeItem(ui->HeroImage->scene()->items().takeFirst());
    QImage image(":/resource/Images/ArcherOrig.png");
    image = image.scaled(120, 130, Qt::IgnoreAspectRatio);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    getScene()->addItem(item);
    ui->HeroClass->setText("Archer");
    QString string = "Health: " + QString::number(teamOfHeroes->getItem(2)->getHealth());
    ui->HeroHP->setText(string);

}

void MainWindow::on_WizardButton_clicked()
{
    currentHero = 3;
    if (teamOfHeroes->getItem(currentHero)->getAttacked())
        ui->attackButton->setEnabled(false);
    else
        ui->attackButton->setEnabled(true);

    ui->HeroImage->scene()->removeItem(ui->HeroImage->scene()->items().takeFirst());
    QImage image(":/resource/Images/MagOrig.png");
    image = image.scaled(120, 130, Qt::IgnoreAspectRatio);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    getScene()->addItem(item);
    ui->HeroClass->setText("Wizard");
    QString string = "Health: " + QString::number(teamOfHeroes->getItem(3)->getHealth());
    ui->HeroHP->setText(string);
}



void MainWindow::on_PriestButton_clicked()
{
    currentHero = 4;
    if (teamOfHeroes->getItem(currentHero)->getAttacked())
        ui->attackButton->setEnabled(false);
    else
        ui->attackButton->setEnabled(true);
    ui->HeroImage->scene()->removeItem(ui->HeroImage->scene()->items().takeFirst());
    QImage image(":/resource/Images/PriestOrig.png");
    image = image.scaled(120, 130, Qt::IgnoreAspectRatio);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    getScene()->addItem(item);
    ui->HeroClass->setText("Priest");
    QString string = "Health: " + QString::number(teamOfHeroes->getItem(4)->getHealth());
    ui->HeroHP->setText(string);
}

QGraphicsScene* MainWindow::getScene(){
    return scene_;
}

void MainWindow::createScene(){
    QGraphicsScene *scene = new QGraphicsScene();
    QImage image(":/resource/Images/WarriorOrig.png");
    image = image.scaled(120, 130, Qt::IgnoreAspectRatio);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    ui->HeroImage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->HeroImage->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->addItem(item);
    ui->HeroImage->setScene(scene);
    QString string = "Health: " + QString::number(teamOfHeroes->getItem(1)->getHealth());
    ui->HeroHP->setText(string);
    scene->setSceneRect(0, 0, 120, 130);
    scene_ = scene;
}


void MainWindow::on_SpellButton_clicked()
{
    regimeBattle = 1;
    if (!ui->SpellBook->isHidden())
      ui->SpellBook->hide();
    else{
        ui->SpellBook->raise();
        ui->SpellBook->show();
    }
}

void MainWindow::setTeamOfHeroes(TeamOfHeroes* teamOfHeroes_){
    teamOfHeroes = teamOfHeroes_;
}

void MainWindow::setTeamOfEnemy(TeamOfEnemy* teamOfEnemy_){
    teamOfEnemy = teamOfEnemy_;
}

TeamOfEnemy* MainWindow::getTeamOfEnemy(){
    return teamOfEnemy;
}

void MainWindow::on_attackButton_clicked()
{
    //enemywidget enemywidget_;
    //enemywidget_.setMain(*this);
    //enemywidget_.setModal(true);
    //enemywidget_.exec();
    //ui->frame_6->setStyleSheet("background-image: url(:/resource/Images/Frame.png);");
    regimeBattle = 0;
    if (!ui->frame_6->isHidden()) {
      ui->frame_7->hide();
      ui->frame_6->hide();
    }
    else {
       ui->frame_6->show();
       ui->frame_7->show();
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    cout << "fff" << endl;
}

void MainWindow::createAttackFrame() {
    ui->frame_6->setStyleSheet("background-image: url(:/resource/Images/Frame.png);");
    ui->frame_7->setStyleSheet("background-image: url(:/resource/Images/Панель.png);");
    QPushButton *buttonForMoster1 = new QPushButton(this);
    QPushButton *buttonForMoster2 = new QPushButton(this);
    QPushButton *buttonForMoster3 = new QPushButton(this);
    QPushButton *buttonForMoster4 = new QPushButton(this);


    //font: 24pt "Little Trouble Girl BV";
    buttonForMoster1->setStyleSheet("font: 16pt \"Little Trouble Girl BV\";");
    buttonForMoster2->setStyleSheet("font: 16pt \"Little Trouble Girl BV\";");
    buttonForMoster3->setStyleSheet("font: 16pt \"Little Trouble Girl BV\";");
    buttonForMoster4->setStyleSheet("font: 16pt \"Little Trouble Girl BV\";");

    QString string1 = QString::fromStdString(teamOfEnemy->getItem(1)->getName() + "  Health: "+to_string(teamOfEnemy->getItem(1)->getHP()));
    QString string2 = QString::fromStdString(teamOfEnemy->getItem(2)->getName() + "  Health: "+to_string(teamOfEnemy->getItem(2)->getHP()));
    QString string3 = QString::fromStdString(teamOfEnemy->getItem(3)->getName() + "  Health: "+to_string(teamOfEnemy->getItem(3)->getHP()));
    QString string4 = QString::fromStdString(teamOfEnemy->getItem(4)->getName() + "  Health: "+to_string(teamOfEnemy->getItem(4)->getHP()));

    buttonForMoster1->setText(string1);
    buttonForMoster2->setText(string2);
    buttonForMoster3->setText(string3);
    buttonForMoster4->setText(string4);

    connect(buttonForMoster1, SIGNAL(clicked()), this, SLOT(activateAttack1()));
    connect(buttonForMoster2, SIGNAL(clicked()), this, SLOT(activateAttack2()));
    connect(buttonForMoster3, SIGNAL(clicked()), this, SLOT(activateAttack3()));
    connect(buttonForMoster4, SIGNAL(clicked()), this, SLOT(activateAttack4()));


    ui->verticalLayout_8->addWidget(buttonForMoster1);
    ui->verticalLayout_8->addWidget(buttonForMoster2);
    ui->verticalLayout_8->addWidget(buttonForMoster3);
    ui->verticalLayout_8->addWidget(buttonForMoster4);

    ui->frame_7->hide();
    ui->frame_6->hide();

    buttonForMoster1_ = buttonForMoster1;
    buttonForMoster2_ = buttonForMoster2;
    buttonForMoster3_ = buttonForMoster3;
    buttonForMoster4_ = buttonForMoster4;

}

void MainWindow::activateAttack1(){
    if (teamOfEnemy->getItem(4) != NULL){
        teamOfHeroes->getItem(getCurrentHero())->attack(teamOfEnemy->getItem(1));
        if (teamOfEnemy->getItem(1)->getHP() == 0) teamOfEnemy->del(1);
    }
    EnemyUpdate();
    isHeroesAttacked();
    ui->frame_7->hide();
    ui->frame_6->hide();
    if (teamOfHeroes->getItem(currentHero)->getAttacked())
        ui->attackButton->setEnabled(false);
    else
        ui->attackButton->setEnabled(true);
}

void MainWindow::activateAttack2(){
    if (teamOfEnemy->getItem(4) != NULL){
        teamOfHeroes->getItem(getCurrentHero())->attack(teamOfEnemy->getItem(2));
        if (teamOfEnemy->getItem(2)->getHP() == 0) teamOfEnemy->del(2);
    }
    EnemyUpdate();
    isHeroesAttacked();
    ui->frame_7->hide();
    ui->frame_6->hide();
    if (teamOfHeroes->getItem(currentHero)->getAttacked())
        ui->attackButton->setEnabled(false);
    else
        ui->attackButton->setEnabled(true);
}

void MainWindow::activateAttack3(){
    if (teamOfEnemy->getItem(4) != NULL){
        teamOfHeroes->getItem(getCurrentHero())->attack(teamOfEnemy->getItem(3));
        if (teamOfEnemy->getItem(3)->getHP() == 0) teamOfEnemy->del(3);
    }
    EnemyUpdate();
    isHeroesAttacked();
    ui->frame_7->hide();
    ui->frame_6->hide();
    if (teamOfHeroes->getItem(currentHero)->getAttacked())
        ui->attackButton->setEnabled(false);
    else
        ui->attackButton->setEnabled(true);
}

void MainWindow::activateAttack4(){
    if (teamOfEnemy->getItem(4) != NULL){
        teamOfHeroes->getItem(getCurrentHero())->attack(teamOfEnemy->getItem(4));
        if (teamOfEnemy->getItem(4)->getHP() == 0) teamOfEnemy->del(4);
    }
    EnemyUpdate();
    isHeroesAttacked();
    ui->frame_7->hide();
    ui->frame_6->hide();
    if (teamOfHeroes->getItem(currentHero)->getAttacked())
        ui->attackButton->setEnabled(false);
    else
        ui->attackButton->setEnabled(true);
}

void MainWindow::isHeroesAttacked(){
    if (teamOfHeroes->getItem(1)->getAttacked() && teamOfHeroes->getItem(2)->getAttacked() && teamOfHeroes->getItem(3)->getAttacked() && teamOfHeroes->getItem(4)->getAttacked()){
        teamOfHeroes->getItem(1)->setAttacked();
        teamOfHeroes->getItem(2)->setAttacked();
        teamOfHeroes->getItem(3)->setAttacked();
        teamOfHeroes->getItem(4)->setAttacked();
        EnemiesAttack();
    }
}
void MainWindow::EnemiesAttack(){
    if (teamOfEnemy->getItem(1) != NULL){
        if (teamOfEnemy->getItem(1)->getHP() != 0){
            teamOfEnemy->getItem(1)->attack(teamOfHeroes);
        }
    }

    if (teamOfEnemy->getItem(2) != NULL){
        if (teamOfEnemy->getItem(2)->getHP() != 0){
            teamOfEnemy->getItem(2)->attack(teamOfHeroes);
        }
    }

    if (teamOfEnemy->getItem(3) != NULL){
        if (teamOfEnemy->getItem(3)->getHP() != 0){
            teamOfEnemy->getItem(3)->attack(teamOfHeroes);
        }
    }

    if (teamOfEnemy->getItem(4) != NULL){
        if (teamOfEnemy->getItem(4)->getHP() != 0){
            teamOfEnemy->getItem(4)->attack(teamOfHeroes);
        }
    }

}
void MainWindow::EnemyUpdate(){
    QString string;
    if (teamOfEnemy->getItem(1) != NULL){
        if (teamOfEnemy->getItem(1)->getHP() != 0){
            string = "HP: " + QString::number(teamOfEnemy->getItem(1)->getHP());
            ui->EnemyHP1->setText(string);
            QPixmap qpe1(QString::fromStdString(teamOfEnemy->getItem(1)->getImage()));
            ui->Enemy1->setPixmap(qpe1.scaled(teamOfEnemy->getItem(1)->getScale(), teamOfEnemy->getItem(1)->getScale(), Qt::KeepAspectRatioByExpanding));
            QPixmap qp1(QString::fromStdString(teamOfEnemy->getItem(1)->getWeapon()->getImage()));
            ui->EnemyWeapon1->setPixmap(qp1);
        }
    }
    else ui->widget1->hide();
    if (teamOfEnemy->getItem(2) != NULL){
        if (teamOfEnemy->getItem(2)->getHP() != 0){
            if (teamOfEnemy->getItem(2)->getHP() != 0){
                string = "HP: " + QString::number(teamOfEnemy->getItem(2)->getHP());
                ui->EnemyHP2->setText(string);
                QPixmap qpe2(QString::fromStdString(teamOfEnemy->getItem(2)->getImage()));
                ui->Enemy2->setPixmap(qpe2.scaled(teamOfEnemy->getItem(2)->getScale(), teamOfEnemy->getItem(2)->getScale(), Qt::KeepAspectRatioByExpanding));
                QPixmap qp2(QString::fromStdString(teamOfEnemy->getItem(2)->getWeapon()->getImage()));
                ui->EnemyWeapon2->setPixmap(qp2);
            }
        }
    }
    else ui->widget2->hide();
    if (teamOfEnemy->getItem(3) != NULL){
        if (teamOfEnemy->getItem(3)->getHP() != 0){
            if (teamOfEnemy->getItem(3)->getHP() != 0){
                string = "HP: " + QString::number(teamOfEnemy->getItem(3)->getHP());
                ui->EnemyHP3->setText(string);
                QPixmap qpe3(QString::fromStdString(teamOfEnemy->getItem(3)->getImage()));
                ui->Enemy3->setPixmap(qpe3.scaled(teamOfEnemy->getItem(3)->getScale(), teamOfEnemy->getItem(3)->getScale(), Qt::KeepAspectRatioByExpanding));
                QPixmap qp3(QString::fromStdString(teamOfEnemy->getItem(3)->getWeapon()->getImage()));
                ui->EnemyWeapon3->setPixmap(qp3);
            }
        }
    }
    else ui->widget3->hide();
    if (teamOfEnemy->getItem(4) != NULL){
        if (teamOfEnemy->getItem(4)->getHP() != 0){
            if (teamOfEnemy->getItem(4)->getHP() != 0){
                string = "HP: " + QString::number(teamOfEnemy->getItem(4)->getHP());
                ui->EnemyHP4->setText(string);
                QPixmap qpe4(QString::fromStdString(teamOfEnemy->getItem(4)->getImage()));
                ui->Enemy4->setPixmap(qpe4.scaled(teamOfEnemy->getItem(4)->getScale(), teamOfEnemy->getItem(4)->getScale(), Qt::KeepAspectRatioByExpanding));
                QPixmap qp4(QString::fromStdString(teamOfEnemy->getItem(4)->getWeapon()->getImage()));
                ui->EnemyWeapon4->setPixmap(qp4);
            }
        }
    }
    else ui->widget4->hide();

}



int MainWindow::getCurrentHero() {
    return currentHero;
}



void MainWindow::on_Skill1_clicked()
{
    if (!ui->frame_6->isHidden()) {
      ui->frame_7->hide();
      ui->frame_6->hide();
    }
    else {
       ui->frame_6->show();
       ui->frame_7->show();
    }

}
