#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>
#include<changepsw.h>
#include<purchaserec.h>
#include<QTimer>
#include "selldb.h"

namespace Ui {
class Userform;
}

class Userform : public QDialog
{
    Q_OBJECT

public:
    explicit Userform(QWidget *parent = 0);
    bool setUser(QString);
    QString getUser();

    ~Userform();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void book_detail();

    void book_detail_more();

    void hide();

    void on_pushButton_5_clicked();


private:
    Ui::Userform *ui;
    QString Username;
    ChangePSW changePSW;
    PurchaseRec purchaseRec;
    SellDb Sdb;

};

#endif // USERFORM_H
