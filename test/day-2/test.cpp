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

    using strategy::Choices;
    strategy::AllRoundChoices expectedResult {
        {Choices::A, Choices::Y},
        {Choices::B, Choices::X},
        {Choices::C, Choices::Z},
    };

    auto parsedInputs = strategy::parseInputs(inputFile);

    EXPECT_EQ(parsedInputs, expectedResult);
}

TEST(Day2Tests, ComputeScore)
{
    EXPECT_EQ(strategy::getScoreForRoundChoices({strategy::Choices::A, strategy::Choices::Y}), 8);
    EXPECT_EQ(strategy::getScoreForRoundChoices({strategy::Choices::B, strategy::Choices::X}), 1);
    EXPECT_EQ(strategy::getScoreForRoundChoices({strategy::Choices::C, strategy::Choices::Z}), 6);
}

TEST(Day2Tests, ComputeTotalScore)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    auto parsedInputs = strategy::parseInputs(inputFile);

    auto result = strategy::calculateScoreForAllRounds(parsedInputs);
    EXPECT_EQ(result, 15);
}
