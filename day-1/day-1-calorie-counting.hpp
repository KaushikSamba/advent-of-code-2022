#include <istream>
#include <vector>

namespace calories
{
using CaloriesCarried = std::vector<int>;
using CaloriesPerElf  = std::vector<CaloriesCarried>;

CaloriesPerElf parseInputs(std::istream& stream);

int findMaxCalories(CaloriesPerElf const& cals);

int findTop3Sum(CaloriesPerElf const& cals);

}  // namespace calories