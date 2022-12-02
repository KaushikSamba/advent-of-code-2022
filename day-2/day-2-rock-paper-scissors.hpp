#ifndef DAY_2_ROCK_PAPER_SCISSORS_HPP
#define DAY_2_ROCK_PAPER_SCISSORS_HPP

#include <string>
#include <utility>
#include <vector>
#include "constants.hpp"
namespace strategy
{

using RoundChoices    = std::pair<Choices, Choices>;
using AllRoundChoices = std::vector<RoundChoices>;

AllRoundChoices parseInputs(std::istream& stream);

}  // namespace strategy

#endif  // DAY_2_ROCK_PAPER_SCISSORS_HPP