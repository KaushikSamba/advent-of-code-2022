#include "utils/filehandler.hpp"
#include <gtest/gtest.h>

TEST(Day3Tests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}
