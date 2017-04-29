#include "salerec.h"
#include "ui_salerec.h"

SaleRec::SaleRec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaleRec)
{
    ui->setupUi(this);
}

SaleRec::~SaleRec()
{
    delete ui;
}
