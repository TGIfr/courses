#ifndef CREATEDATA_H
#define CREATEDATA_H

#include <QDialog>

namespace Ui {
class CreateData;
}

class CreateData : public QDialog
{
    Q_OBJECT

public:
    explicit CreateData(QWidget *parent = 0);
    void GetOptions (QString & nameF, QString & nameM, int & ageF, int & ageM);
    ~CreateData();

private:
    Ui::CreateData *ui;
};

#endif // CREATEDATA_H
