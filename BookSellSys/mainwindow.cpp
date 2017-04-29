#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include"QHideEvent"
#include<selldb.h>
#include<QMessageBox>
#include<QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("Login");
    UI();

    //和数据库链接
    Sdb.createconnection();


//    cashier=new Cashier;
//    manager=new Manager;

}

MainWindow::~MainWindow()
{
    Sdb.close();
    delete ui;
}
void MainWindow::UI(){
//    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_pushButton_clicked()
{

    QString account=ui->lineEdit->text();
    QString pwd=ui->lineEdit_2->text();


    if(account.isEmpty()||pwd.isEmpty()){
        //弹出警告框
        QMessageBox::warning(this,tr("Empty"),"Account or password is empty!");
    }else{
        if(ui->comboBox->currentText()==" Member"){

            if(Sdb.Userlogin(account,pwd)){
                //再加上给下一个窗口传送用户名值


                this->hide();
                userForm.show();
                if(!userForm.setUser(account)){
                    qDebug()<<"Error";
                }

                userForm.exec();

                this->show();
            }else{
                //弹出警告框，密码错误
                QMessageBox::warning(this,tr("WRONG"),"ENTER the right account and password!");
            }



        }else if(ui->comboBox->currentText()==" Cashier"){
            if(Sdb.Cashierlogin(account,pwd)){
                //再加上给下一个窗口传送用户名值

                this->hide();
                cashier.show();
                cashier.setCashier(account);
                cashier.exec();
                this->show();
            }else{
                //弹出警告框，密码错误
                QMessageBox::warning(this,tr("Password"),"ENTER the right account and password!");
            }




        }else{
            //if(Sdb.Userlogin(account,pwd)){
            if(account=="manager"&&pwd=="123"){
                //再加上给下一个窗口传送用户名值
                this->hide();
                manager.show();
                manager.exec();
                this->show();
            }else{
                //弹出警告框，密码错误
                QMessageBox::warning(this,tr("Password"),"ENTER the right account and password!");
            }

          }
    }
}

void MainWindow::on_pushButton_2_clicked()
{


}
