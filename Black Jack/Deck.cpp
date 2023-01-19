#pragma once
#include <vector>
#include <stdlib.h>
#include "Hand.cpp"

using namespace std;
//enum array
int arr[13] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
char arr2[4] = {DIAMONDS,CLUBS,SPADES,HEARTS};

class Deck{
    public:
        Deck();

        // one of each value x suite is placed in deck
        void populate(){
            this->cards = {};
            for(int i = 0; i < 13; i++){
                for(int j = 0; j<4;j++){
                    this->cards.push_back(Card(arr[i],arr2[j]));
                }
            }
            this->remaining = 52;
        }
        
        // for casino cheating
        Card peek(){
            return this->cards.back();
        }
        // shuffling
        void shuffle(){
            for(int i=0; i<this->remaining; i++){
                int other = rand() % this->remaining;
                std::swap(this->cards[i],this->cards[other]);
            }
        }
        //pops the last card and returns it
        Card deal(){
            Card ret = this->cards.back();
            this->cards.pop_back();
            this->remaining--;
            return ret;
        }
        void clear(){
            this->cards = {};
        }
    
    protected:
        vector<Card> cards = {};
        int remaining = 0;
};
Deck::Deck(){}


