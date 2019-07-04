#ifndef MAINWINDOW_H
    #define MAINWINDOW_H

    #include <QMainWindow>
    #include <iostream>
    #include <QTableWidget>
    #include <QDateTime>
    #include <QHeaderView>
    #include <QApplication>
    #include <QtGui>
    #include <QTimer>
    #include <QDesktopWidget>
    #include "timeline.h"


    namespace Ui {
    class MainWindow;
    }



    class MainWindow : public QMainWindow
    {
        Q_OBJECT                                        // Qt object (macro).

        public:
            explicit MainWindow(QWidget *parent = nullptr);
            ~MainWindow();

            void launch();

        //public slots:
            //void checkForUpdate();

        private slots:
            void closeEvent(QCloseEvent *event);        // Aufgerufen beim Schließen des Fensters

            void on_calendarWidget_selectionChanged();

            void on_create_task_button_clicked();

            void on_print_task_clicked();

    private:
            Ui::MainWindow *ui;

            // Update functionen
            void set_timeline_label(QDate date);
            void showTimeline();
            void showTimeline(timeline* tl);
            void resetInputs();

            QTableWidget* tableWidget = new QTableWidget (96, 2, this);                                      //Timeline erstellen



    };

#endif
