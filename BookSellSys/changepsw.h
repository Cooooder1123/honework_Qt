#ifndef CHANGEPSW_H
#define CHANGEPSW_H

#include <QDialog>
#include<selldb.h>
namespace Ui {
class ChangePSW;
}

class ChangePSW : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePSW(QWidget *parent = 0);
    void setname(QString);
    ~ChangePSW();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChangePSW *ui;
    SellDb Sdb;
    QString name;
};

#endif // CHANGEPSW_H
