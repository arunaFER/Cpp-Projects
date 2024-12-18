/*
Description

Valid Anagram: Easy

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// most efficient
bool isAnagramVector(std::string &s, std::string &t){
    if (s.length() != t.length()) return false;

    std::vector<int> count (26, 0);

    for(size_t i {0}; i < s.length(); ++i){
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

     for (int val : count) {
        if (val != 0) {
            return false;
        }
    }
    return true;
}

bool isAnagram(std::string &s, std::string &t){

    if (s.length() != t.length()) return false;

    std::unordered_map<char, int> charMap;

    for (char &letter: s){
        charMap[letter] += 1;
    }

    for (char &letter: t){
        charMap[letter] -= 1;
    }

    for(const auto &pair: charMap){
        if(pair.second != 0){
            return false;
        }
    }

    return true;
}

int main(){

    // std::string s{"racecar"};
    // std::string t{"carrace"};

    std::string s{"jar"};
    std::string t{"jam"};

    // std::cout << "Is Anagram output: " << std::boolalpha << isAnagram(s, t) << std::endl;

    std::cout << "Is Anagram output: " << std::boolalpha << isAnagramVector(s, t) << std::endl;

    return 0;
}