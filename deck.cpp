#include <deck.h>
deck::deck(int tt,bool shuffled){
    total_set=tt;
    std::cout<<tt<<std::endl;
    the_deck= std::make_unique<std::vector<card>>();
    the_deck->reserve(tt*DECK_SIZE);
    for(int i=0;i<tt;i++) {
        for(suits c_suit:{ suits::club,suits::diamond,suits::heart,suits::spade }) {
            for(int f=1;f<=13;f++){
                //card t_card =  card(c_suit,f);
                //std::cout<<t_card<<std::endl;
                the_deck->emplace_back(card(c_suit,f));

            }
        }
    }
    if(shuffled) {
        this->shuffle();
    }
    
}

void deck::shuffle(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(the_deck->begin(),the_deck->end(),std::default_random_engine(seed));  
}

void deck::reset(){

}

void deck::print_deck() {
    std::cout<<"Total card in the deck is: "<<the_deck->size()<<std::endl;
    for(auto c:*the_deck) {
        std::cout<<c.face_value<<" ";
    }
    std::cout<<std::endl;
}

card deck::draw_card(){
    card t_card = the_deck->back();
    the_deck->pop_back();
    return t_card;
}

