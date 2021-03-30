#pragma once
#include "student.h"
    
using namespace std;

class Roster {
public:
    int studentCount = 0;
    const static int studentData = 5;
    Student* classRosterArray[studentData];

    
    void parse(string studentData);
    //Define functions for student table
    void add(string studentId, string firstName, string lastName, string Email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void remove(string studentID);
    ~Roster();
};

