//header file Istudent.hpp to declare your classes
#ifndef DSTUDENT_HPP
#define DSTUDENT_HPP

using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#include <iomanip>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"

class DStudent : public Student {
    public:
    DStudent();     //default constructor
    DStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int stuID);
    //~DStudent();    //default destructor

    //getters & setters
    string getProvince() const;
    void setProvince(string s);
    
    void set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int stuID);

    friend void printDom(DStudent student[], int size);

    //overloaded operators
    friend ostream& operator <<(ostream& outs, const DStudent &object);
    /*
    friend void Dinsert(DStudent* head, DStudent* tail, int stu, string FN, string LN, string prov, float cgpa, int RS, int ID);
    friend void Dsearch(Student*& head, char type, int Ivalue, float Fvalue, string FN, string LN);
    friend void Ddelete(Student*& head, Student*& tail, string FN, string LN);
    friend void Dremove_head_tail(Student*& head, Student*& tail);
    */
    private:
    string province;
};
typedef DStudent* DStudentPtr;

#endif