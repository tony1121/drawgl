#include "paint_graph.h"

PaintGraph::PaintGraph()
{

}

PaintGraph::~PaintGraph()
{

}


void PaintGraph::DrawCube()
{
	glBegin(GL_QUAD_STRIP);//填充凸多边形
	glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1000.0f, 0.0f);
    glVertex3f(1000.0f, 0.0f, 0.0f);
    glVertex3f(1000.0f, 1000.0f, 0.0f);
    glVertex3f(1000.0f, 0.0f, -1000.0f);
    glVertex3f(1000.0f, 1000.0f, -1000.0f);
    glVertex3f(0.0f, 0.0f, -1000.0f);
    glVertex3f(0.0f, 1000.0f, -1000.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1000.0f, 0.0f);
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -100.0f);
    glVertex3f(100.0f, 0.0f, -100.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    glVertex3f(100.0f, 100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
	glEnd();
}

void PaintGraph::DrawPolygonCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);       //清除。GL_COLOR_BUFFER_BIT表示清除颜色
    float R = 0.5f;
    int n = 80;     //这里的n表示用多边形绘制圆的精度，可以考虑增大精度
    glBegin(GL_POLYGON);
    /*
        表示对以下画出的点进行的操作，这里是形成多边形
        类似的还有GL_LINE_STRIP、GL_LINE_LOOP、GL_POINT等
    */
    for (int i = 0; i < n; i++)     //通过数学计算来画多边形的点
    {
        glVertex2f(R*cos(2 * M_PI*i / n), R*sin(2 * M_PI*i / n));
    }
    glEnd();
}

void PaintGraph::DrawCircle()
{
	glBegin(GL_TRIANGLE_FAN);//扇形连续填充三角形串
    glVertex3f(500.0f, 500.0f, 0.0f);
	int i = 0;
	for (i = 0; i <= 390; i += 15)
	{
		float p = i * 3.14 / 180;
        glVertex3f(500+100*sin(p), 500+100*cos(p), 0.0f);
	}
	glEnd();
}

void PaintGraph::DrawCylinder()
{
	glBegin(GL_QUAD_STRIP);//连续填充四边形串
	int i = 0;
	for (i = 0; i <= 390; i += 15)
	{
		float p = i * 3.14 / 180;
		glVertex3f(sin(p), cos(p), 1.0f);
		glVertex3f(sin(p), cos(p), 0.0f);
	}
	glEnd();
    DrawCircle();
	glTranslatef(0, 0, 1);
    DrawCircle();
}
void PaintGraph::DrawCone()
{
	glBegin(GL_QUAD_STRIP);//连续填充四边形串
	int i = 0;
	for (i = 0; i <= 390; i += 15)
	{
		float p = i * 3.14 / 180;
		glVertex3f(0, 0, 1.0f);
		glVertex3f(sin(p), cos(p), 0.0f);
	}
	glEnd();
    DrawCircle();
}
#if 0
void renderScene(void)
{
	static float i = 0;
	i += 0.1;
	if (i > 360)
		i = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(-2, 2.0, -12);
	glRotatef(i, 1, 1 ,1);
	Cylinder();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(2, 2, -12);
	glRotatef(i, 1, 1, 1);
	Circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslatef(-2, -2, -12);
	glRotatef(i, 1, 1, 1);
	Cube();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(2, -2, -12);
	glRotatef(i, 1, 1, 1);
	Cone();
	glPopMatrix();
	glutSwapBuffers();
}
#endif

void PaintGraph::drawDot(QPointF p1) {
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f( 255, 0, 0);
  //   glVertex2f(p1.x,p1.y);
    glVertex3d(p1.xp, p1.yp, 0.0);
    glEnd();

 //   glFlush();
}

void PaintGraph::drawLine(QPointF p1, QPointF p2)
{
    glBegin(GL_LINES);

      glVertex2f(p1.xp, p1.yp);
      glVertex2f(p2.xp, p2.yp);
    glEnd();
    glFlush();

}
