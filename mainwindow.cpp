#include <QtOpenGL>
#include <QAction>
#include <QLabel>
#include <QMenu>
#include <QSlider>
#include <QScrollArea>
#include <QMenuBar>
#include <QApplication>
#include "mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget;

    setCentralWidget(centralWidget);

    glWidget = new GLWidget;

    select_interface = new QTabWidget;
 // select_interface->setParent(centralWidget);

    //gl
    glWidgetArea = new QScrollArea;
    glWidgetArea->setWidget(glWidget);
    glWidgetArea->setWidgetResizable(true);
    glWidgetArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    glWidgetArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    glWidgetArea->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    glWidgetArea->setMinimumSize(100, 100);

    //slider 滑块
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 16 * 250);
    slider->setSingleStep(30);
    slider->setPageStep(15 * 16);
    slider->setTickInterval(15 * 16);
    slider->setTickPosition(QSlider::TicksLeft);

#if 0
    //widget
    QGridLayout *centralLayout = new QGridLayout;
    centralLayout->addWidget(glWidgetArea, 0, 1);  //waiceng

    centralLayout->addWidget(slider,1,1,1,1);
    centralWidget->setLayout(centralLayout);
#endif

    //status label
    m_statusLabel = new QLabel;
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::green);
    m_statusLabel->setPalette(pe);
    m_statusLabel->resize(100, 100);
    m_statusLabel->setGeometry(0,133,300,280);
    statusBar()->addPermanentWidget(m_statusLabel);

    QString data = QString("x is y is");
    m_statusLabel->setText(data);

    createActions();

    createMenus();

    createToolsBar();

    select_interface->addTab(glWidgetArea,tr("&tab1"));
    select_interface->addTab(slider,tr("&tab2"));

    QGridLayout *centralLayout = new QGridLayout;

    centralLayout->addWidget(select_interface, 2, 1);  //外层

    centralWidget->setLayout(centralLayout);
//    createToolsBar();

  //  select_interface->setTabPosition(QTabWidget::West);//将tabBar的位置放在左边
 //   select_interface->show();

    //title
//    setWindowTitle(tr("Grabeer"));
  //  setWindowIcon(QIcon("/home/rd/glgl/uvd.png"));



    timer1 = new QTimer(this);
    timer1->setInterval(15);
    connect(timer1, SIGNAL(timeout()), this, SLOT(loop1()));
    timer1->start();
}

void MainWindow::createActions()
{
    zoom_in  = new QAction(tr("zoom &in"), this);
    zoom_out  = new QAction(tr("zoom &out"), this);
    caoche  = new QAction(QIcon("/home/rd/glgl/ico/uvd.png"),tr("&File"),this);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(zoom_in);

  //  fileMenu->addSeparator();
    fileMenu->addAction(zoom_out);
}

void MainWindow::createToolsBar()
{
    editToolBar = addToolBar(tr("cao"));
    editToolBar->addAction(caoche);
}

MainWindow::~MainWindow()
{

}

void MainWindow::loop1()
{
//    Nothing to do here, just redraw

    static int i = 0;
    i++;
    if(i%2)
    {
        setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
        showMaximized();
    }else
    {
        setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
        showNormal();
    }

}
