#include "day-1-calorie-counting.hpp"
#include <numeric>
#include "input_parser.hpp"

namespace calories
{

CaloriesPerElf parseInputs(std::istream& stream)
{
    CaloriesPerElf parsed = utils::parsing::parseNewLineSeparatedInputsToType<int>(
        stream, [](std::string const& str) { return std::stoi(str); });

    return parsed;
}

std::vector<int> getSummedCalories(CaloriesPerElf const& cals)
{
    std::vector<int> summedCals;
    summedCals.reserve(cals.size());
    std::transform(cals.begin(), cals.end(), std::back_inserter(summedCals), [](CaloriesCarried const& vec) {
        return std::accumulate(vec.begin(), vec.end(), 0);
    });

    return summedCals;
}

int findMaxCalories(CaloriesPerElf const& cals)
{
    auto summedCals    = getSummedCalories(cals);
    auto max_elem_iter = std::max_element(summedCals.begin(), summedCals.end());

    return *max_elem_iter;
}

int findTop3Sum(CaloriesPerElf const& cals)
{
    auto summedCals = getSummedCalories(cals);
    std::sort(summedCals.begin(), summedCals.end(), std::greater<int>());
    return std::accumulate(summedCals.begin(), summedCals.begin() + 3, 0);
}

}  // namespace calories