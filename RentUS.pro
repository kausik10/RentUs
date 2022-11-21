QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about_us.cpp \
    aboutme.cpp \
    addproperty.cpp \
    admin_dashboard.cpp \
    categories.cpp \
    dashboard.cpp \
    homepage.cpp \
    main.cpp \
    mycontributions.cpp \
    properrty_details.cpp \
    registration_.cpp \
    sign_in.cpp \
    user_details.cpp

HEADERS += \
    about_us.h \
    aboutme.h \
    addproperty.h \
    admin_dashboard.h \
    categories.h \
    dashboard.h \
    globals.h \
    homepage.h \
    mycontributions.h \
    properrty_details.h \
    registration_.h \
    sign_in.h \
    user_details.h

FORMS += \
    about_us.ui \
    aboutme.ui \
    addproperty.ui \
    admin_dashboard.ui \
    categories.ui \
    dashboard.ui \
    homepage.ui \
    mycontributions.ui \
    properrty_details.ui \
    registration_.ui \
    sign_in.ui \
    user_details.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

DISTFILES += \
    images/background_student.jpeg \
    images/bg.jpg \
    images/logo3.png

win32: LIBS += -L$$PWD/lib/ -llibmysql

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
