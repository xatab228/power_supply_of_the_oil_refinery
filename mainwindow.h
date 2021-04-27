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
    //QVector <QVector <double>> base_test;
    QString xlsx_base_A = "E:/Project_all/Project_startup/new_electro_1/base/matrix_a.xlsx";
    QString xlsx_base_E = "E:/Project_all/Project_startup/new_electro_1/base/matrix_e.xlsx";
    QString xlsx_base_Y = "E:/Project_all/Project_startup/new_electro_1/base/matrix_y.xlsx";
    bool keke = false;
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void print_matrix(QVector <QVector <QString>> matrix);
    virtual void xlsx_to_matrix(QString xlsx_base,QVector <QVector <QString>> *base_xlsx);
    virtual void string_to_complex(QString cc,QVector <QString> *complex_vector);
    virtual void multiplication_matrix(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix);
    virtual void multiplication_matrix_complex_on_complex(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix);
    virtual void summ_matrix(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix);
    virtual void summ_matrix_complex_on_complex(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix);
    virtual void transponse_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix);
    virtual void minus_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix);
    virtual void Y_y(QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> * Y_y_matrix);
    virtual void J_matrix(QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> e_matrix,QVector <QVector <QString>> * j_matrix);
    virtual void  mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

public slots:
    void redraw();
private slots:

    void on_checkBoxShowGrid_clicked(bool checked);
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
