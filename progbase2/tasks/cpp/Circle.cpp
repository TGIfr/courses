//
// Created by tgifr on 14.03.17.
//

#include "Circle.h"
#include <cmath>
#include <iostream>

std::string Circle::getColor(){
    return this->color;
}
double Circle::getRadius(){
    return this->radius;
}
std::string Circle::getMaterial(){
    return this->material;
}
Circle::Circle(const std::string color, const std::string material, double radius){
    if(radius < 0) radius = 0;
    this->radius = radius;
    this->material = material;
    this->color = color;
}

double Circle::length(){
    return 2 * M_PI * this->radius;
}
double Circle::area(){
    return  M_PI * this->radius * this->radius;
}
void Circle::print(){
    std::cout <<"Color: "<< this->getColor() <<". Material: " << this->getMaterial()
              << ". Radius: " << this->getRadius()<< ".\n";
}
