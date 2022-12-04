#ifndef DAY_4_CAMP_CLEANUP_HPP
#define DAY_4_CAMP_CLEANUP_HPP

#include <functional>
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

bool checkContainment(Assignment const& ass);
bool checkAnyOverlap(Assignment const& ass);

unsigned int processAllAssignments(std::vector<Assignment> const&         assignments,
                                   std::function<bool(Assignment const&)> func);

}  // namespace cleanup

#endif  // DAY_4_CAMP_CLEANUP_HPP