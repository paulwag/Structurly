#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singletons.h"


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

    connect(tableWidget, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));

    ui->timeline_area->setWidget(tableWidget);                      // init timeline
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setStretchLastSection( true );
    tableWidget->setShowGrid(false);
    //tableWidget->setContentsMargins(0,0,0,0);

    QDateTime cur_date_time = QDateTime::currentDateTime();     // aktuelles Datum + Uhrzeit System

    QDate date = QDate::currentDate();
    ui->date_edit->setDate(date);
    QTime time = QTime::currentTime();
    ui->time_edit->setTime(time);

    set_timeline_label(date);

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
}

// /////////////////////////////////////////////////////////////////////////////// Update functions
void MainWindow::set_timeline_label(QDate date) {
    std::string timeline_label = "Timeline ";
    timeline_label += std::to_string(date.day()) + ".";
    timeline_label += std::to_string(date.month()) + ".";
    timeline_label += std::to_string(date.year());
    ui->timeline_label->setText(QString::fromStdString(timeline_label));
}

void MainWindow::showTimeline(timeline* tl) {
    QBrush brush(QColor::fromRgb(12,108,232));

    for(u_int i = 0; i < 96; i++) {
        if(tl->get_task(i)) {
            QString task_name = QString::fromStdString(tl->get_task(i)->get_title());
            tableWidget->setItem(int (i), 1, new QTableWidgetItem(task_name));
            tableWidget->item(int (i), 1)->setBackground(brush);
            tableWidget->item(int (i), 1)->setTextColor(Qt::white);
        } else
            tableWidget->setItem(int (i), 1, new QTableWidgetItem(""));
    }
}
void MainWindow::showTimeline() {
    for(u_int i = 0; i < 96; i++)
        tableWidget->setItem(int (i), 1, new QTableWidgetItem(""));
}

void MainWindow::resetInputs() {
    ui->name_edit->setText("");
    ui->description_edit->setText("");

    QDate date = QDate::currentDate();
    ui->date_edit->setDate(date);
    QTime time = QTime::currentTime();
    ui->time_edit->setTime(time);
}

void MainWindow::onTableClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        int row = index.row();

        QTableWidgetItem *item = tableWidget->item(row, 0);
        std::string item_text = item->text().toStdString();
        int hour = std::stoi(item_text.substr(0,2));
        int minute = std::stoi(item_text.substr(3,5));
        QTime sel_time(hour, minute);
        ui->time_edit->setTime(sel_time);
    }
}

// /////////////////////////////////////////////////////////////////////////////// slot events
void MainWindow::closeEvent(QCloseEvent *event)
{
    mainCntrl.stop();                                                           // clean up
    event->accept();                                                            // accept finally closes app, event->ignore() would keep it open
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    QDate sel_date = ui->calendarWidget->selectedDate();

    oc_c.set_date_seen_on_gui(sel_date.day(), sel_date.month(), sel_date.year());
    set_timeline_label(sel_date);

    if (oc_c.update_gui_date_changed())
    {
        timeline *tl = oc_c.get_timeline_for_gui();
        cout << "gui hat timeline (ID: " << tl->get_id() << ") erhalten" << endl;
        showTimeline(tl);
    } else
        showTimeline();

    ui->date_edit->setDate(sel_date);
}

void MainWindow::on_create_task_button_clicked()
{
    // Parameter for task creation
    std::string name = ui->name_edit->text().toStdString();
    std::string description = ui->description_edit->toPlainText().toStdString();
    int start_hour = ui->time_edit->time().hour();
    int start_minute = ui->time_edit->time().minute();
    int day = ui->date_edit->date().day();
    int month = ui->date_edit->date().month();
    int year = ui->date_edit->date().year();

    if (ic_c.set_task_parameter(name, description, start_hour, start_minute, day, month, year) == 0)
        ic_c.button_pressed(BUT_CREATE);

    timeline *tl = oc_c.get_timeline_for_gui();
    cout << "gui hat timeline (ID: " << tl->get_id() << ") erhalten" << endl;
    showTimeline(tl);
    resetInputs();
}

void MainWindow::on_print_task_clicked()
{
    ic_c.button_pressed(BUT_PRINT);
}
