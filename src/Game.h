#ifndef POKER_GAME_H
#define POKER_GAME_H

#include "Dealer.h"
#include "Hand.h"
#include "Evaluator.h"

#include <vector>
#include <unordered_map>

class Game {
private:
    Evaluator m_evaluator;

    void showResult(std::unordered_map<Evaluator::HandValue, int>& pokerHandMap);
    float getHandAsPercent(std::unordered_map<Evaluator::HandValue, int>& pokerHandMap, Evaluator::HandValue hv, int count);
    std::vector<Evaluator::HandValue> round();
    static void initResultsMap(std::unordered_map<Evaluator::HandValue, int>& pokerHandMap);

public:
    void runGame(int rounds);
};


#endif //POKER_GAME_H
