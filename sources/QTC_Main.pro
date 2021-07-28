!build_pass:message(Processing QTC_Main...)
include(../qmake_target_platform.pri)
!build_pass:message(QTC_Main PWD: $${PWD})

DESTDIR = $${PWD}/../bin/$${destination_path}
OBJECTS_DIR = $${PWD}/../build/$${destination_path}
MOC_DIR = $${PWD}/../build/$${destination_path}
RCC_DIR = $${PWD}/../build/$${destination_path}
UI_DIR = $${PWD}/../build/$${destination_path}

!build_pass:message(dest. path: $${destination_path})

QT  -= gui core
QT  += widgets

CONFIG += c++17

TEMPLATE = app

TARGET = QTC

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ./ \
    ./Core \
    ./Gui

SOURCES += \
    QTC_Main.cpp

HEADERS += \
    QTC_Configuration.h \
    QTC_Core.h \
    QTC_MainWindow.h

linux {

    LIBS += -L$${PWD}/../bin/$${destination_path}

}

win32 {

    LIBS += -L$${PWD}/../bin/$${destination_path}

}

LIBS += -lQTC_Core \
    -lQTC_Gui

#!build_pass:message(destination_path: $${destination_path})
#!build_pass:message(OBJECTS_DIR: $${OBJECTS_DIR})

#TRANSLATIONS += \
#    QTC_en_US.ts

#CONFIG += lrelease
#CONFIG += embed_translations

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
