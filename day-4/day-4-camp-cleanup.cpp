#include "day-4-camp-cleanup.hpp"
#include <regex>
#include <sstream>
#include "utils/input_parser.hpp"

namespace cleanup
{

Assignment getAssignmentFromString(std::string const& str)
{
    std::regex  regex {"(\\d+)-(\\d+),(\\d+)-(\\d+)"};
    std::smatch matches;

    if(!std::regex_match(str, matches, regex))
    {
        throw std::logic_error("Inputs are not of the expected form!");
    }
    else
    {
        if(matches.size() != 5)
        {
            throw std::logic_error("4 numbers not in this string! Actual size = " + std::to_string(matches.size()));
        }

        return std::make_pair(Range {std::stoi(matches[1].str()), std::stoi(matches[2].str())},
                              Range {std::stoi(matches[3].str()), std::stoi(matches[4].str())});
    }
}

std::vector<Assignment> parseInputs(std::istream& stream)
{
    return utils::parsing::parseSingleLineInputsToType<Assignment>(
        stream, [](std::string const& str) { return getAssignmentFromString(str); });
}

bool checkContainment(Assignment const& ass)
{
    if(ass.first.start <= ass.second.start)
    {
        return (ass.first.end >= ass.second.end);
    }
    else
    {
        return (ass.first.end <= ass.second.end);
    }
}
}  // namespace cleanup
