#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>

class MyClass : public QWidget
{
    Q_OBJECT

public:
    MyClass(QWidget* parent=0)
        :QWidget(parent){}

    ~MyClass(){}

public slots:
    void showFileModified(const QString & str)
    {
        qDebug() << "File modified: " << str;
    }

    void showModified(const QString& str)
    {
        qDebug() << "Directory modified: " << str;
    }
};


#endif // MYCLASS_H
