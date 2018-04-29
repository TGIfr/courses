#include "mainwindow.h"
#include <QApplication>
#include "myclass.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    for (auto dir: watcher.directories()) qDebug() << dir << "/";
    for (auto file: watcher.files()) qDebug() << file << endl;

        MyClass mc;

        QObject::connect(&watcher, SIGNAL(directoryChanged(QString)), &mc, SLOT(showModified(QString)));
        QObject::connect(&watcher, SIGNAL(fileChanged(QString)), &mc, SLOT(showFileModified(QString)));

    return a.exec();
}
