#include "mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::redraw(){
    this->a = (a + 1) % 8;
    this->b = (b + 1) % 9;
    this->c = (c + 1) % 15;
    this->update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
   QPainter myp(this);
   QPixmap pixmap1(":/images/qt1.png");
   myp.fillRect(0, 0, 1400, 880, QBrush(Qt::white));
   myp.drawPixmap(5, 0, 1323, 870, pixmap1);
   myp.drawLine(1400, 0, 1400, 880);
   int x = this->a;
   int y = this->b;
   int z = this->c;

   QPen pen;
   pen.setWidth(2);
   pen.setColor(Qt::black);
   //pen.setDashPattern({0.0, 1.0 + x, 1.0, 10.0 - x});
   pen.setDashPattern({std::min(4.0, std::max(0.0, x - 4.0)), std::min(0.0 + x, 4.0), std::min(4.0, 8.0 - x), std::max(4.0 - x, 0.0)});
   myp.setPen(pen);




   static const QPoint points_water_1[5] = {QPoint(1052, 179),QPoint(1052, 339),QPoint(975, 339),QPoint(397, 339),QPoint(397, 416)};
   static const QPoint points_water_2[3] = {QPoint(1202, 262),QPoint(975, 262),QPoint(975, 339),};
   static const QPoint points_water_3[2] = {QPoint(725, 179),QPoint(725, 339),};
   static const QPoint points_water_4[3] = {QPoint(261, 450),QPoint(214, 450),QPoint(214, 638),};
   static const QPoint points_water_5[5] = {QPoint(214, 638),QPoint(180, 638),QPoint(180, 668),};
   static const QPoint points_water_buf_1[3] = {QPoint(179,695),QPoint(179,700),QPoint(215, 700),};
   static const QPoint points_water_6[5] = {QPoint(214, 638),QPoint(252, 638),QPoint(252, 668),};
   static const QPoint points_water_buf_2[3] = {QPoint(252,695),QPoint(252,700),QPoint(215, 700),};
   static const QPoint points_water_7[2] = {QPoint(215, 700),QPoint(215, 713)};
   static const QPoint points_water_Ostatok_1[3] = {QPoint(215, 708),QPoint(99, 708),QPoint(99, 758)};
   static const QPoint points_water_Ostatok_2[2] = {QPoint(99, 740),QPoint(120, 740)};
   static const QPoint points_water_Ploshad_1[12] = {QPoint(374, 784),QPoint(374, 797),QPoint(263, 797),QPoint(263, 745),QPoint(239, 745),
                                                           QPoint(239,765),QPoint(192,765),QPoint(192,755),QPoint(205,755),QPoint(205,745),QPoint(215, 745),QPoint(215, 738)};
   static const QPoint points_water_Ploshad_2[4] = {QPoint(215, 745),QPoint(239, 745),QPoint(239, 745),QPoint(239, 745)};
   static const QPoint points_water_Group_1[3] = {QPoint(398, 545),QPoint(434, 545),QPoint(434, 670),};
   static const QPoint points_water_Group_2[3] = {QPoint(434, 670),QPoint(374, 670),QPoint(374,703)};
   static const QPoint points_water_Group_3[3] = {QPoint(434, 670),QPoint(523, 670),QPoint(523, 711)};
   static const QPoint points_water_Right_Side_Group_1[7] = {QPoint(374, 755),QPoint(430, 755),QPoint(430,810),QPoint(430,810),QPoint(146,810),QPoint(146,723),
                                                              QPoint(99,723) };
   static const QPoint points_water_Right_Side_Group_2[4]= {QPoint(264,587),QPoint(31,587),QPoint(31,723),QPoint(99,723)};
   static const QPoint points_water_Right_Side_Group_2_1[4]= {QPoint(374,730),QPoint(466,730),QPoint(466,697),QPoint(570,697),};
   static const QPoint points_water_Right_Side_Group_2_2[3]= {QPoint(551,697),QPoint(551,705),QPoint(523,705),};
   static const QPoint points_water_Holle[3]= {QPoint(523,735),QPoint(523,771),QPoint(505,787)};
   static const QPoint points_water_Center_Nas_1[3]= {QPoint(523,690),QPoint(570,690),QPoint(570,710)};
   static const QPoint points_water_Center_Nas_2[3]= {QPoint(570,736),QPoint(570,757),QPoint(523,757)};


    myp.drawPolyline(points_water_1, 5); //сепарат высокого давления
    myp.drawPolyline(points_water_2, 3); //престная вода со скважены
    myp.drawPolyline(points_water_3, 2); //сепарат низкого давления
    myp.drawPolyline(points_water_4, 3);// путь к бустерам
    myp.drawPolyline(points_water_5, 3);//группа бустерных насосов (2 шт)
    myp.drawPolyline(points_water_buf_1, 3);
    myp.drawPolyline(points_water_buf_2, 3);
    myp.drawPolyline(points_water_6, 3);//группа бустерных насосов (4 шт)
    myp.drawPolyline(points_water_7, 2);
    myp.drawPolyline(points_water_Ostatok_1, 3);//возрат остаток в систему
    myp.drawPolyline(points_water_Ostatok_2, 2);//возрат остаток в систему стрелка в право
    myp.drawPolyline(points_water_Ploshad_1, 12);//площадка А и В
    myp.drawPolyline(points_water_Ploshad_2, 4);//площадка А и В
    myp.drawPolyline(points_water_Group_1, 3);//группа бустерных насосов (2 шт)
    myp.drawPolyline(points_water_Group_2, 3);//группа бустерных насосов (2 шт)
    myp.drawPolyline(points_water_Group_3, 3);//группа бустерных насосов (2 шт)
    myp.drawLine(374,728,374,761);
    myp.drawPolyline(points_water_Right_Side_Group_1, 7);//возрат остаток в систему
    myp.drawPolyline(points_water_Right_Side_Group_2, 4);//возрат остаток в систему
    myp.drawPolyline(points_water_Right_Side_Group_2_1, 4);
    myp.drawPolyline(points_water_Right_Side_Group_2_2, 3);
    myp.drawPolyline(points_water_Holle, 3);//Скважена В-1 и А-5
    myp.drawLine(523,771,541,787);//Скважена В-1 и А-5
    myp.drawPolyline(points_water_Center_Nas_1, 3);//Центральный насос
    myp.drawPolyline(points_water_Center_Nas_2, 3);//Центральный насос
    myp.drawPolyline(points_water_1, 5); //сепарат высокого давления
    myp.drawPolyline(points_water_2, 3); //престная вода со скважены
    myp.drawPolyline(points_water_3, 2); //сепарат низкого давления
    myp.drawPolyline(points_water_4, 3);// путь к бустерам
    myp.drawPolyline(points_water_5, 3);//группа бустерных насосов (2 шт)
    myp.drawPolyline(points_water_buf_1, 3);
    myp.drawPolyline(points_water_buf_2, 3);
    myp.drawPolyline(points_water_6, 3);//группа бустерных насосов (4 шт)
    myp.drawPolyline(points_water_7, 2);
    myp.drawPolyline(points_water_Ostatok_1, 3);//возрат остаток в систему
    myp.drawPolyline(points_water_Ostatok_2, 2);//возрат остаток в систему стрелка в право

    pen.setDashPattern({std::max(0.0, y - 5.0), std::min(2.0, std::max(0.0, y - 3.0)), std::min(1.0, std::max(0.0, y - 2.0)),
                           std::min(2.0, std::max(0.0, y - 0.0)), std::min(4.0, 9.0 - y),
                           std::max(0.0, std::min(2.0, 5.0 - y)), std::max(0.0, std::min(1.0, 3.0 - y)), std::max(0.0, 2.0 - y)});

    pen.setColor("orange");
    myp.setPen(pen);


    static const QPoint points_Gas_Seport_1[3]= {QPoint(1119,179),QPoint(1119,243),QPoint(188,243)};

    myp.drawPolyline(points_Gas_Seport_1, 3);
    myp.drawLine(792,179,792,243);
    myp.drawLine(188,119,297,119);
    myp.drawLine(322,119,403,119);
    myp.drawLine(188,188,297,188);
    myp.drawLine(320,188,417,188);
    myp.drawLine(446,188,496,188);
    myp.drawLine(530,168,578,168);
    myp.drawLine(530,180,578,180);
    myp.drawLine(188,46,188,342);//без анимации


    QPen pen2;
    pen2.setWidth(2);
    myp.setPen(pen2);
    static const QPoint points_oil_1[2] = {QPoint(1261, 90),QPoint(1120, 90)};//с месторождений
    static const QPoint points_oil_2[2] = {QPoint(1051, 90),QPoint(953, 90)};// в нагреватель второй ступени
    static const QPoint points_oil_3[2] = {QPoint(909, 90),QPoint(793, 90)};//в сепаратор низкого давления
    static const QPoint points_oil_4[5] = {QPoint(725, 90),QPoint(705, 90),QPoint(705, 369),QPoint(741, 369),QPoint(741, 415)};//в б нефть подг и хр
    static const QPoint points_oil_5[6] = {QPoint(725, 90),QPoint(705, 90),QPoint(705, 369),QPoint(741, 369),
                                           QPoint(987, 369),QPoint(987, 416)};//в а нефть подг и хр
    static const QPoint points_oil_6[2] = {QPoint(741, 620),QPoint(741, 762)};//в группа бустерных насосов
    static const QPoint points_oil_7[2] = {QPoint(741, 786),QPoint(741, 799)};//группа трубопроводных нефтяных насосов
    static const QPoint points_oil_8[2] = {QPoint(741, 822),QPoint(741, 847)};//на терминал
    static const QPoint points_oil_9[4] = {QPoint(741, 833),QPoint(723, 833),QPoint(723, 417),QPoint(626, 417)};//с нефть хр
    static const QPoint points_oil_10[5] = {QPoint(1122, 622),QPoint(1122, 663),QPoint(1047, 663),QPoint(1047, 716),QPoint(978, 716)};//в цирк насос
    static const QPoint points_oil_11[2] = {QPoint(930, 716),QPoint(723, 716)};//в с нефть хр
    static const QPoint points_oil_12[6] = {QPoint(930, 716),QPoint(898, 716),QPoint(898, 763),QPoint(1166, 763),
                                            QPoint(1166, 417),QPoint(1121, 417)};//в а нефть подг и хр
    static const QPoint points_oil_13[3] = {QPoint(626, 622),QPoint(626, 663),QPoint(1047, 663)};//в цирк насос
    static const QPoint points_oil_14[2] = {QPoint(867, 620),QPoint(867, 663)};//в цирк насос
    static const QPoint points_oil_15[3] = {QPoint(987, 622),QPoint(987, 649),QPoint(741, 649)};//в
    static const QPoint points_oil_16[5] = {QPoint(930, 716),QPoint(898, 716),QPoint(898, 229),
                                            QPoint(1009, 229),QPoint(1009, 90)};//в нагреватель нефти второй ступени


    myp.drawPolyline(points_oil_1, 2);
    myp.drawPolyline(points_oil_2, 2);
    myp.drawPolyline(points_oil_3, 2);
    myp.drawPolyline(points_oil_4, 5);
    myp.drawPolyline(points_oil_5, 6);
    myp.drawPolyline(points_oil_6, 2);
    myp.drawPolyline(points_oil_7, 2);
    myp.drawPolyline(points_oil_8, 2);
    myp.drawPolyline(points_oil_9, 4);
    myp.drawPolyline(points_oil_10, 5);
    myp.drawPolyline(points_oil_11, 2);
    myp.drawPolyline(points_oil_12, 6);
    myp.drawPolyline(points_oil_13, 3);
    myp.drawPolyline(points_oil_14, 2);
    myp.drawPolyline(points_oil_15, 3);
    myp.drawPolyline(points_oil_16, 5);

    pen2.setWidth(4);
    myp.setPen(pen2);
    pen2.setDashPattern({0, 0.0 + z, 1, 14.0 - z});
    myp.setPen(pen2);
    myp.drawPolyline(points_oil_1, 2);
    myp.drawPolyline(points_oil_2, 2);
    myp.drawPolyline(points_oil_3, 2);
    myp.drawPolyline(points_oil_4, 5);
    myp.drawPolyline(points_oil_5, 6);
    myp.drawPolyline(points_oil_6, 2);
    myp.drawPolyline(points_oil_7, 2);
    myp.drawPolyline(points_oil_8, 2);
    myp.drawPolyline(points_oil_9, 4);
    myp.drawPolyline(points_oil_10, 5);
    myp.drawPolyline(points_oil_11, 2);
    myp.drawPolyline(points_oil_12, 6);
    myp.drawPolyline(points_oil_13, 3);
    myp.drawPolyline(points_oil_14, 2);
    myp.drawPolyline(points_oil_15, 3);
    myp.drawPolyline(points_oil_16, 5);
    myp.drawPolyline(points_oil_16, 5);


  if (!this->keke){
       QTimer *timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(redraw()));
       timer->start(25);
       this->keke = true;
   }




}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
     qDebug() << "Mouse pressed X position";
    qDebug() << event->x();

    qDebug() << "Mouse pressed Y position";
    qDebug() << event->y();


}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     qDebug() << "Mouse Realease X position";
    qDebug() << event->x();

    qDebug() << "Mouse Realease Y position";
    qDebug() << event->y();

}

void MainWindow::on_checkBoxShowGrid_clicked(bool checked)
{

}

void MainWindow::print_matrix(QVector <QVector <QString>> matrix){
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

void MainWindow::xlsx_to_matrix(QString xlsx_base,QVector <QVector <QString>> *base_xlsx){
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

void MainWindow::string_to_complex(QString cc,QVector <QString> *complex_vector){
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

    if (str.find('-') == 0)pepa[0]=pepa[0]*(-1);//xz
    if (str.find('-',1) > 0)pepa[1]=pepa[1]*(-1);
    if (str.find('-') == 0 && pepa[0]==0.0)pepa[1]=pepa[1]*(-1);

    for (auto it: pepa)
    {
       complex_vector->push_back(QString::number(it));
    }
    pepa.clear();

}

void MainWindow::multiplication_matrix(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix){
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

void MainWindow::multiplication_matrix_complex_on_complex(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix){
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

void MainWindow::transponse_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix){
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

void MainWindow::summ_matrix(QVector <QVector <QString>> first_matrix,QVector <QVector <QString>> second_matrix,QVector <QVector <QString>> *end_matrix){
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

void MainWindow::summ_matrix_complex_on_complex(QVector<QVector<QString> > first_matrix, QVector<QVector<QString> > second_matrix, QVector<QVector<QString> > *end_matrix){
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

void MainWindow::minus_matrix(QVector <QVector <QString>> matrix,QVector <QVector <QString>> *end_matrix){
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

void MainWindow::Y_y(QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> * Y_y_matrix){
    QVector <QVector <QString>> pepa;
    QVector <QVector <QString>> pepa_two;
    QVector <QVector <QString>> a_t;
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

void MainWindow::J_matrix(QVector <QVector <QString>> a_matrix,QVector <QVector <QString>> y_matrix,QVector <QVector <QString>> e_matrix,QVector <QVector <QString>> * j_matrix){
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


//?? obr matrix

void MainWindow::on_pushButton_clicked()
{
    QVector <QVector <QString>> base_a;
    QVector <QVector <QString>> base_e;
    QVector <QVector <QString>> base_y;
    QVector <QVector <QString>> y_y;
    QVector <QVector <QString>> j;
    xlsx_to_matrix(xlsx_base_A,&base_a);
    xlsx_to_matrix(xlsx_base_E,&base_e);
    xlsx_to_matrix(xlsx_base_Y,&base_y);
    //multiplication_matrix_complex_on_complex(base_a,base_y,&matrix_end);
    //transponse_matrix(base_a,&matrix_end);
    //string_to_complex("-5-0.1i",&c_v);



    // TESTS FUNCTION
    // Display_matrix
    Y_y(base_a,base_y,&y_y);
    //J_matrix(base_a,base_y,base_e,&j);
    print_matrix(y_y);
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
