#ifndef HAND_BLACKJACK
#define HAND_BLACKJACK

#include <library_collection.h>
#include <card.h>
#include <deck.h>
using bets = int;
enum class check_type{split,bust,blackjack,twentyone,surrender};
const std::vector<std::string> actions {
    "Split",
    "Bust",
    "Blackjack",
    "Twentyone",
    "Surrender"
};
class hand {
    public:

        bool original_hand=true;
        std::vector<card> cur_hand;
        bets bet;
        bool completed_hand=false;

        
        int count(); //return the total point of the hand
        bool check(check_type ct);
        std::vector<check_type> evaluate(); //evaluate the hand to see if there is any aviable action.
        void show_hand();
        hand(bets b);
        hand(card c, bets b);
    private:
        
        
};


#endif 