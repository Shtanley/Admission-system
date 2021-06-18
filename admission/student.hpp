//header file student.hpp to declare your classes
#ifndef STUDENT_HPP
#define STUDENT_HPP

using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <cstring>
#include <iostream>

class Student {
    public:
    Student();  //default constructor
    //Student(string FirstName, string LastName, float Cgpa, int rs, int ID);
    //~Student(); //default destructor

    //getters & setters
    string getFirstName() const;
    void setFirstName(string s);

    string getLastName() const;
    void setLastName(string s);

    float getCGPA() const;
    void setCGPA(float c);

    int getRS() const;  //gets students Research Score
    void setRS(int rs); //sets students Research Score

    int getID() const;
    void setID(int id);

    virtual string getProvince()const = 0;

    void set(string FirstName, string LastName, float Cgpa, int rs, int ID);

    //void print(Student student, int size);

    Student* getlink() const;
    void setlink(Student* next);

    //error checking
    bool checkCGPA();
    bool checkRS();

    //compare functions for 2 students
    friend int compareCGPA(Student* st1, Student* st2);
    friend int compareRS(Student* st1, Student* st2); //compare Research Scores
    friend int compareFN(Student* st1, Student* st2); //compare last names
    friend int compareLN(Student* st1, Student* st2); //compare first names

    friend int compareProvince(Student* st1, Student* st2);


    private:
    int stuID;
    string firstName;
    string lastName;
    float CGPA;
    int Rscore;

    Student* link;  //link to next node
};
typedef Student* StudentPtr;

//helper functions
//compare functions outside class as it is used by the inheritors as well
int compareInts(int a, int b);
int compareFloats(float a, float b);
int compareStrings(string s1, string s2);

#endif