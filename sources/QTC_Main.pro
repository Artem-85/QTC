QT  -= gui core
QT  += widgets

CONFIG += c++17

TEMPLATE = app

TARGET = QTC

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ./Core/

SOURCES += \
    QTC_Main.cpp

HEADERS += \
    QTC_Configuration.h

LIBS += -L$$PWD/../build_linux64_6.1.1/sources/Core -lQTC_Core

#TRANSLATIONS += \
#    QTC_en_US.ts

#CONFIG += lrelease
#CONFIG += embed_translations

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
