!build_pass:message(Processing QTC_Gui...)
include(../../qmake_target_platform.pri)
!build_pass:message(QTC_Gui PWD: $${PWD})

DESTDIR = $${PWD}/../../bin/$${destination_path}
OBJECTS_DIR = $${PWD}/../../build/$${destination_path}
MOC_DIR = $${PWD}/../../build/$${destination_path}
RCC_DIR = $${PWD}/../../build/$${destination_path}
UI_DIR = $${PWD}/../../build/$${destination_path}

QT  -= gui core
QT  += widgets

CONFIG += c++17

TEMPLATE = lib

TARGET = QTC_Gui

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ../ \
    ./

SOURCES += \
    QTC_MainWindow.cpp

HEADERS += \
    ../QTC_Configuration.h \
    QTC_MainWindow.h
