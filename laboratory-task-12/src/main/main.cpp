#include "src/MyString/MyString.hpp"


int main()
{
MyString str("Hello");
MyString str2(" ");
MyString str3 = "world!";
MyString str4(str3);
MyString str5 = str;
MyString temp;
temp = str5 + str2;
std::cout << temp + str4;
}
