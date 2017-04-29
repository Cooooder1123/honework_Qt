#include "purchaserec.h"
#include "ui_purchaserec.h"

//userform.cpp call this interface

PurchaseRec::PurchaseRec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PurchaseRec)
{
    ui->setupUi(this);
    //ui->tableWidget

}

PurchaseRec::~PurchaseRec()
{
    delete ui;
}
void PurchaseRec::setname(QString name){
    this->name=name;
}
void PurchaseRec::record(QString name){
    qDebug()<<name<<endl;
     QSqlQueryModel *model=Sdb.Buy_search(name);
    ui->tableView->setSortingEnabled(true);
    QSortFilterProxyModel *tmodel=new QSortFilterProxyModel(this);
    tmodel->setSourceModel(model);
    ui->tableView->setModel(tmodel);
}
