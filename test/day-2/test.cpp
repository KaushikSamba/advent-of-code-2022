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
