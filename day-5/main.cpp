#include <iostream>
#include "day-5.hpp"
#include "utils/filehandler.hpp"

int main()
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/input"};
    auto [config, instructions] = supply::parseInputs(inputFile);
    supply::processAllInstructions(config, instructions);
    auto part1result = supply::getTopsOfStacks(config);

    std::cout << "Result for part 1 = " << part1result << std::endl;
    std::cout << "Result for part 2 = " << std::endl;
}