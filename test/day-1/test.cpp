#include "day-1-calorie-counting.hpp"
#include "filehandler.hpp"
#include <gtest/gtest.h>

TEST(Day1Tests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}

TEST(Day1Tests, InputParsing)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    std::vector<std::vector<int>> expectedResult {
        {1000, 2000, 3000},
        {4000},
        {5000, 6000},
        {7000, 8000, 9000},
        {10000},
    };

    auto parsedInputs = calories::parseInputs(inputFile);

    EXPECT_EQ(parsedInputs, expectedResult);
}

TEST(Day1Tests, FindMaximumCalorieTotal)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    auto               parsedInputs = calories::parseInputs(inputFile);

    auto result = calories::findMaxCalories(parsedInputs);
    EXPECT_EQ(result, 24000);
}

TEST(Day1Tests, FindTop3CalorieTotal)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    auto               parsedInputs = calories::parseInputs(inputFile);

    auto result = calories::findTop3Sum(parsedInputs);
    EXPECT_EQ(result, 45000);
}