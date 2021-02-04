#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showNormal();

    m_statusLabel = new QLabel;

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::green);
    m_statusLabel->setPalette(pe);

//    m_statusLabel->setContentsMargins(300,0,100,0);
     m_statusLabel->resize(100, 100);
     m_statusLabel->setGeometry(0,133,300,280);

     ui->statusBar->addPermanentWidget(m_statusLabel);
     ui->statusBar->setSizeIncrement(1000,100);


     m_statusLabel2 = new QLabel;
      m_statusLabel2->resize(0, 100);
  //    m_statusLabel2->colorCount();
      ui->statusBar->addWidget(m_statusLabel2,1);


    filename = "../IV_Fusion_Platoon/init/tc.obj";

    ui->widget->setupScene(filename);
    connect(ui->widget, SIGNAL(emitClose()), this, SLOT(close()));

    tim = new QTimer();

    tim->setInterval(1000);

    connect(tim,SIGNAL(timeout()),this,SLOT(onTimeOut()));

    tim->start();
//    ui->statusBar->showMessage(tr("临时信息!"),2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::resizeGL(int w, int h)
//{

//}

void MainWindow::onTimeOut()
{
//    ui->statusBar->setStyleSheet("color:green");
    QString data = QString("x is %1,y is %2").arg(ui->widget->point_x).arg(ui->widget->point_y);
//    ui->statusBar->showMessage(data,2000);

    m_statusLabel->setText(data);
    QString data1 = QString("x is %1,y is %2").arg(rect().x()).arg(rect().y());

    m_statusLabel2->setText(data1);
}

void MainWindow::on_actionBbb_triggered(bool checked)
{
 //   std::cout<<"funck"<<std::endl;
    if(checked)
        ui->widget->fillchecked = true;
    else
    {
        ui->widget->fillchecked = false;
    }
}


//void MainWindow::mouseMoveEvent()
//{
//       std::cout<<"lllll"<<std::endl;
//}

void MainWindow::on_actionClose_triggered(bool checked)
{
    if(checked)
        ui->widget->bbbchecked = true;
    else
    {
        ui->widget->bbbchecked = false;
    }
}
