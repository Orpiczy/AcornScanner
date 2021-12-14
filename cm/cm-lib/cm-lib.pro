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


QT += gui
QT += charts
QT += serialport

TARGET = cm-lib
TEMPLATE = lib
DEFINES += CMLIB_LIBRARY

INCLUDEPATH += source
CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/controllers/LowLevelFunctionality/BaseClasses/SimpleLogger.cpp \
    source/controllers/LowLevelFunctionality/Common/Translators.cpp \
    source/controllers/LowLevelFunctionality/DeviceController/CameraManager/CameraManager.cpp \
    source/controllers/LowLevelFunctionality/DeviceController/DeviceController.cpp \
    source/controllers/LowLevelFunctionality/DeviceController/ProfilometerManager/MsgManager.cpp \
    source/controllers/LowLevelFunctionality/DeviceController/ProfilometerManager/ProfilometerManager.cpp \
    source/controllers/LowLevelFunctionality/DeviceController/ProfilometerManager/SerialPortManager.cpp \
    source/controllers/LowLevelFunctionality/FileSystemController/FileSystem/FileSystemController.cpp \
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
    source/models/cameraDeviceUi.cpp \
    source/models/dailyStatisticsData.cpp \
    source/models/profilometerDeviceUi.cpp \
    source/models/scannedData.cpp

HEADERS += \
    source/cm-lib_global.h \
    source/controllers/LowLevelFunctionality/BaseClasses/DeviceManager.hpp \
    source/controllers/LowLevelFunctionality/BaseClasses/SimpleLogger.hpp \
    source/controllers/LowLevelFunctionality/Common/ControllersFlags.hpp \
    source/controllers/LowLevelFunctionality/Common/CustomEnumTypes.hpp \
    source/controllers/LowLevelFunctionality/Common/Translators.hpp \
    source/controllers/LowLevelFunctionality/DeviceController/CameraManager/CameraManager.hpp \
    source/controllers/LowLevelFunctionality/DeviceController/DeviceController.hpp \
    source/controllers/LowLevelFunctionality/DeviceController/ProfilometerManager/CommandProvider.hpp \
    source/controllers/LowLevelFunctionality/DeviceController/ProfilometerManager/ErrorProvider.hpp \
    source/controllers/LowLevelFunctionality/DeviceController/ProfilometerManager/MsgManager.hpp \
    source/controllers/LowLevelFunctionality/DeviceController/ProfilometerManager/ProfilometerManager.hpp \
    source/controllers/LowLevelFunctionality/DeviceController/ProfilometerManager/SerialPortManager.hpp \
    source/controllers/LowLevelFunctionality/FileSystemController/FileSystem/FileSystemController.hpp \
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
    source/models/camerDeviceUi.h \
    source/models/dailyStatisticsData.h \
    source/models/profilometerDeviceUi.h \
    source/models/scannedData.hpp

# Default rules for deployment.
#unix {
#    target.path = /usr/lib
#}
#!isEmpty(target.path): INSTALLS += target



##TO DO, jak bedziesz pracowal przy raspberrypi to zamien windowsa w tej sciezce na raspbiana albo cokolwiek innego lub inni release
##!build_pass:message(cm-lib output dir: $${DESTDIR})



