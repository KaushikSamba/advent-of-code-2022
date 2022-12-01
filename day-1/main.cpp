#include <fstream>
#include <iostream>
#include "day-1-calorie-counting.hpp"

int main()
{
    std::ifstream inputFile {CURRENT_SOURCE_DIR "/input-part-1"};
    auto          parsedInputs = calories::parseInputs(inputFile);

    auto result_part1 = calories::findMaxCalories(parsedInputs);
    std::cout << "Part 1 result: " << result_part1 << std::endl;

    auto result_part2 = calories::findTop3Sum(parsedInputs);
    std::cout << "Part 2 result: " << result_part2 << std::endl;

    inputFile.close();

    return 0;
}