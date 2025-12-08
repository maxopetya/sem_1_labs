#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Узел списка
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Переменные для списка
Node* head = nullptr;
Node* tail = nullptr;
int listType = 0;

// Функция для создания узла
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Функция добавления элемента в список
void addElement(int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        // Список пустой
        head = newNode;
        tail = newNode;

        // Если список кольцевой, замыкаем
        if (listType == 3 || listType == 4) {
            newNode->next = head;
            if (listType == 4) {
                newNode->prev = head;
            }
        }
    } else {
        // Добавляем в конец
        if (listType == 1) {
            // Однонаправленный
            tail->next = newNode;
            tail = newNode;
        }
        else if (listType == 2) {
            // Двунаправленный
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else if (listType == 3) {
            // Однонаправленный кольцевой
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
        else if (listType == 4) {
            // Двунаправленный кольцевой
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }
}

// Функция вывода списка
void printList() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    // Выводим тип списка
    if (listType == 1) cout << "> ";
    else if (listType == 2) cout << "<> ";
    else if (listType == 3) cout << ">0 ";
    else if (listType == 4) cout << "<>0 ";

    Node* current = head;

    // Проходим по списку и выводим элементы
    if (listType == 1 || listType == 2) {
        // Не кольцевые списки
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " ";
            }
            current = current->next;
        }
    } else {
        // Кольцевые списки
        do {
            cout << current->data;
            current = current->next;
            if (current != head) {
                cout << " ";
            }
        } while (current != head);
    }

    cout << endl;
}

// Функция поиска элемента
void findElement(int value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    vector<int> positions;
    int pos = 0;
    Node* current = head;

    // Проходим по списку
    if (listType == 1 || listType == 2) {
        // Не кольцевые списки
        while (current != nullptr) {
            if (current->data == value) {
                positions.push_back(pos);
            }
            pos++;
            current = current->next;
        }
    } else {
        // Кольцевые списки
        do {
            if (current->data == value) {
                positions.push_back(pos);
            }
            pos++;
            current = current->next;
        } while (current != head);
    }

    // Выводим результаты
    if (positions.empty()) {
        cout << "Element " << value << " not found!" << endl;
    } else {
        cout << "Element " << value << " found at positions: ";
        for (int i = 0; i < positions.size(); i++) {
            cout << positions[i];
            if (i < positions.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

// Функция удаления элемента (первого вхождения)
bool deleteFirst(int value) {
    if (head == nullptr) return false;

    Node* current = head;

    // Ищем элемент для удаления
    if (listType == 1 || listType == 2) {
        // Не кольцевые списки
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data == value) {
                // Нашли элемент для удаления
                if (prev == nullptr) {
                    // Удаляем первый элемент
                    head = current->next;
                    if (head != nullptr && listType == 2) {
                        head->prev = nullptr;
                    }
                    if (current == tail) {
                        tail = nullptr;
                    }
                } else {
                    // Удаляем элемент из середины или конца
                    prev->next = current->next;
                    if (current == tail) {
                        tail = prev;
                    }
                    if (current->next != nullptr && listType == 2) {
                        current->next->prev = prev;
                    }
                }

                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
    } else {
        // Кольцевые списки
        Node* prev = (listType == 4) ? tail : nullptr;

        // Для однонаправленного кольцевого нужно найти предыдущий
        if (listType == 3) {
            Node* temp = head;
            while (temp->next != head) {
                if (temp->next->data == value) {
                    prev = temp;
                    current = temp->next;
                    break;
                }
                temp = temp->next;
            }
        }

        do {
            if (current->data == value) {
                // Нашли элемент для удаления
                if (current == head && current == tail) {
                    // Единственный элемент
                    head = tail = nullptr;
                } else if (current == head) {
                    // Удаляем первый элемент
                    head = head->next;
                    tail->next = head;
                    if (listType == 4) {
                        head->prev = tail;
                    }
                } else if (current == tail) {
                    // Удаляем последний элемент
                    tail = (listType == 4) ? current->prev : prev;
                    tail->next = head;
                    if (listType == 4) {
                        head->prev = tail;
                    }
                } else {
                    // Удаляем элемент из середины
                    if (listType == 4) {
                        current->prev->next = current->next;
                        current->next->prev = current->prev;
                    } else {
                        prev->next = current->next;
                    }
                }

                delete current;
                return true;
            }

            if (listType == 4) {
                prev = current;
                current = current->next;
            } else {
                prev = current;
                current = current->next;
            }
        } while (current != head);
    }

    return false;
}

// Функция удаления всех вхождений элемента
void deleteAll(int value) {
    bool deleted = false;
    while (deleteFirst(value)) {
        deleted = true;
    }

    if (deleted) {
        cout << "All occurrences of " << value << " deleted!" << endl;
    } else {
        cout << "Element " << value << " not found!" << endl;
    }
}

// Функция очистки списка
void clearList() {
    if (head == nullptr) {
        cout << "List is already empty!" << endl;
        return;
    }

    Node* current = head;

    // Разрываем кольцо для кольцевых списков
    if (listType == 3 || listType == 4) {
        tail->next = nullptr;
    }

    // Удаляем все элементы
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    cout << "List cleared!" << endl;
}

// Функция записи в файл
void writeToFile(string filename) {
    if (head == nullptr) {
        cout << "Cannot write empty list to file!" << endl;
        return;
    }

    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        return;
    }

    // Записываем тип списка
    if (listType == 1) file << ">" << endl;
    else if (listType == 2) file << "<>" << endl;
    else if (listType == 3) file << ">0" << endl;
    else if (listType == 4) file << "<>0" << endl;

    // Записываем элементы
    Node* current = head;

    if (listType == 1 || listType == 2) {
        // Не кольцевые списки
        while (current != nullptr) {
            file << current->data << endl;
            current = current->next;
        }
    } else {
        // Кольцевые списки
        do {
            file << current->data << endl;
            current = current->next;
        } while (current != head);
    }

    file.close();
    cout << "List saved to file: " << filename << endl;
}

// Функция чтения из файла
void readFromFile(string filename) {
    if (head != nullptr) {
        cout << "Error: List is not empty! Clear it first." << endl;
        return;
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        return;
    }

    string line;

    // Читаем тип списка
    if (!getline(file, line)) {
        cout << "File is empty!" << endl;
        return;
    }

    // Определяем тип списка из файла
    if (line == ">") listType = 1;
    else if (line == "<>") listType = 2;
    else if (line == ">0") listType = 3;
    else if (line == "<>0") listType = 4;
    else {
        cout << "Invalid file format!" << endl;
        return;
    }

    // Читаем элементы
    while (getline(file, line)) {
        if (!line.empty()) {
            try {
                int value = stoi(line);
                addElement(value);
            } catch (...) {
                cout << "Error reading value: " << line << endl;
            }
        }
    }

    file.close();
    cout << "List loaded from file: " << filename << endl;
}

// Главное меню
void showMenu() {
    int choice;

    do {
        cout << "\n=== LINKED LIST MENU ===" << endl;
        cout << "1. Add element" << endl;
        cout << "2. Print list" << endl;
        cout << "3. Find element" << endl;
        cout << "4. Delete element (first)" << endl;
        cout << "5. Delete element (all)" << endl;
        cout << "6. Clear list" << endl;
        cout << "7. Save to file" << endl;
        cout << "8. Load from file" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            addElement(value);
            cout << "Element added!" << endl;
        }
        else if (choice == 2) {
            printList();
        }
        else if (choice == 3) {
            int value;
            cout << "Enter value to find: ";
            cin >> value;
            findElement(value);
        }
        else if (choice == 4) {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            if (deleteFirst(value)) {
                cout << "Element deleted!" << endl;
            } else {
                cout << "Element not found!" << endl;
            }
        }
        else if (choice == 5) {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            deleteAll(value);
        }
        else if (choice == 6) {
            clearList();
        }
        else if (choice == 7) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            writeToFile(filename);
        }
        else if (choice == 8) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            readFromFile(filename);
        }
        else if (choice == 0) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}

// Обработка аргументов командной строки
bool processArguments(int argc, char* argv[]) {
    // Проверяем минимальное количество аргументов
    if (argc < 7) {
        cout << "Usage: program -t <type> -c <count> -e <elements>" << endl;
        cout << "Type: 1-4 (1: singly, 2: doubly, 3: circular singly, 4: circular doubly)" << endl;
        cout << "Example: program -t 1 -c 3 -e 10,20,30" << endl;
        return false;
    }

    // Парсим аргументы
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];

        if (arg == "-t" && i + 1 < argc) {
            // Тип списка
            listType = atoi(argv[i + 1]);
            if (listType < 1 || listType > 4) {
                cout << "Error: Type must be 1-4" << endl;
                return false;
            }
            i++;
        }
        else if (arg == "-c" && i + 1 < argc) {
            // Количество элементов
            int count = atoi(argv[i + 1]);
            if (count < 0) {
                cout << "Error: Count cannot be negative" << endl;
                return false;
            }
            i++;
        }
        else if (arg == "-e" && i + 1 < argc) {
            // Элементы списка
            string elementsStr = argv[i + 1];
            stringstream ss(elementsStr);
            string item;
            vector<int> elements;

            // Разделяем элементы по запятой
            while (getline(ss, item, ',')) {
                try {
                    elements.push_back(stoi(item));
                } catch (...) {
                    cout << "Error: Invalid element: " << item << endl;
                    return false;
                }
            }

            // Добавляем элементы в список
            for (int elem : elements) {
                addElement(elem);
            }
            i++;
        }
        else {
            cout << "Error: Unknown argument: " << arg << endl;
            return false;
        }
    }

    return true;
}

// Главная функция
int main(int argc, char* argv[]) {
    cout << "Linked List Program" << endl;

    // Обрабатываем аргументы командной строки
    if (argc > 1) {
        if (!processArguments(argc, argv)) {
            return 1;
        }
    }

    // Запускаем меню
    showMenu();

    // Очищаем память перед выходом
    clearList();

    return 0;
}