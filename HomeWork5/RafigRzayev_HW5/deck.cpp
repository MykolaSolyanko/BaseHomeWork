#include "deck.hpp"

const size_t DECK_SIZE = 52;

// generate 52 cards deck on a heap
const std::string *generate_deck() {
  // Card values: 2 -> Ace
  const size_t VALUE_COUNT{13};
  std::string values[VALUE_COUNT]{"2", "3",  "4", "5", "6", "7", "8",
                                  "9", "10", "J", "Q", "K", "A"};
  // Card symbols: Spade, Heart, Diamond, Club
  const size_t SYMBOL_COUNT{4};
  std::string symbols[SYMBOL_COUNT]{"\u2660", "\u2665", "\u2666", "\u2663"};
  // Create 52 card deck once
  static std::string deck[DECK_SIZE];
  // Fill deck
  for (size_t i{0}; i < SYMBOL_COUNT; ++i) {
    for (size_t j{0}; j < VALUE_COUNT; ++j) {
      deck[i * VALUE_COUNT + j] = values[j] + symbols[i];
    }
  }
  return deck;
}

// returns a random card from the generated deck
const std::string &get_random_card() {
  // deck is created on first function call
  static const std::string *const DECK = generate_deck();
  std::random_device seed;
  std::default_random_engine rng(seed());
  std::uniform_int_distribution<int> distr(0, DECK_SIZE - 1);
  return *(DECK + distr(rng));
}