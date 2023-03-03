#ifndef POKER_DECK_H
#define POKER_DECK_H

#include "Card.h"
#include <vector>

class Deck {
private:
    std::vector<Card> m_cards;
    std::vector<Card>::iterator m_cardIter;

public:
    Deck();
    ~Deck(){}

    int getDeckSize() {return m_cards.size();}
    Card* popCard();
};


#endif //POKER_DECK_H
