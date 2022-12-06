#ifndef DAY_5_SUPPLY_STACKS_HPP
#define DAY_5_SUPPLY_STACKS_HPP

#include <istream>
#include <stack>
#include <vector>

namespace supply
{
using Configuration = std::vector<std::stack<char>>;

Configuration parseStartingConfiguration(std::vector<std::string> const& configStr);

struct Instruction
{
    std::size_t numberOfCrates;
    std::size_t source;
    std::size_t dest;
};

std::vector<Instruction> parseInstructions(std::vector<std::string> const& instructionsStr);

std::pair<Configuration, std::vector<Instruction>> parseInputs(std::istream& stream);


}  // namespace supply

#endif  // DAY_5_SUPPLY_STACKS_HPP
