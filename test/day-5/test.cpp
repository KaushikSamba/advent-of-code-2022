#include <stack>
#include "day-5.hpp"
#include "utils/filehandler.hpp"
#include <gtest/gtest.h>

TEST(Day5Tests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}


namespace std
{
std::ostream& operator<<(std::ostream& os, std::stack<char> stack)
{
    std::vector<char> debugVector;
    while(!stack.empty())
    {
        auto t = stack.top();
        debugVector.push_back(t);
        stack.pop();
    }

    for(const char& elem : debugVector)
    {
        os << elem << ' ';
    }
    return os;
}
}  // namespace std


TEST(Day5Tests, parseStartingConfiguration)
{
    std::vector<std::string> input {
        "    [D]    ",
        "[N] [C]    ",
        "[Z] [M] [P]",
        " 1   2   3 ",
    };

    std::vector<std::stack<char>> expected = {
        std::stack(std::deque {'Z', 'N'}),
        std::stack(std::deque {'M', 'C', 'D'}),
        std::stack(std::deque {'P'}),
    };

    auto parsed = supply::parseStartingConfiguration(input);

    EXPECT_EQ(parsed, expected);
}