#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

using namespace std;

int main()
{

    QString filePath(":/data/file.json");
    QFile qFile(filePath);
    if (!qFile.open(QFile::ReadOnly | QFile::Text)) {
        cerr << "Can't open file" << endl;
        return 1;
    }
    QTextStream in(&qFile);
    QString jsonString = in.readAll();
    cout << jsonString.toStdString();
    qFile.close();
    int count = 0;
    float sum = 0;
            auto jdoc = QJsonDocument::fromJson(jsonString.toUtf8());
            if (jdoc.isObject()) {
                QJsonObject jobj = jdoc.object();
                cout << "Object properties count: " << jobj.count() << endl;
                for (auto key : jobj.keys()) {
                    cout << key.toStdString() << ": ";
                    auto p = jobj[key];
                    if (p.isDouble()) cout << p.toDouble();
                    else if (p.isString()) cout << p.toString().toStdString();
                    cout << endl;
                }
            } else if (jdoc.isArray()) {
                QJsonArray jarr = jdoc.array();
                cout << "Array items count: " << jarr.count() << endl;
                for (auto item : jarr) {
                    if (item.isDouble()) {
                        sum += item.toDouble();
                        count ++;
                    }
                }
                cout << endl;
            } else if (jdoc.isNull()) {
                cout << "JSON is NULL" << endl;
            }
    cout << "Sum: "<< sum << "\n Count: " << count << endl;
    return 0;
}
