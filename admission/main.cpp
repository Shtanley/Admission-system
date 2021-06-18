//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "list.hpp"
#include "node.hpp"
#include "student.hpp"
//#include "Istudent.hpp"
#include "Dstudent.hpp"
#include "TOEFLscore.hpp"
//#include "sort.hpp"


using namespace std;
/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */

int main(){

    typedef class DStudent* DStudentPtr;

  //Read the domestic-stu.txt file and exit if failed
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  cout << "File format: " << line << endl;

  int Dstu_count = 0;
  int sID = 20200000;
  NodePtr Dhead = NULL;
  List Dlist;

  while( getline(domesticFile, line) ) {
    
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    /*
    //print the student info to the screen
    cout << "Domestic student " << Dstu_count << " " << firstName << " " 
	 << lastName << " from " << province << " province has cgpa of "
	 << cgpa << ", and research score of " << researchScore << endl;*/

    DStudentPtr DStu = new DStudent;
    DStu->set(firstName, lastName, province, cgpa, researchScore, sID);

    Dlist.insDom(DStu);

    Dstu_count++;
    sID++;
  }
  //close your file
  domesticFile.close();
  Dlist.printList();
  /*
  ifstream internationalFile("international-stu.txt");
  if (!internationalFile.is_open()) {
      cout << "Unable to open file international-stu.txt" << endl;
      return -1;
  }

  getline(internationalFile, line);
  cout << "File format: " << line << endl;
  //IntStudent temp;
  int y = 0;
  int Istu_count = 0;
  IntStudent IStuArr[100];
  while (getline(internationalFile, line)) {

      istringstream ss(line);

      string firstName, lastName, country, s_cgpa, s_researchScore, s_listening, s_reading, s_speaking, s_writing;
      float cgpa;
      int researchScore, listening, reading, speaking, writing;

      //get firstName separated by comma
      getline(ss, firstName, ',');

      //get lastName separated by comma
      getline(ss, lastName, ',');

      //get province separated by comma
      getline(ss, country, ',');

      //get cpga separated by comma, and convert string to float
      getline(ss, s_cgpa, ',');
      cgpa = atof(s_cgpa.c_str());

      //get researchScore separated by comma, and convert it to int
      getline(ss, s_researchScore, ',');
      researchScore = atoi(s_researchScore.c_str());

      getline(ss, s_listening, ',');
      listening = atoi(s_listening.c_str());

      getline(ss, s_reading, ',');
      reading = atoi(s_reading.c_str());

      getline(ss, s_speaking, ',');
      speaking = atoi(s_speaking.c_str());

      getline(ss, s_writing, ',');
      writing = atoi(s_writing.c_str());

      IStuArr[y].Iset(firstName, lastName, country, cgpa, researchScore, listening, reading, speaking, writing, sID);
      //temp = IStuArr[y];
      //cout << temp.TOEFLcheck() << " | ";
      Istu_count++;
      y++;
      sID++;
  }
  //cout << check;
  internationalFile.close();
  
  char group, sort;
  char cont;
  while (true)
  {
      cout << "\n\nEnter number to choose which students to sort:\n" << "[1] Domestic students\n[2] International students\n\n\tEnter Number: ";
      cin >> group;
      cout << "\n\nEnter number to sort by:\n" << "[1] CGPA\n[2] Research score\n[3] First name\n[4] Last name\n[5] Overall\n\n\tEnter Number: ";
      cin >> sort;
      while (group != '1' && group != '2') {
          cout << "Did not input 1 or 2, please try again\n[1] Domestic students\n[2] International students\n\n\tEnter Number: ";
          cin >> group;
      }
      if (group == '1') {
          //cout << "b4 sort\n";
          sortArray(DStu, sort, Dstu_count);
          //cout << "aftr sort\n"
          cout << endl;
          printDom(DStu, Dstu_count);
      }/*
      if (group == '2') {
          sortArray(IStuArr, sort, y);
          //printIntS(IStuArr, Istu_count);
      }
      cout << "Continue sorting? Y/N\n";
      cin >> cont;
      if (cont != 'Y' && cont != 'y')
      {
          break;
      }
  }*/

  return 0;
}
