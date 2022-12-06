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

    supply::Configuration expected = {
        std::stack(std::deque {'Z', 'N'}),
        std::stack(std::deque {'M', 'C', 'D'}),
        std::stack(std::deque {'P'}),
    };

    auto parsed = supply::parseStartingConfiguration(input);

    EXPECT_EQ(parsed, expected);
}

namespace supply
{
bool operator==(Instruction const& i1, Instruction const& i2)
{
    return (i1.numberOfCrates == i2.numberOfCrates) and (i1.source == i2.source) and (i1.dest == i2.dest);
}

std::ostream& operator<<(std::ostream& os, Instruction const& i)
{
    return os << "(Num crates: " << i.numberOfCrates << "; Source = " << i.source << "; Dest = " << i.dest << ")";
}
}  // namespace supply

TEST(Day5Tests, parseInstructions)
{
    std::vector<std::string> input {
        "move 1 from 2 to 1",
        "move 3 from 1 to 3",
        "move 2 from 2 to 1",
        "move 1 from 1 to 2",
    };

    using supply::Instruction;
    std::vector<Instruction> expected = {
        Instruction {1, 2, 1},
        Instruction {3, 1, 3},
        Instruction {2, 2, 1},
        Instruction {1, 1, 2},
    };

    auto parsed = supply::parseInstructions(input);
    EXPECT_EQ(parsed, expected);
}

TEST(Day5Tests, parseInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    auto parsed = supply::parseInputs(inputFile);

    supply::Configuration expectedConfigs = {
        std::stack(std::deque {'Z', 'N'}),
        std::stack(std::deque {'M', 'C', 'D'}),
        std::stack(std::deque {'P'}),
    };
    using supply::Instruction;
    std::vector<Instruction> expectedInstructions = {
        Instruction {1, 2, 1},
        Instruction {3, 1, 3},
        Instruction {2, 2, 1},
        Instruction {1, 1, 2},
    };
    EXPECT_EQ(parsed.first, expectedConfigs);
    EXPECT_EQ(parsed.second, expectedInstructions);
}