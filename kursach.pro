QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Enemy.cpp \
    EnemyTypes.cpp \
    Heroes.cpp \
    ListOfSpells.cpp \
    Magic.cpp \
    TeamOfEnemy.cpp \
    Weapon.cpp \
    WeaponCollection.cpp \
    enemywidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Constants.h \
    Enemy.h \
    EnemyTypes.h \
    Heroes.h \
    ListOfHeroes.h \
    ListOfSpells.h \
    Magic.h \
    TeamOfEnemy.h \
    Weapon.h \
    WeaponCollection.h \
    enemywidget.h \
    mainwindow.h

FORMS += \
    enemywidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Font.qrc \
    Images.qrc

DISTFILES +=
