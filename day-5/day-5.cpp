#include "day-5.hpp"
#include "utils/input_parser.hpp"

namespace supply
{
int parseInputs(std::istream& stream)
{
    auto parsed = utils::parsing::parseNewLineSeparatedInputsToType<std::string>(
        stream, [](std::string const& str) { return str; });

    auto startingConfiguration = parsed.at(0);
    auto numberLine            = startingConfiguration.back();

    return (numberLine.at(numberLine.find_last_of("0123456789")) - '0');
}
}  // namespace supply
