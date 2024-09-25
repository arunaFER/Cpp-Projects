#include <iostream>
#include <cstring>

#include "MyString.h"

// no-args constructor
MyString::MyString()
    :str{nullptr}{
    str = new char[1];
    *str = '\0';
}

// overloaded constructor
MyString::MyString(const char* s)
    :str{nullptr}{
        if (s == nullptr){
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
}

// copy constructor
MyString::MyString(const MyString &source)
    :str{nullptr}{
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;
}

// move constructor
MyString::MyString(MyString &&source)
    :str{source.str}{
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// destructor
MyString::~MyString(){
    delete [] str;
}

// copy assignment
MyString &MyString::operator=(const MyString &rhs){
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs){
        return *this;
    }

    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);

    return *this;
}

// move assignment
MyString &MyString::operator=(MyString &&rhs){
    std::cout << "Using move assignment" << std::endl;

    if (this == &rhs){
        return *this;
    }

    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
} 

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const MyString &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, MyString &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = MyString{buff};
    delete [] buff;
    return in;
}

// unary -

/*
    The first unary - modifies the object in place
    The second one creates a new object and returns it.
    This is preferred - Preserves concept of immutability.
*/

// MyString &MyString::operator-(){
//     std::cout << "Using  unary - " << std::endl;

//     for (int i {0}; str[i] != '\0'; ++i){
//         str[i] = std::tolower(static_cast<unsigned char>(str[i]));
//     }

//     return *this;
// }

MyString MyString::operator-() const {
    char *buff= new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i=0; i<std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    MyString temp {buff};
    delete [] buff;
    return temp;
}


bool MyString::operator==(const MyString &rhs) const{
    return std::strcmp(str, rhs.str) == 0;
}

bool MyString::operator!=(const MyString &rhs) const{
    return std::strcmp(str, rhs.str);
}

bool MyString::operator<(const MyString &rhs) const{
    return std::strcmp(str, rhs.str) < 0;
}

bool MyString::operator>(const MyString &rhs) const{
    return std::strcmp(str, rhs.str) > 0;
}


MyString MyString::operator+(const MyString &rhs) const{
    char* buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    MyString temp {buff};
    delete [] buff;
    return temp;
}


MyString &MyString::operator+=(const MyString &rhs){
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);

    delete [] str;
    str = new char[std::strlen(buff) + std::strlen(rhs.str) + 1];

    std::strcat(str, buff);
    std::strcat(str, rhs.str);

    delete [] buff;

    return *this;
}


MyString MyString::operator*(int n) const{
    if (n <= 0) {
        return MyString("");
    }
    
    MyString temp;
    for (int i=1; i<= n; i++)
        temp = temp + *this;
    return temp;
    
    // char* buff = new char[(std::strlen(str) * n) + 1];
    // strcpy(buff, "");
    // for (int i {0}; i < n; ++i){
    //     std::strcat(buff, str);
    // }
    // MyString temp {buff};
    // delete [] buff;
    // return temp;   
}

MyString &MyString::operator*=(int n){
    if (n <= 0){
        std::strcpy(str, "");
        return *this;
    }

    *this += *this * n;

    // for (int i {0}; i < n; ++i){
    //     *this += *this;
    // }

    // char* buff = new char[std::strlen(str) * n + 1];
    // std::strcpy(buff, str);

    // delete [] str;
    // str = new char[(std::strlen(str) * n) + 1];
    // std::strcpy(str, "");

    // for (int i {0}; i < n; ++i){
    //     std::strcat(str, buff);
    // }

    // delete [] buff;

    return *this;    
}


// Pre-increment - make the string upper-case
MyString &MyString::operator++()   {  // pre-increment
    for (size_t i=0; i<std::strlen(str); i++)
        str[i] = std::toupper(str[i]);   
   return *this;
}

//Post-increment - make the string upper-case
MyString MyString::operator++(int) { 
   MyString temp (*this);       // make a copy
   operator++();                // call pre-increment - make sure you call preincrement!
   return temp;                 // return the old value
}


int MyString::getLength() const{
    return strlen(str);
}

const char* MyString::getStr() const{
    return str;
}

void MyString::display() const{
    std::cout << str << " : " << getLength() << std::endl;
}