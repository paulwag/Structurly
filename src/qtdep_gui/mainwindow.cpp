#include <iostream>
#include <QTableWidget>
#include <QHeaderView>
#include <QApplication>
#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singletons.h"
#include "input_controller.h"



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

    mainCntrl.inject(&db_c);        // 1. Database
    mainCntrl.inject(&tm_c);        // 2. taskManager
    mainCntrl.inject(&cm_c);        // 3. calenderManager
    mainCntrl.inject(&oc_c);        // 4. outputController
    mainCntrl.inject(&ic_c);        // 5. inputController
    mainCntrl.start();              // start components

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


// /////////////////////////////////////////////////////////////////////////////// slot events
void MainWindow::on_create_task_btn_clicked()
{
    /* Alter Kram von Paul, vllt noch später nützlich
    QString qtitle= QString::fromStdString(erstellterTask->get_title());        // TASK AUSGEBEN
    auto task_in_timeline = new QTableWidgetItem(qtitle);
    task_in_timeline->setBackgroundColor("blue");
    ui->timeline_table->setItem(10, 1, task_in_timeline);*/

    // Parameter for task creation
    std::string name = ui->task_name_edit->text().toStdString();
    std::string description = ui->description_edit->toPlainText().toStdString();
    int start_hour = ui->date_time_edit->time().hour();
    int start_minute = ui->date_time_edit->time().minute();
    int day = ui->date_time_edit->date().day();
    int month = ui->date_time_edit->date().month();
    int year = ui->date_time_edit->date().year();

    ic_c.set_task_parameter(name, description, start_hour, start_minute, day, month, year);
    ic_c.button_pressed(BUT_CREATE);
}

void MainWindow::on_printTasks_clicked()
{
    ic_c.button_pressed(BUT_PRINT);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    mainCntrl.stop();                                                           // clean up
    event->accept();                                                            // accept finally closes app, event->ignore() would keep it open
}

