
#include "header.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <numeric>

// Сортировка студентов по именам
void SortByName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.Name < b.Name;
              });
}

// Сортировка по убыванию средней оценки
void SortByRating(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  if (a.Ratings.empty() && b.Ratings.empty()) return false;
                  if (a.Ratings.empty()) return true;
                  if (b.Ratings.empty()) return false;

                  double avgA = std::accumulate(a.Ratings.begin(), a.Ratings.end(), 0.0) / a.Ratings.size();
                  double avgB = std::accumulate(b.Ratings.begin(), b.Ratings.end(), 0.0) / b.Ratings.size();
                  return avgA > avgB;
              });
}

// Подсчет количества студентов с неудовлетворительной оценкой хотя бы по одному предмету
size_t CountTwoness(const std::vector<Student>& students) {
    size_t count = 0;
    for (const auto& student : students) {
        bool hasBadGrade = false;
        for (unsigned rating : student.Ratings) {
            if (rating == 2) {
                hasBadGrade = true;
            }
        }
        if (hasBadGrade) {
            count++;
            break;
        }
    }
    return count;
}

// Подсчет количества студентов, сдавших все экзамены на 5
size_t CountExcellent(const std::vector<Student>& students) {
    size_t count = 0;
    for (const auto& student : students) {
        if (student.Ratings.empty()) continue;

        bool allExcellent = true;
        for (unsigned rating : student.Ratings) {
            if (rating != 5) {
                allExcellent = false;
                break;
            }
        }
        if (allExcellent) {
            count++;
        }
    }
    return count;
}

// Задание массива студентов, имеющих отметку "отлично" по предмету "Math"
std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
    std::vector<Student> result;
    for (const auto& student : students) {
        for (size_t i = 0; i < student.Subjects.size() && i < student.Ratings.size(); ++i) {
            if (student.Subjects[i] == "Math" && student.Ratings[i] == 5) {
                result.push_back(student);
                break;
            }
        }
    }
    return result;
}

// Уникальные названия групп студентов
std::vector<std::string> GroupsId(const std::vector<Student>& students) {
    std::set<std::string> uniqueGroups;
    for (const auto& student : students) {
        uniqueGroups.insert(student.GroupId);
    }
    return std::vector<std::string>(uniqueGroups.begin(), uniqueGroups.end());
}

// Список групп
std::vector<Group> Groups(const std::vector<Student>& students) {
    std::vector<Group> result;

    // Сначала получаем уникальные ID групп
    std::vector<std::string> groupIds = GroupsId(students);

    // Для каждой группы собираем студентов
    for (const auto& groupId : groupIds) {
        Group group;
        group.Id = groupId;

        for (const auto& student : students) {
            if (student.GroupId == groupId) {
                group.Students.push_back(student);
            }
        }

        result.push_back(group);
    }
    return result;
}

int main() {
    Student Student1 = {"Max", "IU8-14", {5, 5, 5}, {"PE", "Math", "Cpp"}};
    Student Student2 = {"Vadim", "IU8-14", {5, 2, 5}, {"PE", "Math", "Cpp"}};
    Student Student3 = {"Sasha", "E2-12", {3, 5, 4}, {"PE", "Math", "Cpp"}};
    std::vector<Student> students = {Student1, Student2, Student3};
    SortByName(students);
    SortByRating(students);
    CountTwoness(students);
    CountTwoness(students);
    VectorMathExcellent(students);
    Groups(students);
    Groups(students);
}

