/*
Description

Contains Duplicate: Easy
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

bool hasDuplicate(std::vector<int> &nums){
    std::unordered_set<int> numSet{};

    for(auto &num: nums){
        if(numSet.count(num)){
            return true;
        }
        numSet.insert(num);
    }

    return false;
}

int main(){
    std::vector<int> nums = {1, 2, 3, 4};

    std::cout << "Output: " << std::boolalpha << hasDuplicate(nums) << std::endl;
    return 0;
}

/*
Answer

We can use hash set for constant time.
brute force is n2

there is also sorting & hash set length method.
*/