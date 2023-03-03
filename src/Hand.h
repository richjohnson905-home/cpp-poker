#ifndef POKER_HAND_H
#define POKER_HAND_H

#include "Card.h"

#include <vector>

class Hand {
private:
    std::vector<Card*> m_cards;

public:
    static bool sortByCardValue(Card* c1, Card* c2){return c1->getIntValue() < c2->getIntValue();}
    void sortHand();
    void push(Card* c) {m_cards.push_back(c);}
    std::string to_string();
    Card* cardAt(int index){return m_cards[index];}
};


#endif //POKER_HAND_H
