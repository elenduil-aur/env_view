
QT += quick

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

MOC_DIR = mocs
OBJECTS_DIR = objs
RCC_DIR = rcc
UI_DIR = ui

SOURCES += \
        src/main.cc \
        src/process_environment_model/processenvironmentmodel.cc

RESOURCES += resources/qml/qml.qrc

HEADERS += \
    src/process_environment_model/processenvironmentmodel.h
