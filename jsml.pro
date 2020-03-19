TEMPLATE = app
TARGET = jsml
QT += webenginewidgets
CONFIG += c++11

HEADERS += \
    browser.h \
    browserwindow.h \
    tabwidget.h \
    urllineedit.h \
    webview.h \
    webpage.h \
    webpopupwindow.h

SOURCES += \
    browser.cpp \
    browserwindow.cpp \
    main.cpp \
    tabwidget.cpp \
    urllineedit.cpp \
    webview.cpp \
    webpage.cpp \
    webpopupwindow.cpp

FORMS += \
    certificateerrordialog.ui \
    passworddialog.ui

RESOURCES += data/simplebrowser.qrc

MOC_DIR = ./intermidiate
OBJECTS_DIR = ./intermidiate
UI_DIR = ./intermidiate

