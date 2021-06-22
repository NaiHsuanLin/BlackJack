#ifndef DECK_BLACKJACK
#define DECK_BLACKJACK

#include <library_collection.h>
#include <card.h>
#define DECK_SIZE 52
class deck{
    public:
        std::unique_ptr<std::vector<card>> the_deck;
        int total_set;
        deck() = delete;
        deck(int tt,bool shuffled);

        card draw_card();

        void reset();
        void print_deck();
    private:
        void shuffle();

};

#endif