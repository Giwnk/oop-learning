#include <iostream>
using namespace std;

class Student{
    private:
    string name,nim,studyProgram;

    
    public:
    Student(string inputName,string inputNim,string inputStudyProgram){
        setName(inputName);
        setNim(inputNim);
        setStudyProgram(inputStudyProgram);
    }
    
    void setName(string inputName){
        name = inputName;
    }
    void setNim(string inputNim){
        nim = inputNim;
    }
    void setStudyProgram(string inputStudyProgram){
        studyProgram = inputStudyProgram;
    }
    string getName(){
        return name;
    }
    string getNim(){
        return nim;
    }
    string getStudyProgram(){
        return studyProgram;
    }

    void showData(){
        cout << "Name: " << name << endl;
        cout << "NIM: " << nim << endl;
        cout << "Study Program: " << studyProgram << endl;
    }
};

class AssistantPracticum : public Student{
    private:
    string subject;
    int meetingsNumber;

    public:
    AssistantPracticum(string inputName,string inputNim,string inputStudyProgram,string inputSubject,int inputMeetingsNumber) 
    : Student(inputName,inputNim,inputStudyProgram){
        subject = inputSubject;
        meetingsNumber = inputMeetingsNumber;
    }
    void setSubject(string inputSubject){
        subject = inputSubject;
    }

    void showDataAsisstant(){
        cout << "Name: " << getName() << endl;
        cout << "NIM: " << getNim() << endl;
        cout << "Study Program: " << getStudyProgram() << endl;
        cout << "Subject: " << subject << endl;
        cout << "Meetings Number: " << meetingsNumber << endl;

    }

    int totalHonor(){
        return meetingsNumber * 50000;
    }
};

int main(int argc, char const *argv[])
{
    Student student1("Giwank","1313624038","Computer Science");
    student1.showData();
    student1.setName("Nayaa");
    student1.showData();

    AssistantPracticum ap1("Giwank","1313624038","Computer Science","HCI",20);
    ap1.showDataAsisstant();
    cout << "Total Honor: " << ap1.totalHonor() << endl;
    return 0;
}
