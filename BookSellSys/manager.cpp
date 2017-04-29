#include "manager.h"
#include "ui_manager.h"
#include<QtGui>
#include<QLayout>
#include<QBoxLayout>


Manager::Manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manager)
{

    ui->setupUi(this);
    setWindowTitle("Manager Frame");
    //initial widgets
    this->initSearchWidget();
    this->initCheckyearsWidget();
    this->initDeleteWidget();
    this->initBookWidget();
    this->initSearchUserWidget();
    //left four button
    QVBoxLayout *leftLayout=new QVBoxLayout;
    leftLayout->addWidget(SearchButton);
    leftLayout->addWidget(CheckyearsButton);
    leftLayout->addWidget(DeleteButton);
    leftLayout->addWidget(AddBookButton);
    leftLayout->addWidget(SearchUserButton);
    leftLayout->setSpacing(10);
    //this->setLayout(leftLayout);

    //using stacklayout to seperate
    stacklayout=new QStackedLayout;
    stacklayout->addWidget(Swidget);
    stacklayout->addWidget(Cwidget);
    stacklayout->addWidget(Dwidget);
    stacklayout->addWidget(Bwidget);
    stacklayout->addWidget(Uwidget);
    stacklayout->setCurrentWidget(Swidget);

    QHBoxLayout *mainlayout=new QHBoxLayout;
    mainlayout->addLayout(leftLayout);
    mainlayout->addLayout(stacklayout);
    this->setLayout(mainlayout);
    //

    //
    connect(SearchButton,SIGNAL(clicked()),
            this,SLOT(to_Swidget()));
    connect(CheckyearsButton,SIGNAL(clicked()),
            this,SLOT(to_Cwidget()));
    connect(DeleteButton,SIGNAL(clicked()),
            this,SLOT(to_Dwidget()));
    connect(AddBookButton,SIGNAL(clicked()),
            this,SLOT(to_Bwidget()));
    connect(SearchUserButton,SIGNAL(clicked()),
            this,SLOT(to_Uwidget()));
    //
    connect(sbPushButton1,SIGNAL(clicked()),
            this,SLOT(search_book()));
    connect(dButton2,SIGNAL(clicked()),
            this,SLOT(add()));
    connect(dButton1,SIGNAL(clicked()),
            this,SLOT(A_delete()));
    connect(tPushButton1,SIGNAL(clicked()),
            this,SLOT(data_search()));
    connect(bButton_add,SIGNAL(clicked()),
            this,SLOT(book_insert()));
    connect(bButton_exc,SIGNAL(clicked()),
            this,SLOT(book_insert_from_file()));
    connect(uButton,SIGNAL(clicked()),
            this,SLOT(User_search()));
    connect(uTable1,SIGNAL(doubleClicked(QModelIndex)),
            this,SLOT(User_info()));

}
Manager::~Manager()
{
    delete ui;
}
void Manager::initSearchWidget(){
    Swidget=new QWidget(this);
    SearchButton=new QPushButton(tr(""));
    SearchButton->setMinimumSize(100,70);
    SearchButton->setMaximumSize(100,70);
    SearchButton->setStyleSheet("border-image:url(E:/Qt code/BookSellSys/book4.png);");

    sbCheckBox1=new QCheckBox(tr("Book &name"));
    sbCheckBox2=new QCheckBox(tr("Author"));
    sbCheckBox3=new QCheckBox(tr("Book &printer"));
    sbLineEdit1=new QLineEdit;
    sbLineEdit2=new QLineEdit;
    sbLineEdit3=new QLineEdit;
    sbTable=new QTableView;
    sbPushButton1=new QPushButton(tr("Check"));
    sbPushButton2=new QPushButton(tr("Clear"));

    //the first button-search book
    QGridLayout *t1leftLayout=new QGridLayout;

    t1leftLayout->addWidget(sbCheckBox1,0,0);
    t1leftLayout->addWidget(sbCheckBox2,1,0);
    t1leftLayout->addWidget(sbCheckBox3,2,0);

    t1leftLayout->addWidget(sbLineEdit1,0,1);
    t1leftLayout->addWidget(sbLineEdit2,1,1);
    t1leftLayout->addWidget(sbLineEdit3,2,1);
    t1leftLayout->addWidget(sbTable,4,0,1,2);
    t1leftLayout->setContentsMargins(10,0,10,10);
    QVBoxLayout *midLayout=new QVBoxLayout;

    midLayout->addWidget(sbPushButton1);
    midLayout->addWidget(sbPushButton2);
//    midLayout->addStretch();
    sbPushButton1->setMaximumSize(90,100);
    sbPushButton2->setMaximumSize(90,100);
    sbPushButton1->setMinimumWidth(70);
    sbPushButton2->setMinimumWidth(70);
    QHBoxLayout *mainlayout=new QHBoxLayout;

    mainlayout->addLayout(t1leftLayout);
    mainlayout->addLayout(midLayout);

    //将mianlayout赋值给widget
    Swidget->setLayout(mainlayout);
}
void Manager::initCheckyearsWidget(){
    Cwidget=new QWidget(this);
    CheckyearsButton=new QPushButton(tr(""));
    CheckyearsButton->setMinimumSize(100,70);
    CheckyearsButton->setMaximumSize(100,70);
    CheckyearsButton->setStyleSheet("border-image:url(E:/Qt code/BookSellSys/sale_record.png);");
    tLabel1=new QLabel(tr(" From "));
    tLabel2=new QLabel(tr(" to "));
    tDateEdit1=new QDateEdit;
    tDateEdit2=new QDateEdit;
    tPushButton1=new QPushButton(tr("&Search"));
    tPushButton2=new QPushButton(tr("&Clear"));

    //checking time layout
    QGridLayout *tlayout=new QGridLayout;
    tlayout->addWidget(tLabel1,0,0);
    tlayout->addWidget(tLabel2,1,0);
    tlayout->addWidget(tDateEdit1,0,1,1,1);
    tlayout->addWidget(tDateEdit2,1,1,1,1);
    tlayout->addWidget(tPushButton1,2,0);
    tlayout->addWidget(tPushButton2,2,1);
    tlayout->setContentsMargins(10,10,10,10);
    tPushButton1->setMaximumSize(100,40);
    tPushButton2->setMaximumSize(100,40);
    //赋值
    Cwidget->setLayout(tlayout);
}
void Manager::initDeleteWidget(){
    Dwidget=new QWidget(this);
    DeleteButton=new QPushButton(tr(" "));
    DeleteButton->setMinimumSize(100,70);
    DeleteButton->setMaximumSize(100,70);
    DeleteButton->setStyleSheet("border-image:url(E:/Qt code/BookSellSys/add_account.png);");
    dcombobox=new QComboBox;
    dcombobox->addItem("Member");
    dcombobox->addItem("Cashier");
    dLabel=new QLabel(tr("Account:"));
    dLabel1=new QLabel(tr("Password:"));
    dLabel2=new QLabel(tr("Sex:"));
    dLabel3=new QLabel(tr("Age:"));
    dLabel4=new QLabel(tr("Phone:"));
    dLineEdit=new QLineEdit;
    dLineEdit1=new QLineEdit;
    dLineEdit_age=new QLineEdit;
    dLineEdit_sex=new QLineEdit;
    dLineEdit_phone=new QLineEdit;

    dButton1=new QPushButton(tr("&Del"));
    dButton2=new QPushButton(tr("&Add"));

    QGridLayout *toplayout=new QGridLayout;
    toplayout->addWidget(dcombobox,0,0);
    toplayout->addWidget(dLabel,1,0);
    toplayout->addWidget(dLineEdit,1,1,1,2);
    toplayout->addWidget(dLabel1,2,0);
    toplayout->addWidget(dLineEdit1,2,1,1,2);
    toplayout->addWidget(dLabel2,3,0);
    toplayout->addWidget(dLineEdit_sex,3,1,1,2);
    toplayout->addWidget(dLabel3,4,0);
    toplayout->addWidget(dLineEdit_age,4,1,1,2);
    toplayout->addWidget(dLabel4,5,0);
    toplayout->addWidget(dLineEdit_phone,5,1,1,2);
    toplayout->addWidget(dButton1,6,0,1,2);
    toplayout->addWidget(dButton2,6,2,1,2);
    dLabel->setMaximumSize(60,40);
    dLineEdit->setMaximumSize(120,40);
    dLabel1->setMaximumSize(60,40);
    dLineEdit1->setMaximumSize(120,40);
    dLabel2->setMaximumSize(60,40);
    dLineEdit1->setMaximumSize(120,40);
    dLabel3->setMaximumSize(60,40);
    dLineEdit_sex->setMaximumSize(120,40);
    dLabel4->setMaximumSize(60,40);
    dLineEdit_age->setMaximumSize(120,40);

    dLineEdit_phone->setMaximumSize(120,40);
    dButton1->setMaximumSize(90,40);
    dButton2->setMaximumSize(90,40);
    toplayout->setSpacing(20);
    toplayout->setContentsMargins(100,10,10,10);


    Dwidget->setLayout(toplayout);
}
void Manager::initBookWidget(){
    Bwidget=new QWidget;
    AddBookButton=new QPushButton(tr(" "));
    AddBookButton->setMaximumSize(100,70);
    AddBookButton->setMinimumSize(100,70);
    AddBookButton->setStyleSheet("border-image:url(E:/Qt code/BookSellSys/book_insert.png);");
    //widget init
    bLabel_num=new QLabel(tr("Book num:"));
    bLabel_nam=new QLabel(tr("Book name:"));
    bLabel_aut=new QLabel(tr("Author:"));
    bLabel_pub=new QLabel(tr("Publisher:"));
    bLabel_pri=new QLabel(tr("Price:"));
    bLabel_qua=new QLabel(tr("Quantity:"));
    bLineEdit_num=new QLineEdit;
    bLineEdit_nam=new QLineEdit;
    bLineEdit_aut=new QLineEdit;
    bLineEdit_pub=new QLineEdit;
    bLineEdit_pri=new QLineEdit;
    bLineEdit_qua=new QLineEdit;
    bButton_add=new QPushButton(tr("Add Book"));
    bButton_exc=new QPushButton(tr("Add from excel"));

    bLineEdit_num->setMaximumSize(150,20);
    bLineEdit_nam->setMaximumSize(150,20);
    bLineEdit_aut->setMaximumSize(150,20);
    bLineEdit_pri->setMaximumSize(150,20);
    bLineEdit_qua->setMaximumSize(150,20);
    bLineEdit_pub->setMaximumSize(150,20);
    bLabel_num->setMaximumSize(80,20);
    bLabel_nam->setMaximumSize(80,20);
    bLabel_aut->setMaximumSize(80,20);
    bLabel_pri->setMaximumSize(80,20);
    bLabel_qua->setMaximumSize(80,20);
    bLabel_pub->setMaximumSize(80,20);

    bButton_add->setMinimumSize(150,60);
    bButton_exc->setMinimumSize(150,60);
    bButton_add->setMaximumSize(150,60);
    bButton_exc->setMaximumSize(150,60);
    //frame initial
    QGridLayout *leftlayout=new QGridLayout;
    leftlayout->addWidget(bLabel_num,0,0);
    leftlayout->addWidget(bLabel_nam,1,0);
    leftlayout->addWidget(bLabel_aut,2,0);
    leftlayout->addWidget(bLabel_pub,3,0);
    leftlayout->addWidget(bLabel_pri,4,0);
    leftlayout->addWidget(bLabel_qua,5,0);
    leftlayout->addWidget(bLineEdit_num,0,1);
    leftlayout->addWidget(bLineEdit_nam,1,1);
    leftlayout->addWidget(bLineEdit_aut,2,1);
    leftlayout->addWidget(bLineEdit_pub,3,1);
    leftlayout->addWidget(bLineEdit_pri,4,1);
    leftlayout->addWidget(bLineEdit_qua,5,1);
    leftlayout->addWidget(bButton_add,1,3,2,1);
    leftlayout->addWidget(bButton_exc,3,3,2,1);

    leftlayout->setContentsMargins(70,10,10,10);

    Bwidget->setLayout(leftlayout);

}
void Manager::initSearchUserWidget(){
    Uwidget=new QWidget;
    SearchUserButton=new QPushButton(tr(" "));
    SearchUserButton->setMinimumSize(100,70);
    SearchUserButton->setMaximumSize(100,70);
    SearchUserButton->setStyleSheet("border-image:url(E:/Qt code/BookSellSys/user_search.png);");
    uLabel=new QLabel(tr("Account:"));
    uLineEdit=new QLineEdit;
    uButton=new QPushButton(tr("&Search"));
    uTable1=new QTableView;
    uTable2=new QTableView;
    QGridLayout *mainlayout=new QGridLayout;
    mainlayout->addWidget(uLabel,0,0);
    mainlayout->addWidget(uLineEdit,0,1,1,2);
    mainlayout->addWidget(uButton,0,3);
    mainlayout->addWidget(uTable1,1,0,5,5);
    mainlayout->addWidget(uTable2,6,0,5,5);
    uTable2->hide();
    Uwidget->setLayout(mainlayout);
}

void Manager::to_Swidget(){
    stacklayout->setCurrentWidget(Swidget);
}
void Manager::to_Cwidget(){
    stacklayout->setCurrentWidget(Cwidget);
}
void Manager::to_Dwidget(){
    stacklayout->setCurrentWidget(Dwidget);
}
void Manager::to_Bwidget(){
    stacklayout->setCurrentWidget(Bwidget);
}
void Manager::to_Uwidget(){
    stacklayout->setCurrentWidget(Uwidget);
}

//
void Manager::search_book(){
    if(sbCheckBox1->isChecked()){
        QString book_name=sbLineEdit1->text();

        if(sbCheckBox2->isChecked()){
            QString Author=sbLineEdit2->text();

            if(sbCheckBox3->isChecked()){
                QString Publisher=sbLineEdit3->text();
                QSqlQueryModel* model=Sdb.B_A_P_search(book_name,Author,Publisher);
                sbTable->setModel(model);

            }else{
                QSqlQueryModel* model=Sdb.B_A_search(book_name,Author);
                sbTable->setModel(model);
            }
        }else{
            if(sbCheckBox3->isChecked()){
                QString Publisher=sbLineEdit3->text();
                QSqlQueryModel* model=Sdb.B_P_search(book_name,Publisher);
                sbTable->setModel(model);

            }else{
                QSqlQueryModel* model=Sdb.B_search(book_name);
                sbTable->setModel(model);
                //qDebug()<<model->data(model->index(1,3)).toString();
            }
        }
    }else{
        if(sbCheckBox2->isChecked()){
            QString Author=sbLineEdit2->text();
            if(sbCheckBox3->isChecked()){
                QString Publisher=sbLineEdit3->text();
                QSqlQueryModel* model=Sdb.A_P_search(Author,Publisher);
                sbTable->setModel(model);
            }else{
                QSqlQueryModel* model=Sdb.A_search(Author);
               sbTable->setModel(model);
            }
        }else{
            if(sbCheckBox3->isChecked()){
                QString Publisher=sbLineEdit3->text();
                QSqlQueryModel* model=Sdb.P_search(Publisher);
                sbTable->setModel(model);
            }else{
                QSqlQueryModel* model=Sdb.All_search();
                sbTable->setModel(model);

            }
        }
    }
}
//
void Manager::add(){
    QString user=dcombobox->currentText();
    QString name=dLineEdit->text();
    QString password=dLineEdit1->text();
    QString sex=dLineEdit_sex->text();
    int age=dLineEdit_age->text().toInt();
    QString phone=dLineEdit_phone->text();
    QMessageBox *mb=new QMessageBox(this);

    if(user=="Member"){
        if(Sdb.UserAcc_add(name,password,sex,age,phone)){

            mb->warning(this,"Succeed","Add account succeed!");
            connect(mb,SIGNAL(destroyed()),dLineEdit,SLOT(clear()));
            connect(mb,SIGNAL(destroyed()),dLineEdit1,SLOT(clear()));

         }else{
            //mb->warning(this,"Failed","Add account Failed!");
        }
    }else{
        if(Sdb.CashAcc_add(name,password,sex,age,phone)){

            mb->warning(this,"Succeed","Add account succeed!");
            connect(mb,SIGNAL(destroyed()),dLineEdit,SLOT(clear()));
            connect(mb,SIGNAL(destroyed()),dLineEdit1,SLOT(clear()));

         }else{
            //mb->warning(this,"Failed","Add account Failed!");
        }
    }
}

void Manager::A_delete(){
    QString name=dLineEdit->text();
    QMessageBox *mb=new QMessageBox(this);
    if(Sdb.Acc_delete(name)){

        mb->warning(this,"Succeed","Delete account succeed!");
//        connect(mb,SIGNAL(),dLineEdit,SLOT(clear()));
//        connect(mb,SIGNAL(destroyed(QObject*)),dLineEdit1,SLOT(clear()));
        dLineEdit->clear();
        dLineEdit1->clear();

     }else{
       // mb->warning(this,"Failed","Delete account Failed!");
    }
}

void Manager::data_search(){
    QString date1=tDateEdit1->text();
    QString date2=tDateEdit2->text();
    date1.replace(4,1,'-');
    date1.replace(6,1,'-');
    date2.replace(4,1,'-');
    date2.replace(6,1,'-');
    Ds.search(date1,date2);
    Ds.show();
    Ds.exec();
}

void Manager::book_insert(){
    QString book_num=bLineEdit_num->text();
    QString book_nam=bLineEdit_nam->text();
    QString book_aut=bLineEdit_aut->text();
    QString book_pub=bLineEdit_pub->text();
    QString book_pri=bLineEdit_pri->text();
    QString book_qua=bLineEdit_qua->text();

    bool insert=Sdb.Book_add(book_num,book_nam,book_aut,
                 book_pub,book_pri,book_qua);
    if(insert){
        QMessageBox::warning(0,"Succeed!","Insert Succeed!");
        bLineEdit_num->clear();
        bLineEdit_nam->clear();
        bLineEdit_aut->clear();
        bLineEdit_pub->clear();
        bLineEdit_pri->clear();
        bLineEdit_qua->clear();
    }


}

void Manager::book_insert_from_file(){
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open Excel"),"C:/Users/ThinkPad/Desktop",tr("Execl files (*.csv)"));
    qDebug()<<fileName;
    QString line,book_num,book_nam,book_aut,book_pub,book_pri,book_qua;
    QStringList ls;
    bool insert;
    QFile file(fileName);
    if(file.open(QFile::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            line=in.readLine();
            ls=line.split(',');
            qDebug()<<line;
            book_num=ls.at(0);
            book_nam=ls.at(1);
            book_aut=ls.at(2);
            book_pub=ls.at(3);
            book_pri=ls.at(4);
            book_qua=ls.at(5);
//            insert=Sdb.Book_add(book_num,book_nam,book_aut,
//                         book_pub,book_pri,book_qua);
            if(insert=Sdb.Book_add(book_num,book_nam,book_aut,
                                   book_pub,book_pri,book_qua)){
                qDebug()<<book_num<<book_nam<<book_aut<<
                        book_pub<<book_pri<<book_qua;
            }else{
                break;
            }
        }
        if(insert){
            QMessageBox::warning(0,"Succeed!","Insert Succeed!");
        }
        file.close();
    }
}

void Manager::User_search(){
    QString account=uLineEdit->text();
    QSqlQueryModel *model=new QSqlQueryModel;
    uTable2->hide();
    if(account.isEmpty()){
        model=Sdb.user_search();
        uTable1->setModel(model);

    }else{
        model=Sdb.user_search(account);
        uTable1->setModel(model);
    }
}
void Manager::User_info(){
    QModelIndex index=uTable1->currentIndex();
    int row=index.row();
    QString name=index.data((row,0)).toString();
    qDebug()<<name;
    QSqlQueryModel *model= Sdb.Buy_search(name);
    uTable2->setModel(model);
    uTable2->show();
}
