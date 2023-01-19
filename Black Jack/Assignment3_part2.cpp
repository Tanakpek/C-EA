#include "BlackJackGame.cpp"

using namespace std;

int main(){
    cout<<"\tWelcome to the COMP322 Blackjack Game"<<endl<<endl;
    BlackJackGame game;

    bool playagain = true;
    char answer = 'y';
    while(playagain){
        game.play();
        cout<<"Would you like another round? (y/n): " ;
        cin >> answer;
        playagain = (answer == 'y' ? true : false);
    }
    cout<<"game over!";
    return 0;

}