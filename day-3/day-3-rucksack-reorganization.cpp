#include "day-3-rucksack-reorganization.hpp"
#include <functional>
#include "utils/input_parser.hpp"

namespace rucksack
{
std::vector<std::string> parseInputs(std::istream& stream)
{
    return utils::parsing::parseSingleLineInputsToType<std::string>(stream, [](const auto& str) { return str; });
}

}  // namespace rucksack