#include "QtWidgetsApplication1.h"

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setCentralWidget(ui.openGLWidget);
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::on_drawRectAction_triggered()
{
    ui.openGLWidget->drawShape(AXBOpenGLWidget::Rect);
}

void QtWidgetsApplication1::on_clearAction_triggered()
{
    ui.openGLWidget->drawShape(AXBOpenGLWidget::None);
}

void QtWidgetsApplication1::on_wireFrameAction_triggered()
{
    ui.openGLWidget->setWirefame(ui.wireFrameAction->isChecked());
}
