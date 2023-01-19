
#pragma once
#include <vector>
#include "Card.cpp"

using namespace std;

//enum Rank{ACE=1, TWO=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK=10, QUEEN=10, KING=10};
//enum Type{DIAMONDS='D',CLUBS='C',HEARTS='H',SPADES='S'};

class Hand{
    public:
        Hand();
        //vector<Card> v = {};
        //char getType(){
        //    return this->type;
        //}
        void add(Card c){
            int val = c.getValue();
            if(val == 1){
                if(11+total <= 21){
                    total += 11;
                    this->largeAce+=1;
                    this->numofAces+=1;
                }
                else{
                    total += 1;
                    this->numofAces+=1;
                }
            }
            else{
                if(this->numofAces > 0 && this->largeAce > 0){
                    if(this->total + val > 21){
                        total += -10;
                        this->largeAce--;
                        this->total += val;
                    }
                    else{
                        this->total += val;
                    }
                }
                else{
                    this->total += val;
                }
            }
            this->cards.push_back(c);
        }
        void clear(){
            this->numofAces = 0;
            this->total = 0;
            this->cards = {};
            this->largeAce = 0;
        }
        int getTotal(){
            return this->total;
        }
        vector<Card> getcards(){
            return this->cards;
        }
        
    protected:
        int numofAces;
        int total;
        vector<Card> cards = {};
        int largeAce;
};
Hand::Hand():numofAces(0),total(0),largeAce(0){}

/*
int main(){
    Card one = Card(ACE,DIAMONDS);
    Card two = Card(TWO,DIAMONDS);
    Card three = Card(THREE,DIAMONDS);
    Card four = Card(FOUR,DIAMONDS);
    Card five = Card(FIVE,DIAMONDS);
    Card six = Card(SIX,DIAMONDS);
    Card seven = Card(SEVEN,DIAMONDS);
    Card eight = Card(EIGHT,DIAMONDS);
    Card nine = Card(NINE,DIAMONDS);
    Card ten = Card(TEN,DIAMONDS);

    Hand myhand;
    myhand.add(two);
    myhand.add(one);
    myhand.add(one);
    myhand.add(ten);
    myhand.clear();
    myhand.add(ten);
    
    
    
    cout<<myhand.getTotal()<<endl;

}
*/