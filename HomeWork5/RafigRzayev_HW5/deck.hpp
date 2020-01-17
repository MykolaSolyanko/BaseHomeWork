#pragma once

#include <random>
#include <string>

// generate 52 cards deck on a heap
const std::string *generate_deck();

// returns a random card from a generated deck
const std::string &get_random_card(const std::string *DECK);
