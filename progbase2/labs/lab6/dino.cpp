#include "dino.h"
Dino::Dino (void){}

Dino::Dino (QString name, QString fr, float mass, int age){
    this->name = name;
    this->age = age;
    this->mass = mass;
    this->fr = fr;

}

QString Dino::getName(){
    return name;
}

QString Dino::getFriend(){
    return fr;
}

int Dino::getAge(){
    return age;
}

float Dino::getMass(){
    return mass;
}

void Dino::setName(std::string name){
    this->name = QString::fromStdString(name);
}

void Dino::setFriend(std::string fr){
    this->fr = QString::fromStdString(fr);
}

void Dino::setAge(int age){
    this->age = age;
}

void Dino::setMass(float mass){
    this->mass = mass;
}
