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


class PaintGraph {
 public:
  PaintGraph();
  ~PaintGraph();

 public:
  void DrawCube();
  void DrawCircle();
  void DrawCylinder();
  void DrawCone();
};


#endif  // PAINTGRAPH_H
