#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class QMenu;
class QSlider;
class QScrollArea;

class GLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    void createActions();
    void createMenus();
    void createToolsBar();


private:
    QStatusBar *statusbar;
    QLabel *pixmapLabel;
    GLWidget *glWidget;
    QWidget *centralWidget;
    QScrollArea *glWidgetArea;
    QLabel  *m_statusLabel;

    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;

    QAction *zoom_in;
    QAction *zoom_out;

    QAction *caoche;


    QMenu *fileMenu;
    QToolBar *editToolBar;
    QTabWidget *select_interface;



};

#endif // MAINWINDOW_H
