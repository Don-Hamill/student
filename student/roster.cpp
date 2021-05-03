#pragma once
#include <iostream>
#include "roster.h"
#include "student.h"


using namespace std;

void Roster::parse(string studentData)
{
    
    DegreeProgram degreeProgram = NONE;
    
    // determines student's degree program
    
    if ((studentData.at(1) == '1') || (studentData.at(1) == '4')) {
        degreeProgram = SECURITY;
    }
    if ((studentData.at(1) == '2')) {
        degreeProgram = NETWORK;
    }

    if ((studentData.at(1) == '3') || (studentData.at(1) == '5')) {
        degreeProgram = SOFTWARE;
    }

    //student data parse, vectorizing not allowed
    
    int Pos1 = studentData.find(","); 
    string studentID = studentData.substr(0, Pos1);

    int Pos2 = Pos1 + 1;
    Pos1 = studentData.find(",", Pos2);
    string firstName = studentData.substr(Pos2, Pos1 - Pos2);
    
    Pos2 = Pos1 + 1;
    Pos1 = studentData.find(",", Pos2);
    string lastName = studentData.substr(Pos2, Pos1 - Pos2);
    
    Pos2 = Pos1 + 1;
    Pos1 = studentData.find(",", Pos2);
    string Email = studentData.substr(Pos2, Pos1 - Pos2);
    
    Pos1 = Pos1 + 1;
    Pos1 = studentData.find(",", Pos2);
    int age = stoi(studentData.substr(Pos2, Pos1 - Pos2));
    
    Pos2 = Pos1 + 1;
    Pos1 = studentData.find(",", Pos2);
    int daysInCourse1 = stoi(studentData.substr(Pos2, Pos1 - Pos2));
    
    Pos2 = Pos1 + 1;
    Pos1 = studentData.find(",", Pos2);
    int daysInCourse2 = stoi(studentData.substr(Pos2, Pos1 - Pos2));
    
    Pos2 = Pos1 + 1;
    Pos1 = studentData.find(",", Pos2);
    int daysInCourse3 = stoi(studentData.substr(Pos2, Pos1 - Pos2));
    
    Pos2 = Pos1 + 1;
    Pos1 = studentData.find(",", Pos2);
    to_string(degreeProgram) = studentData.substr(Pos2, Pos1 - Pos2);

    add(studentID, firstName, lastName, Email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
  
}



// Implementing add
void Roster::add(string studentID, string firstName, string lastName, string Email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[studentCount] = new Student(studentID, firstName, lastName, Email, age, daysToComplete, degreeProgram); 
    studentCount++;
    
}

// prints a complete list of students
void Roster::printAll() {
    for (int i = 0; i < Roster::studentCount; ++i) {
        classRosterArray[i]->print();
        }
    }


// Removes students from the roster by student ID. 
void Roster::remove(string studentID) {
    bool studentIDFound = false;
    for (int i = 0; (i <= studentCount) && !studentIDFound; ++i) {
        if (classRosterArray[i]->GetstudentID() == studentID) {
            classRosterArray[i] = classRosterArray[studentCount - 1];
            --studentCount;
           studentIDFound = true;
        }
    }
    if (studentIDFound) {
        cout << "Student ID " << studentID << " found and removed." << endl;
    }
    else {
        cout << "Error: student with this ID not found." << endl;
    }
}



// Prints a student’s average number of days in the three courses.
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= studentCount; ++i) {
        if (classRosterArray[i]->GetstudentID() == studentID) {
            cout << "Student ID " << classRosterArray[i]->GetstudentID() << ": ";
            int* days = classRosterArray[i]->GetDaystoComplete();
            cout << "Average number of days in courses: " << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}

// prints invalid emails if they don't adhere to email standards
void Roster::printInvalidEmails() {
    for (int i = 0; i < studentCount; ++i) {
        string Email = classRosterArray[i]->GetEmail();
        long atSign = Email.find('@');
        long period = Email.find('.', atSign);

        if (atSign == string::npos) {
            cout << "Invalid email. Missing an @ symbol:" << Email << endl;
        }

        else if (period == string::npos) {
            cout << "Invalid email. Missing a '.' : " << Email << endl;
        }

        else if (Email.find(' ') != string::npos) {
            cout << "Invalid email. Spaces are not allowed in emails: " << Email << endl;
        }
    }
}

// prints degree program using enumeration
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
