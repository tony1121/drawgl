#include "glwidget.h"
#include <QGLWidget>

#include <GL/glu.h>
#include <math.h>

#include <iostream>

using namespace std;


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    showNormal();

//    glutInitWindowSize(100, 100);
    setFocusPolicy(Qt::ClickFocus);   //
    setMouseTracking(true);     //
//    glutReshapeFunc(reshape);

    timer = new QTimer(this);
    timer->setInterval(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
    timer->stop();
//    setWindowIcon(QIcon("/home/rd/glgl/uvd.png"));

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
    glShadeModel(GL_SMOOTH); // 启用阴影平滑
    glClearColor(0.0f, 1.0f, 0.0f, 0.5f); // 蓝色背景
    glClearDepth(1.0f);	// 设置深度缓存
    glEnable(GL_BLEND); // 启用深度测试
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void glRect(int leftX,int leftY,int rightX,int rightY,int MODE){
    //画封闭曲线
    glBegin(MODE);
    //左下角
    glVertex2d(leftX,leftY);
    //右下角
    glVertex2d(rightX,leftY);
    //右上角
    glVertex2d(rightX,rightY);
    //左上角
    glVertex2d(leftX,rightY);
    //结束画线
    glEnd();
}


void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //glClear()函数在这里就是对initializeGL()函数
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(Perspective_theta, (GLfloat) width()/(GLfloat) height() ,  0.01, 400000);

//    std::cout<<Perspective_theta<<std::endl;

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
          glVertex3i((i-num/2)*100*2, -(num*100), 0);//单位cm   1ge  200danwei
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
  //     glui->statusBar->showMessage(tr("临时信息!"),2000);


    if(bbbchecked)
    {
        int i;
        if(point_draw.size()>0)
        {
        for(i=0;i<point_draw.size()-1;i++)
        {

            glPointSize(5);
            glBegin(GL_POINTS);
            glColor3f( 255, 0, 0);
            glVertex3d(point_draw.at(i).x, point_draw.at(i).y, 0.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f( 0, 0, 0);
            glVertex3i(point_draw.at(i).x,point_draw.at(i).y,point_draw.at(i).z);
            glVertex3i(point_draw.at(i+1).x,point_draw.at(i+1).y,point_draw.at(i+1).z);
            glEnd();

        }
        glPointSize(5);
        glBegin(GL_POINTS);
        glColor3f( 255, 0, 0);
        glVertex3d(point_draw.at(i).x, point_draw.at(i).y, 0.0);
        glEnd();
        if(!esc_Escape)
        {
            glBegin(GL_LINES);
            glColor3f( 0, 0, 0);
            glVertex3i(point_draw.at(i).x,point_draw.at(i).y,point_draw.at(i).z);
            glVertex3i(point_x_old,point_y_old,0);
            glEnd();
        }
        }
//        glBegin(GL_LINES);
//        glColor3f( 0, 0, 0);
//        glVertex3i(point_x_new, point_y_new, 0);//单位cm
//        glVertex3i(point_x_old, point_y_old, 0);//单位cm

//  //      while(point_x_new == )
//        std::cout<<point_x_new<<"........."<<point_y_new<<std::endl;
//  //      glVertex3i((point_x, point_y);//单位cm
//        glEnd();
    }else
        point_draw.clear();

    if(fillchecked)
    {

        int i;
        float x_down,x_up,y_right,y_left;
        for(i=0;i<fill_draw.size();i++)
        {

            if(fill_draw[i].x >= 0)
            {
                x_down = ((int)fill_draw[i].x / 200)*200;
                x_up = ((int)fill_draw[i].x / 200 + 1)*200;
            }else
            {
                x_down = ((int)fill_draw[i].x / 200-1)*200;
                x_up = ((int)fill_draw[i].x / 200 )*200;
            }
            if(fill_draw[i].y >= 0)
            {
                y_right = ((int)fill_draw[i].y / 200 + 1)*200;
                y_left = ((int)fill_draw[i].y / 200)*200;
            }else
            {
                y_right = ((int)fill_draw[i].y / 200)*200;
                y_left = ((int)fill_draw[i].y / 200 - 1)*200;
            }


        glColor3ub(166,166,1);
        glRect(x_down,y_right,x_up,y_left,GL_POLYGON);
  //      std::cout<<x_left<<":"<<x_right<<" : "<<y_up<<" : "<<y_down<<std::endl;
        }
    }else
        fill_draw.clear();
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
            glVertex3i(-num*10

                       0, (i-num/2)*100*2, 0);//单位cm
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

            glColor3ub(166,166,1);
            glRect(0,0,200,200,GL_POLYGON);
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
    point_type_t point_data;
    float dX = event->pos().x()-previousMousePosition.x();
    float dY = event->pos().y()-previousMousePosition.y();
    if(isMouseDown)
    {
        m_roty += 0.4f * dY;
        m_rotx += 0.4f * dX;
    }

    previousMousePosition = event->pos(); //w,h

    float x1=-event->pos().y()*sin(M_PI/2)+height()/2;
    float y1 = event->pos().x()*sin(M_PI/2)+event->pos().y()*cos(M_PI/2)-width()/2;

//    float point_x = x1*
    float ox = length_g*2;
    float oy = length_g*2*width()/height();
    point_x_old = x1*length_g*2/height();
    point_y_old = y1*oy/width();

//    std::cout<<event->pos().x()<<": "<<event->pos().y()<<width()<<height()<<"   "<<x1<<" and "<<y1<<std::endl;
 //   std::cout<<point_x<<" : "<<point_y<<std::endl;
//    std::cout<<x1<<" 22222: "<<y1<<std::endl;

}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    point_type_t point_data;

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
    if(bbbchecked)
    {
                point_data.x = point_x;
                point_data.y = point_y;
                point_data.z = 0;
                point_draw.push_back(point_data);

    }
    esc_Escape = 0;

    if(fillchecked)
    {
                fill_point_data.x = point_x;
                fill_point_data.y = point_y;
                fill_point_data.z = 0;
                fill_draw.push_back(fill_point_data);
    }

//    std::cout<<point_x<<" : "<<point_y<<std::endl;


    previousMousePosition = event->pos();
    update();
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_F2:
    {
        std::cout<<"key press"<<std::endl;
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
    case Qt::Key_Escape:
    {
        esc_Escape = 1;
        break;
    }
    }
}

void GLWidget::wheelEvent(QWheelEvent* event)
{
//    std::cout<<" uuuuuuuuu "<<std::endl;
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
            m_iMag /= 1.2;
            bUpdate = true;
        }
    }

    if(Perspective_theta *m_iMag< 120)
         Perspective_theta = Perspective_theta*m_iMag;
    else
        Perspective_theta = 120;
    updateGL();

}
