/*
Description

Two Sum: Easy
Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target){
    std::unordered_map<int, int> numMap; // current number and index

    for(int i {0}; i < nums.size(); ++i){
        int difference = target - nums[i];
        
        if(numMap.find(difference) != numMap.end()){
            return {numMap[difference], i};
        }
        numMap.emplace(nums[i], i);
    }
    return {};
}

int main(){
    std::vector<int> nums {3, 4, 5, 6};
    int target {7};
    std::vector<int> vec = twoSum(nums, target);

    std::cout << "Output: ";
    std::cout << "[";
    for (const auto &num: vec){
        std::cout << num << " ";
    }
     std::cout << "]" << std::endl;
    

    return 0;
}