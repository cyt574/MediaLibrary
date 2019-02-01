#-------------------------------------------------
#
# Project created by QtCreator 2019-01-29T21:27:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MedaiLibrary
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mediamodel.cpp \
    settings.cpp \
    mediatree.cpp \
    callback.cpp

HEADERS += \
        mainwindow.h \
    mediamodel.h \
    settings.h \
    mediatree.h \
    callback.h

FORMS += \
        mainwindow.ui

TRANSLATIONS += \
        zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    QSS.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../curl-7.63.0/build/lib/release/ -llibcurl_imp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../curl-7.63.0/build/lib/release/ -llibcurl_imp
else:unix: LIBS += -L$$PWD/../curl-7.63.0/build/lib/ -llibcurl_imp

INCLUDEPATH += $$PWD/../curl-7.63.0/include
DEPENDPATH += $$PWD/../curl-7.63.0/include
