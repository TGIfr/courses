#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

private:
    QString jsonStr = "";
    QString SaveDataToJsonStr(QString & nameF, QString & nameM, int & ageF, int & ageM);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
