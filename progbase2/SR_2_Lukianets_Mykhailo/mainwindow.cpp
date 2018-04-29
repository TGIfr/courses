#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createdata.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString MainWindow::SaveDataToJsonStr(QString & nameF, QString & nameM, int & ageF, int & ageM){
    QJsonObject jsonObject;

    QJsonObject father;
    father["name"] = nameF;
    father["age"] = ageF;

    jsonObject["father"] = father;

    QJsonObject mother;
    mother["name"] = nameM;
    mother["age"] = ageM;

    jsonObject["mother"] = mother;

    QJsonDocument jsonDoc(jsonObject);


    return jsonDoc.toJson();
}

void MainWindow::on_pushButton_pressed()
{
     CreateData dialog;
     dialog.setWindowTitle("Enter data");
        if (dialog.exec()) {
            QString nameF;
            QString nameM;
            int ageF;
            int ageM;
            dialog.GetOptions(nameF, nameM, ageF, ageM);
            jsonStr = SaveDataToJsonStr( nameF,  nameM,  ageF,  ageM);
            qDebug() << "Accepted!" << jsonStr;
        } else {
            qDebug() << "Rejected!";
        }
}

void MainWindow::on_pushButton_2_pressed()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString filename = QFileDialog::getSaveFileName(NULL, "Save file", "", ".conf");
    QFile f( filename );
    f.open( QIODevice::WriteOnly );
    f.write(jsonStr.toStdString().c_str(), jsonStr.length());
    f.close();
}
