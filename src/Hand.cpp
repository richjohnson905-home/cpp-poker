
#include "Hand.h"
#include <algorithm>
#include <sstream>

std::string Hand::to_string() {
    std::stringstream ss;
    for (auto c : m_cards) {
        ss << Card::to_string(*c) << ",";
    }
    return ss.str();
}

void Hand::sortHand(){
    std::sort(m_cards.begin(), m_cards.end(), Hand::sortByCardValue);
}