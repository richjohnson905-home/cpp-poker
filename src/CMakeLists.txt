
message(STATUS "Building Poker App")

set(Poker_SRCS
        main.cpp
        Card.cpp
        Deck.cpp
        Hand.cpp
        Dealer.cpp
        Evaluator.cpp
        Game.cpp
        )

add_executable(PokerApp
        ${Poker_SRCS}
        )