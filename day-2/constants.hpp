#ifndef DAY_2_CONSTANTS_HPP
#define DAY_2_CONSTANTS_HPP

#include <array>
#include <map>

namespace strategy
{

enum class Score : unsigned int
{
    LOSS = 0,
    DRAW = 3,
    WIN  = 6,
};

using RoundChoices = std::pair<char, char>;

}  // namespace strategy

#endif  // DAY_2_CONSTANTS_HPP