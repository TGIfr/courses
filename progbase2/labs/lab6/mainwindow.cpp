#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dino.h"
#include <QString>
#include <QDebug>
#include "adddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString name("Ori");
    QString fr("Sein");
    Dino din(name, fr, 15.6, 48);

    QVariant qVariant;
    qVariant.setValue(din);

    QListWidgetItem *qDinoListItem = new QListWidgetItem();
    qDinoListItem->setText(din.getName());
    qDinoListItem->setData(Qt::UserRole, qVariant);

    ui->Dino_listWidget->addItem(qDinoListItem);
    ui->pushButton_2->setEnabled(false);
    ui->editPushButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Dino_listWidget_itemSelectionChanged()
{
    auto items =  ui->Dino_listWidget->selectedItems();
    if (items.size() == 0) {
        ui->pushButton_2->setEnabled(false);
          qDebug() << "no selected items";
        ui->editPushButton->setEnabled(false);
          return;
    }

    ui->pushButton_2->setEnabled(true);
    ui->editPushButton->setEnabled(true);

    QListWidgetItem * selectedItem = items[0];
    Dino din = selectedItem->data(Qt::UserRole).value<Dino>();
    ui->Age_label->setText(QString::number(din.getAge()));
    ui->Name_label->setText(din.getName());
    ui->Friend_label->setText(din.getFriend());
    ui->Mass_label->setText(QString::number(din.getMass()));

}

void MainWindow::on_pushButton_2_pressed()
{
    QList<QListWidgetItem*> items = ui->Dino_listWidget->selectedItems();

    foreach(QListWidgetItem * item, items)
    {
        delete ui->Dino_listWidget->takeItem(ui->Dino_listWidget->row(item));
    }



}

void MainWindow::on_FindByMass_pushButton_pressed()
{

    float critMass = ui->Mass_doubleSpinBox->value();
    QString res = "";
    for(int index = 0; index < ui->Dino_listWidget->count(); index++)
    {
        QListWidgetItem * item = ui->Dino_listWidget->item(index);
        Dino din = item->data(Qt::UserRole).value<Dino>();
        if(din.getMass() < critMass) {
            res += din.getName();
            res += "\n";
        }

    }
    ui->Result_textBrowser->setText(res);
}

void MainWindow::on_pushButton_pressed()
{
    AddDialog dialog;
    dialog.setWindowTitle("Enter data");
        if (dialog.exec()) {
            QString name;
            QString fr;
            int age;
            float mass;
            dialog.GetOptions(name, fr, age, mass);
            Dino din(name, fr, mass, age);
            QVariant qVariant;
            qVariant.setValue(din);

            QListWidgetItem *qDinoListItem = new QListWidgetItem();
            qDinoListItem->setText(din.getName());
            qDinoListItem->setData(Qt::UserRole, qVariant);

            ui->Dino_listWidget->addItem(qDinoListItem);
            qDebug() << "Accepted!";
        } else {
            qDebug() << "Rejected!";
        }

}

void MainWindow::on_editPushButton_clicked()
{
    auto items =  ui->Dino_listWidget->selectedItems();
    if(items.size() == 0) return;

    AddDialog dialog;
    dialog.setWindowTitle("Enter data");
        if (dialog.exec()) {
            QString name;
            QString fr;
            int age;
            float mass;
            dialog.GetOptions(name, fr, age, mass);
            Dino din(name, fr, mass, age);
            QVariant qVariant;
            qVariant.setValue(din);

            QListWidgetItem *qDinoListItem = new QListWidgetItem();
            qDinoListItem->setText(din.getName());
            qDinoListItem->setData(Qt::UserRole, qVariant);

            foreach(QListWidgetItem * item, items)
            {
                delete ui->Dino_listWidget->takeItem(ui->Dino_listWidget->row(item));
            }

            ui->Dino_listWidget->addItem(qDinoListItem);
            qDebug() << "Accepted!";
        } else {
            qDebug() << "Rejected!";
        }

}
