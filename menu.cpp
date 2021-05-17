#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "ui_mainwindow.h"
#include <QInputEvent>
#include "QDebug"
#include "QPainterPath"
#include "QVector"
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <QStandardItemModel>
#include <QtMath>

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    man = new MainWindow(this);
    man->show();
}

void menu::on_action_2_triggered()
{
   QApplication::quit();
}

void menu::on_action_3_triggered()

{
     ui->statusbar->showMessage("Программу разработали студенты группы 351812. Версия программы: v0.1.5");
}

void menu::on_action_4_triggered()
{
   avt = new vhod(this);
    avt->show();
}

void menu::on_action_6_triggered()
{
    fiz = new fizika(this);
    fiz->show();
}

void menu::on_action_5_triggered()
{
    matem= new matematika(this);
    matem->show();
}

void menu::on_action_triggered()
{
    prim= new primenenie(this);
    prim->show();
}
