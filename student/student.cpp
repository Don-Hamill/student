#include "student.h"
#include "degree.h"

Student::Student(string studentID, string firstName, string lastName, string Email, int age, int daysToComplete[], DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName), age(age), Email(Email), daysToComplete(new int[NUMOFCOURSES]),degreeProgram(degreeProgram) 
    {
    for (int i = 0; i < NUMOFCOURSES; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    
}

//getter implementations
string Student::GetstudentID() 
{ return this->studentID; }

string Student::GetfirstName() 
{return this->firstName;}

string Student::GetlastName() 
{return this->lastName;}

int Student::GetAge() 
{ return this->age;}

string Student::GetEmail() 
{return this->Email;}

int* Student::GetDaystoComplete() 
{return this->daysToComplete;}

DegreeProgram Student::GetDegreeProgram() 
{return degreeProgram;}


// setter implementations
void Student::SetstudentID(string studentID) 
{this->studentID = studentID;}

void Student::SetfirstName(string firstName) 
{this->firstName = firstName;}

void Student::SetAge(int age) 
{this->age = age;}

void Student::SetEmail(string Email) 
{ this->Email = Email;}

void Student::SetDaystoComplete(int daysToComplete[]) {
    for (int i = 0; i < NUMOFCOURSES; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}


//print specifics for each student in data table
void Student::print() {
    cout << "Student ID: " << GetstudentID() << '\t'
    << "First name: " << firstName << '\t' 
    << "Last name: " << lastName << '\t'
    << "Email: " << Email << '\t' 
    << "Age: " << age << '\t' 
    << "Days In Course: ";

    for (int i = 0; i < NUMOFCOURSES; i++) {
        cout << daysToComplete[i];
        if (i != NUMOFCOURSES - 1) {
            cout << ", ";
        }
    }
    cout << '\t' << "Degree Program: ";

    
    if (degreeProgram == 0) {
        cout << "SECURITY";
    }
    else if (degreeProgram == 1) {
        cout << "NETWORK";
    }
    else if (degreeProgram == 2) {
        cout << "SOFTWARE";
    }
    else if (degreeProgram == 3) {
        cout << "NONE";
    }

    cout << endl;
    return;
}