QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

TARGET = multi-camera-remote

SOURCES +=  src/main.cpp\
            src/mainwindow.cpp

HEADERS +=  src/mainwindow.h

FORMS   +=  form/mainwindow.ui

#LIBS    +=  -lgphoto2 \
#            -lm \
#            -lgphoto2_port \
#            -ldl
unix:CXXFLAGS += `pkg-config --cflags libgphoto2`
unix:LIBS += `pkg-config --libs libgphoto2`

# All objects should go into tmp
MOC_DIR = tmp/
UI_DIR = tmp/
UI_HEADER_DIR = tmp/
UI_SOURCE_DIR = tmp/
OBJECTS_DIR = tmp/
RCC_DIR = tmp/
 
include("config/local.pro")

