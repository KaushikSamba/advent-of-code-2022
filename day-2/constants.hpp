#ifndef DAY_2_CONSTANTS_HPP
#define DAY_2_CONSTANTS_HPP

#include <array>
#include <map>

namespace strategy
{
enum class Choices : unsigned int
{
    // Opponent choices
    A = 1,  // Rock
    B = 2,  // Paper
    C = 3,  // Scissors

    // My choices
    X = A,  // Rock
    Y = B,  // Paper
    Z = C,  // Scissors
};

enum class Score : unsigned int
{
    LOSS = 0,
    DRAW = 3,
    WIN  = 6,
};

using RoundChoices = std::pair<Choices, Choices>;

namespace constants
{
const std::map<char, Choices> CHAR_TO_CHOICE {
    {'A', Choices::A},
    {'B', Choices::B},
    {'C', Choices::C},
    {'X', Choices::X},
    {'Y', Choices::Y},
    {'Z', Choices::Z},
};

const std::array<RoundChoices, 3> WINNING_PAIRS {
    std::make_pair(Choices::A, Choices::Y),  // Rock is beaten by paper
    std::make_pair(Choices::B, Choices::Z),  // Paper is beaten by scissors
    std::make_pair(Choices::C, Choices::X),  // Scissors is beaten by rock
};

}  // namespace constants
}  // namespace strategy

#endif  // DAY_2_CONSTANTS_HPP