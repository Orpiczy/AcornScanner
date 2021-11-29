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
#!build_pass:message(ORPICZY cm-lib output dir: $${DESTDIR})
######################

QT -= gui

TARGET = cm-lib
TEMPLATE = lib
DEFINES += CMLIB_LIBRARY

INCLUDEPATH += source
CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += source/models/client.cpp \
    source/controllers/command-controller.cpp \
    source/controllers/master-controller.cpp \
    source/data/data-decorator.cpp \
    source/data/datetime-decorator.cpp \
    source/data/entity.cpp \
    source/data/enumerator-decorator.cpp \
    source/data/int-decorator.cpp \
    source/data/map-decorator.cpp \
    source/data/string-decorator.cpp \
    source/framework/command.cpp \
    source/models/address.cpp \
    source/models/appointment.cpp \
    source/models/client-search.cpp \
    source/models/contact.cpp \
    source/models/storage.cpp

HEADERS += \
    source/cm-lib_global.h \
    source/controllers/command-controller.h \
    source/controllers/master-controller.h \
    source/controllers/navigation-controller.h \
    source/data/data-decorator.h \
    source/data/datetime-decorator.h \
    source/data/entity-collection.h \
    source/data/entity.h \
    source/data/enumerator-decorator.h \
    source/data/int-decorator.h \
    source/data/map-decorator.h \
    source/data/string-decorator.h \
    source/framework/command.h \
    source/models/address.h \
    source/models/appointment.h \
    source/models/client-search.h \
    source/models/client.h \
    source/models/contact.h \
    source/models/storage.h

# Default rules for deployment.
#unix {
#    target.path = /usr/lib
#}
#!isEmpty(target.path): INSTALLS += target



##TO DO, jak bedziesz pracowal przy raspberrypi to zamien windowsa w tej sciezce na raspbiana albo cokolwiek innego lub inni release
##!build_pass:message(cm-lib output dir: $${DESTDIR})


