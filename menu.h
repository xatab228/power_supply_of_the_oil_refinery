#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <MainWindow.h>

#include <vhod.h>
#include <fizika.h>
#include <primenenie.h>
#include <matematika.h>
namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_6_triggered();

    void on_action_5_triggered();

    void on_action_triggered();

private:
    Ui::menu *ui;
    MainWindow * man;
    vhod * avt;
    fizika *fiz;
    primenenie * prim;
    matematika * matem;
};

#endif // MENU_H
