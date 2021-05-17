#ifndef FIZIKA_H
#define FIZIKA_H

#include <QMainWindow>

namespace Ui {
class fizika;
}

class fizika : public QMainWindow
{
    Q_OBJECT

public:
    explicit fizika(QWidget *parent = nullptr);
    ~fizika();
private slots:
    void on_action_triggered();

private:
    Ui::fizika *ui;
};

#endif // FIZIKA_H
