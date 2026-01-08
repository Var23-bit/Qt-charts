#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLineSeries *series =new QLineSeries();
    series->append(0,0);
    series->append(1,3);
    series->append(2,4);
    series->append(3,2);
    series->append(4,1);
    series->append(5,7);
    series->append(6,9);
    series->append(7,3);
    series->append(8,9);
    series->append(9,7);


    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0,11);
    chart->axes(Qt::Horizontal).first()->setRange(2,0);
    chart->setVisible(true);

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setVisible(true);
    setCentralWidget(chartview);
}

MainWindow::~MainWindow()
{
    delete ui;
}
