//
//  student.cpp
//  C867 repository
//
//  Created by Alex Alvizuris on 7/20/20.
//  Copyright © 2020 Alex Alvizuris. All rights reserved.

#include "degree.h"
#include <iomanip>
#include "student.h"

using std::left;
using std::setw;
using std::cout;
using std::cerr;

using namespace std;


//empty constructor
Student::Student() {
    
    this->studentID      = "";
    this->firstName      = "";
    this->lastName       = "";
    this->emailAddress   = "";
    this->studentAge     = "";
    for (int i = 0; i < sizeOfArray; i++) this->daysInCourse[i] = 0;
    this->degreeProgram  = UNDECIDED;
    
}

//constructor
Student::Student(string ID, string firstN, string lastN, string email, string age, double daysInCourse[], DegreeProgram degree) {
    
    this->studentID      = ID;
    this->firstName      = firstN;
    this->lastName       = lastN;
    this->emailAddress   = email;
    this->studentAge     = age;
    for (int i = 0; i < sizeOfArray; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram  = degree;
 
}


//accessors
string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmail() {
    return emailAddress;
}

string Student::getAge() {
    return studentAge;
}

double* Student::getDaysInCourse() {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}


//mutators
void Student::setStudentID(string ID) {
    this->studentID = ID;
}

void Student::setFirstName(string firstN) {
    this->firstName = firstN;
}

void Student::setLastName(string lastN) {
    this->lastName = lastN;
}

void Student::setEmail(string email) {
    this->emailAddress = email;
}

void Student::setAge(string age) {
    this->studentAge = age;
}

void Student::setDaysInCourse(double daysInCourse[]) {
    for (int i = 0; i < sizeOfArray; i++)
        this->daysInCourse[i] = daysInCourse[i];
}

void Student::setDegreeProgram(DegreeProgram degree) {
    this->degreeProgram = degree;
}

void Student::print() {
    
    cout << left << setw(4)  << studentID;
    cout << left << setw(10) << firstName;
    cout << left << setw(10) << lastName;
    cout << left << setw(25) << emailAddress;
    cout << left << setw(4)  << studentAge;
    cout << left << setw(3)  << daysInCourse[0];
    cout << left << setw(3)  << daysInCourse[1];
    cout << left << setw(3)  << daysInCourse[2];
    cout << left << setw(10) << degreeProgramType[getDegreeProgram()] << endl;
    
}

//destructor
Student::~Student() {
    
}












