// Task 3 - Using Logic
#include <iostream>
using namespace std;

class Grade
{
private:
    string name;
    int grade;
public:
    void setName(string inputName){
        name = inputName;
    }

    void setGrade(int inputGrade){
        if (inputGrade >= 0 && inputGrade <= 100)
        {
            grade = inputGrade;
        }
        else
        {
            cout << "Invalid Input, Make sure the grade is between 0 and 100" << endl;
        }
    }

    string getName(){
        return name;
    }

    char getGrade(){
        char letterGrade;
        if (grade >= 85)
        {
            letterGrade = 'A';
        }
        else if (grade >= 70)
        {
            letterGrade = 'B';
        }
        else if (grade >= 55)
        {
            letterGrade = 'C';
        }
        else
        {
            letterGrade = 'D';
        }
        return letterGrade;
    }
};

int main(int argc, char const *argv[])
{
    char grade;
    string name;

    Grade grade1;

    grade1.setName("Giwank");
    grade1.setGrade(70);
    name = grade1.getName();
    grade = grade1.getGrade();

    cout << "Hi " << name << ", Your Char Grade is: " << grade << endl;
    
    return 0;
}
