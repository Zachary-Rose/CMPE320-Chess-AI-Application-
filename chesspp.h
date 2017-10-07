#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chesspp.h"

class chesspp : public QMainWindow
{
    Q_OBJECT

public:
    chesspp(QWidget *parent = Q_NULLPTR);

private:
    Ui::chessppClass ui;
};
