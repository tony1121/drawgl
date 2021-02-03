#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
// /   void keyPressEvent(QKeyEvent *event) override;
//    void resizeGL(int w, int h);



private:
    Ui::MainWindow *ui;
    QString filename;
    bool mFullScreen;
};

#endif // MAINWINDOW_H
