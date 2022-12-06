#include <iostream>
#include "day-5.hpp"
#include "utils/filehandler.hpp"

int main()
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/input"};

    std::string part1result, part2result;
    {
        auto [config, instructions] = supply::parseInputs(inputFile);
        supply::processAllInstructions(config, instructions, &supply::processInstruction);
        part1result = supply::getTopsOfStacks(config);
    }

    {
        auto [config, instructions] = supply::parseInputs(inputFile);
        supply::processAllInstructions(config, instructions, &supply::processInstructionBigCrane);
        part2result = supply::getTopsOfStacks(config);
    }

    std::cout << "Result for part 1 = " << part1result << std::endl;
    std::cout << "Result for part 2 = " << part2result << std::endl;
}