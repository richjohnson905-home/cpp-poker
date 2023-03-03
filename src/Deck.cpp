
#include "Deck.h"
#include <algorithm>
#include <random>
#include <stdexcept>

Deck::Deck() {
    for (auto s : Card::SUITS) {
        for (int v = 2; v < 15; ++v) {
            m_cards.push_back(Card(v, s));
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(m_cards.begin(), m_cards.end(), g);
    m_cardIter = m_cards.begin();

}

Card* Deck::popCard() {
    if (m_cardIter == m_cards.end()) {
        throw std::runtime_error(std::string("Deck Empty Exception"));
    }
    Card* c = &(*m_cardIter);
    m_cardIter++;
    return c;
}