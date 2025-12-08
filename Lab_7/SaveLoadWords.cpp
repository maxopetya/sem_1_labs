#include <string>
#include <vector>
#include <fstream>
#include <iostream>


void saveToFile(const std::string& filename, const std::vector<std::string>& data)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (const auto& word : data)
        {
            file << word << "\n";
        }
        file.close();
    }
    else
    {
        std::cout << "Error happened!" << std::endl;
    }
}


void loadFromFile(const std::string& filename, std::vector<std::string>& outData)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line) )
    {
        outData.push_back(line);
    }
}