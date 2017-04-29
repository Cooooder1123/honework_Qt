#include "deleteacc.h"
#include "ui_deleteacc.h"

DeleteAcc::DeleteAcc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteAcc)
{
    ui->setupUi(this);
}

DeleteAcc::~DeleteAcc()
{
    delete ui;
}
