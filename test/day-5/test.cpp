#include "day-5.hpp"
#include "utils/filehandler.hpp"
#include <gtest/gtest.h>

TEST(Day5Tests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}


TEST(Day5Tests, ParseInputs)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    EXPECT_EQ(supply::parseInputs(inputFile), 3);
}
