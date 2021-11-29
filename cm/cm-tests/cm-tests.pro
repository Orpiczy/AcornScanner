#####################
#konfiguracje includow, buildow itd, sztosik sprawa, w nadrzednym folderze nie ma tych plikow
include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

#budowanie sciezki z wykorzystaniem destination path stworzonego w qmake-destination-path
DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui
LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib
#!build_pass:message(ORPICZY test output dir: $${DESTDIR})
######################

QT += testlib
QT -= gui

TARGET = client-tests
TEMPLATE = app

CONFIG += c++14
CONFIG += console
CONFIG -= app_bundle

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

INCLUDEPATH += source

SOURCES += source/models/client-tests.cpp
