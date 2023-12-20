#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

private slots:
    void on_drawRectAction_triggered();

	void on_clearAction_triggered();

    void on_wireFrameAction_triggered();


private:
    Ui::QtWidgetsApplication1Class ui;
};
