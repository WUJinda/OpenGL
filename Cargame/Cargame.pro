# configuration Qt
QT       += core gui opengl widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia
TEMPLATE  = app
CONFIG += c++17

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}


# nom de l'exe genere
TARGET 	  = Cargame

# fichiers sources/headers/ressources
SOURCES += main.cpp myglwidget.cpp \
    Car.cpp \
    Ground.cpp \
    dialog.cpp \
    oppcars.cpp
HEADERS += myglwidget.h \
    Car.h \
    Ground.h \
    dialog.h \
    oppcars.h

RESOURCES += \
    res/textures.qrc

FORMS += \
    dialog.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
