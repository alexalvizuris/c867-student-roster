//
//  main.cpp
//  C867 repository
//
//  Created by Alex Alvizuris on 7/20/20.
//  Copyright © 2020 Alex Alvizuris. All rights reserved.
//


#include "roster.h"
#include "student.h"

using namespace std;

int main() {
    
    cout << "------------" << endl;
    cout << "C867 Scripting and Programming: Applications" << endl;
    cout << "C++" << endl;
    cout << "WGU Student ID # 000952724" << endl;
    cout << "Alejandro Alvizuris" << endl;
    cout << "____________" << endl;
    
    Roster* classRoster = new Roster(numStudents);                 //creates new roster
    cout << "Parsing data and adding students.." << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster->parseAdd(studentData[i]);                     //parses each line, adds to roster
    }
    cout << "Done." << endl;
    cout << "Displaying all students: " << endl;
    classRoster->printALL();                                       //prints out all students added to roster
    
    cout << "____________" << endl;
    
    cout << "Printing invalid emails: " << endl;
    classRoster->printInvalidEmails();                             //prints invalid emails
    
    cout << "____________" << endl;
    
    cout << "Printing average amout of days to complete courses: " << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
    }                                                              //prints avg amout of days to complete course
    
    cout << "____________" << endl;
    
    classRoster->printByDegreeProgram(SOFTWARE);                   //prints out software degree students
    
    cout << "____________" << endl;
    
    cout << "Removing student A3" << endl;
    classRoster->remove("A3");
    
    cout << "____________" << endl;
    
    cout << "Printing remaining students from roster:" << endl;
    classRoster->printALL();
    
    cout << "____________" << endl;
    
    cout << "Removing student A3" << endl;
    classRoster->remove("A3");
    
    cout << "____________" << endl;
    
    
    classRoster->~Roster();
}


