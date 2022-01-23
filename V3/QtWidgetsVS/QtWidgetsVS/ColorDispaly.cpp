#include "ColorDispaly.h"
#include "qdebug.h"

ColorDisplay::ColorDisplay(QWidget *parent): QOpenGLWidget(parent)
{
    img = new QImage(1, 1, QImage::Format_RGB32);
    update();
}
void ColorDisplay::paintEvent(QPaintEvent* event)
{
    painter.begin(this);
    painter.drawImage(event->rect(), *img, img->rect());
    painter.end();
    qInfo("print---------");
}

void ColorDisplay::setColor(QColor color)
{
    img->setPixelColor(0, 0, color);
    update();
}