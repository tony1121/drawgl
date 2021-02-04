#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showNormal();

    filename = "../IV_Fusion_Platoon/init/tc.obj";

    ui->widget->setupScene(filename);
    connect(ui->widget, SIGNAL(emitClose()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::resizeGL(int w, int h)
//{

//}



void MainWindow::on_actionBbb_triggered(bool checked)
{
    std::cout<<"funck"<<std::endl;
    if(checked)
        ui->widget->bbbchecked = true;
    else
        ui->widget->bbbchecked = false;
}


//void MainWindow::mouseMoveEvent()
//{
//       std::cout<<"lllll"<<std::endl;
//}
