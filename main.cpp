#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QIcon icon;
    icon.addPixmap(QPixmap(":/home/rd/perception_l3/pc/modules/ab_perception/init/MSIF.jpg"),QIcon::Normal,QIcon::On);
 //  icon.addFile(QStringLiteral("/home/rd/perception_l3/pc/modules/ab_perception/init/MSIF.jpg"), QSize(), QIcon::Normal, QIcon::Off);

    w.setWindowIcon(icon);


    return a.exec();
}
