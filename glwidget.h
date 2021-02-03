#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QMainWindow>

#include <QGLWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <GL/glu.h>
#include <GL/glut.h>

#include <QGLWidget>
#include <QFile>
#include <QTimer>
#include <GL/glu.h>
#include <QMouseEvent>
#include <QTimer>
#include <QMessageBox>
#include <sstream>
#include <iostream>
#include <QDebug>


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

public:
protected:
    void initializeGL();
    void paintGL();
//    virtual void resizeGL(int width, int height);
    void resizeGL(int width, int heitht) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* event) override;
//    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent* event) override;



   
private:
    QTimer *timer;
    QString fileName;
    QPoint previousMousePosition;
    int xRot;
    int yRot;
    int zRot;
    bool RightButtonIsMouseDown=false;
    bool isMouseDown=false;
    float m_zoom = 700.0f;  //700
    float m_rotx = 0;  //35
    float m_roty = 0; //0.001
    bool mFullScreen=0;
    float wheeldelta = 1;
    float point_x;
    float point_y;



signals:
    void emitClose();
public slots:
    void loop();
    void setupScene(QString fileName);

};

#endif // GLWIDGET_H
