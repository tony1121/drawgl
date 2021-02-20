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
