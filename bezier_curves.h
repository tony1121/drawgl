#ifndef BEZIERCURVES_H
#define BEZIERCURVES_H

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
//#include "func_common.h"
#include "paint_graph.h"


class BezierCurves{
 public:
  BezierCurves();
  ~BezierCurves();

public:
  QPointF abc[20];
  PaintGraph paintgraph;
int points=0;

 public:
  int factorial(int n);
  float binomial_coff(float n,float k);
  QPointF drawBezier(std::vector<QPointF> PT, double t);
  QPointF drawBezierGeneralized(std::vector<QPointF> PT, double t);
  void BezierCtrlPts(QPointF p0, QPointF p1, QPointF p2, QPointF p3, QPointF &u, QPointF &v);
  QPointF drawBezierLine(std::vector<QPointF> PT, double t);

};


#endif  // BEZIERCURVES_H
