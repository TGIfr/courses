#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sundata.h"
#include <QString>
#include <QDebug>
#include "adddialog.h"
#include <QPainter>
#include <time.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SunData Kyiv("Kyiv", 51, 31);
    if(Kyiv.GetCity().compare("ERROR") == 0){
        qDebug() << "FAILED TO GET CITY DATA";
        return;
    }

    QVariant qVariant;
    qVariant.setValue(Kyiv);

    QListWidgetItem *qCityListItem = new QListWidgetItem();
    qCityListItem->setText(QString::fromStdString(Kyiv.GetCity()));
    qCityListItem->setData(Qt::UserRole, qVariant);

    ui->City_listWidget->addItem(qCityListItem);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_City_listWidget_itemSelectionChanged()
{
    auto items =  ui->City_listWidget->selectedItems();
    if (items.size() == 0) {
          return;
    }



    QListWidgetItem * selectedItem = items[0];
    SunData city = selectedItem->data(Qt::UserRole).value<SunData>();
    ui->City_label->setText(QString::fromStdString(city.GetCity()));
    ui->CurTime_label->setText(QString::fromStdString(city.GetLocalTime()));
    ui->Lat_label->setText(QString::number(city.GetLat()));
    ui->Lng_label->setText(QString::number(city.GetLng()));
    ui->Sunrise_label->setText(QString::fromStdString(city.GetSunrise()));
    ui->Sunset_label->setText(QString::fromStdString(city.GetSunset()));
    ui->UTCShift_label->setText(QString::fromStdString(city.GetUTCShift()));
    ui->ZoneId_label->setText(QString::fromStdString(city.GetTimeZoneId()));
    ui->ZoneName_label->setText(QString::fromStdString(city.GetTimeZoneName()));


    //add something for showing circle as sun and turnong off/on sunavalaible lable
    int dayLengthSeconds = abs((city.GetSunsetSeconds() + city.GetUTCShiftSeconds())%(24*60*60) -
            (city.GetSunriseSeconds() + city.GetUTCShiftSeconds()) % (24*60*60));
    time_t thisDaySeconds = city.GetTimeSinceMidnightSeconds() -
            abs((city.GetSunriseSeconds() + city.GetUTCShiftSeconds())%(24*60*60));
    qDebug() << "dayLengthSeconds" << dayLengthSeconds << " thisDaySeconds" << thisDaySeconds <<
                "time since midnight" << city.GetTimeSinceMidnightSeconds();
    if(thisDaySeconds < 0 || thisDaySeconds > dayLengthSeconds){
        ui->SunAvalaible_label->setVisible(true);
        ui->Sun_progressBar->setVisible(false);
    } else {
        ui->SunAvalaible_label->setVisible(false);
        ui->Sun_progressBar->setVisible(true);
        ui->Sun_progressBar->setValue(thisDaySeconds * 100 / dayLengthSeconds);
    }


}

void MainWindow::on_Add_pushButton_pressed()
{
    adddialog dialog;
    dialog.setWindowTitle("Enter data");
        if (dialog.exec()) {
            QString city;
            float lng;
            float lat;
            dialog.GetOptions(city, lat, lng);
            SunData City(city.toStdString(), lat, lng);

            if(City.GetCity().compare("ERROR") == 0){
                qDebug() << "FAILED TO GET CITY DATA";
                return;
            }

            QVariant qVariant;
            qVariant.setValue(City);

            QListWidgetItem *qCityListItem = new QListWidgetItem();
            qCityListItem->setText(QString::fromStdString(City.GetCity()));
            qCityListItem->setData(Qt::UserRole, qVariant);

            ui->City_listWidget->addItem(qCityListItem);
            qDebug() << "Accepted!";
        } else {
            qDebug() << "Rejected!";
        }
}
