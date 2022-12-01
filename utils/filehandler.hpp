// This file holds a file handler object that abstracts away the opening and
// closing of the file stream.

// Interesting C++ things I've done:
//    - Needed to overload the >> operator so that the file is entirely handled
//    by the RAII object and not by the user.
//    - Template function for the operator overload so that it is compatible
//    with any data type that is to be read.
//    - Include guards. These protect against re-inclusion of the header file.
//    - Custom function that handles CSV files.

#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <fstream>
#include <iostream>
#include <vector>

namespace utils
{

class FileHandler : public std::ifstream
{
public:
    explicit FileHandler(std::string filePath);
    ~FileHandler();
};

}  // namespace utils

#endif  // FILEHANDLER_HPP
