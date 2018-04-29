#include "adddialog.h"
#include "ui_adddialog.h"

adddialog::adddialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddialog)
{
    ui->setupUi(this);
}

adddialog::~adddialog()
{
    delete ui;
}
void adddialog::GetOptions (QString & city,  float & lat, float & lng){
     city = ui->City_lineEdit->text();
     lat = ui->Lat_doubleSpinBox->value();
     lng = ui->Lng_doubleSpinBox->value();
}
