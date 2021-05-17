#include "vhod.h"
#include "ui_vhod.h"
#include <QMessageBox>
vhod::vhod(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vhod)
{
    ui->setupUi(this);
}

vhod::~vhod()
{
    delete ui;
}

void vhod::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->pass->text();

    if(login == "matvey1710" && password == "1710") {
        hide();
        QMessageBox::information(this,"Войдено в систему","Вы успешно авторизовались");
    } else {
        ui->statusBar->showMessage("Логин или пароль введены неверно");
    }
}
