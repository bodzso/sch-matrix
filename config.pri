#a static buildekbe nem teszek exceptionkezel�st, �gy ezzel lehet detekt�lni
#egy�bk�nt pedig itt be lehet dr�tozni manu�lisan.
exceptions{
	CONFIG+=mtx_dynamic
	DEFINES+=MTX_QT_IS_DYNAMIC
}else{
	CONFIG+=mtx_static
	DEFINES+=MTX_QT_IS_STATIC
}

QMAKE_CXXFLAGS += -std=gnu++0x
INCLUDEPATH += $$[QT_INSTALL_PREFIX]/src/3rdparty/zlib

# minden pont k�t mappa m�lys�gben van
INCLUDEPATH += ../../int_libs/qtiocompressor/
LIBS += -L../../build/ # magukat a libeket itt nem k�tj�k be