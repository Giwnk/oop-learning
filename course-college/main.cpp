#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Employee
{
    int id {};
    string name{};
    int age {};
    double salary{};
};

vector<Employee> initEmployee(){
    Employee joe {};
    joe.id = 14;
    joe.age = 32;
    joe.salary = 60000.0;
    Employee frank { .id=15, .name="Frank", .age=28, .salary=45000.0 };
    vector<Employee> employees{joe, frank};
    return employees;
}

void printEmployees(vector<Employee> employees){
    for (const auto &employee: employees){
        cout << "ID: " << employee.id << endl;
        cout << "Name: " << employee.name << endl;
        cout << "Age: " << employee.age << endl;
        cout << "Salary: " << employee.salary << endl;
    }
}

vector<Employee> addEmployee(vector<Employee> employees, Employee employee){
    employees.push_back(employee);
    return employees;
}

vector<Employee> removeEmployee(vector<Employee> Employees, int id){
    for (size_t i = 0; i < Employees.size(); ++i){
        if (Employees[i].id == id){
            Employees.erase(Employees.begin() + i);
            break;
        }
    }
    return Employees;
}


int main() {
    vector<Employee> employees = initEmployee();
    Employee joe = employees[0];
    Employee frank = employees[1];
    Employee employee1 { .id=16, .name="Alice", .age=30, .salary=70000.0 };
    employees = addEmployee(employees, employee1);
    int totalAge { joe.age + frank.age };
    cout << "Joe and Frank have lived " << totalAge << " total years\n";
    if (joe.salary > frank.salary)
    cout << "Joe makes more than Frank\n";
    else if (joe.salary < frank.salary)
    cout << "Joe makes less than Frank\n";
    else
    cout << "Joe and Frank make the same amount\n";
    // Frank got a promotion
    frank.salary += 5000.0;
    // Today is Joe's birthday
    ++joe.age; // use pre-increment to increment Joe's age by
    printEmployees(employees);
    return 0;
}


