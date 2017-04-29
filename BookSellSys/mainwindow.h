#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<userform.h>
#include<cashier.h>
#include<manager.h>
#include<selldb.h>
#include<QFile>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void UI();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Userform userForm;
    Cashier cashier;
    Manager manager;
    SellDb Sdb;

};

#endif // MAINWINDOW_H
