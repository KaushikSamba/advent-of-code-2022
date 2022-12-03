#include "day-3-rucksack-reorganization.hpp"
#include <cctype>
#include <functional>
#include <numeric>
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

char findCommonItems(std::vector<std::string> const& compartments)
{
    std::string intersection = compartments.at(0);
    std::sort(intersection.begin(), intersection.end());

    std::for_each(compartments.begin() + 1, compartments.end(), [&intersection](std::string str) {
        std::sort(str.begin(), str.end());
        std::string result;
        std::set_intersection(
            str.begin(), str.end(), intersection.begin(), intersection.end(), std::back_inserter(result));
        intersection = result;
    });
    auto last = std::unique(intersection.begin(), intersection.end());
    if(std::distance(intersection.begin(), last) > 1)
    {
        throw std::runtime_error("More than one common letter!");
    }

    return intersection.at(0);
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

unsigned int processOneRucksack(std::string const& rucksackContents)
{
    auto pieces = splitCompartments(rucksackContents, 2);
    auto item   = findCommonItems(pieces);
    return calculatePriority(item);
}

unsigned int processAllRucksacks(std::vector<std::string> const& rucksacks)
{
    return std::accumulate(
        rucksacks.begin(), rucksacks.end(), 0, [](unsigned int val, std::string const& rucksackContents) {
            return (val + processOneRucksack(rucksackContents));
        });
}

}  // namespace rucksack