//header file Istudent.hpp to declare your classes
#ifndef ISTUDENT_HPP
#define ISTUDENT_HPP

using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#include <iomanip>
#include "student.hpp"
#include "TOEFLscore.hpp"

class IntStudent : public Student {
    public:
    IntStudent();   //default constructor
    //~IntStudent();  //default destructor

    //getters & setters
    TOEFLScore getTOEFL() const;
    void setTOEFL(TOEFLScore toefl);
    void setTOEFL(int reading, int listening, int speaking, int writing);

    int getTotal() const;

    void Iset(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int listening, int reading, int speaking, int writing, int sID);

    bool TOEFLcheck();
    /*
    friend int compareCountry(IntStudent st1, IntStudent st2);
    friend void printIntS(IntStudent student[], int size);
    */
    //overloaded operators
    friend ostream& operator <<(ostream& outs, const IntStudent &object);

    private:
    TOEFLScore score;
};
typedef IntStudent* IntStudentPtr;

#endif