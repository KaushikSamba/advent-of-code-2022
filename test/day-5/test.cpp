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
        Instruction {1, 1, 0},
        Instruction {3, 0, 2},
        Instruction {2, 1, 0},
        Instruction {1, 0, 1},
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
        Instruction {1, 1, 0},
        Instruction {3, 0, 2},
        Instruction {2, 1, 0},
        Instruction {1, 0, 1},
    };
    EXPECT_EQ(parsed.first, expectedConfigs);
    EXPECT_EQ(parsed.second, expectedInstructions);
}

TEST(Day5Tests, ProcessInstruction)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    auto [config, _] = supply::parseInputs(inputFile);

    {
        supply::processInstruction(config, supply::Instruction {1, 1, 0});
        supply::Configuration expectedConfigs = {
            std::stack(std::deque {'Z', 'N', 'D'}),
            std::stack(std::deque {'M', 'C'}),
            std::stack(std::deque {'P'}),
        };
        EXPECT_EQ(config, expectedConfigs);
    }

    {
        supply::processInstruction(config, supply::Instruction {3, 0, 2});
        supply::Configuration expectedConfigs = {
            std::stack<char>(),
            std::stack(std::deque {'M', 'C'}),
            std::stack(std::deque {'P', 'D', 'N', 'Z'}),
        };
        EXPECT_EQ(config, expectedConfigs);
    }
}

TEST(Day5Tests, ProcessAllInstructions)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    auto [config, instructions] = supply::parseInputs(inputFile);

    supply::Configuration expectedConfigs = {
        std::stack(std::deque {'C'}),
        std::stack(std::deque {'M'}),
        std::stack(std::deque {'P', 'D', 'N', 'Z'}),
    };

    supply::processAllInstructions(config, instructions, &supply::processInstruction);
    EXPECT_EQ(config, expectedConfigs);
}

TEST(Day5Tests, CheckTops)
{
    auto res = supply::getTopsOfStacks(supply::Configuration {
        std::stack(std::deque {'Z', 'N'}),
        std::stack(std::deque {'M', 'C', 'D'}),
        std::stack(std::deque {'P'}),
    });
    EXPECT_EQ(res, "NDP");
}

TEST(Day5Tests, ProcessInstructionBigCrane)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    auto [config, _] = supply::parseInputs(inputFile);

    {
        supply::processInstructionBigCrane(config, supply::Instruction {1, 1, 0});
        supply::Configuration expectedConfigs = {
            std::stack(std::deque {'Z', 'N', 'D'}),
            std::stack(std::deque {'M', 'C'}),
            std::stack(std::deque {'P'}),
        };
        EXPECT_EQ(config, expectedConfigs);
    }

    {
        supply::processInstructionBigCrane(config, supply::Instruction {3, 0, 2});
        supply::Configuration expectedConfigs = {
            std::stack<char>(),
            std::stack(std::deque {'M', 'C'}),
            std::stack(std::deque {'P', 'Z', 'N', 'D'}),
        };
        EXPECT_EQ(config, expectedConfigs);
    }
}

TEST(Day5Tests, ProcessAllInstructionsBigCrane)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    auto [config, instructions] = supply::parseInputs(inputFile);

    supply::Configuration expectedConfigs = {
        std::stack(std::deque {'M'}),
        std::stack(std::deque {'C'}),
        std::stack(std::deque {'P', 'Z', 'N', 'D'}),
    };

    supply::processAllInstructions(config, instructions, &supply::processInstructionBigCrane);
    EXPECT_EQ(config, expectedConfigs);
}