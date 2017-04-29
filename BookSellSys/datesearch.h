#ifndef DATESEARCH_H
#define DATESEARCH_H

#include <QDialog>
#include<QtSql>
#include<selldb.h>
namespace Ui {
class DateSearch;
}

class DateSearch : public QDialog
{
    Q_OBJECT

public:
    explicit DateSearch(QWidget *parent = 0);
    void search(QString,QString);
    ~DateSearch();

private:
    Ui::DateSearch *ui;
    SellDb Sdb;
};

#endif // DATESEARCH_H
