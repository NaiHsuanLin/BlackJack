#ifndef PLAYER_BLACKJACK
#define PLAYER_BLACKJACK

#include <library_collection.h>
#include <hand.h>
#include <card.h>
#include <deck.h>
#include <dealer.h>

using bets = int;

class player{
    public:
        std::vector<hand> total_hand;
        std::vector<hand>::iterator d_it;
        std::shared_ptr<deck> deck_;
        bets total_bet;

        void play();
        card deal(); //deal one card from the deck
        void split(); //split the hand into two hand
        void stand(); //stop asking for card for current hand, move to another hand. Also triggered when busted
        void surrender(); //recover half of the bet, only available when the flag orignal_hand is true
        void evaluate(std::vector<check_type> v_action);
        player();

};

#endif