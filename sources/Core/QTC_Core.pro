!build_pass:message(Processing QTC_Core...)
include(../../qmake_target_platform.pri)
!build_pass:message(QTC_Core PWD: $${PWD})

DESTDIR = $${PWD}/../../bin/$${destination_path}
OBJECTS_DIR = $${PWD}/../../build/$${destination_path}/tmp
MOC_DIR = $${PWD}/../../build/$${destination_path}/tmp
RCC_DIR = $${PWD}/../../build/$${destination_path}/tmp
UI_DIR = $${PWD}/../../build/$${destination_path}/tmp

QT  -= gui core
QT  += widgets

CONFIG += c++17

TEMPLATE = lib

TARGET = QTC_Core

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ../ \
    ./

SOURCES += \
    QTC_Core.cpp

HEADERS += \
    ../QTC_Configuration.h \
    QTC_Core.h

#TRANSLATIONS += \
#    QTC_core_en_US.ts

#CONFIG += lrelease
#CONFIG += embed_translations

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
