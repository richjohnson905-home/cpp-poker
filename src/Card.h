#ifndef POKER_CARD_H
#define POKER_CARD_H

#include <vector>
#include <iostream>

class Card {
public:
    enum Suit {
        SPADE,
        CLUB,
        HEART,
        DIAMOND
    };
    static const std::vector<Suit> SUITS;

    Card(int v, Suit s);

    int getIntValue() const;
    std::string getValue() const;
    std::string getSuit() const;
    static std::string to_string(const Card& c);
private:
    int m_value;
    Suit m_suit;

};

#endif //POKER_CARD_H
