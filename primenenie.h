#ifndef PRIMENENIE_H
#define PRIMENENIE_H

#include <QMainWindow>

namespace Ui {
class primenenie;
}

class primenenie : public QMainWindow
{
    Q_OBJECT

public:
    explicit primenenie(QWidget *parent = nullptr);
    ~primenenie();

private slots:
    void on_action_triggered();

private:
    Ui::primenenie *ui;
};

#endif // PRIMENENIE_H
