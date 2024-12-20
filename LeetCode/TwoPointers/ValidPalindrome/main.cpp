/*
Description

Valid Palindrome: Easy

Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
*/

#include <iostream>
#include <string>
#include <cctype>

bool alphaNum(char c) {
    return ((c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z') || 
            (c >= '0' && c <= '9'));
}

// best approch
// O(n) time and O(1) space.

bool isPalindrome(std::string &s) {
    int l = 0, r = s.length() - 1;

    while (l < r) {
        while (l < r && !alphaNum(s[l])) {
            l++;
        }
        while (r > l && !alphaNum(s[r])) {
            r--;
        }
        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        l++; r--;
    }
    return true;
}

// bool isPalindrome(std::string s){
//     std::string cleanString;

//     for (char &c: s){
//         if (std::isalpha(static_cast<unsigned char>(c))){
//             cleanString += std::tolower(static_cast<unsigned char>(c));
//         }
//     }

//     // char* front = &cleanString[0];
//     // char* rear = &cleanString[cleanString.length() - 1];

//     // Using string iterators
//     auto front = cleanString.begin();
//     auto rear = cleanString.end() -1;

//     while (front < rear){
//         if (*front != *rear){
//             return false;
//         }
//         ++front;
//         --rear;
//     }

//     return true;
// }

int main(){
    std::string input {"Was it a car or a cat I saw?"};
    // std::string input {"tab a cat"};
    

    std::cout << "Is Palindrome: " << std::boolalpha << isPalindrome(input) << std::endl;

    return 0;
}