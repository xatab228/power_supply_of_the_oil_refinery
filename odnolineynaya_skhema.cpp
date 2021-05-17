#include "odnolineynaya_skhema.h"
#include "ui_odnolineynaya_skhema.h"
#include <QtWidgets>
#include <QVBoxLayout>
#include <QLayout>
#include <QKeyEvent>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "ui_mainwindow.h"
#include <QInputEvent>
#include "QDebug"
#include "QPainterPath"
#include "QVector"
#include <complex>
#include <stdio.h>
#include <stdlib.h>

using namespace QXlsx;
using namespace std;

void Odnolineynaya_skhema::print_matrix(QVector <QVector <QString>> matrix){
    for (auto it: matrix)
    {
        for (auto git: it)
        {
            cout << git.toStdString() << "|";

        }
        cout << endl;
    }
    cout << "Matrix size: " << matrix.size() << " X " << matrix[0].size() << endl;
    matrix.clear();
}

void Odnolineynaya_skhema::xlsx_to_matrix(QString xlsx_base,QVector <QVector <QString>> *base_xlsx){
    Document doc_xslx(xlsx_base);
    QString strSheetName = "Лист1"; // name sheet on xlsx

    if (!doc_xslx.load()) {qWarning("Error xlsx file");} else {qWarning("File xlsx is open!!!");}


    AbstractSheet* currentSheet = doc_xslx.sheet(strSheetName);
    int maxRow = -1;
    int maxCol = -1;
    currentSheet->workbook()->setActiveSheet(0);
    Worksheet* wsheet = (Worksheet*) currentSheet->workbook()->activeSheet();
    QVector<CellLocation> clList = wsheet->getFullCells( &maxRow, &maxCol );


    for (int rc = 1; rc < maxRow+1; rc++)
    {
        QVector<QString> tempValue;
        for (int cc = 1; cc < maxCol+1; cc++)
        {
            tempValue.push_back(doc_xslx.read(rc,cc).toString());
        }
        base_xlsx->push_back(tempValue);
    }

}

void Odnolineynaya_skhema::string_to_complex(QString cc,QVector <QString> *complex_vector){
    QVector <double> pepa={0.0,0.0};
    string str = cc.toStdString();
    string c = "";
    for(int i = 0; i < str.size(); ++i){
        if (isdigit(str[i]) || str[i]=='.' || str[i]==',')
        {
            if(str[i] == ',')str[i]='.';
            c = c + str[i];
        }
        else if (c!="")
        {
            if (str[i] == 'i')pepa[1] = atof(c.c_str());
            if (str[i]!='i')pepa[0] = atof(c.c_str());
            c="";

        }
    }
    if (c!="")pepa[0] = atof(c.c_str());

    if (str.find('-') == 0 && pepa[0]!=0.0)pepa[0]=pepa[0]*(-1);
    if (str.find('-') == 0 && pepa[0]==0.0)pepa[1]=pepa[1]*(-1);//xz
    if (str.find('-',1) != -1 && str.find('-',1) == str.find('-'))pepa[1]=pepa[1]*(-1);
    if (str.find('-') == 0 && str.find('-',1) != -1)pepa[1]=pepa[1]*(-1);


    for (auto it: pepa)
    {
       complex_vector->push_back(QString::number(it));
    }
    pepa.clear();

}

float Odnolineynaya_skhema::stringСomplex_to_Re(QString complex){

    float Re=0;
    QString StrRe="";
    for(int i = 0; i < complex.size(); ++i){
        if(complex[i]!="-"){
            StrRe+=complex[i];
        }else{
            break;
        }
    }
  //   qDebug() <<StrRe;
    Re=StrRe.toFloat();
    return Re;

}
float Odnolineynaya_skhema::stringСomplex_to_Im(QString complex){
    float Im;
    bool im=false;
    QString StrIm="";
    for(int i = 0; i < complex.size(); ++i){
        if(complex[i]=="-"){
            im=true;
                i++;
        }
        if(im && complex[i]!="i"){
            StrIm+=complex[i];
        }
    }
    // qDebug() <<StrIm;
    Im=StrIm.toFloat();
    return Im;
}
void Odnolineynaya_skhema::multiplication_matrix(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix){
    if (first_matrix[0].size()!=second_matrix.size()){qWarning("Error size of matrix");}else{
        QVector <QVector <double>> pepa;
        pepa.resize(first_matrix.size());
        for (int i = 0; i < first_matrix.size(); ++i)pepa[i].resize(second_matrix[0].size());
        for (int i = 0;i<first_matrix.size();i++){
            for (int j = 0;j<second_matrix[0].size();j++){
                pepa[i][j] = 0;
                for(int k = 0;k<first_matrix[0].size();k++){
                    pepa[i][j] += first_matrix[i][k].toDouble() * second_matrix[k][j].toDouble();
                }
            }
        }
        for (auto it: pepa)
        {
            QVector<QString> tempValue;
            for (auto git: it)
            {
                tempValue.push_back(QString::number(git));

            }
            end_matrix->push_back(tempValue);
        }
        pepa.clear();

    };




}

void Odnolineynaya_skhema::multiplication_matrix_complex_on_complex(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix){
    QVector <QVector <QString>> pepa;
    pepa.resize(first_matrix.size());
    for (int i = 0; i < first_matrix.size(); ++i)pepa[i].resize(second_matrix[0].size());
    if (first_matrix[0].size()!=second_matrix.size()){qWarning("Error size of matrix");}else{
        QVector <QVector <QString>> pepa;
        pepa.resize(first_matrix.size());
        for (int i = 0; i < first_matrix.size(); ++i)pepa[i].resize(second_matrix[0].size());
        for (int i = 0;i<first_matrix.size();i++){
            for (int j = 0;j<second_matrix[0].size();j++){
                pepa[i][j] = "0";
                complex <double> z(0.0,0.0);
                for(int k = 0;k<first_matrix[0].size();k++){
                    QVector <QString> f_c_v;
                    QVector <QString> s_c_v;
                    string_to_complex(first_matrix[i][k],&f_c_v);
                    string_to_complex(second_matrix[k][j],&s_c_v);
                    complex <double> z1(f_c_v[0].toDouble(),f_c_v[1].toDouble());
                    complex <double> z2(s_c_v[0].toDouble(),s_c_v[1].toDouble());
                    z += z1 * z2;
                }
                if( z.imag() >= 0){
                    pepa[i][j]=QString::number(z.real()) + "+" + QString::number(z.imag())+"i";
                } else {pepa[i][j]=QString::number(z.real()) + QString::number(z.imag())+"i";}
                if (pepa[i][j]=="0+0i")pepa[i][j]="0";

            }
        }

        for (auto it: pepa)
        {
            QVector<QString> tempValue;
            for (auto git: it)
            {
                tempValue.push_back(git);

            }
           end_matrix->push_back(tempValue);
        }
        pepa.clear();
    }
}

void Odnolineynaya_skhema::transponse_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix){
    QVector <QVector <QString>> pepa;
    pepa.resize(matrix[0].size());
    for (int i = 0; i < matrix[0].size(); ++i)pepa[i].resize(matrix.size());

    for (int i = 0;i < matrix.size();++i){
        for (int j = 0;j < matrix[0].size();++j){
            pepa[j][i]=matrix[i][j];
        }
    }
    for (auto it: pepa)
    {
        QVector<QString> tempValue;
        for (auto git: it)
        {
            tempValue.push_back(git);

        }
       end_matrix->push_back(tempValue);
    }
    pepa.clear();

}

void Odnolineynaya_skhema::summ_matrix(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix){
    if (first_matrix.size()!=second_matrix.size() || first_matrix[0].size()!=second_matrix[0].size() ){qWarning("Error size of matrix");} else {
        QVector <QVector <QString>> pepa;
        pepa.resize(first_matrix.size());
        for (int i = 0; i < first_matrix.size(); ++i)pepa[i].resize(first_matrix[0].size());

        for(int i = 0;i < first_matrix.size();++i){
            for(int j = 0;j < first_matrix[0].size();++j){
                pepa[i][j] = QString::number(first_matrix[i][j].toDouble() + second_matrix[i][j].toDouble());
            }

        }
        for (auto it: pepa)
        {
            QVector<QString> tempValue;
            for (auto git: it)
            {
                tempValue.push_back(git);

            }
           end_matrix->push_back(tempValue);
        }
        pepa.clear();
    }

}

void Odnolineynaya_skhema::summ_matrix_complex_on_complex(QVector<QVector<QString> > first_matrix, QVector<QVector<QString> > second_matrix, QVector<QVector<QString> > *end_matrix){
    if (first_matrix.size()!=second_matrix.size() || first_matrix[0].size()!=second_matrix[0].size() ){qWarning("Error size of matrix");} else{
        QVector <QVector <QString>> pepa;
        pepa.resize(first_matrix.size());
        for (int i = 0; i < first_matrix.size(); ++i)pepa[i].resize(first_matrix[0].size());

        for(int i = 0;i < first_matrix.size();++i){
            for(int j = 0;j < first_matrix[0].size();++j){
                QVector <QString> f_c_v;
                QVector <QString> s_c_v;
                string_to_complex(first_matrix[i][j],&f_c_v);
                string_to_complex(second_matrix[i][j],&s_c_v);
                complex <double> z1(f_c_v[0].toDouble(),f_c_v[1].toDouble());
                complex <double> z2(s_c_v[0].toDouble(),s_c_v[1].toDouble());
                complex <double> z(0.0,0.0);
                z = z1 + z2;
                //cout<<z.real() << " "<< z.imag() <<" = " <<z1.imag()<<" + " <<z2.imag()<< endl;
                if( z.imag() >= 0){
                    pepa[i][j]=QString::number(z.real()) + "+" + QString::number(z.imag())+"i";
                } else {pepa[i][j]=QString::number(z.real()) + QString::number(z.imag())+"i";}
                if (pepa[i][j]=="0+0i")pepa[i][j]="0";
            }

        }
        for (auto it: pepa)
        {
            QVector<QString> tempValue;
            for (auto git: it)
            {
                tempValue.push_back(git);

            }
           end_matrix->push_back(tempValue);
        }
        pepa.clear();

    }

}

void Odnolineynaya_skhema::minus_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix){
    for (auto it: matrix)
    {
        QVector<QString> tempValue;
        for (auto git: it)
        {
            tempValue.push_back(QString::number(git.toDouble() * (-1)));

        }
       end_matrix->push_back(tempValue);
    }
    matrix.clear();
}

void Odnolineynaya_skhema::slau(QVector <QVector <QString>> matrix,QVector <QString> sv_chlen,QVector <QString> *end_matrix){
    QVector <QString> pepa;
    QVector <QString> x_n;
    pepa.resize(matrix.size());
    x_n.resize(matrix.size());
    QString eps_c = "0.001";
    QVector <QString> c_eps;
    string_to_complex(eps_c,&c_eps);
    complex <double> eps (c_eps[0].toDouble(),c_eps[1].toDouble());

    for (int i = 0; i < matrix.size(); i++)
    {
        QVector <QString> f_c_v;
        QVector <QString> s_c_v;
        string_to_complex(sv_chlen[i],&f_c_v);
        string_to_complex(matrix[i][i],&s_c_v);
        complex <double> z1(f_c_v[0].toDouble(),f_c_v[1].toDouble());
        complex <double> z2(s_c_v[0].toDouble(),s_c_v[1].toDouble());
        complex <double> z(0.0,0.0);
        z = z1 / z2;
        if( z.imag() >= 0){
            pepa[i]=QString::number(z.real()) + "+" + QString::number(z.imag())+"i";
        } else {pepa[i]=QString::number(z.real()) + QString::number(z.imag())+"i";}
        if (pepa[i]=="0+0i")pepa[i]="0";
    }



    do {
        for (int i = 0; i < matrix.size(); i++) {
            QVector <QString> fr_c_v;
            QVector <QString> sr_c_v;
            string_to_complex(sv_chlen[i],&fr_c_v);
            string_to_complex(matrix[i][i],&sr_c_v);
            complex <double> z1(fr_c_v[0].toDouble(),fr_c_v[1].toDouble());
            complex <double> z2(sr_c_v[0].toDouble(),sr_c_v[1].toDouble());
            complex <double> z(0.0,0.0);
            z = z1 / z2;
            if( z.imag() >= 0){
                x_n[i]=QString::number(z.real()) + "+" + QString::number(z.imag())+"i";
            } else {x_n[i]=QString::number(z.real()) + QString::number(z.imag())+"i";}
            if (x_n[i]=="0+0i")x_n[i]="0";

            for (int j = 0; j < matrix.size(); j++) {
                if (i == j)
                    continue;
                else {
                    QVector <QString> t_c_v;
                    QVector <QString> fi_c_v;
                    QVector <QString> si_c_v;
                    QVector <QString> b_c_v;

                    string_to_complex(matrix[i][j],&t_c_v);
                    string_to_complex(matrix[i][i],&b_c_v);
                    string_to_complex(pepa[i],&fi_c_v);
                    string_to_complex(x_n[i],&si_c_v);
                    complex <double> z1(t_c_v[0].toDouble(),t_c_v[1].toDouble());
                    complex <double> z2(b_c_v[0].toDouble(),b_c_v[1].toDouble());
                    complex <double> z3(fi_c_v[0].toDouble(),fi_c_v[1].toDouble());
                    complex <double> z(si_c_v[0].toDouble(),si_c_v[1].toDouble());
                    z -= z1 / z2 * z3;
                    if( z.imag() >= 0){
                        x_n[i]=QString::number(z.real()) + "+" + QString::number(z.imag())+"i";
                    } else {x_n[i]=QString::number(z.real()) + QString::number(z.imag())+"i";}
                    if (x_n[i]=="0+0i")x_n[i]="0";
                }
            }
        }


        bool flag = true;
        for (int i = 0; i < matrix.size() - 1; i++) {
            QVector <QString> lol_c_v;
            QVector <QString> kol_c_v;
            string_to_complex(x_n[i],&lol_c_v);
            string_to_complex(pepa[i],&kol_c_v);
            complex <double> z1(lol_c_v[0].toDouble(),lol_c_v[1].toDouble());
            complex <double> z2(kol_c_v[0].toDouble(),kol_c_v[1].toDouble());
            complex <double> z(0.0,0.0);
            z = z1 - z2;
            double re = z.real();
            double im = z.imag();
            if (z.real()<0)re = z.real()*(-1);
            if (z.imag()<0)im = z.imag()*(-1);
            z = complex <double> (re,im); // abs


            if (z.real() > eps.real() && z.imag() > eps.imag()) {
                flag = false;
                break;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            pepa[i] = x_n[i];
        }

        if (flag)
            break;
    } while (1);

    for (auto it: pepa)
    {
       end_matrix->push_back(it);
    }
    pepa.clear();

    // XZ Voobshe


}

void Odnolineynaya_skhema::obr_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix){
    QVector <QVector <QString>> pepa;
    QVector <QString> y;
    QVector <QString> itr;
    y.resize(matrix.size());
    pepa.resize(matrix.size());
    for (int i = 0; i < matrix.size(); ++i)pepa[i].resize(matrix[0].size());
    //int i, j, k;


    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (i == j)
            {
                y[j] = QString::number(1);
            }
            else
            {
                y[j] = QString::number(0);
            }
        }
        slau(matrix, y, &itr);
        for (int k = 0; k < matrix.size(); k++)
        {
            pepa[k][i] = itr[k];
        }
    }

    for (auto it: pepa)
    {
        QVector<QString> tempValue;
        for (auto git: it)
        {
            tempValue.push_back(git);

        }
       end_matrix->push_back(tempValue);
    }
    pepa.clear();
    // XZ Voobshe

}

void Odnolineynaya_skhema::Y_y(QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> * Y_y_matrix){
    QVector <QVector <QString>> pepa;
    QVector <QVector <QString>> pepa_two;
    QVector <QVector <QString>> a_t;
    QVector <QString> chek;
    multiplication_matrix_complex_on_complex(a_matrix,y_matrix,&pepa_two);
    transponse_matrix(a_matrix,&a_t);
    multiplication_matrix_complex_on_complex(pepa_two,a_t,&pepa);

    for (auto it: pepa)
    {
        QVector<QString> tempValue;
        for (auto git: it)
        {

            tempValue.push_back(git);

        }
       Y_y_matrix->push_back(tempValue);
    }
    pepa.clear();

}

void Odnolineynaya_skhema::J_matrix(QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> e_matrix,QVector <QVector <QString>> * j_matrix){
    QVector <QVector <QString>> pepa;
    QVector <QVector <QString>> a_m;
    QVector <QVector <QString>> pepa_two;
    minus_matrix(a_matrix,&a_m);
    multiplication_matrix_complex_on_complex(a_m,y_matrix,&pepa_two);
    multiplication_matrix_complex_on_complex(pepa_two,e_matrix,&pepa);

    for (auto it: pepa)
    {
        QVector<QString> tempValue;
        for (auto git: it)
        {

            tempValue.push_back(git);

        }
       j_matrix->push_back(tempValue);
    }
    pepa.clear();
}

void Odnolineynaya_skhema::U_y(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> * U_y){
    QVector <QVector <QString>> pepa;
    QVector <QVector <QString>> obr_y;
    QVector <QVector <QString>> pepa_two;
    obr_matrix(first_matrix,&obr_y);
    print_matrix(obr_y);
    // Dont work
}


void Odnolineynaya_skhema::I_matrix(QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> e_matrix,QVector <QVector <QString>> u_matrix,QVector <QVector <QString>> *i_matrix){
    QVector <QVector <QString>> pepa;
    QVector <QVector <QString>> pepa_two;
    QVector <QVector <QString>> a_t;
    QVector <QVector <QString>> i_matr;
    QVector <QString> chek;
    transponse_matrix(a_matrix,&a_t);
    multiplication_matrix_complex_on_complex(a_t,u_matrix,&pepa_two);
    summ_matrix_complex_on_complex(pepa_two,e_matrix,&pepa);
    multiplication_matrix_complex_on_complex(y_matrix,pepa,&i_matr);

    for (auto it: i_matr)
    {
        QVector<QString> tempValue;
        for (auto git: it)
        {

            tempValue.push_back(git);

        }
       i_matrix->push_back(tempValue);
    }
    pepa.clear();

}
//?? obr matrix
void Odnolineynaya_skhema::on_pushButton_clicked()
{
    QVector <QVector <QString>> base_a;
    QVector <QVector <QString>> base_e;
    QVector <QVector <QString>> base_y;
    QVector <QVector <QString>> i_m_test;
    xlsx_to_matrix(xlsx_base_A,&base_a);
    xlsx_to_matrix(xlsx_base_E,&base_e);
    xlsx_to_matrix(xlsx_base_Y,&base_y);
    xlsx_to_matrix(xlsx_base_U,&u_y);
    xlsx_to_matrix(xlsx_base_I,&i_m_test);
    //multiplication_matrix_complex_on_complex(base_a,base_y,&matrix_end);
    //transponse_matrix(base_a,&matrix_end);
    //string_to_complex("-5-0.1i",&c_v);



    // TESTS FUNCTION
    // Display_matrix
    //Y_y(base_a,base_y,&y_y); // --true
    //J_matrix(base_a,base_y,base_e,&j); // --true
    //U_y(base_y,j,&u_y);
    I_matrix(base_y,base_a,base_e,u_y,&i_m);
    print_matrix(i_m);
    print_matrix(i_m_test);
    //transponse_matrix(base_a,&matrix_end);
    //cout << "////////////////////////////////////////"<<endl;
    //print_matrix(matrix_end);


    //*/
    // Display_complecs_number
    /*
    for (auto it: c_v)
    {
      qDebug() << it;
    }
    */

    // SOLVE:
    // Yy = A * Y * Aт
    // J = -A * Y * E
    // Uy = Yy^(-1) * J
    // I = Y * (Aт * Uy + E)


}

Odnolineynaya_skhema::Odnolineynaya_skhema(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Odnolineynaya_skhema)
{
    on_pushButton_clicked();
    ui->setupUi(this);
    ImageWidget=this->findChild<QWidget*>("widget");
    HorizontalBar=this->findChild<QScrollBar*>("horizontalScrollBar");
    HorizontalBar->setMinimum(0);
    HorizontalBar->setMaximum(3500);
    HorizontalBar->setFocusPolicy(Qt::StrongFocus);

    QObject::connect(HorizontalBar, &QScrollBar::valueChanged,
                         this, &Odnolineynaya_skhema::HorizontalScroll);


    VerticalBar=this->findChild<QScrollBar*>("verticalScrollBar");
    VerticalBar->setMinimum(0);
    VerticalBar->setMaximum(1400);
    VerticalBar->setFocusPolicy(Qt::StrongFocus);


    QObject::connect(VerticalBar, &QScrollBar::valueChanged,
                         this, &Odnolineynaya_skhema::VerticalScroll);

    S_Label =this->findChild<QLabel*>("label_S1");
   /* qDebug() <<  u_y[0][0];
    qDebug() << stringСomplex_to_Re(u_y[0][0]);
    qDebug() << stringСomplex_to_Im(u_y[0][0]);

    float Re=stringСomplex_to_Re(u_y[0][0])-stringСomplex_to_Re(u_y[4][0])*3;
    float Im=stringСomplex_to_Im(u_y[0][0])-stringСomplex_to_Im(u_y[4][0])*3;
    QString StrRe="";
    QString StrIm="";
    StrRe.setNum(Re);
    StrIm.setNum(Im);
    StrIm+="i";

    S_Label->setText("S= "+StrRe+StrIm);*/

    for(int i=0;i<23;i++){
        QString labelNumber="";
        labelNumber.setNum(i+1);
        I_Label=this->findChild<QLabel*>("label_I"+labelNumber);
        I_Label->setText("I= "+i_m[i][0]);
    }


    for(int i=0;i<28;i++){
        QString labelNumber="";
        labelNumber.setNum(i+1);
         S_Label =this->findChild<QLabel*>("label_S"+labelNumber);
         S_Label->setText("S= "+i_m[i][0]);
    }



}

Odnolineynaya_skhema::~Odnolineynaya_skhema()
{
    delete ui;
}



void Odnolineynaya_skhema::VerticalScroll(){
    ImageWidget->setGeometry(ImageWidget->geometry().x(),-VerticalBar->value(),ImageWidget->geometry().width(),ImageWidget->geometry().height());

}

void Odnolineynaya_skhema::HorizontalScroll(){
    ImageWidget->setGeometry(-HorizontalBar->value(),ImageWidget->geometry().y(),ImageWidget->geometry().width(),ImageWidget->geometry().height());

}

void Odnolineynaya_skhema::LeftScroll(){

     ImageWidget->setGeometry(ImageWidget->geometry().x()+50,ImageWidget->geometry().y(),ImageWidget->geometry().width(),ImageWidget->geometry().height());


}
void Odnolineynaya_skhema::RightScroll(){
     ImageWidget->setGeometry(ImageWidget->geometry().x()-50,ImageWidget->geometry().y(),ImageWidget->geometry().width(),ImageWidget->geometry().height());

}
void Odnolineynaya_skhema::UpScroll(){
     ImageWidget->setGeometry(ImageWidget->geometry().x(),ImageWidget->geometry().y()+50,ImageWidget->geometry().width(),ImageWidget->geometry().height());

}
void Odnolineynaya_skhema::DownScroll(){
     ImageWidget->setGeometry(ImageWidget->geometry().x(),ImageWidget->geometry().y()-50,ImageWidget->geometry().width(),ImageWidget->geometry().height());

}

void Odnolineynaya_skhema::keyPressEvent(QKeyEvent *event)
{

    qDebug() << "pressed key";
    qDebug() << event;
    if(event->key() == Qt::Key_Right)
    {
        RightScroll();
    }
    if(event->key() == Qt::Key_Left)
    {
        LeftScroll();
    }
    if(event->key() == Qt::Key_Up)
    {
        UpScroll();
    }
    if(event->key() == Qt::Key_Down)
    {
        DownScroll();
    }
}


