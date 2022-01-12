#ifndef OPENGL_H
#define OPENGL_H

#include <QOpenGLWidget>
#include <QImage>
#include <QMouseEvent>
#include <QBrush>
#include <QPen>
#include <QPainter>

#include <algorithm>


class OpenGl : public QOpenGLWidget
{
public:
    OpenGl();

    void setColorPen(QColor color);

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:

    void drawLine(int x1, int y1, int x2, int y2);
    void drawLine(QPoint p1, QPoint p2);

    bool isPressed;

    int sizeCanvas[2];

    QColor colorPen;

    QImage *img;
    QPainter painter;

    std::list<QPoint> lpoints;

};

#endif // OPENGL_H