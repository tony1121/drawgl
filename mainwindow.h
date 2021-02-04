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
//    void mouseMoveEvent();

private slots:
    void on_actionBbb_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    QString filename;
    bool mFullScreen;
};

#endif // MAINWINDOW_H
