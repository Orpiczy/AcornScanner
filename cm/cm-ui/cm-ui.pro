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
message(ORPICZY lib printh: $${PWD}/../binaries/$${DESTINATION_PATH})
#!build_pass:message(ORPICZY ui output dir: $${DESTDIR})
######################

QT += qml quick charts
QT += widgets

TEMPLATE = app

CONFIG += c++14

INCLUDEPATH += source \
    ../cm-lib/source

SOURCES += source/main.cpp

RESOURCES += views.qrc \
    assets.qrc \
    components.qrc


###################### OPENCV RELATED
INCLUDEPATH += E:/Programs/Libraries/opencv/release/install/include
LIBS += E:/Programs/Libraries/opencv/release/bin/libopencv_core454.dll
LIBS += E:/Programs/Libraries/opencv/release/bin/libopencv_highgui454.dll
LIBS += E:/Programs/Libraries/opencv/release/bin/libopencv_imgcodecs454.dll
LIBS += E:/Programs/Libraries/opencv/release/bin/libopencv_imgproc454.dll
LIBS += E:/Programs/Libraries/opencv/release/bin/libopencv_features2d454.dll
LIBS += E:/Programs/Libraries/opencv/release/bin/libopencv_calib3d454.dll
LIBS += E:/Programs/Libraries/opencv/release/bin/libopencv_videoio454.dll
######################
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD
#QML_IMPORT_PATH += C:/Qt/5.15.2/mingw81_32/qml/QtGraphicalEffects
# Additional import path used to resolve QML modules just for Qt Quick Designer
#QML_DESIGNER_IMPORT_PATH =

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
