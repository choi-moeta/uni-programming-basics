#-------------------------------------------------
#
# Project created by QtCreator 2019-06-22T01:54:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        add_dish.cpp \
        add_ingredient.cpp \
        create_relation.cpp \
        dish.cpp \
        dish_ingredient.cpp \
        dishes.cpp \
        ingredient.cpp \
        ingredients.cpp \
        main.cpp \
        mainwindow.cpp \
        show_dish.cpp \
        show_ingredient.cpp

HEADERS += \
        add_dish.h \
        add_ingredient.h \
        create_relation.h \
        dish.h \
        dish_ingredient.h \
        dishes.h \
        ingredient.h \
        ingredients.h \
        mainwindow.h \
        show_dish.h \
        show_ingredient.h

FORMS += \
        add_dish.ui \
        add_ingredient.ui \
        create_relation.ui \
        mainwindow.ui \
        show_dish.ui \
        show_ingredient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
