#pragma once
#include "AbstractPlayer.cpp"

using namespace std;

//extending class Abstract Player
class ComputerPlayer: public AbstractPlayer{
    public:
        ComputerPlayer():AbstractPlayer(){}
        ~ComputerPlayer(){}
        bool isDrawing(){return true;}
        bool isDrawing(float winrate, Card nextcard){
            if(this->hand.at(0).getTotal() < 16){
                    return true;
            }
            else{
                // cheats by looking at next card even though total cards >= 16
                if(winrate<.55){
                    if(this->hand.at(0).getTotal() + nextcard.getValue() + 1 <= 21){     // there is an error bias of +1
                        return true;                                           //so that the computer can still bust 
                    }
                    else return false;
                }
                else return false;
            }
        }

};

