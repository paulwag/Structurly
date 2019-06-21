#include <iostream>
#include <QTableWidget>
#include <QHeaderView>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    launch();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::launch() {

    //Timeline erstellen
    auto tableWidget = new QTableWidget(96, 2, ui->timeline_area);

    // Timeline Layout
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->setShowGrid(false);

    int current_hour = 0;
    for(int i = 0; i < 96; i++) {
        QString minutes, daytime, hours;
        hours = current_hour;

        // Minuten hinzufügen
        if(i % 4 == 0) {
            minutes = ":00";
            current_hour++;
        }
        else if(i % 4 == 1)
            minutes = ":15";
        else if(i % 4 == 2)
            minutes = ":30";
        else
            minutes = ":45";

        daytime = hours + minutes;
        tableWidget->setItem(i, 0, new QTableWidgetItem(daytime));
    }

    tableWidget->setItem(0, 1, new QTableWidgetItem("Hello"));
    tableWidget->setItem(0, 0, new QTableWidgetItem("00:00"));


}


void MainWindow::on_create_task_btn_clicked()
{
    QString new_text = "Task wurde angelegt";
    ui->status_label->setText(new_text);
    ui->status_label->repaint();

    std::cout << "btn gedrueckt";
}
