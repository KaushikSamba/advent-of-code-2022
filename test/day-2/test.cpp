#include "day-2-rock-paper-scissors.hpp"
#include "utils/filehandler.hpp"
#include <gtest/gtest.h>

TEST(Day2Tests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}

TEST(Day2Tests, InputParsing)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    strategy::AllRoundChoices expectedResult {
        {'A', 'Y'},
        {'B', 'X'},
        {'C', 'Z'},
    };

    auto parsedInputs = strategy::parseInputs(inputFile);

    EXPECT_EQ(parsedInputs, expectedResult);
}

TEST(Day2Tests, ComputeScore)
{
    EXPECT_EQ(strategy::getScoreForRoundChoices({'A', 'Y'}), 8);
    EXPECT_EQ(strategy::getScoreForRoundChoices({'B', 'X'}), 1);
    EXPECT_EQ(strategy::getScoreForRoundChoices({'C', 'Z'}), 6);
}

TEST(Day2Tests, ComputeTotalScore)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    auto parsedInputs = strategy::parseInputs(inputFile);

    auto result = strategy::calculateScoreForAllRounds(parsedInputs, &strategy::getScoreForRoundChoices);
    EXPECT_EQ(result, 15);
}

TEST(Day2Tests, ComputeScoreGivenChoiceAndOutcome)
{
    EXPECT_EQ(strategy::getScoreForRoundChoiceAndOutcome({'A', 'Y'}), 4);
    EXPECT_EQ(strategy::getScoreForRoundChoiceAndOutcome({'B', 'X'}), 1);
    EXPECT_EQ(strategy::getScoreForRoundChoiceAndOutcome({'C', 'Z'}), 7);
}