SOURCES += src/main.cpp\
        src/mainwindow.cpp

HEADERS  += src/mainwindow.h

FORMS    += form/mainwindow.ui

LIBS += -lgphoto2 \
    -lm \
    -lgphoto2_port \
    -ldl

# All objects should go into tmp
MOC_DIR = tmp/
UI_DIR = tmp/
UI_HEADER_DIR = tmp/
UI_SOURCE_DIR = tmp/
OBJECTS_DIR = tmp/
RCC_DIR = tmp/
 
include("config/local.pro")

