
#include "../function/function.hpp"


int main() {

  std::string numbersPath("src/data/Numbers.txt");
  std::string stringsPath("src/data/Strings.txt");

  // Чтение чисел из файла
  int countNumbers;
  int* allNumbers = ReadNumbersFromFile(numbersPath, &countNumbers);

  // Чтение фамилий из файла
  int countSurnames;
  std::string* allSurnames = ReadSurnamesFromFile(stringsPath, &countSurnames);

  // Создание и заполнение массива структур
  Employee* employees = CreateEmployees(allSurnames, allNumbers, countSurnames);

  // Сортировка массива структур
  //Sort(employees, countSurnames, CompareEmployees);

  // Запись массива в текстовый файл
  WriteEmployeesToFile("src/data/result.txt", employees, countSurnames);

  // Запись массива в бинарный файл
  WriteEmployeesToFileBinary("src/data/result.bin", employees, countSurnames);

  // Очистка памяти
  delete[] allNumbers;
  delete[] allSurnames;
  delete[] employees;

  return 0;
}
