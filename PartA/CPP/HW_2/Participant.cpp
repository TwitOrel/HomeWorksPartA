#include "Participant.h"

#include <utility>

using namespace std;

Participant:: Participant(string  sign):countWins(0),sign(move(sign)){}


Participant:: ~Participant()= default;

void Participant::ParticipantSetWins(int wins) {
    countWins = wins;
}
string Participant::ParticipantGetSign() {
    return sign;
}







