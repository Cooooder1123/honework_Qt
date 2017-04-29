#include "cashier.h"
#include "ui_cashier.h"
#include<QtSql>
#include<QMessageBox>
Cashier::Cashier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cashier)
{
    ui->setupUi(this);
    setWindowTitle("Cashier Frame");
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(buy_book()));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),
            this,SLOT(book_detail()));

}
void Cashier::setCashier(QString name){
    ui->label_2->setText(name);
}

Cashier::~Cashier()
{
    delete ui;
}

void Cashier::on_pushButton_3_clicked()
{
    if(ui->checkBox->isChecked()){
        QString book_name=ui->lineEdit->text();

        if(ui->checkBox_2->isChecked()){
            QString Author=ui->lineEdit_2->text();

            if(ui->checkBox_3->isChecked()){
                QString Publisher=ui->lineEdit_3->text();
                QSqlQueryModel* model=Sdb.B_A_P_search(book_name,Author,Publisher);
                ui->tableView->setModel(model);

            }else{
                QSqlQueryModel* model=Sdb.B_A_search(book_name,Author);
                ui->tableView->setModel(model);
            }
        }else{
            if(ui->checkBox_3->isChecked()){
                QString Publisher=ui->lineEdit_3->text();
                QSqlQueryModel* model=Sdb.B_P_search(book_name,Publisher);
                ui->tableView->setModel(model);

            }else{
                QSqlQueryModel* model=Sdb.B_search(book_name);
                ui->tableView->setModel(model);
                //qDebug()<<model->data(model->index(1,3)).toString();
            }
        }
    }else{
        if(ui->checkBox_2->isChecked()){
            QString Author=ui->lineEdit_2->text();
            if(ui->checkBox_3->isChecked()){
                QString Publisher=ui->lineEdit_3->text();
                QSqlQueryModel* model=Sdb.A_P_search(Author,Publisher);
                ui->tableView->setModel(model);
            }else{
                QSqlQueryModel* model=Sdb.A_search(Author);
                ui->tableView->setModel(model);
            }
        }else{
            if(ui->checkBox_3->isChecked()){
                QString Publisher=ui->lineEdit_3->text();
                QSqlQueryModel* model=Sdb.P_search(Publisher);
                ui->tableView->setModel(model);
            }else{
                QSqlQueryModel* model=Sdb.All_search();
                ui->tableView->setModel(model);

            }
        }
    }
}
    //进行购书操作
void Cashier::buy_book()
{
    bool kind1,kind2;
    QString book_num=ui->lineEdit_4->text();
    QString User=ui->lineEdit_5->text();

    if(User.isEmpty()){
        kind1=Sdb.Buying(book_num);
    }else{
        kind2=Sdb.Buying(book_num,User);
    }
    if(kind1||kind2){
        QMessageBox::warning(this,"Succeed","Succeed!");
    }else{
        QMessageBox::warning(this,"Failed","Failed!");
    }
    Sdb.close();
}

void Cashier::book_detail(){
    QModelIndex index=ui->tableView->currentIndex();
    int row=index.row();
    QString book_num=index.data((row,0)).toString();
    QString style=tr("#UserPic{"
                     "border-image:url(E:/Qt code/BookSellSys/BookPhoto/%1.jpg);"
                     "border:2px solid rgb(121,189,143);"
                     "border-radius:5px;"
                     "background-color:rbg(255,255,255);}").arg(book_num);
    qDebug()<<style;
    ui->UserPic->setStyleSheet(style);
}




void Cashier::on_pushButton_5_clicked()
{
    this->close();
}
