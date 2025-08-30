#include <iostream>
using namespace std;

class Vehicle
{
private:
    string brand;
    int year;
public:
    Vehicle(string inputBrand, int inputYear){
        brand = inputBrand;
        year = inputYear;
    };

    void setBrand(string inputBrand){
        brand = inputBrand;
    }

    void setYear(int inputYear){
        year = inputYear;
    }

    string getBrand(){
        return brand;
    }

    int getYear(){
        return year;
    }

    void showData(){
        cout << "Brand: " << getBrand() << endl;
        cout << "Year: " << getYear() << endl;
    }
};

class Car : public Vehicle{
    private:
    int doorsNumber;
    public:

    Car(string inputBrand, int inputYear, int inputDoorsNumber) 
    : Vehicle(inputBrand,inputYear){
        doorsNumber = inputDoorsNumber;
    }

    void setDoorsNumber(int inputDoorsNumber){
        doorsNumber = inputDoorsNumber;
    }
    int getDoorsNumber(){
        return doorsNumber;
    }
    void showCarData(){
        showData();
        cout << "Doors Number: " << getDoorsNumber() << endl;
    }
};

class Motorcycle : public Vehicle{
    private:
    string motorType;
    public:

    Motorcycle(string inputBrand, int inputYear, string inputmotorType) 
    : Vehicle(inputBrand,inputYear){
        motorType = inputmotorType;
    }

    void setMotorType(string inputmotorType){
        motorType = inputmotorType;
    }
    string getMotorType(){
        return motorType;
    }
    void showMotorcycleData(){
        showData();
        cout << "Motor Type: " << getMotorType() << endl;
    }
};

int main(int argc, char const *argv[])
{
    Car cars[3] = {
        Car("Suzuki",1980,4),
        Car("Ferarri", 2007, 4),
        Car("Toyota", 2004, 2)
    };

    Motorcycle motorcycles[3] = {
        Motorcycle("Honda",2018,"Trail"),
        Motorcycle("Yamaha",2015,"Sport"),
        Motorcycle("Honda",2007,"Matic")
    };

    
    cout << "\n=== Car List ===" << endl;
    for (Car car : cars)
    {
        car.showCarData();
        cout << "-----------------" << endl;
    }
    
    cout << "\n=== Motorcycle List ===" << endl;
    for (Motorcycle motorcycle : motorcycles)
    {
        motorcycle.showMotorcycleData();
        cout << "-----------------" << endl;
    }
    
    return 0;
}
