//
//  student.hpp
//  C867 repository
//
//  Created by Alex Alvizuris on 7/20/20.
//  Copyright © 2020 Alex Alvizuris. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include <iomanip>

using namespace std;

class Student {
    
public:
    
    const static int sizeOfArray = 3;
    
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    string studentAge;
    double    daysInCourse[sizeOfArray];
    DegreeProgram degreeProgram;
    
    
public:
    
//constructors
    Student();
    Student(string ID, string firstN, string lastN, string email, string age, double daysInCourse[], DegreeProgram degree);
    
//introduce accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    string getAge();
    double*   getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
//introduce mutators
    void setStudentID(string ID);
    void setFirstName(string firstN);
    void setLastName(string lastN);
    void setEmail(string email);
    void setAge(string age);
    void setDaysInCourse(double daysInCourse[]);
    void setDegreeProgram(DegreeProgram degree);
    void print();
    
//destructor
    ~Student();
    
};


