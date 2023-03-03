
#include "Card.h"

#include <sstream>

const std::vector<Card::Suit> Card::SUITS = {Card::SPADE, Card::CLUB, Card::HEART, Card::DIAMOND};

Card::Card(int v, Card::Suit s):m_value(v), m_suit(s) {

}

int Card::getIntValue() const {
    return m_value;
}

std::string Card::getValue() const {
    switch (m_value) {
        case 10:
            return "T";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        case 14:
            return "A";
        default:
            return std::to_string(m_value);
    }
}

std::string Card::getSuit() const {
    switch (m_suit) {
        case Card::SPADE:
            return "S";
        case Card::CLUB:
            return "C";
        case Card::HEART:
            return "H";
        case Card::DIAMOND:
            return "D";
        default:
            return "U";
    }
}

std::string Card::to_string(const Card& c) {
    std::stringstream ss;
    ss << c.getValue() << c.getSuit();
    return ss.str();
}