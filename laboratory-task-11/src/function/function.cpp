
#include "function.hpp"


bool IsEven(int number) {
  return number % 2 == 0;
}

bool CompareByParity(int a, int b) {
  return IsEven(a) < IsEven(b);
}

bool CompareEmployees(const Employee& a, const Employee& b) {
  if (a.surname == b.surname) {
    return a.children > b.children;
  }
  return a.surname < b.surname;
}

template <typename T>
void Sort(T* data, int size, bool (*compare)(const T&, const T&)) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (compare(data[i], data[j])) {
        std::swap(data[i], data[j]);
      }
    }
  }
}

int* ReadNumbersFromFile(const std::string& filename, int* countNumbers) {
  std::ifstream fin(filename);
  if (!fin.is_open()) {
   throw std::invalid_argument("File not opened!");
  }

  std::string line;
  getline(fin, line); // Разделители

  *countNumbers = 0;
  while (getline(fin, line)) {
    for (int i = 0; i < line.size(); i++) {
      if (isdigit(line[i])) {
        (*countNumbers)++;
      }
    }
  }

  fin.close();

  if (*countNumbers == 0) {
    throw std::invalid_argument("No Numbers in file!");
  }

  int* allNumbers = new int[*countNumbers];
  fin.open(filename);
  getline(fin, line); // Разделители

  int i = 0;
  while (getline(fin, line)) {
    for (int j = 0; j < line.size(); j++) {
      if (isdigit(line[j])) {
        allNumbers[i++] = line[j] - '0';
      }
    }
  }
  return allNumbers;
}

std::string* ReadSurnamesFromFile(const std::string& filename, int* countSurnames) {
  std::ifstream fin(filename);
  if (!fin.is_open()) {
    std::cout << "Ошибка открытия файла " << filename << std::endl;
    return nullptr;
  }

  std::string line;
  getline(fin, line); // Разделители

  *countSurnames = 0;
  while (getline(fin, line)) {
    for (int i = 0; i < line.size(); i++) {
      if (isupper(line[i])) {
        (*countSurnames)++;
      }
    }
  }

  fin.close();

  if (*countSurnames == 0) {
  throw std::invalid_argument("No surnames found!");
  }

  std::string* allSurnames = new std::string[*countSurnames];
  fin.open(filename);
  getline(fin, line); // Разделители

  int i = 0;
  while (getline(fin, line)) {
    for (int j = 0; j < line.size(); j++) {
      if (isupper(line[j])) {
        std::string surname;
        while (isupper(line[j]) || islower(line[j])) {
          surname += line[j++];
        }
        allSurnames[i++] = surname;
      }
    }
  }

  return allSurnames;
}

Employee* CreateEmployees(std::string* allSurnames, int* allNumbers, int count) {
  Employee* employees = new Employee[count];
  for (int i = 0; i < count; i++) {
    employees[i].surname = allSurnames[i];

    int children;
    if (i < count && allNumbers[i] < 10) {
      children = allNumbers[i];
    } else {
      std::cout << "Введите количество детей для " << employees[i].surname << ": ";
      std::cin >> children;
    }
    employees[i].children = children;
  }

  return employees;
}

void WriteEmployeesToFile(const std::string& filename, Employee* employees, int count) {
  std::ofstream fout(filename);
  for (int i = 0; i < count; i++) {
    fout << employees[i].surname << " " << employees[i].children << std::endl;
  }
}

void WriteEmployeesToFileBinary(const std::string& filename, Employee* employees, int count) {
  std::ofstream fout(filename, std::ios::binary);
  for (int i = 0; i < count; i++) {
    fout.write((char*)&employees[i], sizeof(employees[i]));
  }

  // Меняем местами первую и последнюю записи
  Employee temp = employees[0];
  employees[0] = employees[count - 1];
  employees[count - 1] = temp;

  fout.seekp(0);
  for (int i = 0; i < count; i++) {
    fout.write((char*)&employees[i], sizeof(employees[i]));
  }
}