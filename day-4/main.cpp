#include <iostream>
#include "day-4-camp-cleanup.hpp"
#include "utils/filehandler.hpp"

int main()
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/input"};
    auto               parsed = cleanup::parseInputs(inputFile);

    std::cout << "Result for part 1 = " << cleanup::processAllAssignments(parsed, &cleanup::checkContainment)
              << std::endl;
    std::cout << "Result for part 2 = " << cleanup::processAllAssignments(parsed, &cleanup::checkAnyOverlap)
              << std::endl;
}