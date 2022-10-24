QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutme.cpp \
    addproperty.cpp \
    dashboard.cpp \
    homepage.cpp \
    main.cpp \
    mycontributions.cpp \
    regsitration.cpp \
    sign_in.cpp

HEADERS += \
    aboutme.h \
    addproperty.h \
    dashboard.h \
    homepage.h \
    mycontributions.h \
    regsitration.h \
    sign_in.h

FORMS += \
    aboutme.ui \
    addproperty.ui \
    dashboard.ui \
    homepage.ui \
    mycontributions.ui \
    regsitration.ui \
    sign_in.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

DISTFILES += \
    images/background_student.jpeg \
    images/bg.jpg

win32: LIBS += -L$$PWD/lib/ -llibmysql

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
