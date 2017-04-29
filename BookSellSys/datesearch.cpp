#include "datesearch.h"
#include "ui_datesearch.h"

//manger.cpp call this interface

DateSearch::DateSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateSearch)
{
    ui->setupUi(this);
}

void DateSearch::search(QString date1,QString date2 ){
    QSqlQueryModel *model=Sdb.data_search(date1,date2);
    ui->tableView->setSortingEnabled(true);
    QSortFilterProxyModel *tmodel=new QSortFilterProxyModel(this);
    tmodel->setSourceModel(model);
    ui->tableView->setModel(tmodel);
}

DateSearch::~DateSearch()
{
    delete ui;
}
