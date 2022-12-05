#include "day-5.hpp"
#include "utils/input_parser.hpp"

namespace supply
{

std::vector<std::stack<char>> parseStartingConfiguration(std::vector<std::string> const& configStr)
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

    std::vector<std::stack<char>> result;
    for(const auto& elem : config)
    {
        result.emplace_back(std::stack<char>(elem));
    }

    return result;
}

}  // namespace supply
