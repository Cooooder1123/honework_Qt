#ifndef PURCHASEREC_H
#define PURCHASEREC_H

#include <QDialog>
#include"selldb.h"

namespace Ui {
class PurchaseRec;
}

class PurchaseRec : public QDialog
{
    Q_OBJECT

public:
    explicit PurchaseRec(QWidget *parent = 0);
    void setname(QString);
    void record(QString);
    ~PurchaseRec();

private:
    Ui::PurchaseRec *ui;
    SellDb Sdb;
    QString name;
};

#endif // PURCHASEREC_H
