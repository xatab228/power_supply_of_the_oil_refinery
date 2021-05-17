#ifndef MATEMATIKA_H
#define MATEMATIKA_H

#include <QMainWindow>

namespace Ui {
class matematika;
}

class matematika : public QMainWindow
{
    Q_OBJECT

public:
    explicit matematika(QWidget *parent = nullptr);
    ~matematika();

private slots:
    void on_action_triggered();

private:
    Ui::matematika *ui;
};

#endif // MATEMATIKA_H
