#ifndef DINO_H
#define DINO_H
#include <string>
#include <QString>
#include <QMetaType>
using namespace std;

class Dino {
private:
    QString name;
    int age;
    float mass;
    QString fr;


public:
    Dino();
    Dino(QString name, QString fr, float mass, int age);

    QString getName();
    QString getFriend();
    int getAge();
    float getMass();

    void setName(std::string name);
    void setFriend(std::string fr);
    void setAge(int age);
    void setMass(float mass);

};

Q_DECLARE_METATYPE(Dino )

#endif // DINO_H
