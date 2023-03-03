#ifndef POKER_DEALER_H
#define POKER_DEALER_H

#include "Deck.h"
#include "Hand.h"

class Dealer {
private:
    Deck m_deck;
public:
    void deal(Hand* h1, Hand* h2);
};


#endif //POKER_DEALER_H
