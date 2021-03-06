#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include "plan.h"

#include <QMouseEvent>

#include<QOpenGLFramebufferObject>

#include <algorithm>

#include <math.h>
#include <stdlib.h>

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    //Scene(QWidget* parent = Q_NULLPTR);
    using QOpenGLWidget::QOpenGLWidget;
    ~Scene();
    void print(int value = 0);
    void initExt();
public slots:
    void extUpdate();
protected:
    void initializeGL() override;
    void initShaders();
    void initTextures();
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mouseMoveEvent(QMouseEvent* e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
private:

    void addPointLine(QPoint p1, QPoint p2);

    Plan* plan = nullptr;
    QOpenGLShaderProgram program;
    QImage img;
    QOpenGLTexture* texture = nullptr;
    QMatrix4x4 projection;

    QPoint p_1 = QPoint(0,0);
    QPoint p_2 = QPoint(0,0);
    QPoint p_3 = QPoint(0,0);
    QPoint p_4 = QPoint(0,0);
    QPoint p_5 = QPoint(0,0);
    QPoint p_6 = QPoint(0,0);
    QPoint p_7 = QPoint(0,0);
    QPoint p_8 = QPoint(0,0);

    QVector2D p2p[60];
    std::list<QPoint> lpoints;
    std::list<QPoint> lpointsToAdd;

    GLfloat brush[25] = {
                    0.0f,0.5f,0.5f,0.5f,0.0f,
                    0.5f,0.8f,1.0f,0.8f,0.5f,
                    0.5f,1.0f,1.0f,1.0f,0.5f,
                    0.5f,0.8f,1.0f,0.8f,0.5f,
                    0.0f,0.5f,0.5f,0.5f,0.0f
                        };
    QOpenGLFramebufferObject *fbo = nullptr;
    int step=0;

};

#endif // SCENE_H
