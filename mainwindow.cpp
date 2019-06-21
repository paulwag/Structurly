#include <iostream>
#include <QTableWidget>
#include <QHeaderView>
#include <QApplication>
#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"

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
    auto tableWidget = ui->timeline_table;

    // Timeline Layout
    tableWidget->setRowCount(96);
    tableWidget->setColumnCount(2);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->setShowGrid(false);
    tableWidget->setContentsMargins(0,0,0,0);


    // Zeit aufbauen
    int current_hour = 0;
    for(int i = 0; i < 96; i++) {
        QString minutes{}, daytime{}, hours{};

        // Stunden zuweisen
        if(current_hour < 10)
            hours = "0";
        hours += QString::number(current_hour);

        // Minuten hinzufügen
        if(i % 4 == 0)
            minutes = ":00";
        else if(i % 4 == 1)
            minutes = ":15";
        else if(i % 4 == 2)
            minutes = ":30";
        else
            minutes = ":45";

        // neue Stunde
        if(minutes == ":45")
            current_hour++;

        daytime = hours + minutes;
        tableWidget->setItem(i, 0, new QTableWidgetItem(daytime));
        tableWidget->setItem(i, 1, new QTableWidgetItem(""));
    }
    tableWidget->setItem(10, 1, new QTableWidgetItem("Task 1"));
}


void MainWindow::on_create_task_btn_clicked()
{
    /* TASK ERSTELLEN */
    auto erstellterTask = new task();
    erstellterTask->set_title(ui->task_name_edit->text().toUtf8().constData());

    /* TASK AUSGEBEN */
    QString qtitle= QString::fromStdString(erstellterTask->get_title());
    auto task_in_timeline = new QTableWidgetItem(qtitle);
    task_in_timeline->setBackgroundColor("blue");
    ui->timeline_table->setItem(10, 1, task_in_timeline);


    // Status Meldung
    QString new_text = "Task wurde angelegt";
    ui->status_label->setText(new_text);
    ui->status_label->repaint();
}
