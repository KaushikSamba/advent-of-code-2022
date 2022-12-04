#include "day-4-camp-cleanup.hpp"
#include "utils/filehandler.hpp"
#include <gtest/gtest.h>

TEST(Day4Tests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}
