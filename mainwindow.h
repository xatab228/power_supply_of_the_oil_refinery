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
    QString xml_base_A = "base/matrix_a.xml";
    QString xml_base_E = "base/matrix_e.xml";
    QString xml_base_Y = "base/matrix_y.xml";
    bool keke = false;
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void  mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

public slots:
    void redraw();
private slots:

    void on_checkBoxShowGrid_clicked(bool checked);
};
#endif // MAINWINDOW_H
