/*
										Лабораторная работа №9
	Вариант 13
	Строки текстового файла input.txt состоят из слов, разделенных одним  или несколькими пробелами.
	Перед первым, а также после последнего слова  строки пробелы могут отсутствовать.
	Требуется в каждой строке найти слова  максимальной и минимальной длины и поменять их местами.
	Если таких  слов несколько – брать последние.
*/


#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


// Функция для разбиения строки на слова
std::vector<std::string> splitWords(const std::string& str) 
{
    std::vector<std::string> words;
    std::string currentWord;

    for (char ch : str) {
        if (std::isspace(ch)) {
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        else {
            currentWord += ch;
        }
    }

    // Проверка последнего слова в строке
    if (!currentWord.empty()) {
        words.push_back(currentWord);
    }

    return words;
}

// Функция для замены слов местами
std::string swapMinMaxWords(const std::string& str)
{
    std::vector<std::string> words = splitWords(str);

    if (words.empty()) {
        return str; // Возвращаем исходную строку, если нет слов
    }

    // Находим индексы максимального и минимального слов
    auto maxInd = std::max_element(words.begin(), words.end(),
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });

    auto minInd = std::min_element(words.begin(), words.end(),
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });

    // Меняем местами максимальное и минимальное слово
    std::iter_swap(minInd, maxInd);

    // Объединяем слова в строку с пробелами
    std::string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += ' ';
        }
    }

    return result;
}

int main()
{
    std::string input;
    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    std::string result = swapMinMaxWords(input);

    std::cout << "Result: " << result << '\n';

    return 0;
}
