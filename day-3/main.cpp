#include <iostream>
#include "day-3-rucksack-reorganization.hpp"
#include "utils/filehandler.hpp"

int main()
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/input"};

    auto parsed = rucksack::parseInputs(inputFile);

    std::cout << "Result for part 1 = " << rucksack::processAllRucksacks(parsed) << std::endl;
    std::cout << "Result for part 2 = " << std::endl;
}