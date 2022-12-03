#ifndef DAY_3_RUCKSACK_REORGANIZATION_HPP
#define DAY_3_RUCKSACK_REORGANIZATION_HPP

#include <string>
#include <vector>

namespace rucksack
{
std::vector<std::string> parseInputs(std::istream& stream);

std::vector<std::string> splitCompartments(std::string const& contents, std::size_t numParts);
}  // namespace rucksack

#endif  // DAY_3_RUCKSACK_REORGANIZATION_HPP