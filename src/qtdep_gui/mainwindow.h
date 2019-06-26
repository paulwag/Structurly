#ifndef MAINWINDOW_H
    #define MAINWINDOW_H

    #include <QMainWindow>

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

        private slots:
            void on_create_task_btn_clicked();
            void on_printTasks_clicked();

            //void keyPressEvent(QKeyEvent *event);       // Aufgerufen???
            void closeEvent(QCloseEvent *event);        // Aufgerufen beim Schließen des Fensters

    private:
            Ui::MainWindow *ui;
    };

#endif
