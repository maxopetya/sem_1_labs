#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

using Groups = std::map<std::string, std::vector<Student>>;

void saveToFile(const std::string& filename, const Groups& groups)
{
    std::ofstream file(filename);
    if (file.is_open() )
    {
        for (const auto& group : groups)
        {
            file << "[G]" << "\n";
            file << group.first << "\n";
            for (const auto& student : group.second)
            {
                file << "[S]" << "\n";
                file << student.Name << "\n";
                file << student.Year << "\n";
                for (auto it = student.RecordBook.begin(); it != student.RecordBook.end(); ++it)
                {
                    file << it->first << ":" << it->second;
                    if (std::next(it) != student.RecordBook.end() )
                    {
                        file << ",";
                    }
                }
                file << "\n";
                file << "[s]" << "\n";
            }
            file << "[g]" << "\n";
        }
    }
    else
    {
        std::cout << "Error happened!" << std::endl;
    }
}

void loadFromFile(const std::string& filename, Groups& outGroups)
{
    std::ifstream file(filename);
    std::string line, currentGroup;
    Student student;

    while (std::getline(file, line))
    {
        if (line == "[G]") std::getline(file, currentGroup);
        else if (line == "[S]")
        {
            student = Student();
            std::getline(file, student.Name);
            std::getline(file, line); student.Year = std::stoi(line);
            std::getline(file, line);
            std::stringstream ss(line);
            std::string item;
            while (std::getline(ss, item, ',')) {
                int pos = item.find(':');
                student.RecordBook[item.substr(0, pos)] = static_cast<Score>(std::stoi(item.substr(pos + 1)));
            }
        }
        else if (line == "[s]") outGroups[currentGroup].push_back(student);
    }
}
