
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>


struct Employee {
  std::string surname;
  size_t children;
};


bool IsEven(int);

bool CompareByParity(int, int);

bool CompareEmployees(const Employee&, const Employee&);

template <typename T>
void Sort(T* , int , bool (*compare)(const T&, const T&));

int* ReadNumbersFromFile(const std::string& , int* );

std::string* ReadSurnamesFromFile(const std::string& , int* );

Employee* CreateEmployees(std::string* , int* , int );

void WriteEmployeesToFile(const std::string& , Employee* , int );

void WriteEmployeesToFileBinary(const std::string& , Employee* , int );

#endif //FUNCTION_HPP
