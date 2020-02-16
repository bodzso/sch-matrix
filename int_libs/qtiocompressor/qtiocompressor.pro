TEMPLATE = lib
TARGET = qtiocompressor
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += qtiocompressor.h
SOURCES += qtiocompressor.cpp

CONFIG += staticlib

include(../int_libs.pri)
