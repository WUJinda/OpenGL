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
TARGET 	  = TDGL_BARBIERRENARD_EMILE_SHARE

# fichiers sources/headers/ressources
SOURCES += main.cpp myglwidget.cpp \
    Car.cpp \
    DataTypes.cpp \
    Ground.cpp \
    Keyboard.cpp \
    Sign.cpp \
    entity.cpp \
    plane.cpp
HEADERS += myglwidget.h \
    Car.h \
    DataTypes.h \
    Ground.h \
    Keyboard.h \
    Sign.h \
    entity.h \
    plane.h
RESOURCES += \
    textures.qrc
