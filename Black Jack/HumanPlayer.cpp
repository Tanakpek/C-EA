#pragma once
#include "AbstractPlayer.cpp"

using namespace std;
// extending abstract player
class HumanPlayer: public AbstractPlayer{
    public:
        HumanPlayer():AbstractPlayer(){}
        ~HumanPlayer(){}
        int numHands = 1;

        // is drawing based on standard input
        bool isDrawing(){
            char in;
            cout<<"Dealer is looking at you"<<endl;
            cout<<"\"hit me\" (y) pass (n): ";
            cin>>in;
            return (in == 'y' ? true :  false);
        }
        // overloaded isdrawing for multiple hands
        bool isDrawing(int i){
            char in;
            cout<<"Do you want to draw for hand "<<i+1<<": "<<endl;
            cout<<"\"hit me\" (y) pass (n): ";
            cin>>in;
            return (in == 'y' ? true :  false);
        }
        // adds the specified number of hands to player
        void addHand(int h){
            if(this->numHands + h <= 3){
                for(int a = 0; a<h; a++){
                    Hand n;
                    this->hand.push_back(n);
                }
            }
            else{cout<<"Dealer: Sorry, I can only allow a maximum of three hands."<<endl;}
            
        }
        // so that virtual method is implemented. Never used
        bool isDrawing(float winrate, Card nextcard){return true;}

        // announcement made based on parameter
        void announce(int a){
            if(a==0){
                cout<<"No one wins."<<endl;
            }
            else if(a==-1){
                cout<<"house wins."<<endl;
            }
            else{cout<<"player wins."<<endl;}
        }

};

