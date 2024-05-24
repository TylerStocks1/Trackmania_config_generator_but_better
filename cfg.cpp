#include <iostream>
#include <limits>
#include <filesystem>

#include <fstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

std::vector<std::string> getGBXFiles(const std::string& path) //function is a vector that holds strings which will be our paths.
{
    std::vector<std::string> gbxFiles;
    for (auto& entry : fs::directory_iterator(path)) // this iterates over all files in the dir specified by the path we give in the main function.
    {
        if(entry.path().extension() == ".gbx")  //checking to see if the extension is gbx
        {
            gbxFiles.push_back(entry.path().string()); //adding it to the vector gbxfiles
        }
    }

    return gbxFiles;
}


int main()
{
    char responce;

    std::cout << "Set path?  y/N \n";
    responce = std::cin.get();

    if(responce == '\n')
    {
        responce = 'N';
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (responce == 'y' || responce == 'Y')
    {
        std::string path;
        std::cout << "Enter the path: ";
        std::cin >> path;

    }
     else
    {
        std::cout << "Path set to current working directory. \n";
        std::string path = std::filesystem::current_path().string();
        std::cout << "Path set to current working directory: " << path << '\n';


    }
    return 0;
}