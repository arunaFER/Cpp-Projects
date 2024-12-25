/*
Valid Parentheses: Easy

You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.
*/

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>


// best answer: time and space = O(n)
bool isValid(std::string &s){
    std::stack<char> stack;
    std::unordered_map<char, char> bracketMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for(char &c: s){
        // check if closing bracket
        if (bracketMap.count(c)){
            if (!stack.empty() && stack.top() == bracketMap[c]){
                stack.pop();
            } else {
                return false;
            }
        } else if (c == '(' || c == '{' || c == '['){
                stack.push(c);
        }
    }

    return stack.empty(); // check if all brackets matched!
    
}

// bool isValid(std::string &s){
//     std::stack<char> parenthesisCheck;

//     for (auto &c: s){
//         if (c == '(' || c == '{' || c == '['){
//             parenthesisCheck.push(c);
//         } else if (c == ')' || c == '}' || c == ']')
//         {
//            if (parenthesisCheck.empty()) {
//                 return false; // If the stack is empty, there's no matching open bracket
//             }

//             char bracket = parenthesisCheck.top();

//             if ((bracket == '{' && c == '}') ||
//                 (bracket == '(' && c == ')') ||
//                 (bracket == '[' && c == ']')) {
//                 parenthesisCheck.pop();
//             } else {
//                 return false; // If the bracket doesn't match, return false
//             }
//         }
//     }

//     return true;
// }

int main(){
    // std::string input {"([{}])"};
    std::string input {"A(bcd{})"};
    // std::string input {"[(])"};

    std::cout << "Is Valid Parenthesis: " << std::boolalpha << isValid(input) << std::endl;

    return 0;
}