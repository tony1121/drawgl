#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

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


    void on_actionClose_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    QString filename;
    bool mFullScreen;
        QTimer *tim;

public slots:
        void onTimeOut();
public:
        QLabel  *m_statusLabel;
        QLabel  *m_statusLabel2;
};

#endif // MAINWINDOW_H
