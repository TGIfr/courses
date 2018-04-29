#include <QCoreApplication>
#include <QFileSystemWatcher>
#include <QDebug>
#include "myclass.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QFileSystemWatcher watcher;
        //
        // directories and files should exist
        watcher.addPath("/home/tgifr/projects/c/progbase2/practice2");


        for (auto dir: watcher.directories()) qDebug() << dir << "/";
        for (auto file: watcher.files()) qDebug() << file << endl;

        MyClass mc;

        QObject::connect(&watcher, SIGNAL(directoryChanged(QString)), &mc, SLOT(showModified(QString)));
        QObject::connect(&watcher, SIGNAL(fileChanged(QString)), &mc, SLOT(showFileModified(QString)));

   return app.exec();
}
