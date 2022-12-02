#include "day-2-rock-paper-scissors.hpp"
#include <sstream>
#include "constants.hpp"
#include "utils/input_parser.hpp"

namespace strategy
{
AllRoundChoices parseInputs(std::istream& stream)
{
    auto func = [](std::string const& line) {
        std::stringstream sub_ss {line};
        auto              vec = utils::parsing::parseSpaceSeparatedLine<char>(sub_ss);

        return std::make_pair(constants::CHAR_TO_CHOICE.at(vec.at(0)), constants::CHAR_TO_CHOICE.at(vec.at(1)));
    };

    return utils::parsing::parseSingleLineInputsToType<RoundChoices>(stream, func);
}
}  // namespace strategy