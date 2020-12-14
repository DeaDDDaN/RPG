#include "enemywidget.h"
#include "ui_enemywidget.h"

enemywidget::enemywidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enemywidget)
{
    ui->setupUi(this);
}

enemywidget::~enemywidget()
{
    delete ui;
}

void enemywidget::setMain(MainWindow& mainWin) {
    mainWindow = &mainWin;
}
MainWindow* enemywidget::getMain() const{
    return mainWindow;
}
