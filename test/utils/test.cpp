#include <sstream>
#include "utils/input_parser.hpp"
#include <gtest/gtest.h>

TEST(InputParserTest, CommaSeparatedLineNoCommaAtEnd)
{
    std::string       input("7,4,9,5,11,17");
    std::stringstream ss {input};
    std::vector<int>  expectedResult {7, 4, 9, 5, 11, 17};

    EXPECT_EQ(utils::parsing::parseCommaSeparatedLine<int>(ss), expectedResult);
}

TEST(InputParserTest, NewLineSeparatedInputs)
{
    std::string                           input = R""""(
22 13 17 11  0
 8  2 23  4 24
21  9 14 16  7
 6 10  3 18  5
 1 12 20 15 19

 3 15  0  2 22
 9 18 13 17  5
19  8  7 25 23
20 11 10 24  4
14 21 16 12  6

14 21 17 24  4
10 16 15  9 19
18  8 23 26 20
22 11 13  6  5
2  0 12  3  7
)"""";
    std::stringstream                     ss {input};
    std::vector<std::vector<std::string>> expectedResult {{
                                                              "22 13 17 11  0",
                                                              " 8  2 23  4 24",
                                                              "21  9 14 16  7",
                                                              " 6 10  3 18  5",
                                                              " 1 12 20 15 19",
                                                          },
                                                          {
                                                              " 3 15  0  2 22",
                                                              " 9 18 13 17  5",
                                                              "19  8  7 25 23",
                                                              "20 11 10 24  4",
                                                              "14 21 16 12  6",
                                                          },
                                                          {
                                                              "14 21 17 24  4",
                                                              "10 16 15  9 19",
                                                              "18  8 23 26 20",
                                                              "22 11 13  6  5",
                                                              "2  0 12  3  7",
                                                          }};

    EXPECT_EQ(utils::parsing::parseNewLineSeparatedInputs(ss), expectedResult);
}

TEST(NewLineSeparatedInputs, NewLineSeparatedInputsToInt)
{
    std::string input {
        R""""(
1000
2000
3000

4000

5000
6000

7000
8000
9000

10000
)""""};
    std::vector<std::vector<int>> expectedResult {
        {1000, 2000, 3000},
        {4000},
        {5000, 6000},
        {7000, 8000, 9000},
        {10000},
    };

    std::stringstream ss {input};
    auto              parsedResult = utils::parsing::parseNewLineSeparatedInputsToType<int>(
        ss, [](std::string const& str) { return std::stoi(str); });

    EXPECT_EQ(parsedResult, expectedResult);
}

TEST(InputParserTest, SpaceSeparatedString)
{
    std::string               input {"22 13 17 11  0"};
    std::stringstream         ss(input);
    std::vector<unsigned int> expectedResult {22, 13, 17, 11, 0};
    EXPECT_EQ(utils::parsing::parseSpaceSeparatedLine<unsigned int>(ss), expectedResult);
}

class SpaceSeparatedLinesTests : public ::testing::Test
{
protected:
    SpaceSeparatedLinesTests()
    {
        std::string input {
            R""""(
A Y
B X
C Z
)""""};
        ss << input;
    }
    std::stringstream ss;
};


TEST_F(SpaceSeparatedLinesTests, ToCharVector)
{
    std::vector<std::vector<char>> expectedResult {
        {'A', 'Y'},
        {'B', 'X'},
        {'C', 'Z'},
    };

    auto func = [](std::string const& line) {
        std::stringstream sub_ss {line};
        return utils::parsing::parseSpaceSeparatedLine<char>(sub_ss);
    };

    auto parsed = utils::parsing::parseSingleLineInputsToType<std::vector<char>>(ss, func);
    EXPECT_EQ(parsed, expectedResult);
}

TEST_F(SpaceSeparatedLinesTests, ToIntPair)
{
    std::vector<std::pair<int, int>> expectedResult {
        {65, 89},
        {66, 88},
        {67, 90},
    };

    auto func = [](std::string const& line) {
        std::stringstream sub_ss {line};
        auto              vec = utils::parsing::parseSpaceSeparatedLine<char>(sub_ss);
        return std::make_pair(static_cast<int>(vec.at(0)), static_cast<int>(vec.at(1)));
    };

    auto parsed = utils::parsing::parseSingleLineInputsToType<std::pair<int, int>>(ss, func);
    EXPECT_EQ(parsed, expectedResult);
}
