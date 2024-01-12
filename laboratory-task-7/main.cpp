/*
*                       Лабораторная работа №7

    Дана строка, слова в которой состоят из букв латинского алфавита и
    десятичных цифр. Остальные символы считаются разделителями между
    словами. Получить новую строку, выполняя в заданой строке замены по
    следующему правилу. Все слова, имеющие длину менее 7 символов и
    состоящие только из цифр, заменяются словами, записанными в обратном
    порядке. Все слова, состоящие только из букв, записываются строчными
    буквами. Слова в новой строке должны разделяться ровно одним пробелом.
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>


bool isDecimalNumber(const std::string& s) {
    return std::all_of(s.begin(), s.end(), [](char c) {
        return std::isdigit(c) || c == '.';
        }) && std::count(s.begin(), s.end(), '.') <= 1;
}

std::string reverseNumber(const std::string& s) {
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

std::string modifyString(const std::string& inputString) {
    std::vector<std::string> words;
    std::string currentWord;

    for (char c : inputString) {
        if (std::isalnum(c) || c == '.') {
            currentWord.push_back(c);
        }
        else if (!currentWord.empty()) {
            // Обрабатываем слово
            if (isDecimalNumber(currentWord) && currentWord.length() < 7) {
                currentWord = reverseNumber(currentWord);
            }
            else {
                //tolower делает символы нижними
                std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
            }
            words.push_back(currentWord);
            currentWord.clear();
        }
    }

    // Обработка последнего слова
    if (!currentWord.empty()) {
        if (isDecimalNumber(currentWord) && currentWord.length() < 7) {
            currentWord = reverseNumber(currentWord);
        }
        else {
            std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
        }
        words.push_back(currentWord);
    }

    // Формируем результирующую строку
    std::string result;
    for (const auto& modifiedWord : words) {
        result += modifiedWord + ' ';
    }

    return result;
}

int main()
{
    std::string inputString;
    getline(std::cin, inputString);
    std::string result = modifyString(inputString);
    std::cout << result << '\n';
    return 0;
}
