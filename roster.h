//
//  roster.hpp
//  C867 repository
//
//  Created by Alex Alvizuris on 7/20/20.
//  Copyright © 2020 Alex Alvizuris. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>
#include "student.h"


using namespace std;

const int numStudents = 5;

const string studentData[numStudents] = {
    "A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
    "A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
    "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
    "A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
    "A5, Alejandro, Alvizuris, Aalvizu@wgu.edu, 29, 21, 14, 30, SOFTWARE"
};




class Roster {
    
public:
    
    int     lastIndex;
    int     maxCapacity;
    Student** classRosterArray;
    

    //constructor
    Roster();
    Roster(int capacity);
    
    
    void    parseAdd(string datarow);
    
    bool    remove(string studentID);
    void    printALL();
    void    printAverageDaysInCourse(string studentID);
    void    printInvalidEmails();
    void    printByDegreeProgram(DegreeProgram degreeProgram);
    
    
    //destructor
    ~Roster();
    
};

