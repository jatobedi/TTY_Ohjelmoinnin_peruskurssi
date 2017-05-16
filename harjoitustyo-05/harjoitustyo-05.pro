TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11

SOURCES += main.cpp \
    kayttoliittyma.cpp \
    resepti_map.cpp \
    reppu.cpp \
    tiedostonluku.cpp

HEADERS += \
    kayttoliittyma.hh \
    resepti_map.hh \
    reppu.hh \
    tiedostonluku.hh \
    vakiot.hh

