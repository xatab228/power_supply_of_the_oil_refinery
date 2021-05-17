#include "matematika.h"
#include "ui_matematika.h"

matematika::matematika(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::matematika)
{
    ui->setupUi(this);
}

matematika::~matematika()
{
    delete ui;
}

void matematika::on_action_triggered()
{
    close();
}
