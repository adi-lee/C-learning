QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrator.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow1.cpp \
    student.cpp \
    student_inquiry.cpp \
    teacher.cpp

HEADERS += \
    Myvector.h \
    administrator.h \
    mainwindow.h \
    mainwindow1.h \
    person.h \
    student.h \
    student_inquiry.h \
    teacher.h

FORMS += \
    mainwindow.ui \
    mainwindow1.ui \
    student_inquiry.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc




    RC_ICONS =favicon.ico
