#pragma once
#include "Deck.cpp"

using namespace std;

class AbstractPlayer{
    public: 
    AbstractPlayer(){}
    virtual bool isDrawing() = 0;
    virtual bool isDrawing(float winrate, Card nextcard) = 0;
    virtual ~AbstractPlayer(){}

    bool isBusted(int i){
        if(hand.at(i).getTotal()>21){
            return true;
        }
        return false;
        
    }
    
    Hand minhand;
    vector<Hand> hand = {minhand};

};

