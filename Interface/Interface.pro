QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    toggledbutton.cpp \
    boardrenderer.cpp \
    flashingTextRenderer.cpp \
    gamemenuscene.cpp \
    gamestartscene.cpp \
    maingamescene.cpp \
    screenMapper.cpp \
    textRenderer.cpp \
    pieceRenderer.cpp \
    main.cpp \
    buttonGroup2D.cpp \
    sceneManager.cpp \
    applicationScene.cpp \
    controlSelectionScene.cpp \
    controlSelectionButton.cpp \
    pauseMenuRenderer.cpp \
    gameOverRenderer.cpp \
    qGameController.cpp \
	controllerEventHandler.cpp


HEADERS += \
    toggledbutton.h \
    assets.h \
    boardrenderer.h \
    flashingTextRenderer.h \
    gamemenuscene.h \
    gamestartscene.h \
    maingamescene.h \
    screenMapper.h \
    textRenderer.h \
    pieceRenderer.h \
    buttonGroup2D.h \
    sceneManager.h \
    applicationScene.h \
    controlSelectionScene.h \
    controlSelectionButton.h \
    pauseMenuRenderer.h \
    gameOverRenderer.h \
    qGameController.h \
	controllerEventHandler.h

INCLUDEPATH += ..\Tetris
DEPENDPATH += ..\Tetris
LIBS += ..\Tetris\Tetris.lib
FORMS +=

TEMPLATE = vcapp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

