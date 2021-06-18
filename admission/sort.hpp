#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include "student.hpp"
#include "Dstudent.hpp"
#include "Istudent.hpp"
#include "TOEFLscore.hpp"

using namespace std;

void arrSwap(DStudentPtr student[], int n);
void sortArray(DStudentPtr student[], char arg, int size);

void arrSwap(IntStudent student[], int n);
void sortArray(IntStudent student[], char arg, int size);

#endif