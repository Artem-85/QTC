QT  -= gui core
QT  += widgets

CONFIG += c++17

TEMPLATE = lib

TARGET = QTC_Core

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ../

SOURCES += \
    QTC_Core.cpp

HEADERS += \
    QTC_Core.h \
    QTC_Configuration.h

#TRANSLATIONS += \
#    QTC_core_en_US.ts

#CONFIG += lrelease
#CONFIG += embed_translations

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
