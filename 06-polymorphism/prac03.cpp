#include <iostream>
using namespace std;

class Shape{
    private:
    string name;
    public:
    virtual double area() = 0;
    virtual double volume() = 0;
    
};