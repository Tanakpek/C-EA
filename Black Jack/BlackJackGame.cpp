


#include "ComputerPlayer.cpp"
#include "HumanPlayer.cpp"

using namespace std;

// game class
class BlackJackGame{
    public:
    BlackJackGame();
    float houseWinRatio = 0.5;
    Deck m_deck;
    ComputerPlayer m_casino;
    HumanPlayer player1;
    
    float wins = 0;
    int games = 0;

    int play(){
        Hand firsthand;
        this->games++;
        //start off by making player1 hand, an empty hand
        player1.hand = {firsthand};
        m_casino.hand.at(0).clear();

        // taking user input as to how many hands they want
        int nhands;
        cout<<"Please type in the number of hands you want (max 3): ";
        cin>>nhands;
        while(nhands !=1 && nhands !=2 && nhands !=3){
            cout<<nhands<<endl;
            cout<<"Please enter a valid value: ";
            cin>>nhands;
        }
        // adding accounting for initial hand
        this->player1.addHand(nhands - 1);

        // deck reset
        m_deck.clear();
        this->m_deck.populate();
        this->m_deck.shuffle();
        
        
        m_casino.hand.at(0).add(m_deck.deal());

        //each hand gets two cards
        for(int j = 0 ; j < player1.hand.size(); j++){
            player1.hand.at(j).add(m_deck.deal());
            player1.hand.at(j).add(m_deck.deal());
        }
        //print state of hands
        for(int j = 0 ; j < player1.hand.size(); j++){
            cout<<"Player hand "<<j+1<<" ";
            for(int i = 0; i<player1.hand.at(j).getcards().size();i++){
                player1.hand.at(j).getcards().at(i).displayCard();
                cout<<" ";
            }
            int tots = player1.hand.at(j).getTotal();
            cout<<'['<<tots<<']'<<endl;
        }
        // print house state
        cout<<"House: ";
                for(int i = 0; i<m_casino.hand.at(0).getcards().size();i++){
                    m_casino.hand.at(0).getcards().at(i).displayCard();
                    cout<<" ";
                }
        int tots2 = m_casino.hand.at(0).getTotal();
        cout<<'['<<tots2<<']';
        cout<<endl;

       
        // with each iteration isDrawing is overloaded with a integer iterator asking the user if he wants to draw
        // for that hand, which initiates a while loop for that hand
        int cursize = player1.hand.size();
        for(int j = 0 ; j < cursize; j++){
            cout<<"Player hand "<<j+1<<": ";
            for(int i = 0; i<player1.hand.at(j).getcards().size();i++){
                player1.hand.at(j).getcards().at(i).displayCard();
                cout<<" ";
            }
            int tots = player1.hand.at(j).getTotal();
            cout<<'['<<tots<<']'<<endl;
        while(player1.isDrawing(j)){
            player1.hand.at(j).add(m_deck.deal());
            cout<<"Player hand "<<j+1<<": ";
            for(int i = 0; i<player1.hand.at(j).getcards().size();i++){
                player1.hand.at(j).getcards().at(i).displayCard();
                cout<<" ";
            }
            int tots = player1.hand.at(j).getTotal();
            cout<<'['<<tots<<']';
            cout<<endl;
            
            //player busts, announced that player loses that hand. Casino can still bust as well
            //but in blackjack you lose even if casino busts after you
            if(player1.isBusted(j)){
                cout<<"player busts. For player hand "<<j+1<<": "<<endl;
                player1.announce(-1);
                
                // ratio updated
                this->wins++;
                this->houseWinRatio = this->wins/this->games;
                if(player1.hand.size() == 0){
                    return 0;
                }
                break;
            }
        }
        }
        //same for casino
        while(m_casino.isDrawing(houseWinRatio,m_deck.peek())){
            m_casino.hand.at(0).add(m_deck.deal());
            if(m_casino.isBusted(0)){
                cout<<"House: ";
                for(int i = 0; i<m_casino.hand.at(0).getcards().size();i++){
                    m_casino.hand.at(0).getcards().at(i).displayCard();
                    cout<<" ";
                }
                int tots2 = m_casino.hand.at(0).getTotal();
                cout<<'['<<tots2<<']';
                cout<<endl;
                cout<<"house busts."<<endl;
            }
        }
        

            
        // house state print
        cout<<"House: ";
        for(int i = 0; i<m_casino.hand.at(0).getcards().size();i++){
            m_casino.hand.at(0).getcards().at(i).displayCard();
            cout<<" ";
            }
        tots2 = m_casino.hand.at(0).getTotal();
        cout<<'['<<tots2<<']';
        cout<<endl;

        // if casino busts, winning hands announced
        if(m_casino.isBusted(0)){
            for(int j = 0 ; j < cursize; j++){
                if(!player1.isBusted(j)){
                    cout<<"For player hand "<<j+1<<": "<<endl;
                    player1.announce(1);
                    this->houseWinRatio = this->wins/this->games;
                }
            }
            return 0;
        }
        // only non-busted hands chosen for comparison
        for(int j = 0 ; j < cursize; j++){
            if(player1.isBusted(j)){
                continue;
            }

            // this if branch makes the appropriate comparisons and announcements for each non-busted hand
            if(player1.hand.at(j).getTotal()>m_casino.hand.at(0).getTotal()){
                cout<<"Player hand "<<j+1<<": ";
                for(int i = 0; i< player1.hand.at(j).getcards().size();i++){
                    player1.hand.at(j).getcards().at(i).displayCard();
                    cout<<" ";
                }
                int tots = player1.hand.at(j).getTotal();
                cout<<'['<<tots<<']'<<endl;
            
            
                this->houseWinRatio = this->wins/this->games;

                cout<<"for player hand "<<j+1<<": ";
                player1.announce(1);
                
            }
            else if(player1.hand.at(j).getTotal() < m_casino.hand.at(0).getTotal()){
                cout<<"Player hand"<<j+1<<": ";
                for(int i = 0; i<player1.hand.at(j).getcards().size();i++){
                    player1.hand.at(j).getcards().at(i).displayCard();
                    cout<<" ";
                }
                int tots = player1.hand.at(j).getTotal();
                cout<<'['<<tots<<']'<<endl;

                this->wins++;
                this->houseWinRatio = this->wins/this->games;

                cout<<"for player hand "<<j+1<<": ";
                player1.announce(-1);
                
            }
            else{
                cout<<"Player hand"<<j+1<<": ";
                for(int i = 0; i<player1.hand.at(j).getcards().size();i++){
                    player1.hand.at(j).getcards().at(i).displayCard();
                    cout<<" ";
                }
                int tots = player1.hand.at(j).getTotal();
                cout<<'['<<tots<<']'<<endl;

                this->games --;

                cout<<"for player hand "<<j+1<<": ";
                player1.announce(0);
                
            }
        // return
        }return 0;
    }
    
};
BlackJackGame::BlackJackGame(){}


