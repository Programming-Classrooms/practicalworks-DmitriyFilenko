#define _CRT_SECURE_NO_WARNINGS
#include "MyString.hpp"


int MyString::stringAmount = 0;

int MyString::howMany()
{
    return stringAmount;
}

MyString::MyString(const char* s)
{
    strLength = std::strlen(s);
    str = new char[strLength + 1];
    std::strcpy(str, s);
    stringAmount++;
}

MyString::MyString()
{
    strLength = 1;
    str = new char[1];
    str[0] = '\0';
    stringAmount++;
}

MyString::MyString(const MyString& st)
{
    stringAmount++;
    strLength = st.strLength;
    str = new char[strLength + 1];
    std::strcpy(str, st.str);
}

MyString::~MyString()
{
    --stringAmount;
    delete[] str;
}

char* MyString::getStr()
{
    char* temp = new char[strLength + 1];
    strcpy(temp, str);
    return temp;
}

void MyString::setStr(const char* rhs)
{
    delete[] str;
    strLength = strlen(rhs);
    str = new char[strLength + 1];
    std::strcpy(str, rhs);
}

void MyString::setStr(const MyString& rhs)
{
    strLength = rhs.strLength;
    str = new char[strLength + 1];
    std::strcpy(str, rhs.str);
}

void MyString::setSize(int rhs)
{
    this->strLength = rhs;
}


MyString& MyString::operator=(const MyString& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] str;
    strLength = rhs.strLength;
    str = new char[strLength + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

MyString& MyString::operator=(const char* rhs)
{
    delete[] str;
    strLength = std::strlen(rhs);
    str = new char[strLength + 1];
    std::strcpy(str, rhs);
    return *this;
}

void MyString::stringLow()
{
    for (int j = 0; j < strLength; ++j)
        str[j] = (char)tolower(str[j]);
}


void MyString::stringUp()
{
    for (int j = 0; j < strLength; ++j)
        str[j] = (char)toupper(str[j]);
}

int MyString::has(char rhs) const
{
    int counter = 0;
    for (int j = 0; j < strLength; ++j)
        if (str[j] == rhs)
            ++counter;

    return counter;
}

char& MyString::operator[](int i)
{
    return str[i];
}

const char& MyString::operator[](int i) const
{
    return str[i];
}

bool operator<(const MyString& st1, const MyString& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const MyString& st1, const MyString& st2)
{
    return st2 < st1;
}

bool operator==(const MyString& st1, const MyString& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}


std::ostream& operator<<(std::ostream& os, const MyString& st)
{
    os << st.str;
    return os;
}

MyString operator+(const MyString& st1, const MyString& st2)
{
    MyString _temp;
    delete[] _temp.str;
    _temp.strLength = st1.strLength + st2.strLength;
    _temp.str = new char[_temp.strLength + 1];

    std::strcpy(_temp.str, st1.str);
    std::strcpy(_temp.str + st1.strLength, st2.str);
    return _temp;
}

std::istream& operator>>(std::istream& is, MyString& st)
{
    char temp[MyString::CINLIM];
    is.get(temp, MyString::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}