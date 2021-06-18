//header file TOEFLscore.hpp to declare your classes
#ifndef TOEFLSCORE_HPP
#define TOEFLSCORE_HPP

using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>

class TOEFLScore {
    public:
    TOEFLScore();
    //~TOEFLScore();

    //getters & setters
    int getReading() const;
    void setReading(int R);
    int getListening() const;
    void setListening(int L);
    int getSpeaking() const;
    void setSpeaking(int S);
    int getWriting() const;
    void setWriting(int W);
    
    //error checkers
    bool checkReading();
    bool checkListening();
    bool checkSpeaking();
    bool checkWriting();

    private:
    int reading;
    int listening;
    int speaking;
    int writing;
};

bool checkError(int x);

#endif