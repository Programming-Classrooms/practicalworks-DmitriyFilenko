
#include "funcs.hpp"

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;


int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String& st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete[] str;
}


String& String::operator=(const String& st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String& String::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

void String::stringlow()
{
    for (int j = 0; j < len; ++j)
        str[j] = (char)tolower(str[j]);
}


void String::stringup()
{
    for (int j = 0; j < len; ++j)
        str[j] = (char)toupper(str[j]);
}

int String::has(char ch) const
{
    int counter = 0;
    for (int j = 0; j < len; ++j)
        if (str[j] == ch)
            ++counter;

    return counter;
}

char& String::operator[](int i)
{
    return str[i];
}

const char& String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}


ostream& operator<<(ostream& os, const String& st)
{
    os << st.str;
    return os;
}

String operator+(const String& st1, const String& st2)
{
    String _temp;                         // âðåìåííûé îáúåêò
    delete[] _temp.str;                   // ñòèðàåì ñòðîêó, âûäåëåííóþ â êîíñòðóêòîðå ïî óìîë÷àíèþ
    _temp.len = st1.len + st2.len;        // âû÷èñëÿåì äëèíó áóäóùåé ñòðîêè
    _temp.str = new char[_temp.len + 1];  // âûäåëÿåì ìåñòî ïîä íîâóþ ñòðîêó + íóëåâîé ñèìâîë


    // ñîáñòâåííî, ñöåïëÿåì è ñîõðàíÿåì â íîâûé îáúåêò
    std::strcpy(_temp.str, st1.str);
    std::strcpy(_temp.str + st1.len, st2.str);
    return _temp;
}

istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}