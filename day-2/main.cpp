#include <iostream>
#include "day-2-rock-paper-scissors.hpp"
#include "utils/filehandler.hpp"

int main()
{
    utils::FileHandler inputFile {CURRENT_SOURCE_DIR "/input"};

    auto parsedInputs = strategy::parseInputs(inputFile);

    auto part1_result = strategy::calculateScoreForAllRounds(parsedInputs, &strategy::getScoreForRoundChoices);
    std::cout << "Result for part 1 = " << part1_result << std::endl;

    auto part2_result = strategy::calculateScoreForAllRounds(parsedInputs, &strategy::getScoreForRoundChoiceAndOutcome);
    std::cout << "Result for part 2 = " << part2_result << std::endl;
}