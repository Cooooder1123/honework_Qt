#ifndef SALEREC_H
#define SALEREC_H

#include <QDialog>

namespace Ui {
class SaleRec;
}

class SaleRec : public QDialog
{
    Q_OBJECT

public:
    explicit SaleRec(QWidget *parent = 0);
    ~SaleRec();

private:
    Ui::SaleRec *ui;
};

#endif // SALEREC_H
