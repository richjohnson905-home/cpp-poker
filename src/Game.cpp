
#include "Game.h"
#include "Hand.h"

#include <iostream>

using namespace std;

void Game::runGame(int rounds) {
    std::cout << "Poker 5-Card Stud!" << std::endl;
    std::unordered_map<Evaluator::HandValue, int> pokerHandmap;
    initResultsMap(pokerHandmap);

    for (int i = 0; i < rounds; ++i) {
        std::vector<Evaluator::HandValue> pokerHands = round();

        for(auto ph : pokerHands) {
            pokerHandmap[ph] += 1;
        }
    }
    showResult(pokerHandmap);
}

vector<Evaluator::HandValue> Game::round() {
    Dealer dealer;

    std::vector<Evaluator::HandValue> pokerHands;
    for (int i = 0; i < 5; ++i) {
        Hand h1;
        Hand h2;
        dealer.deal(&h1, &h2);
        pokerHands.push_back(m_evaluator.evaluate(h1));
        pokerHands.push_back(m_evaluator.evaluate(h2));

//        std::cout << "\nH1: " << h1.to_string() << std::endl;
//        std::cout << "H2: " << h2.to_string() << std::endl;

    }
    return pokerHands;
}

void Game::initResultsMap(std::unordered_map<Evaluator::HandValue, int>& pokerHandMap) {
    pokerHandMap[Evaluator::HandValue::HIGH_CARD] = 0;
    pokerHandMap[Evaluator::HandValue::PAIR] = 0;
    pokerHandMap[Evaluator::HandValue::TWO_PAIR] = 0;
    pokerHandMap[Evaluator::HandValue::TRIPS] = 0;
    pokerHandMap[Evaluator::HandValue::STRAIGHT] = 0;
    pokerHandMap[Evaluator::HandValue::FLUSH] = 0;
    pokerHandMap[Evaluator::HandValue::FULL_HOUSE] = 0;
    pokerHandMap[Evaluator::HandValue::QUAD] = 0;
    pokerHandMap[Evaluator::HandValue::STRAIGHT_FLUSH] = 0;
    pokerHandMap[Evaluator::HandValue::ROYAL_FLUSH] = 0;
}

void Game::showResult(std::unordered_map<Evaluator::HandValue, int>& pokerHandMap) {
    int count = 0;
    for (std::unordered_map<Evaluator::HandValue, int>::iterator it = pokerHandMap.begin(); it != pokerHandMap.end(); ++it) {
        count += it->second;
    }
    std::cout << "\nTotal Hands Played: " << count << std::endl;
    std::cout << "\nHighCard: " << getHandAsPercent(pokerHandMap, Evaluator::HIGH_CARD, count) << std::endl;
    std::cout << "Pair: " << getHandAsPercent(pokerHandMap, Evaluator::PAIR, count) << std::endl;
    std::cout << "TwoPair: " << getHandAsPercent(pokerHandMap, Evaluator::TWO_PAIR, count) << std::endl;
    std::cout << "Trips: " << getHandAsPercent(pokerHandMap, Evaluator::TRIPS, count) << std::endl;
    std::cout << "Straight: " << getHandAsPercent(pokerHandMap, Evaluator::STRAIGHT, count) << std::endl;
    std::cout << "Flush: " << getHandAsPercent(pokerHandMap, Evaluator::FLUSH, count) << std::endl;
    std::cout << "FullHouse: " << getHandAsPercent(pokerHandMap, Evaluator::FULL_HOUSE, count) << std::endl;
    std::cout << "Quad: " << getHandAsPercent(pokerHandMap, Evaluator::QUAD, count) << std::endl;
    std::cout << "StraightFlush: " << getHandAsPercent(pokerHandMap, Evaluator::STRAIGHT_FLUSH, count) << std::endl;
    std::cout << "RoyalFlush: " << getHandAsPercent(pokerHandMap, Evaluator::ROYAL_FLUSH, count) << std::endl;
}

float Game::getHandAsPercent(std::unordered_map<Evaluator::HandValue, int>& pokerHandMap, Evaluator::HandValue hv, int count) {
    int v = pokerHandMap[hv];
    return (static_cast<float>(v)/count) * 100;
}