#pragma once
#include "degree.h"
#include <string>
#include <iostream>


using namespace std;

// student class with ID, First name, email, age, array of days for courses and degree.

class Student {
public:
        const static int NUMOFCOURSES = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    int age;
    string Email;
    int* daysToComplete;
    DegreeProgram degreeProgram;
public:
    //student constructor 
    Student();
    Student(string studentID, string firstName, string lastName, string Email, int age, int daysToComplete[], DegreeProgram degreeProgram);
    ~Student();

    //Getters
    string GetstudentID();
    string GetfirstName();
    string GetlastName();
    string GetEmail();
    int GetAge();
    int* GetDaystoComplete();
    DegreeProgram GetDegreeProgram();

    //Setters
    void SetstudentID(string studentID);
    void SetfirstName(string firstName);
    void SetlastName(string lastName);
    void SetAge(int age);
    void SetEmail(string Email);
    void SetDaystoComplete(int daysToComplete[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);

    //print() to print specific student data
    void print();
    

};