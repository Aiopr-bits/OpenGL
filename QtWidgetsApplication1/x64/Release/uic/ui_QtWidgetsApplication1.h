/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION1_H
#define UI_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "axbopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication1Class
{
public:
    QAction *drawRectAction;
    QAction *clearAction;
    QAction *wireFrameAction;
    QWidget *centralWidget;
    AXBOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName(QString::fromUtf8("QtWidgetsApplication1Class"));
        QtWidgetsApplication1Class->resize(600, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8("le.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QtWidgetsApplication1Class->setWindowIcon(icon);
        QtWidgetsApplication1Class->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color:rgb(68, 68, 68);\n"
"	color:rgb(255, 255, 255);\n"
"	font: 10pt \"\345\271\274\345\234\206\";\n"
"}\n"
"QMenuBar{\n"
"	background-color:rgb(200, 200, 200);\n"
"	color:rgb(60, 60, 60);\n"
"}\n"
""));
        drawRectAction = new QAction(QtWidgetsApplication1Class);
        drawRectAction->setObjectName(QString::fromUtf8("drawRectAction"));
        clearAction = new QAction(QtWidgetsApplication1Class);
        clearAction->setObjectName(QString::fromUtf8("clearAction"));
        wireFrameAction = new QAction(QtWidgetsApplication1Class);
        wireFrameAction->setObjectName(QString::fromUtf8("wireFrameAction"));
        wireFrameAction->setCheckable(true);
        centralWidget = new QWidget(QtWidgetsApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        openGLWidget = new AXBOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(140, 60, 300, 200));
        QtWidgetsApplication1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtWidgetsApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 19));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        QtWidgetsApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsApplication1Class->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        mainToolBar->addAction(drawRectAction);
        mainToolBar->addAction(clearAction);
        mainToolBar->addAction(wireFrameAction);

        retranslateUi(QtWidgetsApplication1Class);

        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "QtWidgetsApplication1", nullptr));
        drawRectAction->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\347\224\273\344\270\200\344\270\252\347\237\251\345\275\242", nullptr));
        clearAction->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\346\270\205\347\251\272\345\233\276\345\203\217", nullptr));
        wireFrameAction->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "\347\272\277\346\241\206\346\270\262\346\237\223", nullptr));
        menu->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\345\270\256\345\277\231", nullptr));
        menu_2->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\346\226\207\344\273\266", nullptr));
        menu_3->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\346\237\245\347\234\213", nullptr));
        menu_4->setTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
