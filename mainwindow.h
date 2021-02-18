#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qpushbutton.h>

class QAction;
class QLabel;
class QMenu;
class QSlider;
class QScrollArea;
class QPushButton;

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
    QTimer *timer1;
    bool press_bool = false;




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

    QPushButton *ok_button;



public slots:
    void loop1();
    void F2_pressed_slot();

};

#endif // MAINWINDOW_H
