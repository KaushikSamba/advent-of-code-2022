#include "day-4-camp-cleanup.hpp"
#include "utils/filehandler.hpp"
#include <gtest/gtest.h>

TEST(Day4Tests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}

TEST(Day4Tests, ParseInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    using cleanup::Range;

    std::vector<cleanup::Assignment> expectedResult {
        std::make_pair(Range {2, 4}, Range {6, 8}),
        std::make_pair(Range {2, 3}, Range {4, 5}),
        std::make_pair(Range {5, 7}, Range {7, 9}),
        std::make_pair(Range {2, 8}, Range {3, 7}),
        std::make_pair(Range {6, 6}, Range {4, 6}),
        std::make_pair(Range {2, 6}, Range {4, 8}),
    };

    EXPECT_EQ(cleanup::parseInputs(inputFile), expectedResult);
}

TEST(Day4Tests, ConvertLineToAssignment)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    using cleanup::Range;

    EXPECT_EQ(cleanup::getAssignmentFromString("2-4,6-8"), std::make_pair(Range {2, 4}, Range {6, 8}));
    EXPECT_THROW(cleanup::getAssignmentFromString("asdfa2-4,6-8"), std::logic_error);
}

TEST(Day4Tests, CheckContainment)
{
    using cleanup::Range;
    EXPECT_FALSE(cleanup::checkContainment(std::make_pair(Range {2, 4}, Range {6, 8})));
    EXPECT_FALSE(cleanup::checkContainment(std::make_pair(Range {2, 3}, Range {4, 5})));
    EXPECT_FALSE(cleanup::checkContainment(std::make_pair(Range {5, 7}, Range {7, 9})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {2, 8}, Range {3, 7})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {6, 6}, Range {4, 6})));
    EXPECT_FALSE(cleanup::checkContainment(std::make_pair(Range {2, 6}, Range {4, 8})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {86, 88}, Range {79, 88})));
    EXPECT_FALSE(cleanup::checkContainment(std::make_pair(Range {67, 83}, Range {68, 84})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {50, 83}, Range {82, 83})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {5, 47}, Range {5, 5})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {78, 78}, Range {55, 79})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {43, 48}, Range {12, 99})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {4, 39}, Range {4, 77})));
    EXPECT_TRUE(cleanup::checkContainment(std::make_pair(Range {4, 77}, Range {12, 77})));
}

TEST(Day4Tests, Part1Result)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    auto parsed = cleanup::parseInputs(inputFile);
    EXPECT_EQ(cleanup::processAllAssignments(parsed), 2);
}