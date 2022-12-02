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

        return std::make_pair(vec.at(0), vec.at(1));
    };

    return utils::parsing::parseSingleLineInputsToType<RoundChoices>(stream, func);
}

unsigned int getScoreForRoundChoices(RoundChoices const& roundChoices)
{
    static const std::array<RoundChoices, 3> WINNING_PAIRS {
        std::make_pair('A', 'Y'),  // Rock is beaten by paper
        std::make_pair('B', 'Z'),  // Paper is beaten by scissors
        std::make_pair('C', 'X'),  // Scissors is beaten by rock
    };

    Score score;
    if(std::find(WINNING_PAIRS.begin(), WINNING_PAIRS.end(), roundChoices) != WINNING_PAIRS.end())
    {
        score = Score::WIN;
    }
    else if(roundChoices.first == (roundChoices.second - ('X' - 'A')))  // Both players played the same thing
    {
        score = Score::DRAW;
    }
    else
    {
        score = Score::LOSS;
    }

    unsigned int choiceScore = roundChoices.second - 'X' + 1;  // Score based on the option I played.

    return (static_cast<std::underlying_type_t<Score>>(score) + choiceScore);
}

unsigned int calculateScoreForAllRounds(AllRoundChoices const&                                  allChoices,
                                        std::function<unsigned int(RoundChoices const&)> const& scoringFunc)
{
    // This doesn't work with the version of gcc I'm running.
    // TODO: Make a Docker container with the latest version of gcc so that I can play with the latest algorithms.
    // std::transform_reduce(allChoices.begin(), allChoices.end(), 0, std::plus(), getScoreForRoundChoices);

    return std::accumulate(
        allChoices.begin(),
        allChoices.end(),
        0,
        [&scoringFunc](unsigned int const& a, strategy::RoundChoices const& b) { return (a + scoringFunc(b)); });
}

unsigned int getScoreForRoundChoiceAndOutcome(RoundChoices const& roundChoices)
{
    Score score;
    switch(roundChoices.second)
    {
    case 'X':
        score = Score::LOSS;
        break;
    case 'Y':
        score = Score::DRAW;
        break;
    case 'Z':
        score = Score::WIN;
        break;
    }

    static const std::map<std::pair<char, Score>, char> combinations {
        {std::make_pair('A', Score::WIN), 'Y'},
        {std::make_pair('A', Score::DRAW), 'X'},
        {std::make_pair('A', Score::LOSS), 'Z'},
        {std::make_pair('B', Score::WIN), 'Z'},
        {std::make_pair('B', Score::DRAW), 'Y'},
        {std::make_pair('B', Score::LOSS), 'X'},
        {std::make_pair('C', Score::WIN), 'X'},
        {std::make_pair('C', Score::DRAW), 'Z'},
        {std::make_pair('C', Score::LOSS), 'Y'},
    };

    unsigned int choiceScore = combinations.at(std::make_pair(roundChoices.first, score)) - 'X' + 1;

    return (static_cast<std::underlying_type_t<Score>>(score) + choiceScore);
}

}  // namespace strategy