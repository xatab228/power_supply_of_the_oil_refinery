#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <iostream>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include "QVector"
#include <sstream>
#include <complex>
#include <primenenie.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);
    int a = 0;
    int b = 0;
    int c = 0;

    bool keke = false;
    virtual void mousePressEvent(QMouseEvent *event);


private:
    Ui::MainWindow *ui;
primenenie * prim;
public slots:
    void redraw();
private slots:

    void on_pushButton_clicked();
   // void on_pushButton2_clicked();
    void on_pushButton_4_clicked();
};
#endif // MAINWINDOW_H
