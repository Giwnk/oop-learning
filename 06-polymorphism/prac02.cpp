#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    int id;
public:
    Employee(string inputName, int inputID) {
        name = inputName;
        id = inputID;
    }

    void setName(string inputName){
        name = inputName;
    }

    void setID(int inputID){
        id = inputID;
    }

    string getName(){
        return name;
    }

    int getID(){
        return id;
    }

    void showInfo(){
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getID() << endl;
    }

    virtual int calSalary() = 0;

    virtual string getType() = 0;


};

class PermanentEmployee : public Employee
{
private:
    double monthlySalary;
public:
    PermanentEmployee(string inputName, int inputID, double inputMonthlySalary) 
    : Employee(inputName, inputID){
        monthlySalary = inputMonthlySalary;
    }

    void setMonthlySalary(double inputMonthlSalary){
        monthlySalary = inputMonthlSalary;
    }

    double getMonthlySalary(){
        return monthlySalary;
    }

    string getType(){
        string type = "Permanent Employee";
        return type;
    }

    int calSalary(){
        return monthlySalary;
    }
};

class ContractEmployee : public Employee
{
private:
    double hourlySalary;
    int workingHours;
public:
    ContractEmployee(string inputName, int inputID, int inputWorkingHours) 
    : Employee(inputName, inputID){
        hourlySalary = 50000;
        workingHours = inputWorkingHours;
    }

    void setWorkingHours(int inputWorkingHours){
        workingHours = inputWorkingHours;
    }

    double getHourlySalary(){
        return hourlySalary;
    }

    int getWorkingHours(){
        return workingHours;
    }

    string getType(){
        string type = "Contract Employee";
        return type;
    }

    int calSalary() {
        return hourlySalary * workingHours;
    }
};

class FreelanceEmployee : public Employee
{
private:
    double salaryPerProjects;
    int amountProjects;
public:
    FreelanceEmployee(string inputName, int inputID, int inputAmountProjects) 
    : Employee(inputName, inputID){
        salaryPerProjects = 500000;
        amountProjects = inputAmountProjects;
    }

    void setAmountProjects(int inputAmountProjects){
        amountProjects = inputAmountProjects;
    }

    double getSalaryPerProjects(){
        return salaryPerProjects;
    }

    int getAmountProjects(){
        return amountProjects;
    }

    string getType(){
        string type = "Freelance Employee";
        return type;
    }

    int calSalary(){
        return salaryPerProjects * amountProjects;
    }
};

void printSalarySlip(Employee* eptr){
    cout << "===============" << endl;
    cout << "Type Role: " << eptr->getType() << endl;
    eptr->showInfo();
    cout << "Salary: Rp." << eptr->calSalary() << endl;
}


int main(int argc, char const *argv[])
{

    PermanentEmployee pe1("Giwank",1038,2000000);
    PermanentEmployee pe2("Naya",1017,4500000);
    ContractEmployee ce1("Nanda",2043,75);
    ContractEmployee ce2("Dila",2026,50);
    FreelanceEmployee fe1("Ristia",3052,5);
    FreelanceEmployee fe2("Rahma",3096,8);

    Employee* employees[6] = { &pe1,&pe2,&ce1,&ce2,&fe1,&fe2} ;

    for (auto employee : employees)
    {
        printSalarySlip(employee);
    }
    



    return 0;
}

