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


    QVBoxLayout *vboxlayout;
    vboxlayout = new QVBoxLayout;
    vboxlayout->addWidget(select_interface,0,0);

    //gl
    glWidgetArea = new QScrollArea;
    glWidgetArea->setWidget(glWidget);
    glWidgetArea->setWidgetResizable(true);
    glWidgetArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    glWidgetArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    glWidgetArea->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    glWidgetArea->setMinimumSize(100, 100);

 //   glWidgetArea->setLayout();
    //slider 滑块
//    QSlider *slider = new QSlider(Qt::Horizontal);
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 16 * 250);
    slider->setSingleStep(30);
    slider->setPageStep(15 * 16);
    slider->setTickInterval(15 * 16);
    slider->setTickPosition(QSlider::TicksLeft);
    vboxlayout->addWidget(slider,1);

#if 0
    //widget
    QGridLayout *centralLayout = new QGridLayout;
    centralLayout->addWidget(glWidgetArea, 0, 1);  //waiceng

    centralLayout->addWidget(slider,1,1,1,1);
    centralWidget->setLayout(centralLayout);
#endif

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



#if 0
            static QList<QPointF> points = QList<QPointF>() << QPointF(0, 0) << QPointF(1000, 1000);
            QPainterPath path(points[0]);
            //计算
            QPointF c1;
            QPointF c2;
            for (int i = 0; i < points.size() - 1; ++i) {
                // 控制点的 x 坐标为 sp 与 ep 的 x 坐标和的一半
                // 第一个控制点 c1 的 y 坐标为起始点 sp 的 y 坐标
                // 第二个控制点 c2 的 y 坐标为结束点 ep 的 y 坐标
                QPointF sp = points[i];
                QPointF ep = points[i+1];
                c1 = QPointF((sp.x() + ep.x()) / 2, sp.y());
                c2 = QPointF((sp.x() + ep.x()) / 2, ep.y());
                path.cubicTo(c1, c2, ep);
            }
            QPainter painter(tab_2);
            //设置渲染提示为消除锯齿
            painter.setRenderHint(QPainter::Antialiasing, true);
            //设置画笔颜色和宽度
            painter.setPen(QPen(Qt::black, 2));
            //将坐标系转换为矢量
            painter.translate(40, 130);
            //绘制path
            painter.drawPath(path);
            // 绘制曲线上的点
            painter.setBrush(Qt::gray);
            //绘制曲线上的点
            for (int i = 0; i < points.size(); ++i) {
                painter.drawEllipse(points[i], 4, 4);
            }
            painter.drawEllipse(c1 , 4, 4);
            painter.drawEllipse(c2 , 4, 4);

#endif

    QWidget *tab_3;
    tab_3 = new QWidget();
    tab_3->setObjectName(QStringLiteral("tab_3"));


    newTree = new QTreeWidget(tab_3);

    newTree->headerItem()->setText(0,QString());	//设置表头为空
    newTree->setGeometry(50,50,400,240);	//设置起始坐标和大小
    QStringList hraders;
    hraders<<" "<<"类型"<<"时间";
    newTree->setHeaderLabels(hraders);		//添加树表的表头
    QTreeWidgetItem *item1 = new QTreeWidgetItem(newTree);	//创建第一个父节点
    item1->setText(0,"111");
    item1->setCheckState(0,Qt::Unchecked);		//添加复选框，起始为未勾选
    item1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

    //Qt::ItemIsSelectable表示可选的
    //Qt::ItemIsUserCheckable项目上是否有复选框
    //Qt::ItemIsEnabled 项目上是否没有被禁用（Enabled可用/Disabled禁用）
    QTreeWidgetItem *item1_1 = new QTreeWidgetItem(item1);		//添加子节点
    item1_1->setText(0,"111_111");
    item1_1->setCheckState(0,Qt::Unchecked);
    item1_1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

    QTreeWidgetItem *item1_2 = new QTreeWidgetItem(item1);
    item1_2->setText(0,"111_222");
    item1_2->setCheckState(0,Qt::Unchecked);
    item1_2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

    QTreeWidgetItem *item1_3 = new QTreeWidgetItem(item1);
    item1_3->setText(0,"111_333");
    item1_3->setCheckState(0,Qt::Unchecked);
    item1_3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

    QTreeWidgetItem *item2 = new QTreeWidgetItem(newTree);
    item2->setText(0,"222");
    item2->setCheckState(0,Qt::Unchecked);
    item2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

    QTreeWidgetItem *item2_1 = new QTreeWidgetItem(item2);
    item2_1->setText(0,"222_222");
    item2_1->setCheckState(0,Qt::Unchecked);
    item2_1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
    item2_1->setText(1,"222_222");
    connect(newTree,SIGNAL(itemClicked(QTreeWidgetItem *, int)),this,SLOT(treeCheck(QTreeWidgetItem *, int)));

    //tab2 button
    ok_button = new QPushButton(tab_2);
    ok_button->setObjectName(QStringLiteral("pushButton"));
  //  ok_button->setGeometry(QRect(80, 80, 80, 22));

    ok_button->setText(QApplication::translate("MainWindow", "PushButton", 0));



    select_interface->addTab(glWidgetArea,tr("&tab1"));
    select_interface->addTab(tab_2,tr("&tab2"));
    select_interface->addTab(tab_3,tr("&tab3"));


    QGridLayout *centralLayout = new QGridLayout;

//    centralLayout->addWidget(select_interface, 2, 1);  //外层
 //   centralLayout->addWidget(vboxlayout, 2, 1);  //外层

    centralWidget->setLayout(vboxlayout);
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

    connect(caoche,SIGNAL(triggered(bool)),this,SLOT(on_caoche_triggered(bool)));
    connect(lines,SIGNAL(triggered(bool)),this,SLOT(on_lines_triggered(bool)));

}



void MainWindow::createActions()
{
    zoom_in  = new QAction(tr("zoom &in"), this);
    zoom_out  = new QAction(tr("zoom &out"), this);
    caoche  = new QAction(QIcon("/home/rd/glgl/ico/uvd.png"),tr("&File"),this);
    lines  = new QAction(QIcon("/home/rd/glgl/ico/auto.png"),tr("&File"),this);

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
    caoche->setCheckable(true);

    editToolBar->addAction(lines);
    lines->setCheckable(true);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_caoche_triggered(bool checked)
{
 //   std::cout<<"funck"<<std::endl;
    if(checked)
        this->glWidget->fillchecked = true;
    else
    {
        this->glWidget->fillchecked = false;
    }

    std::cout<<"checked: "<<checked<<std::endl;
}

void MainWindow::on_lines_triggered(bool checked)
{
 //   std::cout<<"funck"<<std::endl;
    if(checked)
        this->glWidget->bbbchecked = true;
    else
    {
        this->glWidget->bbbchecked = false;
    }

 //   std::cout<<"checked: "<<checked<<std::endl;
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


void MainWindow::treeCheck(QTreeWidgetItem *item, int column)
{
    if(Qt::Checked == item->checkState(0))		//若被选中
    {
        int count = item->childCount();			//得到选中的子节点个数
        if(count>0)								//若大于0，说明选中的是父节点，则将全部的子节点选中
        {
            for (int i = 0;i<count;i++) {
                item->child(i)->setCheckState(0,Qt::Checked);
            }
        }
        else {								//否则选中的是子节点
            PartiallyCheck(item);			//将节点传到函数中进行其他操作
        }
    }
    else if(Qt::Unchecked == item->checkState(0)){	//没有被选中
        int count = item->childCount();
        if(count>0)
        {
            for (int i = 0;i<count;i++) {
                item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }
        else {
            PartiallyCheck(item);
        }
    }
}

void MainWindow::PartiallyCheck(QTreeWidgetItem *item)
{
    //得到节点的父节点，首先判断是否为空，为空说明是父节点，则直接退出，若不加判断会造成程序异常退出。
    QTreeWidgetItem *parent = item->parent();
    if(parent==NULL)
        return;
    int selectedCount = 0;		//记录被选中的子节点个数
    int count = parent->childCount();		//记录子节点个数
    for (int i = 0;i<count ;i++) {			//父节点下的所有子节点，记录选中的子节点个数
        if(parent->child(i)->checkState(0)==Qt::Checked)
            selectedCount++;
    }
    if(selectedCount<=0)					//等于0说明没有子节点被选中，则将父节点取消选中
        parent->setCheckState(0,Qt::Unchecked);
    else if(selectedCount>0&&selectedCount<count)	//若大于0且小于总的子节点数，说明选中了一部分，则将父节点设置为半选中
        parent->setCheckState(0,Qt::PartiallyChecked);
    else {								//否则，全选中
        parent->setCheckState(0,Qt::Checked);
    }
}
