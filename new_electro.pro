QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./source/  # current QXlsx source path is ./source/
include(./QXlsx.pri)

SOURCES += \
    fizika.cpp \
    main.cpp \
    mainwindow.cpp \
    matematika.cpp \
    menu.cpp \
    odnolineynaya_skhema.cpp \
    primenenie.cpp \
    vhod.cpp

HEADERS += \
    fizika.h \
    mainwindow.h \
    matematika.h \
    menu.h \
    odnolineynaya_skhema.h \
    primenenie.h \
    vhod.h

FORMS += \
    fizika.ui \
    mainwindow.ui \
    matematika.ui \
    menu.ui \
    odnolineynaya_skhema.ui \
    primenenie.ui \
    vhod.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    base.qrc \
    images.qrc
