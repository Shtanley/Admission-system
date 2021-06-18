#include <iostream>
#include "sort.hpp"

using namespace std;

void arrSwap(DStudentPtr student[], int n) {   //swap in arrays with sorting priority
	DStudentPtr temp = student[n];
	student[n] = student[n + 1];
	student[n + 1] = temp;
}
void arrSwap(IntStudent student[], int n) {   //swap in arrays with sorting priority
    IntStudent temp = student[n];
    student[n] = student[n + 1];
    student[n + 1] = temp;
}
//bubble sort
void sortArray(DStudentPtr student[], char arg, int size) {
    //DStudentPtr temp;
    switch (arg) {
    case '1':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareCGPA(student[i], student[i + 1]) == -1) {
                    //cout << "arrswap\n";
                    arrSwap(student, i);
                }
            }
        }
        break;
    case '2':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareRS(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
            }
        }
        break;
    case '3':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareFN(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
            }
        }
        break;
    case '4':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareLN(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
            }
        }
        break;
    case '5':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareRS(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
                if (compareRS(student[i], student[i + 1]) == 0) {
                    if (compareCGPA(student[i], student[i + 1]) == -1) {
                        arrSwap(student, i);
                    }
                    if (compareCGPA(student[i], student[i + 1]) == 0) {
                        if (compareProvince(student[i], student[i + 1]) == -1) {
                            arrSwap(student, i);
                        }
                    }
                }
            }
        }
        break;
    default:
        cout << "Input not 1-5, choosing default (overall) sorting\n";
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareRS(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
                if (compareRS(student[i], student[i + 1]) == 0) {
                    if (compareCGPA(student[i], student[i + 1]) == -1) {
                        arrSwap(student, i);
                    }
                    if (compareCGPA(student[i], student[i + 1]) == 0) {
                        if (compareProvince(student[i], student[i + 1]) == -1) {
                            arrSwap(student, i);
                        }
                    }
                }
            }
        }
        break;
    }
}
/*
IntStudent temp;
void sortArray(IntStudent student[], char arg, int size) {
    IntStudent temp;
    switch (arg) {
    case '1':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareCGPA(student[i], student[i + 1]) == -1) {
                    //cout << "arrswap\n";
                    arrSwap(student, i);
                }
            }
        }
        printIntS(student, size);
        break;
    case '2':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareRS(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
            }
        }
        printIntS(student, size);
        break;
    case '3':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareFN(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
            }
        }
        printIntS(student, size);
        break;
    case '4':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareLN(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
            }
        }
        printIntS(student, size);
        break;
    case '5':
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareRS(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
                if (compareRS(student[i], student[i + 1]) == 0) {
                    if (compareCGPA(student[i], student[i + 1]) == -1) {
                        arrSwap(student, i);
                    }
                    if (compareCGPA(student[i], student[i + 1]) == 0) {
                        if (compareCountry(student[i], student[i + 1]) == -1) {
                            arrSwap(student, i);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) {
            temp = student[i];
            if (temp.TOEFLcheck() == true && temp.getTotal() >= 93) {
                cout << i + 1 << ") ";
                cout << student[i];
            }
        }
        break;
    default:
        cout << "Input not 1-5, choosing default (overall) sorting\n";
        for (int j = 0; j < size - 1; j++) {
            for (int i = 0; i < size - j - 1; i++) {
                if (compareRS(student[i], student[i + 1]) == -1) {
                    arrSwap(student, i);
                }
                if (compareRS(student[i], student[i + 1]) == 0) {
                    if (compareCGPA(student[i], student[i + 1]) == -1) {
                        arrSwap(student, i);
                    }
                    if (compareCGPA(student[i], student[i + 1]) == 0) {
                        if (compareCountry(student[i], student[i + 1]) == -1) {
                            arrSwap(student, i);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) {
            temp = student[i];
            if (temp.TOEFLcheck() == true && temp.getTotal() >= 93) {
                cout << i + 1 << ") ";
                cout << student[i];
            }
        }
        break;
    }
}*/
