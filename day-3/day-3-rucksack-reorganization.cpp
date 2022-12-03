#include "day-3-rucksack-reorganization.hpp"
#include <functional>
#include "utils/input_parser.hpp"

namespace rucksack
{
std::vector<std::string> parseInputs(std::istream& stream)
{
    return utils::parsing::parseSingleLineInputsToType<std::string>(stream, [](const auto& str) { return str; });
}

std::vector<std::string> splitCompartments(std::string const& contents, std::size_t numParts)
{
    auto                     size      = contents.size();
    std::size_t              splitSize = size / numParts;
    std::vector<std::string> splits;

    for(std::size_t i = 0; i < size; i += splitSize)
    {
        splits.push_back(contents.substr(i, splitSize));
    }
    return splits;
}
}  // namespace rucksack