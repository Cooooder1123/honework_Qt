#include "changepsw.h"
#include "ui_changepsw.h"
#include<QMessageBox>
ChangePSW::ChangePSW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePSW)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

ChangePSW::~ChangePSW()
{
    delete ui;
}
void ChangePSW::setname(QString name){
    this->name=name;
}

void ChangePSW::on_pushButton_clicked()
{
    int age=ui->lineEdit_2->text().toInt();
    QString pho=ui->lineEdit_3->text();

        //qDebug()<<this->name;
        Sdb.modify(this->name,age,pho);

}
