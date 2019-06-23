#include <iostream>
#include <QTableWidget>
#include <QHeaderView>
#include <QApplication>
#include <QtGui>

#include "singeltons.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"



// /////////////////////////////////////////////////////////////////////////////// De- / Konstruktor
MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// /////////////////////////////////////////////////////////////////////////////// launch / close
void MainWindow::launch() {

    mainCntrl.inject(&tm_c);
    mainCntrl.inject(&ic_c);
    mainCntrl.start();

    auto tableWidget = ui->timeline_table;                                      //Timeline erstellen
    tableWidget->setRowCount(96);
    tableWidget->setColumnCount(2);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->setShowGrid(false);
    tableWidget->setContentsMargins(0,0,0,0);

    int current_hour = 0;                                                       // Zeit aufbauen
    for(int i = 0; i < 96; i++)
    {
        QString minutes{}, daytime{}, hours{};

        if (current_hour < 10)                                                  // Stunden zuweisen
            hours = "0";
        hours += QString::number(current_hour);

        if (i % 4 == 0)                                                         // Minuten hinzufügen
            minutes = ":00";
        else if (i % 4 == 1)
            minutes = ":15";
        else if (i % 4 == 2)
            minutes = ":30";
        else
            minutes = ":45";

        if(minutes == ":45")                                                    // neue Stunde
            current_hour++;

        daytime = hours + minutes;
        tableWidget->setItem(i, 0, new QTableWidgetItem(daytime));
        tableWidget->setItem(i, 1, new QTableWidgetItem(""));
    }
    tableWidget->setItem(10, 1, new QTableWidgetItem("Task 1"));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    mainCntrl.stop();                                                           // clean up
    event->accept();                                                            // accept finally closes app, event->ignore() would keep it open
}


// /////////////////////////////////////////////////////////////////////////////// buttons klicked
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

    cout << "create task geklickt" << endl;
}




