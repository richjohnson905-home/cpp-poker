
#include "Evaluator.h"

Evaluator::HandValue Evaluator::evaluate(Hand &h) {
    h.sortHand();
    if (isRoyalFlush(h)) {
        return ROYAL_FLUSH;
    } else if (isStraightFlush(h)) {
        return STRAIGHT_FLUSH;
    } else if (isQuad(h)) {
        return QUAD;
    } else if (isFullHouse(h)) {
        return FULL_HOUSE;
    } else if (isFlush(h)) {
        return FLUSH;
    } else if (isStraight(h)) {
        return STRAIGHT;
    } else if (isTrips(h)) {
        return TRIPS;
    } else if (isTwoPair(h)) {
        return TWO_PAIR;
    } else if (isPair(h)) {
        return PAIR;
    } else {
        return HIGH_CARD;
    }
}


bool Evaluator::isPair(Hand& h){
    bool firstTwo = are2CardsEqual(h.cardAt(0), h.cardAt(1));
    bool secondTwo = are2CardsEqual(h.cardAt(1), h.cardAt(2));
    bool thirdTwo = are2CardsEqual(h.cardAt(2), h.cardAt(3));
    bool fourthTwo = are2CardsEqual(h.cardAt(3), h.cardAt(4));
    return firstTwo || secondTwo || thirdTwo || fourthTwo;
}

bool Evaluator::isTwoPair(Hand& h){
    bool firstFour = are2CardsEqual(h.cardAt(0), h.cardAt(1)) && are2CardsEqual(h.cardAt(2), h.cardAt(3));
    bool firstLast = are2CardsEqual(h.cardAt(0), h.cardAt(1)) && are2CardsEqual(h.cardAt(3), h.cardAt(4));
    bool lastFour = are2CardsEqual(h.cardAt(1), h.cardAt(2)) && are2CardsEqual(h.cardAt(3), h.cardAt(4));
    return firstFour || firstLast || lastFour;
}

bool Evaluator::isTrips(Hand& h){
    bool firstThree = are3CardsEqual(h.cardAt(0), h.cardAt(1), h.cardAt(2));
    bool middleThree = are3CardsEqual(h.cardAt(1), h.cardAt(2), h.cardAt(3));
    bool lastThree = are3CardsEqual(h.cardAt(2), h.cardAt(3), h.cardAt(4));
    return firstThree || middleThree || lastThree;
}

bool Evaluator::isStraight(Hand& h){
    return (h.cardAt(4)->getIntValue() - h.cardAt(3)->getIntValue() == 1) &&
        (h.cardAt(3)->getIntValue() - h.cardAt(2)->getIntValue() == 1) &&
        (h.cardAt(2)->getIntValue() - h.cardAt(1)->getIntValue() == 1) &&
        (h.cardAt(1)->getIntValue() - h.cardAt(0)->getIntValue() == 1);
}

bool Evaluator::isFlush(Hand& h){
    return (h.cardAt(0)->getSuit() == h.cardAt(1)->getSuit()) &&
        (h.cardAt(0)->getSuit() == h.cardAt(2)->getSuit()) &&
        (h.cardAt(0)->getSuit() == h.cardAt(3)->getSuit()) &&
        (h.cardAt(0)->getSuit() == h.cardAt(4)->getSuit());
}

bool Evaluator::isFullHouse(Hand& h){
    bool twoThree = are2CardsEqual(h.cardAt(0), h.cardAt(1)) &&
            are3CardsEqual(h.cardAt(2), h.cardAt(3), h.cardAt(4));
    bool threeTwo = are3CardsEqual(h.cardAt(0), h.cardAt(1), h.cardAt(2)) &&
            are2CardsEqual(h.cardAt(3), h.cardAt(4));
    return twoThree || threeTwo;
}

bool Evaluator::isQuad(Hand& h){
    bool firstFour = are4CardsEqual(h.cardAt(0), h.cardAt(1), h.cardAt(2), h.cardAt(3));
    bool lastFour = are4CardsEqual(h.cardAt(1), h.cardAt(2), h.cardAt(3), h.cardAt(4));
    return firstFour || lastFour;
}

bool Evaluator::isStraightFlush(Hand& h){
    return isStraight(h) && isFlush(h);
}

bool Evaluator::isRoyalFlush(Hand& h){
    return isStraightFlush(h) && h.cardAt(0)->getIntValue() == 10;
}


bool Evaluator::are2CardsEqual(Card* c1, Card* c2){
    return c1->getIntValue() == c2->getIntValue();
}

bool Evaluator::are3CardsEqual(Card* c1, Card* c2, Card* c3){
    return c1->getIntValue() == c2->getIntValue() && c2->getIntValue() == c3->getIntValue();
}

bool Evaluator::are4CardsEqual(Card* c1, Card* c2, Card* c3, Card* c4){
    return c1->getIntValue() == c2->getIntValue() &&
    c2->getIntValue() == c3->getIntValue() &&
    c3->getIntValue() == c4->getIntValue();
}
