#include "selldb.h"
#include<QMessageBox>
#include<QDate>
#include<QDebug>
SellDb::SellDb()
{
    db=QSqlDatabase::addDatabase("QODBC");
    dbname=QString("DRIVER={SQL SERVER};"
           "SERVER=%1;"
           "DATABASE=%2;"
           "UID=%3;"
           "PWD=%4;")
              .arg("PAN")
   .arg("book1")
   .arg("sa")
   .arg("123456");
}
void SellDb::close(){
    db.commit();
}

void SellDb::set_dbname(QString name){
    if(!dbname.isNull()){
        dbname.clear();
    }
    dbname.append(name);
}
QString SellDb::get_dbname(){
    if(!dbname.isNull()){
        return dbname;
    }
    return "";
}
void SellDb::createconnection(){
    db.setDatabaseName(dbname);
    if(db.open()){
        qDebug()<<"Connect to database";
    }else{
        QMessageBox::warning(0,qApp->tr("Cannot open database"),
                             db.lastError().text(),QMessageBox::Cancel);
    }
}
QSqlQueryModel* SellDb::B_search(QString name){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Book where Name like \'%%1%\'").arg(name));
    return model;
}
QSqlQueryModel* SellDb::A_search(QString Author){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Book where Author like \'%%1%\'").arg(Author));
    return model;
}

QSqlQueryModel* SellDb::P_search(QString Publisher){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Book where Publisher like \'%%1%\'").arg(Publisher));
    return model;
}

QSqlQueryModel* SellDb::B_A_search(QString name,QString Author){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery((QObject::tr("select * from Book where Name like \'%%1%\' and Author like \'%%2%\'")).arg(name).arg(Author));
    return model;
}

QSqlQueryModel* SellDb::B_P_search(QString name,QString Publisher){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Book where Name like \'%%1%\' and Publisher like \'%%2%\'").arg(name).arg(Publisher));
    return model;
}

QSqlQueryModel* SellDb::A_P_search(QString Author,QString Publisher){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Book where Author like \'%%1%\' and Publisher like \'%%2%\'").arg(Author).arg(Publisher));
    return model;
}

QSqlQueryModel* SellDb::B_A_P_search(QString name,QString Author,QString Publisher){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Book where Name like \'%%1%\'and Author like \'%%2%\' and Publisher like \'%%3%\'").arg(name).arg(Author).arg(Publisher));
    return model;
}
QSqlQueryModel* SellDb::All_search(){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Book"));
    return model;
}


QSqlQueryModel *SellDb::Buy_search(QString Username){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("Select * from %1").arg(Username));
    return model;
}
bool SellDb::modify(QString Account, int age, QString phone){
    QSqlQuery *model=new QSqlQuery;
    if(model->exec((QObject::tr("update Users set phone=\'%1\' , age=%3 where Account=\'%2\'").arg(phone).arg(Account).arg(age)))){

        qDebug()<<"modify Succeed";
        return true;
    }else{

         qDebug()<<"modify Failed";
        return false;
    }
}

bool SellDb::Buying(QString Book_num){
    QSqlQuery *model1=new QSqlQuery;

    QSqlQuery *model2=new QSqlQuery;

    QSqlQuery *model3=new QSqlQuery;
    QSqlQueryModel *DataModel=new QSqlQueryModel;
    DataModel->setQuery(QObject::tr("select * from Book where Book_num=\'%1\'").arg(Book_num));


    QString name=DataModel->data(DataModel->index(0,2)).toString();
    QString price=DataModel->data(DataModel->index(0,4)).toString();
    int quantity=DataModel->data(DataModel->index(0,5)).toInt();
    //if the quantitu of the book is below 1 than return warining;
    if(quantity<1){
        QMessageBox::warning(0,"Failed","There is no book in the store");
        return false;
    }
    QDateTime *date=new QDateTime;

     QString date1=date->currentDateTime().toString("yyyy-MM-dd");
    if(model2->exec(QObject::tr("insert into Sell_table values(1,%1,%2%3,%4)").arg(name).arg(Book_num).arg(price).arg(date1))){
        model1->exec(QObject::tr("update Book set Quantity=Quantity-1 where Book_num=\'%1\'").arg(Book_num));
        qDebug()<<"Buying Succeed(by insert)";
        return true;
    }else{
        if(model3->exec(QObject::tr("update Sell_table set Sell_num=Sell_num+1 where Book_num=\'%1\'").arg(Book_num))){
            model1->exec(QObject::tr("update Book set Quantity=Quantity-1 where Book_num=\'%1\'").arg(Book_num));
            qDebug()<<"Buying Succeed(by update)";
            return true;
        }
        else {delete DataModel;return false;}
    }

    return false;
}
bool SellDb::Buying(QString Book_num, QString User){
    QSqlQuery *model1=new QSqlQuery;

    QSqlQuery *model2=new QSqlQuery;

    QSqlQuery *model3=new QSqlQuery;

    QSqlQuery *model4=new QSqlQuery;

    QSqlQuery *model5=new QSqlQuery;
    QSqlQueryModel *DataModel=new QSqlQueryModel;
    DataModel->setQuery(QObject::tr("select * from Book where Book_num=\'%1\'").arg(Book_num));\

    qDebug()<<(QObject::tr("select * from Book where Book_num=\'%1\'").arg(Book_num));
    QString name=DataModel->data(DataModel->index(0,1)).toString();
    QString price=DataModel->data(DataModel->index(0,4)).toString();
    QDateTime *date=new QDateTime;
    QString date1=date->currentDateTime().toString("yyyy-MM-dd");

    qDebug()<<name<<price<<date1;
    if(model2->exec(QObject::tr("insert into Sell_table values(1,\'%1\',\'%2\',%3,\'%4\')").arg(name).arg(Book_num).arg(price).arg(date1))){
        model1->exec(QObject::tr("update Book set Quantity=Quantity-1 where Book_num=\'%1\'").arg(Book_num));
        model5->exec(QObject::tr("update Users set qty=qty+1 where Account=\'%1\'").arg(User));
        model4->exec(QObject::tr("insert into %1(name,Book_num,sell_date) values(\'%2\',\'%3\',\'%4\')").arg(User).arg(name).arg(Book_num).arg(date1));

        qDebug()<<QObject::tr("update Book set Quantity=Quantity-1 where Book_num=\'%1\'").arg(Book_num)<<"\n"
               <<QObject::tr("insert into %1 values(\'%2\',\'%3\',\'%4\')").arg(User).arg(name).arg(Book_num).arg(date1);
        qDebug()<<"Buying Succeed(by insert)"<<model5->lastError().text();
        return true;
    }else{
        if(model3->exec(QObject::tr("update Sell_table set Sell_num=Sell_num+1 where Book_num=\'%1\'").arg(Book_num))){
            model1->exec(QObject::tr("update Users set qty=qty+1 where Account=\'%1\'").arg(User));
            model5->exec(QObject::tr("update Book set Quantity=Quantity-1 where Book_num=\'%1\'").arg(Book_num));
            model4->exec(QObject::tr("insert into %1(name,Book_num,sell_date) values(\'%2\',\'%3\',\'%4\')").arg(User).arg(name).arg(Book_num).arg(date1));
             qDebug()<<QObject::tr("insert into %1 values(\'%2\',\'%3\',\'%4\')").arg(User).arg(name).arg(Book_num).arg(date1);
            qDebug()<<"Buying Succeed(by update)";
            return true;
        }
        else {
            QMessageBox::warning(0,"Buying error","cannot update data into Selltable");
            return false;
        }
    }

    return false;
}

QSqlQueryModel* SellDb::day_search(QString date){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Sell_table where Sell_date=\'%1\'").arg(date));
    return model;
}

QSqlQueryModel* SellDb::data_search(QString date1,QString date2){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from Sell_table where Sell_date between \'%1\' and \'%2\'").arg(date1).arg(date2));
    qDebug()<<QObject::tr("select * from Sell_table where Sell_date between \'%1\' and \'%2\'").arg(date1).arg(date2);
    return model;
}

bool SellDb::Acc_delete(QString User){
    QSqlQuery *model=new QSqlQuery;
    bool x,y;
   if(x=model->exec(QObject::tr("delete from Users "
                                 "where account=\'%1\'").arg(User))){
        qDebug()<<"delete Account Succeed from Users";
   }else{
        qDebug()<<"delete Account Failed from Users";
   }
    QSqlQuery *model1=new QSqlQuery;
    if(y=model1->exec(QObject::tr("drop table %1").arg(User))){
        qDebug()<<"drop table Succeed ";
    }else{
        qDebug()<<"drop table Failed";
    }
    if(x&&y){
        return true;
        qDebug()<<"delete Account Succeed";
    }else{
        qDebug()<<"delete Account failed";
        return false;
    }
}

bool SellDb::Userlogin(QString user,QString pwd){

    QSqlQueryModel *model1=new QSqlQueryModel;
    model1->setQuery(QObject::tr("select * from Users where Account=\'%1\' ").arg(user));

    QString cmp=model1->data(model1->index(0,1)).toString();
//    for(int i=0;i<5;i++){
//        for(int j=0;j<5;j++){
//             qDebug()<<model1->data(model1->index(i,j)).toString();
//        }
//    }



    if(cmp.isEmpty()){
        return false;
    }
    if(cmp==pwd){
        return true;
    }else{
        return false;
    }
}
bool SellDb::Cashierlogin(QString Cashier,QString pwd){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select Passwords from Cashier where Account=\'%1\'").arg(Cashier));
    QString cmp=model->data(model->index(0,0)).toString();
    if(cmp.isEmpty()){
        return false;
    }
    if(cmp==pwd){
        return true;
    }else{
        return false;
    }
}
//add account,1.to check if there is a same name 2.to create table 3.to ceate a account in users
bool SellDb::UserAcc_add(QString name, QString password){
    QSqlQuery *model=new QSqlQuery;
    model->exec(QObject::tr("select Account from users where account=\'%1\'").arg(name));

    QString check=model->value(0).toString();
    if (!check.isEmpty()){
        QMessageBox::warning(0,"Error","Account existing!");
        return false;
    }
    if(model->exec(QObject::tr("create table %1 ("
                            "name varchar(10),"
                            " book_num varchar(10),"
                            "sell_date date)").arg(name))){
        qDebug()<<QObject::tr("create table %1 ("
                                    "name varchar(10),"
                                    " book_num varchar(10),"
                                    "sell_date date)").arg(name);
        qDebug()<<"create table succeed!";
    }else{
        qDebug()<<"create table Failed!";
        return false;
    }
    if(model->exec(QObject::tr("insert into users(Account,Passwords) values(\'%1\',\'%2\')").arg(name).arg(password))){
        qDebug()<<"insert user succeed!";

        return true;
    }else{
        qDebug()<<"create table failed!";
        return false;
    }


}
bool SellDb::UserAcc_add(QString name, QString password, QString sex, int age, QString phone){
    QSqlQuery *model=new QSqlQuery;
    model->exec(QObject::tr("select Account from users where account=\'%1\'").arg(name));

    QString check=model->value(0).toString();
    if (!check.isEmpty()){
        QMessageBox::warning(0,"Error","Account existing!");
        return false;
    }
    if(model->exec(QObject::tr("create table %1 ("
                            "name varchar(10),"
                            " book_num varchar(10),"
                            "sell_date date,"
                               "payment varchar(10))").arg(name))){
        qDebug()<<QObject::tr("create table %1 ("
                                    "name varchar(10),"
                                    " book_num varchar(10),"
                                    "sell_date date,"
                              "payment varchar(10))").arg(name);
        qDebug()<<"create table succeed!";
    }else{
        qDebug()<<"create table Failed!";
        return false;
    }
    if(model->exec(QObject::tr("insert into users(account,passwords,sex,age,phone) values(\'%1\',\'%2\',\'%3\',%4,\'%5\')").arg(name).arg(password).arg(sex).arg(age).arg(phone))){
        qDebug()<<"insert user succeed!";

        return true;
    }else{
        qDebug()<<"create table failed!";
        return false;
    }

}
//Add Cashier account
bool SellDb::CashAcc_add(QString name, QString password){
    QSqlQuery *model=new QSqlQuery;
    model->exec(QObject::tr("select Account from Cashier where account=\'%1\'").arg(name));

    QString check=model->value(0).toString();
    if (!check.isEmpty()){
        QMessageBox::warning(0,"Error","Account existing!");
        return false;
    }

    if(model->exec(QObject::tr("insert into Cashier(Account,Passwords) values(\'%1\',\'%2\')").arg(name).arg(password))){
        qDebug()<<"insert Cashier succeed!";

        return true;
    }else{
        qDebug()<<"Insert  failed!";
        return false;
    }
}
bool SellDb::CashAcc_add(QString name, QString password, QString sex, int age, QString phone){
    QSqlQuery *model=new QSqlQuery;
    model->exec(QObject::tr("select Account from Cashier where account=\'%1\'").arg(name));

    QString check=model->value(0).toString();
    if (!check.isEmpty()){
        QMessageBox::warning(0,"Error","Account existing!");
        return false;
    }

    if(model->exec(QObject::tr("insert into Cashier values(\'%1\',\'%2\',\'%3\',%4,\'%5\')").arg(name).arg(password).arg(sex).arg(age).arg(phone))){
        qDebug()<<"insert Cashier succeed!";

        return true;
    }else{
        qDebug()<<"Insert  failed!";
        return false;
    }
}

//Manager add books into the database
bool SellDb::Book_add(QString book_num, QString book_nam, QString book_aut, QString book_pub, QString book_pri, QString book_qua){
    QSqlQuery *model=new QSqlQuery;
    if(model->exec(QObject::tr("insert into book values (\'%1\',\'%2\',"
                            "\'%3\',\'%4\',%5,%6)").arg(book_num).arg(book_nam).arg(book_aut).arg(book_pub)
                                                   .arg(book_pri).arg(book_qua))){
        qDebug()<<QObject::tr("insert into book values (\'%1\',\'%2\',"
                          "\'%3\',\'%4\',%5,%6)").arg(book_num).arg(book_nam).arg(book_aut).arg(book_pub)
                                                 .arg(book_pri).arg(book_qua);

        return true;
    }else{
        QMessageBox::warning(0,"Failed",model->lastError().text());
        return false;
    }
}

//Manager search user account
QSqlQueryModel* SellDb::user_search(){
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(QObject::tr("select Account,sex,age,phone,qty from Users "));
    return model;
}
QSqlQueryModel* SellDb::user_search(QString account){
    QSqlQueryModel *model=new QSqlQueryModel;

    model->setQuery(QObject::tr("select Account,sex,age,phone,qty from Users where account like \'%%1%\'").arg(account));

    return model;
}

SellDb::~SellDb(){

}
