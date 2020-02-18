TEMPLATE = lib
TARGET = qtiocompressor
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += qtiocompressor.h
SOURCES += qtiocompressor.cpp

CONFIG += staticlib c++11

include(../int_libs.pri)
