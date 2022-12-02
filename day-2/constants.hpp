#ifndef DAY_2_CONSTANTS_HPP
#define DAY_2_CONSTANTS_HPP

#include <map>

namespace strategy
{
enum class Choices : unsigned int
{
    A = 1,
    B = 2,
    C = 3,
    X = A,
    Y = B,
    Z = C,
};

enum class Score : unsigned int
{
    LOSS = 0,
    DRAW = 3,
    WIN  = 6,
};

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
}
}  // namespace strategy

#endif  // DAY_2_CONSTANTS_HPP