#include "input_parser.hpp"

namespace utils
{
namespace parsing
{
std::vector<std::vector<std::string>> parseNewLineSeparatedInputs(std::istream& stream)
{
    return parseNewLineSeparatedInputsToType<std::string>(stream, [](std::string const& str) { return str; });
}
}  // namespace parsing
}  // namespace utils