#-------------------------------------------------
#
# Project created by QtCreator 2018-06-23T14:10:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3d_raycaster
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


SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/trackball.cpp \
    src/raycastcanvas.cpp \
    src/vtkvolume.cpp \
    src/mesh.cpp \
    src/raycastvolume.cpp \
    src/volume.cpp \
    src/rawvolume.cpp

HEADERS += \
    src/mainwindow.h \
    src/trackball.h \
    src/raycastcanvas.h \
    src/vtkvolume.h \
    src/mesh.h \
    src/raycastvolume.h \
    src/volume.h \
    src/rawvolume.h

INCLUDEPATH += \
    src

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES +=

QMAKE_CXXFLAGS += -std=c++17

QMAKE_CXXFLAGS_RELEASE += -fopenmp -Ofast

LIBS += -fopenmp
