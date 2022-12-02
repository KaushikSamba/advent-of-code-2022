#include <functional>
#include <istream>
#include <vector>

namespace utils
{
namespace parsing
{
template<typename T> std::vector<T> parseCommaSeparatedLine(std::istream& stream)
{
    std::vector<T> array;
    // For files with commas, the >> operator casts commas to integers and
    // generally makes a mess of the whole thing. It's better to have a custom
    // function that handles this case and pushes the relevant data into a
    // vector.
    T    data;
    char ch;
    while(stream >> data >> ch && ch == ',')
    {
        array.push_back(data);
    }
    // The last value does not have a comma after it, and so it is not read in
    // by the above loop.
    stream >> data;
    array.push_back(data);
    return array;
}

template<typename T> std::vector<T> parseSpaceSeparatedLine(std::istream& stream)
{
    std::vector<T> outputVector;
    T              value;
    while(stream >> value)
    {
        outputVector.push_back(value);
    }
    return outputVector;
}

std::vector<std::vector<std::string>> parseNewLineSeparatedInputs(std::istream& stream);

/*!
 * @brief Parses inputs where multiple lines constitute one entry, separated by a blank line.
 */
template<typename T>
std::vector<std::vector<T>> parseNewLineSeparatedInputsToType(std::istream&                        stream,
                                                              std::function<T(std::string const&)> transformationFunc)
{
    std::string                 line;
    std::vector<T>              input;
    std::vector<std::vector<T>> inputNewLineSeparated;
    while(std::getline(stream, line, '\n'))
    {
        if(line.empty())
        {
            // std::cout << "Encountered empty line!\n";
            if(!input.empty())
            {
                inputNewLineSeparated.push_back(input);
                input.clear();
            }
        }
        else
        {
            input.push_back(transformationFunc(line));
            // std::cout << "Pushed line: " << line << '\n';
        }
    }
    if(!input.empty())  // If the last block does not have a trailing new line.
    {
        inputNewLineSeparated.push_back(input);
    }
    return inputNewLineSeparated;
}

template<typename T>
std::vector<T> parseSingleLineInputsToType(std::istream&                        stream,
                                           std::function<T(std::string const&)> transformationFunc)
{
    std::string    line;
    std::vector<T> parsed;
    while(std::getline(stream, line, '\n'))
    {
        if(line.empty())
        {
            continue;
        }
        parsed.push_back(transformationFunc(line));
    }
    return parsed;
}

}  // namespace parsing
}  // namespace utils