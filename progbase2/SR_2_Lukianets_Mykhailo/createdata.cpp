#include "createdata.h"
#include "ui_createdata.h"

CreateData::CreateData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateData)
{
    ui->setupUi(this);
}

CreateData::~CreateData()
{
    delete ui;
}

void CreateData::GetOptions (QString & nameF, QString & nameM, int & ageF, int & ageM){
       nameF = ui->FatName_lineEdit->text();
       nameM = ui->MotName_lineEdit_2->text();
       ageF = ui->FatAge_spinBox->value();
       ageM = ui->MotAge_spinBox_2->value();

}
