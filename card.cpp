#include <card.h>


card::card(suits _suit,deck_point _face_value) : suit(_suit),face_value(_face_value)
{}

std::ostream& operator<< (std::ostream &out, const card &c){
    out <<suitsType[static_cast<int>(c.suit)-1]<<card_face[static_cast<int>(c.face_value)-1]<<std::endl;
    return out;
}