#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>


struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};


void saveToFile(const std::string& filename, const std::vector<Book>& data)
{
    std::ofstream file(filename);
    if (file.is_open() )
    {
        for (const auto& book : data)
        {
            file << book.Author << "," << book.Title << "," << book.Year << "\n";
        }
        file.close();
    }
    else
    {
        std::cout << "Error happened!" << std::endl;
    }
}


void loadFromFile(const std::string& filename, std::vector<Book>& outData)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        Book temp;
        std::string author, title, yearStr;

        if (std::getline(ss, author, ',') &&
            std::getline(ss, title, ',') &&
            std::getline(ss, yearStr))
        {
            temp.Author = author;
            temp.Title = title;
            temp.Year = std::stoi(yearStr);
            outData.push_back(temp);
        }
    }
    file.close();
}