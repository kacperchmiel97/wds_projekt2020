QT       += core gui network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chart.cpp \
    console.cpp \
    ipdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    ../socket_test/socketclient.cpp \
    ../socket_test/socketserver.cpp \
    ../socket_test/serverwindow.cpp \
    ../paint_test/realtimerenderer.cpp\
    ../paint_test/maprenderer.cpp


HEADERS += \
    chart.h \
    console.h \
    ipdialog.h \
    mainwindow.h \
    ../socket_test/socketclient.h \
    ../socket_test/socketserver.h \
    ../socket_test/serverwindow.h \
    ../paint_test/realtimerenderer.h\
    ../paint_test/maprenderer.h


FORMS += \
    ../socket_test/serverwindow.ui \
    ipdialog.ui \
    mainwindow.ui
    ../socket_test/serverwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES +=
