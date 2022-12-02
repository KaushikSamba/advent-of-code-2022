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

namespace constants
{

const std::array<RoundChoices, 3> WINNING_PAIRS {
    std::make_pair('A', 'Y'),  // Rock is beaten by paper
    std::make_pair('B', 'Z'),  // Paper is beaten by scissors
    std::make_pair('C', 'X'),  // Scissors is beaten by rock
};

}  // namespace constants
}  // namespace strategy

#endif  // DAY_2_CONSTANTS_HPP