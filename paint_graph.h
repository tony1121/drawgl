#ifndef PAINTGRAPH_H
#define PAINTGRAPH_H

#include <iostream>
#include <math.h>
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
#include <QDebug>
#include "func_common.h"


class PaintGraph {
 public:
  PaintGraph();
  ~PaintGraph();

 public:
  void DrawCube();
  void DrawCircle();
  void DrawCylinder();
  void DrawCone();
  void DrawPolygonCircle();
  void drawDot(QPointF p1);
  void drawLine(QPointF p1, QPointF p2);

};


#endif  // PAINTGRAPH_H
