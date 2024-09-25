#include <iostream>

#include "MyString.h"

int main(){

    MyString a {"FRANK"};
    MyString b {"tommy"};
    MyString c {"tommy"};


    std::cout << std::endl;

    a.display();
    b.display();

    std::cout << std::endl;
    a = -a;
    a.display();
    std::cout << std::endl;

    std::cout << std::boolalpha << std::endl;
    std::cout << (c==b) << std::endl;         // true
    std::cout << (c!=b) << std::endl;          // false

    b = "george";
    std::cout << (a==b) << std::endl;         // false
    std::cout << (a!=b) << std::endl;          // true
    std::cout << (a<b) << std::endl;          // true
    std::cout << (a>b) << std::endl;           // false

    a = a + "*****";
    a.display();

    a += "-----";                        // frank*****-----
    std::cout << a << std::endl;

    MyString s2{"12345"};
    a = s2 * 3;
    std::cout << a << std::endl;              // 123451234512345

    MyString s3{"abcdef"};  
    s3 *= 5;
    std::cout << s3 << std::endl;             // abcdefabcdefabcdefabcdefabcdef
   
    MyString s = "Frank";
    ++s;
    std::cout << s << std::endl;                  // FRANK
    
    s = -s; 
    std::cout << s << std::endl;                  // frank
    
    MyString result;
    result = ++s;                           
    std::cout << s << std::endl;                  // FRANK
    std::cout << result << std::endl;           // FRANK
    
    s = "Frank";
    s++;
    std::cout << s << std::endl;                  // FRANK
    
    s = -s;
    std::cout << s << std::endl;                  // frank
    result = s++;
    std::cout << s << std::endl;                  // FRANK
    std::cout << result << std::endl;           // frank


    return 0;
}