/*
Description

Binary Search: Easy

You are given an array of distinct integers nums, sorted in ascending order, and an integer target.

Implement a function to search for target within nums. If it exists, then return its index, otherwise, return -1.
*/

#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &nums, int target){
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r){
        int m = l + ((r - l) / 2);
        // int m = (l + r) / 2; // Can overflow

        if (nums[m] > target){
            r = m - 1;
        } else if (nums[m] < target){
            l = m + 1;
        } else {
            return m;
        }
    }

    return -1;
}

int main(){
    std::vector<int> input {-1,0,2,4,6,8};
    int target = 4;

    std::cout << "Output: " << binarySearch(input, target) << std::endl;

    return 0;
}