#include "userform.h"
#include "ui_userform.h"
#include "selldb.h"
Userform::Userform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userform)
{

    ui->setupUi(this);
    setWindowTitle("Member Frame");
    ui->textEdit->hide();
    ui->pushButton_6->hide();
    //Sdb.createconnection();
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),
            this,SLOT(book_detail()));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),
            this,SLOT(book_detail_more()));
    connect(ui->pushButton_6,SIGNAL(clicked()),
            this,SLOT(hide()));
}



Userform::~Userform()
{
    delete ui;
}
bool Userform::setUser(QString name){
    ui->label_2->setText(name);

    return true;
}
QString Userform::getUser(){
    return this->Username;
}

void Userform::on_pushButton_clicked()
{

    changePSW.show();
    qDebug()<<ui->label_2->text();
    qDebug()<<"------------";
    changePSW.setname(ui->label_2->text());
    changePSW.exec();

}


void Userform::on_pushButton_2_clicked()
{


    purchaseRec.show();

    purchaseRec.record(ui->label_2->text());
    purchaseRec.exec();

}

void Userform::on_pushButton_3_clicked()
{
    QSqlQueryModel* model=new QSqlQueryModel;

    //首先判断checkbox的情况
    if(ui->checkBox->isChecked()){
        QString book_name=ui->lineEdit->text();

        if(ui->checkBox_2->isChecked()){
            QString Author=ui->lineEdit_2->text();

            if(ui->checkBox_3->isChecked()){
                QString Publisher=ui->lineEdit_3->text();
               model=Sdb.B_A_P_search(book_name,Author,Publisher);
                ui->tableView->setModel(model);

            }else{
                model=Sdb.B_A_search(book_name,Author);
                ui->tableView->setModel(model);
            }
        }else{
            if(ui->checkBox_3->isChecked()){
                QString Publisher=ui->lineEdit_3->text();
                model=Sdb.B_P_search(book_name,Publisher);
                ui->tableView->setModel(model);

            }else{
                model=Sdb.B_search(book_name);
                ui->tableView->setModel(model);
                //qDebug()<<model->data(model->index(1,3)).toString();
            }
        }
    }else{
        if(ui->checkBox_2->isChecked()){
            QString Author=ui->lineEdit_2->text();
            if(ui->checkBox_3->isChecked()){
                QString Publisher=ui->lineEdit_3->text();
                model=Sdb.A_P_search(Author,Publisher);
                ui->tableView->setModel(model);
            }else{
                model=Sdb.A_search(Author);
                ui->tableView->setModel(model);
            }
        }else{
            if(ui->checkBox_3->isChecked()){
                QString Publisher=ui->lineEdit_3->text();
                model=Sdb.P_search(Publisher);
                ui->tableView->setModel(model);
            }else{
                model=Sdb.All_search();
                ui->tableView->setModel(model);

            }
        }
    }
//    QVector<QString> str(10);
//    QStandardItemModel *model1=new QStandardItemModel;
//    model1->setColumnCount(5);
//    model1->setRowCount(10);
//    QStandardItemModel *model2=new QStandardItemModel;
//    model2->setColumnCount(5);
//    model2->setRowCount(10);
//    for(int i=0;i<5;i++){
//        QModelIndex index=model->index(i,3);
//        str[i]=index.data().toString();
//        qDebug()<<str.at(i);
//        QStandardItem *item=new QStandardItem(str.at(i));
//        model1->setItem(i,0,item);
//    }
//    for(int i=5;i<10;i++){
//        QModelIndex index=model->index(i,2);
//        str[i]=index.data().toString();
//        qDebug()<<str.at(i);
//        QStandardItem *item=new QStandardItem(str.at(i));
//        model2->setItem(i-5,0,item);
//    }



//    ui->listView->setModel(model1);
//    ui->listView_2->setModel(model2);
}

void Userform::book_detail(){
    QModelIndex index=ui->tableView->currentIndex();
    int row=index.row();
    index=index.sibling(row,0);
    qDebug()<<row;
    QString book_num=index.data((row,0)).toString();
    qDebug()<<book_num;
    QString style=tr("#label_3{"
                     "border-image:url(E:/Qt code/BookSellSys/BookPhoto/%1.jpg);"
                     "border:2px solid rgb(121,189,143);"
                     "border-radius:5px;"
                     "background-color:rbg(255,255,255);}").arg(book_num);
    qDebug()<<style;
    ui->label_3->setStyleSheet(style);
}

void Userform::book_detail_more(){
    ui->textEdit->setText("");
    ui->tableView->hide();
    ui->textEdit->show();
    ui->pushButton_6->show();
    QModelIndex index=ui->tableView->currentIndex();
    int row=index.row();
    index=index.sibling(row,1);
    qDebug()<<row;
    QString book_num=index.data((row,0)).toString();
    qDebug()<<book_num;
    QFile file(tr("E:/Qt code/BookSellSys/detail/%1.txt").arg(book_num));
    QString line;
    if(file.open(QFile::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            line=line.append(in.readLine());
            line=line.append("\n");
            qDebug()<<tr("%1.txt").arg(book_num)<<line;

        }
        ui->textEdit->setText(line);
        file.close();
    }
}
void Userform::hide(){
    ui->textEdit->hide();
    ui->pushButton_6->hide();
    ui->tableView->show();
}
void Userform::on_pushButton_5_clicked()
{
    this->close();

}


