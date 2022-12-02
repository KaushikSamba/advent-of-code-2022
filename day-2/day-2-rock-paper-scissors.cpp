#include "day-2-rock-paper-scissors.hpp"
#include <numeric>
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

unsigned int getScoreForRoundChoices(RoundChoices const& roundChoices)
{
    Score score;
    if(std::find(constants::WINNING_PAIRS.begin(), constants::WINNING_PAIRS.end(), roundChoices) !=
       constants::WINNING_PAIRS.end())
    {
        score = Score::WIN;
    }
    else if(roundChoices.first == roundChoices.second)  // Both players played the same thing
    {
        score = Score::DRAW;
    }
    else
    {
        score = Score::LOSS;
    }
    return (static_cast<std::underlying_type_t<Score>>(score) +
            static_cast<std::underlying_type_t<Choices>>(roundChoices.second)  // The value I played.
    );
}

unsigned int calculateScoreForAllRounds(AllRoundChoices const& allChoices)
{
    // This doesn't work with the version of gcc I'm running.
    // TODO: Make a Docker container with the latest version of gcc so that I can play with the latest algorithms.
    // std::transform_reduce(allChoices.begin(), allChoices.end(), 0, std::plus(), getScoreForRoundChoices);

    return std::accumulate(
        allChoices.begin(), allChoices.end(), 0, [](unsigned int const& a, strategy::RoundChoices const& b) {
            return (a + getScoreForRoundChoices(b));
        });
}

}  // namespace strategy