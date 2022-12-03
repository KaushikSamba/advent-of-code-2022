#include "day-3-rucksack-reorganization.hpp"
#include "utils/filehandler.hpp"
#include <gtest/gtest.h>

TEST(Day3Tests, AbleToReadInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};
    EXPECT_TRUE(inputFile);
}

TEST(Day3Tests, ParseInputFile)
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/test-input.txt"};

    std::vector<std::string> expectedResult {
        "vJrwpWtwJgWrhcsFMMfFFhFp",
        "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
        "PmmdzqPrVvPwwTWBwg",
        "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
        "ttgJtRGJQctTZtZT",
        "CrZsJsPPZsGzwwsLwLmpwMDw",
    };

    EXPECT_EQ(rucksack::parseInputs(inputFile), expectedResult);
}

TEST(Day3Tests, SplitStringIntoNParts)
{
    {
        std::vector<std::string> expected {"vJrwpWtwJgWr", "hcsFMMfFFhFp"};
        EXPECT_EQ(rucksack::splitCompartments("vJrwpWtwJgWrhcsFMMfFFhFp", 2), expected);
    }
    {
        std::vector<std::string> expected {"vJrwpWtw", "JgWrhcsF", "MMfFFhFp"};
        EXPECT_EQ(rucksack::splitCompartments("vJrwpWtwJgWrhcsFMMfFFhFp", 3), expected);
    }
    {
        std::vector<std::string> expected {"vJrwpW", "twJgWr", "hcsFMM", "fFFhFp"};
        EXPECT_EQ(rucksack::splitCompartments("vJrwpWtwJgWrhcsFMMfFFhFp", 4), expected);
    }
}

TEST(Day3Tests, CompareSubstrings)
{
    EXPECT_EQ(rucksack::findCommonItems(std::vector<std::string> {"vJrwpWtwJgWr", "hcsFMMfFFhFp"}), 'p');
    EXPECT_EQ(rucksack::findCommonItems(std::vector<std::string> {"jqHRNqRjqzjGDLGL", "rsFMfFZSrLrFZsSL"}), 'L');
    EXPECT_EQ(rucksack::findCommonItems(std::vector<std::string> {"abcde", "defgh"}), 'd');
}

TEST(Day3Tests, ConvertCharToPriority)
{
    EXPECT_EQ(rucksack::calculatePriority('p'), 16);
    EXPECT_EQ(rucksack::calculatePriority('L'), 38);
    EXPECT_EQ(rucksack::calculatePriority('P'), 42);
    EXPECT_EQ(rucksack::calculatePriority('v'), 22);
    EXPECT_EQ(rucksack::calculatePriority('t'), 20);
    EXPECT_EQ(rucksack::calculatePriority('s'), 19);
    EXPECT_THROW(rucksack::calculatePriority('!'), std::logic_error);
}