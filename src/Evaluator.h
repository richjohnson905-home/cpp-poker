#ifndef POKER_EVALUATOR_H
#define POKER_EVALUATOR_H

#include "Hand.h"

class Evaluator {
public:
    enum HandValue {
        HIGH_CARD,
        PAIR,
        TWO_PAIR,
        TRIPS,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        QUAD,
        STRAIGHT_FLUSH,
        ROYAL_FLUSH
    };

    HandValue evaluate(Hand& h);
private:

    bool isPair(Hand& h);
    bool isTwoPair(Hand& h);
    bool isTrips(Hand& h);
    bool isStraight(Hand& h);
    bool isFlush(Hand& h);
    bool isFullHouse(Hand& h);
    bool isQuad(Hand& h);
    bool isStraightFlush(Hand& h);
    bool isRoyalFlush(Hand& h);

    bool are2CardsEqual(Card* c1, Card* c2);
    bool are3CardsEqual(Card* c1, Card* c2, Card* c3);
    bool are4CardsEqual(Card* c1, Card* c2, Card* c3, Card* c4);
};


#endif //POKER_EVALUATOR_H
