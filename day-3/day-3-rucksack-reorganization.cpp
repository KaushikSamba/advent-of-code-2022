#include "day-3-rucksack-reorganization.hpp"
#include <cctype>
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

char findCommonItems(std::vector<std::string> compartments)
{
    if(compartments.size() > 2)
    {
        throw std::logic_error("Should only be 2 compartments!");
    }

    auto pos = compartments.at(0).find_first_of(compartments.at(1));

    return compartments.at(0).at(pos);
}

unsigned int calculatePriority(char ch)
{
    if(std::islower(ch))
    {
        return ch - 'a' + 1;
    }
    else if(std::isupper(ch))
    {
        return ch - 'A' + 27;
    }
    else
    {
        throw std::logic_error("Should not be expecting a non-alphabet char");
    }
}
}  // namespace rucksack