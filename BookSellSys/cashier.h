#ifndef CASHIER_H
#define CASHIER_H

#include <QDialog>
#include<selldb.h>
namespace Ui {
class Cashier;
}

class Cashier : public QDialog
{
    Q_OBJECT

public:
    explicit Cashier(QWidget *parent = 0);
    void setCashier(QString);
    //进行购书操作

    ~Cashier();

private slots:
    void on_pushButton_3_clicked();

    void buy_book();

    void book_detail();
    void on_pushButton_5_clicked();

private:
    Ui::Cashier *ui;
    QString name;
    SellDb Sdb;
};

#endif // CASHIER_H
