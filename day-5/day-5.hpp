#ifndef DAY_5_SUPPLY_STACKS_HPP
#define DAY_5_SUPPLY_STACKS_HPP

#include <istream>
#include <stack>
#include <vector>

namespace supply
{
std::vector<std::stack<char>> parseStartingConfiguration(std::vector<std::string> const& configStr);

}  // namespace supply

#endif  // DAY_5_SUPPLY_STACKS_HPP
