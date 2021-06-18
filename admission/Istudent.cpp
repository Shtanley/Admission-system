//Istudent.cpp to implement your classes
#include "Istudent.hpp"

using namespace std;

IntStudent::IntStudent() { set("z", "z", "z", 0, 0, 0); }

TOEFLScore IntStudent::getTOEFL() const {
    TOEFLScore t;
    t.setListening(this->score.getListening());
    t.setReading(this->score.getReading());
    t.setSpeaking(this->score.getSpeaking());
    t.setWriting(this->score.getWriting());
}
void IntStudent::setTOEFL(TOEFLScore t) {
    this->score.setListening(t.getListening());
    this->score.setReading(t.getReading());
    this->score.setSpeaking(t.getSpeaking());
    this->score.setWriting(t.getWriting());
}
void IntStudent::setTOEFL(int Reading, int Listening, int Speaking, int Writing) {
    this->score.setListening(Listening);
    this->score.setReading(Reading);
    this->score.setSpeaking(Speaking);
    this->score.setWriting(Writing);
}

bool IntStudent::TOEFLcheck() {
    if ((score.getListening() < 20) || (score.getReading() < 20) || (score.getWriting() < 20) || (score.getSpeaking() < 20) || this->getTotal() < 93) { return false; }
    else { return true; }
}
int IntStudent::getTotal() const{
    int total;
    total = score.getListening() + score.getReading() + score.getSpeaking() + score.getWriting();
    return total;
}

void IntStudent::Iset(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, int Listening, int Reading, int Speaking, int Writing, int stuID) {
    //if ((Listening < 20) && (Reading < 20) && (Writing < 20) && (Speaking < 20) && ((Listening + Reading + Speaking + Writing) < 93)) {
    set(FirstName, LastName, Country, Cgpa, ResearchScore, stuID);
    setTOEFL(Reading, Listening, Speaking, Writing);
    //}
}


ostream& operator <<(ostream& outs, const IntStudent &object)
{
    outs << "Student: " << object.getFirstName() << ' ' << object.getLastName() << " (" << object.getID() << ")\tCountry:" << object.getCountry() << endl
        << "CGPA: " << object.getCGPA() << "\tResearch score:" << object.getRS() << endl
        << "TOEFL score: " << object.getTotal() << endl
        << "\tReading: " << object.score.getReading() << endl
        << "\tListening: " << object.score.getListening() << endl
        << "\tSpeaking: " << object.score.getSpeaking() << endl
        << "\tWriting: " << object.score.getWriting() << endl << endl;

    return outs;
}
/*
void printIntS(IntStudent student[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        cout << student[i];
    }
}*/