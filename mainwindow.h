#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void launch();

private slots:
    void on_create_task_btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
