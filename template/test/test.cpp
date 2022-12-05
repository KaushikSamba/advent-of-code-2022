#include "day-N.hpp"
#include "utils/filehandler.hpp"
#include <gtest/gtest.h>

TEST(DayNTests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}
