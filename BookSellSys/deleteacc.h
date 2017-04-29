#ifndef DELETEACC_H
#define DELETEACC_H

#include <QDialog>

namespace Ui {
class DeleteAcc;
}

class DeleteAcc : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteAcc(QWidget *parent = 0);
    ~DeleteAcc();

private:
    Ui::DeleteAcc *ui;
};

#endif // DELETEACC_H
