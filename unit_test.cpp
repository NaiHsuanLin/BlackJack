#include <unit_test.h>


void create_shuffled_deck_and_draw_one() {
    deck test_deck= deck(1,true);
    test_deck.print_deck();
    card t_card = test_deck.draw_card();
    test_deck.print_deck();
    std::cout<<t_card<<std::endl;
}