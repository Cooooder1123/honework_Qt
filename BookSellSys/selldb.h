#ifndef SELLDB_H
#define SELLDB_H

#include <QObject>
#include<QtSql>
#include<QString>
#include<QSqlDatabase>
#include<QTextCodec>
#include<QtGui>
#include<QDebug>
class SellDb
{
public:
    SellDb();
    void close();
    void createconnection();
    //用户登录
    bool Userlogin(QString,QString);
    bool  Cashierlogin(QString,QString);

    //书库静态查找(名称)
    QSqlQueryModel* B_search(QString);
    QSqlQueryModel* A_search(QString);
    QSqlQueryModel* P_search(QString);
    QSqlQueryModel* B_A_search(QString,QString);
    QSqlQueryModel* B_P_search(QString,QString);
    QSqlQueryModel* A_P_search(QString,QString);
    QSqlQueryModel* B_A_P_search(QString,QString,QString);
    QSqlQueryModel* All_search();

    //用户信息修改
    bool modify(QString,int,QString);
    //购买记录查询（用户名称） 静态查询
    QSqlQueryModel* Buy_search(QString);
    //收银员操作购买(书号)or(书号，用户号)
    bool Buying(QString);
    bool Buying(QString,QString);
    //管理员销量查询（日期）
    QSqlQueryModel* day_search(QString);
    QSqlQueryModel* data_search(QString,QString );
    //管理员用户删除
    bool Acc_delete(QString User);
    //管理员添加用户（包括加上密码）
    bool UserAcc_add(QString name,QString password);
    bool UserAcc_add(QString name,QString password,QString sex,int age,QString phone);
    //管理员添加收银员
    bool CashAcc_add(QString name,QString password);
    bool CashAcc_add(QString name, QString password, QString sex, int age, QString phone);
    //管理员加入图书
    bool Book_add(QString book_num,QString book_nam,QString book_aut,
                  QString book_pub,QString book_pri,QString book_qua);
    //管理员查询用户
    QSqlQueryModel* user_search();
    QSqlQueryModel* user_search(QString account);
    //
    void set_dbname(QString);
    //
    QString get_dbname();

    ~SellDb();

private:
    QSqlDatabase db;

    QString dbname;//数据库信息


};

#endif // SELLDB_H
