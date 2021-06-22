#include <hand.h>






//return the total point of the hand


int hand::count(){
    int total =0;
    int ace_count=0;
    for(auto c:cur_hand) {
        if(c.face_value==1) {
            ace_count++;
        } else if(c.face_value>10) {
            total+=10;
        } else {
            total += c.face_value;
        }
    }
    for(int i=0;i<ace_count;i++) {
        if(total<=10) {
            total+=11;
        } else {
            total+=1;
        }
    }
    return total;
} 

bool hand::check(check_type ct){
    switch(ct){
        case check_type::split:
            if( original_hand&&
                cur_hand.size()==2&&
                (cur_hand[0].face_value==cur_hand[1].face_value)
              ){            
                return true;
            }
            break;
        case check_type::bust:
            if(this->count()>21){
                return true;
            }
            break;
        case check_type::blackjack: 
            if(cur_hand.size()==2&&this->count()==21&&original_hand) {

                return true;
            }
            break;
        
        case check_type::twentyone: 
            if(this->count()==21){
                return true;
            }
            break;
        case check_type::surrender: 
            if(original_hand) {
                return true;
            }
            break;
        default:
            return false;            
    }
    return false;
}



std::vector<check_type> hand::evaluate(){
    std::vector<check_type> valid_actions = {};
    for(check_type ct:{check_type::split,check_type::bust,check_type::blackjack,check_type::twentyone,check_type::surrender}){
        if(check(ct)){
            valid_actions.push_back(ct);
        }
    }
    return valid_actions;
}

void hand::show_hand() {
    for(auto c:cur_hand) {
        std::cout<<c<<" ";
    }
}

hand::hand(bets b):bet(b)
{

}

hand::hand(card c,bets b):cur_hand(std::vector<card>{c}),bet(b)
{}