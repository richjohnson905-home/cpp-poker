
#include <catch2/catch.hpp>
#include "../src/Deck.h"

#include <iostream>


TEST_CASE("DeckTest - new deck")
{
    Deck d;

    CHECK(d.getDeckSize() == 52);

}

TEST_CASE("DeckTest popCard") {
    Deck d;

    Card* c = d.popCard();
    c = d.popCard();
    c = d.popCard();
    c = d.popCard();
    c = d.popCard();
    c = d.popCard();

    std::cout << Card::to_string(*c) << std::endl;
}

TEST_CASE("DeckTest deck empty") {
    Deck d;
    for (int i = 0; i < 52; ++i) {
        d.popCard();
    }
    try {
        d.popCard();
    } catch (std::runtime_error& ex) {
        CHECK(std::string(ex.what()) == "Deck Empty Exception");
    }
}