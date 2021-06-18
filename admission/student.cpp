//student.cpp to implement your classes
#include "student.hpp"
#include "Dstudent.hpp"

using namespace std;

string Student::getFirstName() const {return this->firstName;}
void Student::setFirstName(string s) {this->firstName = s;}

string Student::getLastName() const {return this->lastName;}
void Student::setLastName(string s) {this->lastName = s;}

float Student::getCGPA() const {return this->CGPA;}
void Student::setCGPA(float c) {this->CGPA = c;}

int Student::getRS() const {return this->Rscore;}
void Student::setRS(int rs) {this->Rscore = rs;}

int Student::getID() const { return this->stuID; }
void Student::setID(int id) { this->stuID = id; }

void Student::setlink(Student* next) { link = next; }
Student* Student::getlink() const { return link; }


bool Student::checkCGPA() {
    if (CGPA < 0 || CGPA > 4.33) { return false; }
    else { return true; }
}
bool Student::checkRS() {
    if (Rscore < 0 || Rscore > 100) { return false; }
    else { return true; }
}

Student::Student() {
    this->setFirstName("z");
    this->setLastName("z");
    this->setCGPA(0);
    this->setRS(0);
    this->setID(0);
}

void Student::set(string FN, string LN, float Cgpa, int RS, int id)
{
    stuID = id;
    firstName = FN; //set first name
    lastName = LN; //set last name
    CGPA = Cgpa; //set cgpa
    Rscore = RS; //set researchScore
    checkCGPA();
    checkRS();
}
/*
void Student::print(Student student, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        cout << student[i];
    }
}*/

int compareInts(int a, int b) {
    if (a > b) {return 1;}
    else if (a < b) {return -1;}
    else {return 0;}
}
int compareFloats(float a, float b) {
    if (a > b) {return 1;}
    else if (a < b) {return -1;}
    else {return 0;}
}
int compareStrings(string s1, string s2) {
    int res = strcmp(s1.c_str(), s2.c_str());
    if (res > 0) {return -1;}
    else if (res < 0) {return 1;}
    else {return 0;}
}

int compareCGPA(Student* st1, Student* st2) {return compareFloats(st1->getCGPA(), st2->getCGPA());}
int compareRS(Student* st1, Student* st2) {return compareInts(st1->getRS(), st2->getRS());}
int compareFN(Student* st1, Student* st2) {return compareStrings(st1->getFirstName(), st2->getFirstName());}
int compareLN(Student* st1, Student* st2) {return compareStrings(st1->getLastName(), st2->getLastName());}

int compareProvince(Student* st1, Student* st2) { return compareStrings(st1->getProvince(), st2->getProvince()); }

