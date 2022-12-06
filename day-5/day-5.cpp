#include "day-5.hpp"
#include <regex>
#include "utils/input_parser.hpp"

namespace supply
{

Configuration parseStartingConfiguration(std::vector<std::string> const& configStr)
{
    auto numberLine = configStr.back();
    auto numStacks  = numberLine.at(numberLine.find_last_of("0123456789")) - '0';

    // Parsing configuration
    std::size_t startLocation = 1;
    std::size_t gap           = 4;

    std::vector<std::deque<char>> config(numStacks);

    for(auto it = configStr.cbegin(); it != std::prev(configStr.cend()); ++it)
    {
        auto& line = *it;
        for(auto i = startLocation; i < line.size(); i += gap)
        {
            if(line.at(i) != ' ')
            {
                std::size_t stack_id = (i - startLocation) / gap;
                config.at(stack_id).push_front(line.at(i));
            }
        }
    }

    Configuration result;
    for(const auto& elem : config)
    {
        result.emplace_back(std::stack<char>(elem));
    }

    return result;
}

std::vector<Instruction> parseInstructions(std::vector<std::string> const& instructionsStr)
{
    std::vector<Instruction> result;
    std::regex               reg {"move (\\d) from (\\d) to (\\d)"};

    std::transform(
        instructionsStr.begin(), instructionsStr.end(), std::back_inserter(result), [&reg](std::string const& str) {
            std::smatch matches;
            if(!std::regex_match(str, matches, reg))
            {
                throw std::logic_error("Inputs not of expected form!");
            }
            if(matches.size() != 4)
            {
                throw std::logic_error("More than 3 matches!");
            }
            return Instruction {
                std::stoul(matches[1].str()),
                std::stoul(matches[2].str()),
                std::stoul(matches[3].str()),
            };
        });

    return result;
}

std::pair<Configuration, std::vector<Instruction>> parseInputs(std::istream& stream)
{
    auto vecOfStrings = utils::parsing::parseNewLineSeparatedInputs(stream);

    auto startingConfigs = parseStartingConfiguration(vecOfStrings.at(0));
    auto instructions    = parseInstructions(vecOfStrings.at(1));

    return {(std::move(startingConfigs)), std::move(instructions)};
}
}  // namespace supply
