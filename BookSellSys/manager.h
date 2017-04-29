#ifndef MANAGER_H
#define MANAGER_H

#include <QDialog>
#include<salerec.h>
#include<deleteacc.h>
#include<QtWidgets>
#include<selldb.h>
#include<datesearch.h>
#include<QFile>
#include<QFileDialog>

class QCheckBox;
class QLineEdit;
class QPushButton;
class QTableWidget;
class QDateEdit;
class QLayout;

namespace Ui {
class Manager;
}

class Manager : public QDialog
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = 0);
    ~Manager();

private slots:
    void to_Swidget();
    void to_Cwidget();
    void to_Dwidget();
    void to_Bwidget();
    void to_Uwidget();

    void search_book();
    void add();
    void A_delete();
    void data_search();
    void book_insert();
    void book_insert_from_file();
    void User_search();
    void User_info();
private:
    //init
    void initSearchWidget();
    void initCheckyearsWidget();
    void initCheckdaysWidget();
    void initDeleteWidget();
    void initBookWidget();
    void initSearchUserWidget();
    //fileinsert
    void get_from_file();

    Ui::Manager *ui;

    DateSearch Ds;

    QWidget *Swidget;
    QWidget *Cwidget;
    QWidget *Dwidget;
    QWidget *Bwidget;
    QWidget *Uwidget;
    //four main button
    QPushButton *SearchButton;
    QPushButton *CheckyearsButton;
    //QPushButton *CheckdaysButton;
    QPushButton *DeleteButton;
    QPushButton *AddBookButton;
    QPushButton *SearchUserButton;
    //first button
    QCheckBox *sbCheckBox1;
    QCheckBox *sbCheckBox2;
    QCheckBox *sbCheckBox3;
    QLineEdit *sbLineEdit1;
    QLineEdit *sbLineEdit2;
    QLineEdit *sbLineEdit3;
    QPushButton *sbPushButton1;
    QPushButton *sbPushButton2;
    QTableView *sbTable;

    QDateEdit *tDateEdit1;
    QDateEdit *tDateEdit2;
    QLabel *tLabel1;
    QLabel *tLabel2;
    QPushButton *tPushButton1;
    QPushButton *tPushButton2;

    //delete acc
    QLabel *dLabel;
    QLabel *dLabel1;
    QLabel *dLabel2;
    QLabel *dLabel3;
    QLabel *dLabel4;
    QLineEdit *dLineEdit;
    QLineEdit *dLineEdit1;
    QLineEdit *dLineEdit_sex;
    QLineEdit *dLineEdit_age;
    QLineEdit *dLineEdit_phone;
    QPushButton *dButton1;
    QPushButton *dButton2;
    QComboBox *dcombobox;

    //add books
    QLabel *bLabel_num;
    QLabel *bLabel_nam;
    QLabel *bLabel_aut;
    QLabel *bLabel_pub;
    QLabel *bLabel_pri;
    QLabel *bLabel_qua;
    QLineEdit *bLineEdit_num;
    QLineEdit *bLineEdit_nam;
    QLineEdit *bLineEdit_aut;
    QLineEdit *bLineEdit_pub;
    QLineEdit *bLineEdit_pri;
    QLineEdit *bLineEdit_qua;
    QPushButton *bButton_add;
    QPushButton *bButton_exc;

    //search users info
    QLabel *uLabel;
    QLineEdit *uLineEdit;
    QPushButton *uButton;
    QTableView *uTable1;
    QTableView *uTable2;

    QStackedLayout *stacklayout;

    //database
    SellDb Sdb;
};

#endif // MANAGER_H
