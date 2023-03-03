message(STATUS "Building Unit Tests ${UNITTEST}")

include(CTest)

set(allTest_SRCS
        ../src/Deck.cpp
        DeckTest.cpp
        main.cpp
        )

set(deckTest_SRCS
        ../src/Card.cpp
        ../src/Deck.cpp
        DeckTest.cpp
        main.cpp
        )

#add_executable(AllTests ${allTest_SRCS})
#add_test(NAME AllTests COMMAND AllTests WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_libraries(AllTests CONAN_PKG::catch2 )

add_executable(DeckTest ${deckTest_SRCS})
add_test(NAME DeckTest COMMAND DeckTest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(DeckTest CONAN_PKG::catch2 )

enable_testing()