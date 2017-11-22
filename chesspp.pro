#-------------------------------------------------
#
# Project created by QtCreator 2017-11-02T21:17:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChessGame_v2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    gui_board.cpp \
    button.cpp \
    gui_game.cpp \
    square.cpp \
    ai_test.cpp \
    ai.cpp \
    board_io.cpp \
    board_position.cpp \
    board.cpp \
    common.cpp \
    move.cpp

HEADERS += \
    ai.h \
    ai_test.h \
    board.h \
    board_io.h \
    board_position.h \
    button.h \
    common.h \
    gui_board.h \
    gui_game.h \
    move.h \
    square.h

FORMS += \
        mainwindow.ui \

RESOURCES += \
    chesspp.qrc \
    chessImg/images.qrc

SUBDIRS += \
    chesspp.pro

DISTFILES += \
    chessImg/BlackBishop.png \
    chessImg/BlackKing.png \
    chessImg/BlackKnight.png \
    chessImg/BlackPawn.png \
    chessImg/BlackQueen.png \
    chessImg/BlackRook.png \
    chessImg/WhiteBishop.png \
    chessImg/WhiteKing.png \
    chessImg/WhiteKnight.png \
    chessImg/WhitePawn.png \
    chessImg/WhiteQueen.png \
    chessImg/WhiteRook.png \
    chessImg/MainWindowBackground.png \
    chessImg/MainWindowBackground.png \
    chessImg/PlayBackground.png
