#include "primenenie.h"
#include "ui_primenenie.h"

primenenie::primenenie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::primenenie)
{
    ui->setupUi(this);
}

primenenie::~primenenie()
{
    delete ui;
}

void primenenie::on_action_triggered()
{
   close();
}
