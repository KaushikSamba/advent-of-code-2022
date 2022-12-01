#include "filehandler.hpp"

namespace utils
{

FileHandler::FileHandler(std::string filepath)
{
    open(filepath);
    if(!is_open())
    {
        throw std::runtime_error("Unable to open file.");
    }
}

FileHandler::~FileHandler()
{
    close();
}

}  // namespace utils