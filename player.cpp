#include <player.h>

void player::play() {
    total_hand.clear();
    bets b;
    do{
        std::cout<<"Place down your bet"<<std::endl;
        std::cin>>b;
        {
            total_hand.push_back(hand(b));
            d_it=total_hand.begin();
            //draw 2 card to initiate the first hand
            d_it->cur_hand.push_back(this->deck_->draw_card());
            d_it->cur_hand.push_back(this->deck_->draw_card());
        }
        while(!(d_it->completed_hand)) {
            std::vector<check_type> valid_actions=d_it->evaluate();

        }
        d_it++;
    }while(d_it!=total_hand.end());
}

//deal one card from the deck
card player::deal(){
    return deck_->draw_card();
} 
 //split the hand into two hand
void player::split(){
    hand old_hand = *d_it;
    hand new_hand = hand(std::move(old_hand.cur_hand.back()),old_hand.bet);
    old_hand.cur_hand.erase(old_hand.cur_hand.end());
    total_hand.push_back(new_hand);
    total_bet-= old_hand.bet;
}

void player::surrender(){
    
}

void player::stand(){
    
}

void player::evaluate(std::vector<check_type> v_action) {
    
}