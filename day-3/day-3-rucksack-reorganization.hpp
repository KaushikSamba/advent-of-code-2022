#ifndef DAY_3_RUCKSACK_REORGANIZATION_HPP
#define DAY_3_RUCKSACK_REORGANIZATION_HPP

#include <string>
#include <vector>

namespace rucksack
{
std::vector<std::string> parseInputs(std::istream& stream);

std::vector<std::string> splitCompartments(std::string const& contents, std::size_t numParts);

char findCommonItems(std::vector<std::string> const& compartments);

unsigned int calculatePriority(char ch);

unsigned int processOneRucksack(std::string const& rucksackContents);

unsigned int processAllRucksacks(std::vector<std::string> const& rucksacks);
}  // namespace rucksack

#endif  // DAY_3_RUCKSACK_REORGANIZATION_HPP