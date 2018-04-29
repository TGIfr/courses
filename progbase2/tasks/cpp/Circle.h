//
// Created by tgifr on 14.03.17.
//

#ifndef CPP_CIRCLE_H
#define CPP_CIRCLE_H


#include <string>

class Circle {
    double radius;
    std::string color;
    std::string material;
public:
    std::string getColor();
    double getRadius();
    std::string getMaterial();
    double length();
    double area();
    Circle(const std::string color = "red", const std::string material = "metal", double radius = 1.);
    void print();
};


#endif //CPP_CIRCLE_H
