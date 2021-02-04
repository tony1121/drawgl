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

typedef struct{
    float x;
    float y;
    float z;
}point_type_t;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

public:
    bool bbbchecked = false;

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
    float point_x_old = 0;
    float point_y_old = 0;
    float point_x_new = 0;
    float point_y_new = 0;
    float Perspective_theta = 90;
    float m_iMag = 1;
    float length_g;
    int step=0;
    std::vector<point_type_t> point_draw;
    int esc_Escape = 0;



signals:
    void emitClose();
public slots:
    void loop();
    void setupScene(QString fileName);

};

#endif // GLWIDGET_H
