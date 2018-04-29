#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    teachers.push_back(new teacher("test 0", 10, 5.5f));
    teachers.push_back(new teacher("test 1", 20, 4.5f));
    teachers.push_back(new teacher("test 2", 30, 4.5f));
    teachers.push_back(new teacher("test 3", 40, 544.5f));

    //for initializing
    on_lineEdit_textChanged(QString::fromStdString("0"));

    //for spinBox
    //on_spinBoxIndex_valueChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent (QCloseEvent *event)
{
    // use this to cleanup allocated memory

    for (teacher * tc : teachers) {
        delete tc;
    }

    event->accept();
}

//! can be used for spinBox(needs to be enabled and initialization changed)

void MainWindow::on_spinBoxIndex_valueChanged(int index)
{
    QLabel * wrongLabel = this->findChild<QLabel *>("labelWrong");

    if(index + 1 > (signed) teachers.size() || index < 0){
        wrongLabel->show();
    } else {
        teacher * tch = teachers.at(index);
        QLabel * ageLabel = this->findChild<QLabel *>("labelAge");
        QLabel * nameLabel = this->findChild<QLabel *>("labelName");
        QLabel * scoreLabel = this->findChild<QLabel *>("labelScore");

        ageLabel->setText(QString::number(tch->age));
        nameLabel->setText(QString::fromStdString(tch->name));
        scoreLabel->setText(QString::number(tch->score));

        wrongLabel->hide();

    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    int index = arg1.toInt();
    QLabel * wrongLabel = this->findChild<QLabel *>("labelWrong");

    if(index + 1 > (signed) teachers.size() || index < 0){
        wrongLabel->show();
    } else {
        teacher * tch = teachers.at(index);
        QLabel * ageLabel = this->findChild<QLabel *>("labelAge");
        QLabel * nameLabel = this->findChild<QLabel *>("labelName");
        QLabel * scoreLabel = this->findChild<QLabel *>("labelScore");

        ageLabel->setText(QString::number(tch->age));
        nameLabel->setText(QString::fromStdString(tch->name));
        scoreLabel->setText(QString::number(tch->score));

        wrongLabel->hide();

    }
}
