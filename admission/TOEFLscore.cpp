//TOEFLscore.cpp to implement your classes
#include "TOEFLscore.hpp"

using namespace std;

TOEFLScore::TOEFLScore() {
    this->setReading(0);
    this->setListening(0);
    this->setSpeaking(0);
    this->setWriting(0);
}

int TOEFLScore::getListening() const {return this->listening;}
void TOEFLScore::setListening(int L) {this->listening = L;}

int TOEFLScore::getReading() const {return this->reading;}
void TOEFLScore::setReading(int R) {this->reading = R;}

int TOEFLScore::getSpeaking() const {return this->speaking;}
void TOEFLScore::setSpeaking(int S) {this->speaking = S;}

int TOEFLScore::getWriting() const {return this->writing;}
void TOEFLScore::setWriting(int W) {this->writing = W;}

bool checkError(int x) {
    if (x < 0 || x > 30) { return false; }
    else { return true; }
}

bool TOEFLScore::checkListening() { return checkError(this->listening); }
bool TOEFLScore::checkReading() { return checkError(this->reading); }
bool TOEFLScore::checkSpeaking() { return checkError(this->speaking); }
bool TOEFLScore::checkWriting() { return checkError(this->writing); }
