#ifndef DAY_5_SUPPLY_STACKS_HPP
#define DAY_5_SUPPLY_STACKS_HPP

#include <functional>
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

void processInstruction(Configuration& config, Instruction const& instr);
void processInstructionBigCrane(Configuration& config, Instruction const& instr);

void processAllInstructions(Configuration&                  config,
                            std::vector<Instruction> const& instructions,
                            std::function<void(supply::Configuration& config, const supply::Instruction& instr)> func);

std::string getTopsOfStacks(Configuration const& config);
}  // namespace supply

#endif  // DAY_5_SUPPLY_STACKS_HPP
