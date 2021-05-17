#ifndef ODNOLINEYNAYA_SKHEMA_H
#define ODNOLINEYNAYA_SKHEMA_H

#include <QDialog>
#include <QLabel>
#include <QScrollArea>
#include <mainwindow.h>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include "QVector"
#include <sstream>
#include <complex>

namespace Ui {
class Odnolineynaya_skhema;
}

class Odnolineynaya_skhema : public QDialog
{
    Q_OBJECT

public:
    explicit Odnolineynaya_skhema(QWidget *parent = nullptr);
    ~Odnolineynaya_skhema();
     QLabel* I_Label;
     QLabel* S_Label;
      QPixmap scaled;
       QPixmap  screenPixmap;
     QScrollArea* scrollArea;
     QWidget* ImageWidget;
     QScrollBar* HorizontalBar;
      QScrollBar* VerticalBar;

     int scaletParam=140;
//Код Матвея
     QString xlsx_base_A = ":/base/base/matrix_a.xlsx";
     QString xlsx_base_E = ":/base/base/matrix_e.xlsx";
     QString xlsx_base_Y = ":/base/base/matrix_y.xlsx";
     QString xlsx_base_U = ":/base/base/matrix_u.xlsx"; // temporarily
     QString xlsx_base_I = ":/base/base/matrix_i.xlsx"; // temporarily

     virtual void print_matrix(QVector <QVector <QString>> matrix);
     virtual void xlsx_to_matrix(QString xlsx_base,QVector <QVector <QString>> *base_xlsx);
     virtual void string_to_complex(QString cc,QVector <QString> *complex_vector);
     virtual void multiplication_matrix(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix);
     virtual void multiplication_matrix_complex_on_complex(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix);
     virtual void summ_matrix(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix);
     virtual void summ_matrix_complex_on_complex(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix);
     virtual void transponse_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix);
     virtual void minus_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix);
     virtual void Y_y(QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> * Y_y_matrix);
     virtual void slau(QVector <QVector <QString>> matrix,QVector <QString> sv_chlen,QVector <QString> *end_matrix);
     virtual void obr_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix);
     virtual void J_matrix(QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> e_matrix,QVector <QVector <QString>> * j_matrix);
     virtual void U_y(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> * U_y);
     virtual void I_matrix(QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> e_matrix,QVector <QVector <QString>> u_matrix,QVector <QVector <QString>> * i_matrix);

     void on_pushButton_clicked();

     float stringСomplex_to_Re(QString complex);
     float stringСomplex_to_Im(QString complex);


     QVector <QVector <QString>> y_y;
     QVector <QVector <QString>> j;
     QVector <QVector <QString>> u_y;
     QVector <QVector <QString>> i_m;







public slots:
     void HorizontalScroll();
     void VerticalScroll();


protected:


       void LeftScroll();
     void RightScroll();
     void UpScroll();
     void DownScroll();

    void keyPressEvent(QKeyEvent *event);



private:
    Ui::Odnolineynaya_skhema *ui;

};

#endif // ODNOLINEYNAYA_SKHEMA_H
