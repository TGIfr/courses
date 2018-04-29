#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <teacher.h>

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
    void closeEvent (QCloseEvent *event);

    void on_spinBoxIndex_valueChanged(int arg1);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    std::vector<teacher *> teachers;
};

#endif // MAINWINDOW_H
