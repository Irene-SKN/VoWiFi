TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/inc
DEPENDPATH += $$PWD/inc

INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/src

INCLUDEPATH += $$PWD/third/juphoon/include/mme
DEPENDPATH += $$PWD/third/juphoon/include/mme

INCLUDEPATH += $$PWD/third/juphoon/include/service/rcs
DEPENDPATH += $$PWD/third/juphoon/include/service/rcs

INCLUDEPATH += $$PWD/third/juphoon/include/zos
DEPENDPATH += $$PWD/third/juphoon/include/zos

INCLUDEPATH += $$PWD/third/juphoon/include/zos/os/linux
DEPENDPATH += $$PWD/third/juphoon/include/zos/os/linux

INCLUDEPATH += $$PWD/third/libcurl/inc
DEPENDPATH += $$PWD/third/libcurl/inc

INCLUDEPATH += $$PWD/third/rapidjson/inc
DEPENDPATH += $$PWD/third/rapidjson/inc

INCLUDEPATH += $$PWD/third/rapidjson/inc
DEPENDPATH += $$PWD/third/rapidjson/inc

INCLUDEPATH += $$PWD/third/minizip/inc
DEPENDPATH += $$PWD/third/minizip/inc

INCLUDEPATH += $$PWD/third
DEPENDPATH += $$PWD/third

SOURCES += \
    src/commFunc.cpp \
    src/httpmsg.cpp \
    src/jpAudioMng.cpp \
    src/jpNetSDK.cpp \
    src/jpsdk.cpp \
    src/main.cpp \
    src/ping.cpp

HEADERS += \
    inc/commdatadef.h \
    inc/commFunc.h \
    inc/httpmsg.h \
    inc/jpAudioMng.h \
    inc/jpNetSDK.h \
    inc/jpsdk.h \
    inc/ping.h

unix:!macx: LIBS += -lpthread  -lz

unix:!macx: LIBS += -L$$PWD/third/juphoon/lib/x86_64/ -lavatar

INCLUDEPATH += $$PWD/third/juphoon/lib/x86_64
DEPENDPATH += $$PWD/third/juphoon/lib/x86_64

unix:!macx: LIBS += -L$$PWD/third/juphoon/lib/x86_64/ -lmme_jrtc

INCLUDEPATH += $$PWD/third/juphoon/lib/x86_64
DEPENDPATH += $$PWD/third/juphoon/lib/x86_64

unix:!macx: LIBS += -L$$PWD/third/juphoon/lib/x86_64/ -lmtccommon

INCLUDEPATH += $$PWD/third/juphoon/lib/x86_64
DEPENDPATH += $$PWD/third/juphoon/lib/x86_64

unix:!macx: LIBS += -L$$PWD/third/juphoon/lib/x86_64/ -lmtccp

INCLUDEPATH += $$PWD/third/juphoon/lib/x86_64
DEPENDPATH += $$PWD/third/juphoon/lib/x86_64

unix:!macx: LIBS += -L$$PWD/third/juphoon/lib/x86_64/ -lmtcvoip

INCLUDEPATH += $$PWD/third/juphoon/lib/x86_64
DEPENDPATH += $$PWD/third/juphoon/lib/x86_64

unix:!macx: LIBS += -L$$PWD/third/juphoon/lib/x86_64/ -lzmf

INCLUDEPATH += $$PWD/third/juphoon/lib/x86_64
DEPENDPATH += $$PWD/third/juphoon/lib/x86_64

unix:!macx: LIBS += -L$$PWD/third/libcurl/lib/x86_64/ -lcurl

INCLUDEPATH += $$PWD/third/libcurl/lib/x86_64
DEPENDPATH += $$PWD/third/libcurl/lib/x86_64

unix:!macx: LIBS += -L$$PWD/third/minizip/lib/x86_64/ -lminizip -lz

INCLUDEPATH += $$PWD/third/minizip/lib/x86_64
DEPENDPATH += $$PWD/third/minizip/lib/x86_64
