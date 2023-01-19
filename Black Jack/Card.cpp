#pragma once
#include <iostream>
#include <string>
using namespace std;

//enums
enum Rank{ACE=1, TWO=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK='J', QUEEN='Q', KING='K'};
enum Type{DIAMONDS='D',CLUBS='C',HEARTS='H',SPADES='S'};

class Card{
    //if enum rank is ascii then it is larger than 10 so it means card is a face. 10 returned as value
    public:
        Card();
        Card(int rank, char type);
        int getValue(){
            if(this->rank>10){
                return 10;
            }
            else{return this->rank;}
            
        }
        char getType(){
            return this->type;
        }
        // char or int displayed based on face or not
        void displayCard(){
            cout<<this->type;
            if(this->rank>10){
                char r = this->rank;
                cout<<r;
            }
            else{cout<<this->rank;}
            
        }
        
    protected:
        int rank;
        char type;
};
Card::Card(int rank, char type):rank(rank),type(type){}

