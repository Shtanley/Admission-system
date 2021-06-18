//Dstudent.cpp to implement your classes
#include "Dstudent.hpp"

using namespace std;

string DStudent::getProvince() const {return this->province;}
void DStudent::setProvince(string s) {this->province = s;}

DStudent::DStudent() {this->setProvince("");}

DStudent::DStudent(string FN, string LN, string prov, float CGPA, int RS, int ID) {
    this->set(FN, LN, prov, CGPA, RS, ID);
}


void DStudent::set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int stuID)
{
	Student::set(FirstName, LastName, Cgpa, ResearchScore, stuID); //uses student set function to set student class memebers
	province = Province; //set province
}


ostream& operator <<(ostream& outs, const DStudent& student)
{
    outs << "Student: " << student.getFirstName() << ' ' << student.getLastName() << " (" << student.getID() << ")\tProvince:" << student.getProvince() << endl
        << "CGPA: " << student.getCGPA() << "\tResearch score:" << student.getRS() << endl << endl;

	return outs;
}

void printDom(DStudent student[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        cout << student[i];
    }
}
/*  DISGUSTING
void Dinsert(DStudent* head, DStudent* tail, int stu, string FN, string LN, string prov, float cgpa, int RS, int ID) {
    DStudentPtr insNode = new DStudent(FN, LN, prov, cgpa, RS, ID);

    if (stu == 0) { //if empty list, insNode is the new head & tail
        head = insNode;
        tail = insNode;
    }
    else if (stu == 1) {    //if there is 1 student, new node is inserted next
        insNode->setlink(head);
        head = insNode;
        tail = insNode->getlink();
    }
    else {  //main inserting code
        DStudentPtr tmp0 = new DStudent;
        DStudentPtr tmp1 = new DStudent;
        //tmp0 is before tmp1
        tmp1 = head;
        tmp0 = head;
        tmp1 = tmp1->getlink();

        if (tmp1 == NULL) { tmp1 = tmp0; }

        if (compareRS(insNode, tmp0) == 1) {    //if insNode RS > prev node, insNode is new head
            insNode = tmp0->getlink();
            head = insNode;
        }
        else if (compareRS(insNode, tmp0) == 0) {   //if same RS
            if (compareCGPA(insNode, tmp0) == 1) {  //if insNode CGPA > prev node, insNode is new head
                insNode = tmp0->getlink();
                head = insNode;
            }
            else if (compareCGPA(insNode, tmp0) == 0) { //if same CGPA
                if (compareProvince(insNode, tmp0) >= 0) {  //if insNode prov >= prev node, insNode is new head
                    insNode = tmp0->getlink();
                    head = insNode;
                }
                else {  //if head(tmp1) prov is greater
                    //search list till head prov is less than insNode prov
                    while (tmp1 != NULL && compareRS(tmp1, insNode) == 0 && compareCGPA(tmp1, insNode) == 0 && compareProvince(tmp1, insNode) == 1) {
                        tmp1 = tmp1->getlink();
                        tmp0 = tmp0->getlink();
                    }
                    insNode->setlink(tmp0->getlink());
                    tmp0->setlink(insNode);

                    if (tmp0->getID() == head->getID()) { head = tmp0; }    //check if inserting below head
                }
            }
            else {  //if head CGPA is greater
            //search list till head has lower CGPA
                while (tmp1 != NULL && compareRS(tmp1, insNode) == 0 && compareCGPA(tmp1, insNode) == 1) {
                    tmp1 = tmp1->getlink();
                    tmp0 = tmp0->getlink();
                }
                insNode->setlink(tmp0->getlink());
                tmp0->setlink(insNode);

                if (tmp0->getID() == head->getID()) { head = tmp0; }    //check if inserting below head
            }
        }
        else {  //if head RS is greater
            //search till head has lower RS
            while (tmp1 != NULL && compareRS(tmp1, insNode) == 1) {
                tmp1 = tmp1->getlink();
                tmp0 = tmp0->getlink();
            }

            if (tmp1 = NULL) {  //end of the list
                tmp0->setlink(insNode);
                tail = insNode;
            }
            else if (compareRS(tmp1, insNode) == -1) {  //if head RS lower
                insNode->setlink(tmp0->getlink());
                tmp0->setlink(insNode);
            }
            else {  //eaual RS
                while (tmp1 != NULL && compareRS(tmp1, insNode) == 0 && compareCGPA(tmp1, insNode) == 0 && compareProvince(tmp1, insNode) == 1) {
                    tmp1 = tmp1->getlink();
                    tmp0 = tmp0->getlink();
                }
                insNode->setlink(tmp0->getlink());
                tmp0->setlink(insNode);
            }

            if (tmp0->getID() == head->getID()) { head = tmp0; }    //check if inserting below head
        }
    }
    if (stu != 0) { //update tail pointer
        DStudentPtr tmp_tail = new DStudent;
        tmp_tail = head;
        
        while (tmp_tail->getlink() != NULL) { tmp_tail = tmp_tail->getlink(); }
        tail = tmp_tail;
    }
}
*/