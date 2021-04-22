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

void MainWindow:: test_xlsx(){
    Document doc_xslx(xlsx_base_A);
    QString strSheetName = "Лист1";

    if (!doc_xslx.load()) {qWarning("Error xlsx file");} else {qWarning("File xlsx is open!!!");}

    //qDebug() << doc_xslx.read( row, col ).toDouble();
    //

    AbstractSheet* currentSheet = doc_xslx.sheet(strSheetName);
    int maxRow = -1;
    int maxCol = -1;
    currentSheet->workbook()->setActiveSheet(0);
    Worksheet* wsheet = (Worksheet*) currentSheet->workbook()->activeSheet();
    QVector<CellLocation> clList = wsheet->getFullCells( &maxRow, &maxCol );

    //qDebug() << clList;
    QVector <QVector <double>> base_a;
    for (int rc = 0; rc < maxRow; rc++)
    {
        QVector<double> tempValue;
        for (int cc = 0; cc < maxCol; cc++)
        {
            tempValue.push_back(doc_xslx.read(rc,cc).toDouble());
        }
        base_a.push_back(tempValue);
    }

    for ( int ic = 0; ic < clList.size(); ++ic )
    {
        CellLocation cl = clList.at(ic); // cell location

        int row = cl.row - 1;
        int col = cl.col - 1;

        QSharedPointer<Cell> ptrCell = cl.cell; // cell pointer

        // value of cell
        QVariant var = cl.cell.data()->value();
        double doub = var.toDouble();

        base_a[row][col] = doub;
    }

    /* Display matrix

    for (int rc = 0; rc < maxRow; rc++)
    {
        for (int cc = 0; cc < maxCol; cc++)
        {
            double doubCell = base_a[rc][cc];
            qDebug() << "( row : " << rc
                     << ", col : " << cc
                     << ") " << doubCell; // display cell value
        }
    }
    */

}

void MainWindow::on_pushButton_clicked()
{
    test_xlsx();
}
