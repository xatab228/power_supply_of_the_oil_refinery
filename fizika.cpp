#include "fizika.h"
#include "ui_fizika.h"

fizika::fizika(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fizika)
{
    ui->setupUi(this);
}

fizika::~fizika()
{
    delete ui;
}
void fizika::on_action_triggered()
{
    close();
}
