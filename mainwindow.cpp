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


    /*
    //status label
    m_statusLabel = new QLabel;
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::green);
    m_statusLabel->setPalette(pe);
    m_statusLabel->resize(100, 100);
    m_statusLabel->setGeometry(0,133,300,280);
//    statusBar()->addWidget(m_statusLabel);



    statusBar()->addPermanentWidget(m_statusLabel);

    QString data = QString("x is y is");
    m_statusLabel->setText(data);
*/

    QLabel *locationLabel;
    locationLabel = new QLabel("July");

   locationLabel->setAlignment(Qt::AlignCenter);

   locationLabel->setMinimumSize(locationLabel->sizeHint());



   QLabel *aixLabel;

   aixLabel = new QLabel("\"CTRL + H\" for help");



   //Optional

   statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框

   statusBar()->setSizeGripEnabled(false); //设置是否显示右边的大小控制点

   statusBar()->addWidget(locationLabel);

   statusBar()->addWidget(aixLabel, 1);



   QLabel *per1 = new QLabel("Ready1", this);

   QLabel *per2 = new QLabel("Ready2", this);

   QLabel *per3 = new QLabel("Ready3", this);

   statusBar()->addPermanentWidget(per1); //现实永久信息

   statusBar()->addPermanentWidget(per2);

   statusBar()->insertPermanentWidget(2, per3);



   statusBar()->showMessage("Status is here...", 3000); // 显示临时信息，时间3秒钟.



    createActions();

    createMenus();

    createToolsBar();

    // tab2 widget

    QWidget *tab_2;
    tab_2 = new QWidget();
    tab_2->setObjectName(QStringLiteral("tab_2"));

    //tab2 button
    ok_button = new QPushButton(tab_2);
    ok_button->setObjectName(QStringLiteral("pushButton"));
  //  ok_button->setGeometry(QRect(80, 80, 80, 22));

    ok_button->setText(QApplication::translate("MainWindow", "PushButton", 0));


    select_interface->addTab(glWidgetArea,tr("&tab1"));
    select_interface->addTab(tab_2,tr("&tab2"));

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


    connect(glWidget,SIGNAL(F2_pressed()),this,SLOT(F2_pressed_slot()));
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

void MainWindow::F2_pressed_slot()
{
    press_bool = !press_bool;
    if(press_bool)
    {
        setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
        showMaximized();
    }else
    {
        setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
        showNormal();
    }
}


void MainWindow::loop1()
{
//    std::cout<<width()<<"  "<<height()<<std::endl;
    ok_button->setGeometry(width()-150, height()-150, 80, 22);
}
