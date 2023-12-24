/*
                   Лабораторная работа №8
    Из заданной строки получить новую строку, выполняя замены по
    следующему правилу:
    ● символы латинского алфавита следует оставить без изменений;
    ● символ «пробел» следует заменить символом ‘+’;
    ● остальные символы заменяются подстроками вида “%ddd”, где ddd – код
    заменяемого символа в десятичной записи, дополненный в случае
    необходимости ведущими нулями до трёх цифр.
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>


std::string replaceCharacters(const std::string& input)
{
    std::ostringstream output;
    for (char ch : input) {
        if (isalpha(ch)) {
            // Символы латинского алфавита оставляем без изменений
            output << ch;
        }
        else if (ch == ' ') {
            // Пробел заменяем символом '+'
            output << '+';
        }
        else {
            // Остальные символы заменяем подстрокой вида "%ddd"
            int code = static_cast<int>(ch);
            output << '%' << std::setfill('0') << std::setw(3) << code;
        }
    }
    return output.str();
}

int main() {
    std::string inputString;
    std::cout << "Enter words: ";
    std::getline(std::cin, inputString);
    std::string result = replaceCharacters(inputString);
    std::cout << "Result of program: " << result << '\n';
    return 0;
}
