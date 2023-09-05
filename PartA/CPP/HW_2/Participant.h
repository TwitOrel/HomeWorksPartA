#ifndef EX2_PARTICIPANT_H
#define EX2_PARTICIPANT_H
using namespace std;

#include <string>

class Participant{

private:
    int countWins;
    string sign;

public:
    //Constructor
    explicit Participant(string  sign );

    //Destructor
    ~Participant();

    //set countWins
    void ParticipantSetWins(int);

    //return the sign
    string ParticipantGetSign();

};

#endif //EX2_PARTICIPANT_H
