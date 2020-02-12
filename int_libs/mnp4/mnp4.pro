TEMPLATE = lib
TARGET = mnp4
INCLUDEPATH += . \
               src \
               include/libmnp4 \
               src/core \
               src/network \
               src/packets \
               include/libmnp4/addon \
               include/libmnp4/core \
               include/libmnp4/network \
               include/libmnp4/packets

INCLUDEPATH += $$matrix_top_dir/int_libs/qtiocompressor

# Input
HEADERS += include/libmnp4/global.h \
           include/libmnp4/init.h \
           include/libmnp4/core/mcconfig.h \
           include/libmnp4/core/mctime.h
SOURCES += src/init.cpp \
           src/core/mcconfig.cpp \
           src/core/mctime.cpp \
           src/core/mctime_unix.cpp \
           src/core/mctime_win.cpp

QT = core
INCLUDEPATH += include
DEFINES += MNP4_LIBRARY
LIBS += -L$$matrix_top_dir/dist -lqtiocompressor

include(../int_libs.pri)
