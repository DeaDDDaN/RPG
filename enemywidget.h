#ifndef ENEMYWIDGET_H
#define ENEMYWIDGET_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class enemywidget;
}

class enemywidget : public QDialog
{
    Q_OBJECT

public:
    explicit enemywidget(QWidget *parent = nullptr);
    ~enemywidget();
    void setMain(MainWindow& mainWin);
    MainWindow* getMain() const;

private:
    Ui::enemywidget *ui;
    MainWindow* mainWindow;
};

#endif // ENEMYWIDGET_H
