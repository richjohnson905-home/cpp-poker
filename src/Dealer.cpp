
#include "Dealer.h"

void Dealer::deal(Hand* h1, Hand* h2) {

    for (int i = 0; i < 5; ++i) {
        h1->push(m_deck.popCard());
        h2->push(m_deck.popCard());
    }

}