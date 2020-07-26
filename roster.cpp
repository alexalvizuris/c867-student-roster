//
//  roster.cpp
//  C867 repository
//
//  Created by Alex Alvizuris on 7/20/20.
//  Copyright © 2020 Alex Alvizuris. All rights reserved.
//
#include "roster.h"

#include <iostream>
#include <sstream>
#include <string>


using namespace std;
using std::cerr;


//empty constructor
Roster::Roster() {
    
    this->maxCapacity      = 0;
    this->lastIndex        = -1;
    this->classRosterArray = nullptr;
    
}

//constructor
Roster::Roster(int maxCapacity) {
    
    this->maxCapacity      = maxCapacity;
    this->lastIndex        = -1;
    this->classRosterArray = new Student * [maxCapacity];
    
}

//parse through the roster
void Roster::parseAdd(string datarow) {
    
    if (lastIndex < maxCapacity) {
        lastIndex++;
        double daysArray[Student::sizeOfArray];
    
        //set studentID
        int rhs = studentData[lastIndex].find(",");
        classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));
        
        //set firstName
        int lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));
        
        //set lastName
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));
        
        //set emailAddress
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));
        
        //set age
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setAge(studentData[lastIndex].substr(lhs, rhs - lhs));
        
        //add daysInCourse to temporary Array
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        daysArray[0] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        daysArray[1] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        daysArray[2] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));
        
        //set daysInCourse
        classRosterArray[lastIndex]->setDaysInCourse(daysArray);
        
        //set degreeProgram
         lhs = rhs + 1;
         rhs = studentData[lastIndex].find(",", lhs);
         DegreeProgram degreeProgram;
         
         string degreeString = studentData[lastIndex].substr(lhs, rhs - lhs);
         if (degreeString == "SECURITY") {
             degreeProgram = DegreeProgram::SECURITY;
         } else if (degreeString == "SOFTWARE") {
             degreeProgram = DegreeProgram::SOFTWARE;
         } else if (degreeString == "NETWORK") {
             degreeProgram = DegreeProgram::NETWORK;
         } else {
             degreeProgram = DegreeProgram::UNDECIDED;
         }
        
    } else {
        
        cerr << "Error! Maximum number of students reached. Exiting.." << endl;
        exit (-1);
        
    }
    
   
}

//print all
void Roster::printALL() {
    
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
    
}


//remove from roster
bool Roster::remove(string studentID) {
    
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
        }
    
    }
   if (found) {
        cout << "Removed." << endl;
       return found;
    } else {
        cout << "Student doesn't exist." << endl;
        return found;
    }
}


//print average days to complete course
void Roster::printAverageDaysInCourse(string studentID) {
    
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            double* daysAvg = classRosterArray[i]->getDaysInCourse();
            cout << "Average # of days to complete courses for " << studentID << " is " << (daysAvg[0] + daysAvg[1] + daysAvg[2]) / 3 << "." <<endl;
        }
    }
    if (!found) cout << "Student not found." << endl;
}


//print invalid emails
void Roster::printInvalidEmails() {
    
    cout << "Displaying invalid E-mails: " << endl;
    for (int i = 0; i <= lastIndex; i++) {
        string tempEmail = classRosterArray[i]->getEmail();
        if (tempEmail.find(".") == string::npos || tempEmail.find("@") == string::npos || tempEmail.find(" ") != string::npos) {
            cout << tempEmail << endl;
            i++;
        } else {
            cout << "No invalid E-mails." << endl;
        }
    }
}


//print by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    
    cout << "Printing students of degree " << degreeProgramType[degreeProgram] << endl;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
    }
}


//destroys roster
Roster::~Roster() {
    
    for (int i = 0; i < numStudents; i++) {
        delete this->classRosterArray[i];
    }
}

















