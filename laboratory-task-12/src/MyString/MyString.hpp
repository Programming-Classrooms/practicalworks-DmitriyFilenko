#define _CRT_SECURE_NO_WARNINGS
#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <cstdlib>
#include <cctype>
#include <cstring> 
#include <iostream>

class MyString
{
private:
    char* str;
    int strLength;
    static int stringAmount;
    static const int CINLIM = 80;
public:

    MyString();
    MyString(const char*);
    MyString(const MyString&);
    ~MyString();
    //getters
    int strSize() const { return strLength; }
    char* getStr();
    //setters
    void setStr(const char*);
    void setStr(const MyString&);
    void setSize(int);

    MyString& operator=(const MyString&);
    MyString& operator=(const char*);
    char& operator[](int);
    const char& operator[](int) const;
    void stringLow();
    void stringUp();
    int has(char ch) const;
    friend bool operator<(const MyString&, const MyString&);
    friend bool operator>(const MyString&, const MyString&);
    friend bool operator==(const MyString&, const MyString&);
    friend std::ostream& operator<<(std::ostream&, const MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
    friend MyString operator+(const MyString&, const MyString&);
    static int howMany();
};

#endif // MyString_HPP