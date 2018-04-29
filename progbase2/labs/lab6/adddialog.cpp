#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_buttonBox_accepted()
{


}
void AddDialog::GetOptions (QString & name, QString & fr, int & age, float & mass){
     name = ui->Name_lineEdit->text();
     fr = ui->Friend_lineEdit->text();
     mass = ui->Mass_doubleSpinBox->value();
     age = ui->Age_spinBox->value();
}
