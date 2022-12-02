#ifndef DAY_2_ROCK_PAPER_SCISSORS_HPP
#define DAY_2_ROCK_PAPER_SCISSORS_HPP

#include <string>
#include <utility>
#include <vector>
#include "constants.hpp"

namespace strategy
{

using AllRoundChoices = std::vector<RoundChoices>;

AllRoundChoices parseInputs(std::istream& stream);

unsigned int getScoreForRoundChoices(RoundChoices const& roundChoices);

unsigned int getScoreForRoundChoiceAndOutcome(RoundChoices const& roundChoices);

unsigned int calculateScoreForAllRounds(AllRoundChoices const& allChoices);

}  // namespace strategy

#endif  // DAY_2_ROCK_PAPER_SCISSORS_HPP