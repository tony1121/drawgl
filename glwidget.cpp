#include "glwidget.h"
#include <QGLWidget>

#include <GL/glu.h>
#include <math.h>

#include <iostream>

using namespace std;


// 窗口大小变化回调函数
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, (GLfloat)w/(GLfloat)h, 0.1, 100000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10000, 0, 0, 0, 0, 1, 0);
    std::cout<<"w: "<<w<<" h: "<<h<<std::endl;
}

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    showNormal();

//    glutInitWindowSize(100, 100);
    setFocusPolicy(Qt::ClickFocus);
//    glutReshapeFunc(reshape);

    timer = new QTimer(this);
    timer->setInterval(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
    timer->stop();



}

void GLWidget::setupScene(QString fn)
{
    // Set the filename and start the timer
    fileName = fn;
    timer->start();

}

void GLWidget::loop()
{
    // Nothing to do here, just redraw
    updateGL();
}


void GLWidget::initializeGL()
{
    //下一行启用smooth shading(阴影平滑)。阴影平滑通过多边形精细的混合色彩，并对外部光进行平滑。
    //我将在另一个教程中更详细的解释阴影平滑。
    glShadeModel(GL_SMOOTH); // 启用阴影平滑

    glClearColor(0.0f, 1.0f, 0.0f, 0.5f); // 蓝色背景

    glClearDepth(1.0f);	// 设置深度缓存
    glEnable(GL_BLEND); // 启用深度测试
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}


void GLWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //glClear()函数在这里就是对initializeGL()函数
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(Perspective_theta, (GLfloat) width()/(GLfloat) height() ,  0.01, 400000);

    std::cout<<Perspective_theta<<std::endl;

    glClearColor(0.6, 0.6,0.8, 0.5);
    glMatrixMode(GL_MODELVIEW);                                  //中设置的颜色和缓存深度等起作用
    glLoadIdentity();//重置当前的模型观察矩阵,该句执行完后，将焦点移动到了屏幕的中心
    gluLookAt(0, 0, -20000, 0, 0, 0, 0, 1, 0);

    glRotatef(90, 0, 0, 1);

//    glRotatef(m_rotx, 0, 1, 0);
//    glRotatef(m_roty, 0, 0, 1);

    length_g = 20000*tan(M_PI/180*(Perspective_theta/2));

#if 1
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f( 255, 0, 0);  //dark red x axis
    glVertex3i(0, 0, 0);//单位cm
    glVertex3i(4000, 0, 0);
    glColor3f( 0, 255, 0);  //dark red x axis
    glVertex3i(4000, 0, 0);//单位cm
    glVertex3i(8000, 0, 0);
    glColor3f(0, 0, 255);  //dark red x axis
    glVertex3i(8000, 0, 0);//单位cm
    glVertex3i(12000, 0, 0);
    glEnd();

    int num = length_g/100;
    for(int i=0;i<num;i++)
    {
          glLineWidth(1);
          glBegin(GL_LINES);

          glColor3f( 0, 0, 0);
          glVertex3i((i-num/2)*100*2, -(num*100), 0);//单位cm
          glVertex3i((i-num/2)*100*2, num*100, 0);//单位cm
          glEnd();

    }

    for(int i=0;i<num;i++)
    {
        glLineWidth(1);
        glBegin(GL_LINES);

        glColor3f( 0, 0, 0);
        glVertex3i(-num*100, (i-num/2)*100*2, 0);//单位cm
        glVertex3i(num*100, (i-num/2)*100*2, 0);//单位cm
        glEnd();

    }
#if 0
    int num = 200;
        for(int i=0;i<num;i++)
        {
              glLineWidth(1);
              glBegin(GL_LINES);

              glColor3f( 0, 0, 0);
              glVertex3i((i-num/2)*100*2, -(num*100), 0);//单位cm
              glVertex3i((i-num/2)*100*2, num*100, 0);//单位cm
              glEnd();

        }
        for(int i=0;i<num;i++)
        {
            glLineWidth(1);
            glBegin(GL_LINES);

            glColor3f( 0, 0, 0);
            glVertex3i(-num*100, (i-num/2)*100*2, 0);//单位cm
            glVertex3i(num*100, (i-num/2)*100*2, 0);//单位cm
            glEnd();

        }

#endif
            glPointSize(5);
            glBegin(GL_POINTS);
            glColor3f( 255, 0, 0);
            glVertex3d(point_x, point_y, 0.0);

            glEnd();
#endif
}


void GLWidget::resizeGL(int w, int h)
{

    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    gluPerspective(Perspective_theta*m_iMag, (GLfloat) w/(GLfloat) h,  0.01, 400000);
    glMatrixMode(GL_MODELVIEW);	//选择模型观察矩阵
    glLoadIdentity(); // 重置模型观察矩阵
    updateGL();
//    std::cout<<"11w: "<<w<<"h: "<<h<<std::endl;

}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    float dX = event->pos().x()-previousMousePosition.x();
    float dY = event->pos().y()-previousMousePosition.y();
    if(isMouseDown)
    {
        m_roty += 0.4f * dY;
        m_rotx += 0.4f * dX;
    }

    previousMousePosition = event->pos(); //w,h
//    std::cout<<event->pos().x()<<": "<<event->pos().y()<<width()<<height()<<"   "<<x1<<" and "<<y1<<std::endl;
 //   std::cout<<point_x<<" : "<<point_y<<std::endl;
 //   std::cout<<x1<<" : "<<y1<<std::endl;
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isMouseDown = true;
    }
    if(event->button() == Qt::RightButton)
    {
        RightButtonIsMouseDown=true;
    }
    float x1=-event->pos().y()*sin(M_PI/2)+height()/2;
    float y1 = event->pos().x()*sin(M_PI/2)+event->pos().y()*cos(M_PI/2)-width()/2;

//    float point_x = x1*
    float ox = length_g*2;
    float oy = length_g*2*width()/height();
    point_x = x1*length_g*2/height();
    point_y = y1*oy/width();
    std::cout<<point_x<<" : "<<point_y<<std::endl;


    previousMousePosition = event->pos();
    update();
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_F2:
    {
  //      std::cout<<"key press"<<std::endl;
        mFullScreen = !mFullScreen;
        if(mFullScreen) {
            showFullScreen();
        }
        else {
            showNormal();
        }
        updateGL();
        break;
    }

    }
}

void GLWidget::wheelEvent(QWheelEvent* event)
{
    wheeldelta = (float)event->delta();
    QPoint qpMag = event->angleDelta();

        int iMag = qpMag.y();
    bool bUpdate = false;
    if(iMag > 0)
    {
        if(m_iMag < 8)
        {
            m_iMag *= 1.2;
            bUpdate = true;

        }
    }

    if(iMag < 0)
    {
        if(m_iMag >= 1)
        {
            m_iMag /= 2;
            bUpdate = true;
        }
    }
    if(Perspective_theta *m_iMag< 160)
         Perspective_theta = Perspective_theta*m_iMag;

//    if(bUpdate)
//    {
//        updateGL();
//    }
//    std::cout<<wheeldelta<<" hh: "<<qpMag.y()<<" mm "<<m_iMag<<std::endl;
}
