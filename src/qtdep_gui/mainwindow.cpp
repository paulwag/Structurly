#include <iostream>
#include <QTableWidget>
#include <QDateTime>
#include <QHeaderView>
#include <QApplication>
#include <QtGui>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singletons.h"
#include "timeline.h"



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

    QDateTime cur_date_time = QDateTime::currentDateTime();     // aktuelles Datum + Uhrzeit System

    ui->day_edit->setValue(cur_date_time.date().day());                     // aktuelles Datum und Uhrzeit als Standardeinstellung bei Taskerstellung
    ui->month_edit->setValue( cur_date_time.date().month());
    ui->year_edit->setValue( cur_date_time.date().year());
    ui->hour_edit->setValue(cur_date_time.time().hour());
    ui->minute_edit->setValue(cur_date_time.time().minute());

    // Construct timeline label
    std::string timeline_label = "Timeline ";
    timeline_label += std::to_string(cur_date_time.date().day()) + ".";       // Tag hinzufügen
    timeline_label += std::to_string(cur_date_time.date().month()) + ".";       // Tag hinzufügen
    timeline_label += std::to_string(cur_date_time.date().year()) + ".";       // Tag hinzufügen
    ui->timeline_date->setText(QString::fromStdString(timeline_label));

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

    // /// create Update Timer
    //QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(checkForUpdate()));
    //timer->start(500);
}

// /////////////////////////////////////////////////////////////////////////////// Update functions
/*void MainWindow::checkForUpdate() {
        switch(oc_c.getChangeFlag()) {
            case 0:                                         // no changes
                break;
            case 1:                                         // new_timeline
                timelineChanged();
                break;
        }
}
void MainWindow::timelineChanged() {
    oc_c.update_gui_date_changed(); // wenn überhaupt: get_timeline_for_gui(), die timeline auseinandernehmen, anzeigen
}*/


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
    int start_hour = ui->hour_edit->value();
    int start_minute = ui->minute_edit->value();
    int day = ui->day_edit->value();
    int month = ui->month_edit->value();
    int year = ui->year_edit->value();

    if (ic_c.set_task_parameter(name, description, start_hour, start_minute, day, month, year) == 0)
        ic_c.button_pressed(BUT_CREATE);
}

void MainWindow::on_printTasks_clicked()
{
    ic_c.button_pressed(BUT_PRINT);
}

void MainWindow::on_calendar_selectionChanged()
{

    QDate date = ui->calendar->selectedDate();

    oc_c.set_date_seen_on_gui(date.day(), date.month(), date.year());

    if (oc_c.update_gui_date_changed())
    {
        timeline *tl = oc_c.get_timeline_for_gui();
        cout << "gui hat timeline (ID: " << tl->get_id() << ") erhalten" << endl;
    }

    // Tasks aus der Timeline auslesen und in der tabelle anzeigen lassen
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    mainCntrl.stop();                                                           // clean up
    event->accept();                                                            // accept finally closes app, event->ignore() would keep it open
}



