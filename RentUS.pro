QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    homepage.cpp \
    main.cpp \
    regsitration.cpp \
    sign_in.cpp \
    userpage.cpp

HEADERS += \
    homepage.h \
    regsitration.h \
    sign_in.h \
    userpage.h

FORMS += \
    homepage.ui \
    regsitration.ui \
    sign_in.ui \
    userpage.ui

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
