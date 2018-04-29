#include <iostream>
#include <vector>
#include "Circle.h"

using namespace std;
void printCircles(vector<Circle *> & v);
void addCircleFromUser(vector<Circle *> &v);
void printWithLMoreThan(double length, std::vector<Circle *> &v);

enum{
    QUIT = 'q',
    PRINT = 'p',
    PRINT_MASS = 'm',
    ADD = 'a'
};
int main() {
    vector<Circle * > v;
    v.reserve(10);
    v.push_back(new Circle());
    cout<< "q to quit, a to add, p to print, m to print wih length more than x\n";
    char ch = 0;
    while(ch != QUIT){
        cin >> ch ;
        switch (ch) {
            case ADD:
                addCircleFromUser(v);
                cout<<"Done\n";
                break;
            case PRINT_MASS:
                double length;
                cout<< "Enter length\n";
                cin >> length;
                printWithLMoreThan(length, v);
                cout<<"Done\n";
                break;
            case PRINT:
                printCircles(v);
                cout<<"Done\n";
                break;
        }
    }


    for (vector< Circle * >::iterator it = v.begin() ; it != v.end(); ++it) {
        delete (*it);
    }
    v.clear();
    return 0;
}

void printCircles(vector<Circle *> & v){
    for (int i = 0 ; i < v.size(); ++i) {
        cout << "Index: " << i << endl;
        v.at(i)->print();
    }
}
void addCircleFromUser(vector<Circle *> &v){
    string color;
    cout<<"Enter color\n";
    cin >> color;

    string material;
    cout<<"Enter material\n";
    cin >> material;

    double radius;
    cout<<"Enter radius\n";
    cin >> radius;

    v.push_back(new Circle(color, material, radius));
}
void printWithLMoreThan(double length, vector<Circle *> &v) {
    for (int i = 0 ; i < v.size(); ++i) {
        Circle * cur = v.at(i);
        if(cur->length() > length){
            cur->print();
            cout<< "Length: " << cur->length()<< endl;
        }

    }
}

