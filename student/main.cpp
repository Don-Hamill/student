#include <iostream>
#include "student.h"
#include "roster.h"

using namespace std;

int main()
{
    // Course title, programming language used, Student ID and name.

    cout << "--------------------------------------------" << endl;
    cout << "C867: Scripting and Programming Applications" << endl;
    cout << "Language used: C++" << endl;
    cout << "ID: 002240729" << endl;
    cout << "Donald Hamill" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    // student data table 
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Donald,Hamill,dghamill1@gmail.com,27,14,17,21,SOFTWARE",
    };

    
    //create roster class
    Roster* classRoster = new Roster();
   

    //call parse method
    for (int i = 0; i < (sizeof(studentData))/(sizeof(studentData[0])); ++i) {
        classRoster->parse(studentData[i]);
        }
    
    //print class roster
    cout << "Outputting the full roster of students:" << endl;
    classRoster->printAll();
    cout << endl;

    //prints invalid emails
    cout << "The following emails are invalid:" << endl;
    classRoster->printInvalidEmails();
    cout << endl;

    //loop through classRosterArray and for each element:
    cout << "Average days spent in courses: " << endl;
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    cout << endl;


   //print according to degree
    cout << "Displaying roster by SOFTWARE program:" << endl;
    classRoster->Roster::printByDegreeProgram(SOFTWARE);
    cout << endl << "Displaying roster by NETWORK program:" << endl;
    classRoster->Roster::printByDegreeProgram(NETWORK);
    cout << endl << "Displaying roster by SECURITY program:" << endl;
    classRoster->Roster::printByDegreeProgram(SECURITY);
    cout << endl << endl;

   
    classRoster->remove("A3");

  
    classRoster->printAll();

    // Remove student ID A3 again to produce error message
    classRoster->remove("A3");
    cout << endl;
 
    

}