#ifndef VHOD_H
#define VHOD_H

#include <QMainWindow>

namespace Ui {
class vhod;
}

class vhod : public QMainWindow
{
    Q_OBJECT

public:
    explicit vhod(QWidget *parent = nullptr);
    ~vhod();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vhod *ui;
};

#endif // VHOD_H
