#ifndef DAY_4_CAMP_CLEANUP_HPP
#define DAY_4_CAMP_CLEANUP_HPP

#include <istream>
#include <utility>
#include <vector>

namespace cleanup
{
struct Range
{
    int start;
    int end;

    bool operator==(Range const& other) const
    {
        return (start == other.start) and (end == other.end);
    }
};

using Assignment = std::pair<Range, Range>;

Assignment getAssignmentFromString(std::string const& str);

std::vector<Assignment> parseInputs(std::istream& stream);
}  // namespace cleanup

#endif  // DAY_4_CAMP_CLEANUP_HPP