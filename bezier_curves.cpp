#include "bezier_curves.h"

BezierCurves::BezierCurves()
{

}

BezierCurves::~BezierCurves()
{

}

int BezierCurves::factorial(int n)   //阶乘
{
    if (n<=1)
        return(1);
    else
        n=n*factorial(n-1);
    return n;
}


float BezierCurves::binomial_coff(float n,float k)
{
    float ans;
    ans = factorial(n) / (factorial(k)*factorial(n-k));
    return ans;
}

//Calculate the bezier point
QPointF BezierCurves::drawBezier(std::vector<QPointF> PT, double t) {
    QPointF P;
    P.xp = pow((1 - t), 3) * PT[0].xp + 3 * t * pow((1 -t), 2) * PT[1].xp + 3 * (1-t) * pow(t, 2)* PT[2].xp + pow (t, 3)* PT[3].xp;
    P.yp = pow((1 - t), 3) * PT[0].yp + 3 * t * pow((1 -t), 2) * PT[1].yp + 3 * (1-t) * pow(t, 2)* PT[2].yp + pow (t, 3)* PT[3].yp;

    return P;
}

//Calculate the bezier point [generalized]

//Point BezierCurves::drawBezierGeneralized(Point PT[], double t) {
//    Point P;
//    P.x = 0; P.y = 0;
//    int clicks = 4;
//    for (int i = 0; i<clicks; i++)
//    {
//        P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
//        P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
//    }

//    return P;
//}

QPointF BezierCurves::drawBezierGeneralized(std::vector<QPointF> PT, double t) {
    QPointF P;
    P.xp = 0; P.yp = 0;
    int clicks = 4;
    for (int i = 0; i<clicks; i++)
    {
        P.xp = P.xp + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].xp;
        P.yp = P.yp + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].yp;
    }

    return P;
}

void BezierCurves::BezierCtrlPts(QPointF p0, QPointF p1, QPointF p2, QPointF p3,
                          QPointF &u, QPointF &v) {
  const double tension = 0.5f;
  u = (p2 - p0) * (tension / 3) + p1;
  v = (p1 - p3) * (tension / 3) + p2;
}


QPointF BezierCurves::drawBezierLine(std::vector<QPointF> PT, double t) {
    QPointF CP0,CP1;
    std::vector<QPointF> PT_tmp = PT;
  //  QPointF p1 = PT_tmp[0];
    std::vector<QPointF> tmp_point;
    QPointF tmp_point_last;
    int i;

#if 1
    int num = PT_tmp.size();
  //  for(int k=0;k<PT_tmp.size();k++)
  //      std::cout<<"size: "<<num<<" : "<<PT_tmp[k].xp<<" : "<<PT_tmp[k].yp<<std::endl;
    if(num == 1)
        return CP0;
    else if(num == 2)
    {
        paintgraph.drawLine(PT_tmp[0],PT_tmp[1]);
        glColor3f(0.0,0.0,0.0);


    }else if(num == 3)
    {
        for(i =0;i<PT_tmp.size()-2;i++)
        {
            BezierCtrlPts(PT_tmp[i],PT_tmp[i],PT_tmp[i+1],PT_tmp[i+2],CP0,CP1);
            tmp_point.push_back(PT_tmp[i]);
            tmp_point.push_back(CP0);
            tmp_point.push_back(CP1);
            tmp_point.push_back(PT_tmp[i+1]);

            paintgraph.drawDot(tmp_point[0]);
            paintgraph.drawDot(tmp_point[1]);
            paintgraph.drawDot(tmp_point[2]);
            paintgraph.drawDot(tmp_point[3]);

            QPointF p1 = PT_tmp[i];
            for(double t = 0.0;t <= 1.0; t += 0.02)
            {
                QPointF p2 = drawBezierGeneralized(tmp_point,t);
                paintgraph.drawLine(p1, p2);
                p1 = p2;
            }
            glColor3f(0.0,0.0,0.0);

            tmp_point.clear();
     //       std::vector<QPointF>::iterator ite = PT_tmp.begin();
     //       PT_tmp.erase(ite);
     //       tmp_point.clear();
        }
        {
        BezierCtrlPts(PT_tmp[i-1],PT_tmp[i],PT_tmp[i+1],PT_tmp[i+1],CP0,CP1);
        tmp_point.push_back(PT_tmp[i]);
        tmp_point.push_back(CP0);
        tmp_point.push_back(CP1);
        tmp_point.push_back(PT_tmp[i+1]);

        paintgraph.drawDot(tmp_point[0]);
        paintgraph.drawDot(tmp_point[1]);
        paintgraph.drawDot(tmp_point[2]);
        paintgraph.drawDot(tmp_point[3]);

        QPointF p1 = PT_tmp[i];
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            QPointF p2 = drawBezierGeneralized(tmp_point,t);
            paintgraph.drawLine(p1, p2);
            p1 = p2;
        }
        glColor3f(0.0,0.0,0.0);
        tmp_point.clear();


        }
    }else if(num >= 4)
    {
        {
        BezierCtrlPts(PT_tmp[0],PT_tmp[0],PT_tmp[1],PT_tmp[2],CP0,CP1);
        tmp_point.push_back(PT_tmp[0]);
        tmp_point.push_back(CP0);
        tmp_point.push_back(CP1);
        tmp_point.push_back(PT_tmp[1]);
        QPointF p1 = PT_tmp[0];
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            QPointF p2 = drawBezierGeneralized(tmp_point,t);
            paintgraph.drawLine(p1, p2);
            p1 = p2;
        }
        tmp_point.clear();

        }
        for(i=1;i<PT_tmp.size()-2;i++){
        BezierCtrlPts(PT_tmp[i-1],PT_tmp[i],PT_tmp[i+1],PT_tmp[i+2],CP0,CP1);
        tmp_point.push_back(PT_tmp[i]);
        tmp_point.push_back(CP0);
        tmp_point.push_back(CP1);
        tmp_point.push_back(PT_tmp[i+1]);
        QPointF p1 = PT_tmp[i];

//        std::cout<<"start: "<<std::endl;
//        std::cout<<tmp_point[0].x<<" : "<<tmp_point[0].y<<"  ";
//        std::cout<<tmp_point[1].x<<" : "<<tmp_point[1].y<<"  ";
//        std::cout<<tmp_point[2].x<<" : "<<tmp_point[2].y<<"  ";
//        std::cout<<tmp_point[3].x<<" : "<<tmp_point[3].y<<"  ";
//        std::cout<<"end "<<std::endl;

        paintgraph.drawDot(tmp_point[0]);
        paintgraph.drawDot(tmp_point[1]);
        paintgraph.drawDot(tmp_point[2]);
        paintgraph.drawDot(tmp_point[3]);
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            QPointF p2 = drawBezierGeneralized(tmp_point,t);
            paintgraph.drawLine(p1, p2);
            p1 = p2;
        }
        glColor3f(0.0,0.0,0.0);

        tmp_point.clear();

   //     std::vector<QPointF>::iterator ite = PT_tmp.begin();
   //     PT_tmp.erase(ite);
  //      std::cout<<"go: "<<PT_tmp.size()<<std::endl;
   //     tmp_point.clear();
  //      tmp_point.pop_back();
        }
        std::cout<<"iiiiii: "<<i<<std::endl;

        {
        BezierCtrlPts(PT_tmp[i-1],PT_tmp[i],PT_tmp[i+1],PT_tmp[i+1],CP0,CP1);
        tmp_point.push_back(PT_tmp[i]);
        tmp_point.push_back(CP0);
        tmp_point.push_back(CP1);
        tmp_point.push_back(PT_tmp[i+1]);
        QPointF p1 = PT_tmp[i];
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            QPointF p2 = drawBezierGeneralized(tmp_point,t);
            paintgraph.drawLine(p1, p2);
            p1 = p2;
        }
        glColor3f(0.0,0.0,0.0);
        tmp_point.clear();

        }
    }

#endif

}


#if 0
void myMouse(int button, int state, int x, int y) {
  // If left button was clicked
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    // Store where mouse was clicked, Y is backwards.
    abc[points].setxy((float)x,(float)(SCREEN_HEIGHT - y));
    points++;

    // Draw the red  dot.
    drawDot(x, SCREEN_HEIGHT - y);


    // If (click-amout) points are drawn do the curve.
    if(points == clicks)
    {
        glColor3f(0.2,1.0,0.0);
        // Drawing the control lines
        for(int k=0;k<clicks-1;k++)
            drawLine(abc[k], abc[k+1]);

        Point p1 = abc[0];
        /* Draw each segment of the curve.Make t increment in smaller amounts for a more detailed curve.*/
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            Point p2 = drawBezierGeneralized(abc,t);
            cout<<p1.x<<"  ,  "<<p1.y<<endl;
            cout<<p2.x<<"  ,  "<<p2.y<<endl;
            cout<<endl;
            drawLine(p1, p2);
            p1 = p2;
        }
        glColor3f(0.0,0.0,0.0);

        points = 0;
    }
  }
}




#include <math.h>
#include <gl/glut.h>
#include <iostream>
using namespace std;

#define NUM_POINTS 6
#define NUM_SEGMENTS (NUM_POINTS-3)

struct Point2
{
    double x;
    double y;

    Point2() { ; }
    Point2(int px, int py) { x = px; y = py; }
    void SetPoint2(int px, int py) { x = px; y = py; }
};

/*全局变量*/
Point2 vec[NUM_POINTS];
bool mouseLeftDown = false;

/*绘制B样条曲线*/
void Bspline(int n)
{
    float f1, f2, f3, f4;
    float deltaT = 1.0 / n;
    float T;

    glBegin(GL_LINE_STRIP);
    for (int num = 0; num < NUM_SEGMENTS; num++)
    {
        for (int i = 0; i <= n; i++) {

            T = i * deltaT;

            f1 = (-T*T*T + 3*T*T - 3*T + 1) / 6.0;
            f2 =(3*T*T*T - 6*T*T + 4) / 6.0;
            f3 = (-3*T*T*T +3*T*T + 3*T + 1) / 6.0;
            f4 = (T*T*T) / 6.0;

            glVertex2f( f1*vec[num].x + f2*vec[num+1].x + f3*vec[num+2].x + f4*vec[num+3].x,
                f1*vec[num].y + f2*vec[num+1].y + f3*vec[num+2].y + f4*vec[num+3].y);
        }
    }

    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(1.5f);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    for(int i = 0;i < NUM_POINTS; i++)
    {
        glVertex2f(vec[i].x, vec[i].y);
    }
    glEnd();

    glPointSize(10.0f);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for(int i = 0;i < NUM_POINTS; i++)
    {
        glVertex2f(vec[i].x, vec[i].y);
    }
    glEnd();

    Bspline(20);

    glFlush();
    glutSwapBuffers();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);

    vec[0].SetPoint2(200, 400);
    vec[1].SetPoint2(100, 300);
    vec[2].SetPoint2(200, 200);
    vec[3].SetPoint2(250, 300);
    vec[4].SetPoint2(400, 200);
    vec[5].SetPoint2(400, 400);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLsizei)w, (GLsizei)h, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseLeftDown = true;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        mouseLeftDown = false;
    }
}

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2) * (x1 -x2) + (y1-y2) * (y1-y2));
}

void motion(int x, int y)
{
    if (mouseLeftDown)
    {
        for (int i = 0; i < NUM_POINTS; i++)
        {
            if (distance(vec[i].x, vec[i].y, x, y) < 20)
            {
                vec[i].SetPoint2(x, y);
            }
        }
    }

    glutPostRedisplay();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition (200, 200);
    glutCreateWindow("B-Spline Curve");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

    return 0;

}
https://www.cnblogs.com/caster99/p/4746652.html
#endif




