#ifndef CARD_BLACKJACK 
#define CARD_BLACKJACK

#include <library_collection.h>
using deck_point=int;
enum class suits{club=1,diamond,heart,spade};
const std::vector<std::string> suitsType {
    "Club",
    "Dimond",
    "Heart",
    "Spade"
};

const std::vector<std::string> card_face {
    "A","2","3","4","5","6","7","8","9","10","J","Q","K"
};

class card{
    public:
        deck_point face_value;
        suits suit;
        card() = delete;
        card(suits suit,deck_point face_value);

        friend std::ostream& operator<< (std::ostream &out, const card &c);
};

#endif