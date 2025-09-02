// Task 1 - Basic Encapsulation 

#include <iostream>
using namespace std;

class Student
{
private:
    string name,nim;
    int age;
public:

    // Setter
    void setAge(int inputAge){
        if (inputAge >= 17 && inputAge <= 30){
            age = inputAge;
        }
        else{
            cout << "Invalid Age, Try Again!!" << endl;
        }
    }

    void setName(string inputName){
        name = inputName;
    }

    void setNim(string inputNim){
        nim = inputNim;
    }

    // Getter
    void getAge(){
        cout << "Student's Age: " << age << endl;
    }

    void getName(){
        cout << "Student's Name: " << name << endl;
    }

    void getNim(){
        cout << "Student's NIM: " << nim << endl;
    }
};

int main(int argc, char const *argv[])
{
    Student student1;
    student1.setName("Giwank");
    student1.setNim("1313624038");
    student1.setAge(12);

    student1.getName();
    student1.getNim();
    student1.getAge();
    

    return 0;
}


