TEMPLATE = app
TARGET = jsml
QT += webenginewidgets
CONFIG += c++11

HEADERS += \
    browser.h \
    browserwindow.h \
    tabwidget.h \
    urllineedit.h \
		findlineedit.h\
    webview.h \
    webpage.h \

SOURCES += \
    browser.cpp \
    browserwindow.cpp \
    main.cpp \
    tabwidget.cpp \
    urllineedit.cpp \
		findlineedit.cpp\
    webview.cpp \
    webpage.cpp \

FORMS += \

MOC_DIR = ./intermidiate
OBJECTS_DIR = ./intermidiate
UI_DIR = ./intermidiate
RCC_DIR = ./intermidiate

#DESTDIR = /usr/local/bin
